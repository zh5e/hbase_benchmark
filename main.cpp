#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <vector>
#include <string>
#include <random>
#include <thread>
#include <algorithm>
#include <functional>
#include <chrono>
using namespace std;

#include "time.h"

#include <boost/shared_ptr.hpp>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "gen-cpp/THBaseService.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::hadoop::hbase::thrift2;

#define CC cout << __LINE__ << " "

int put_handle(const string& salt, const string& host, int port) {
    string strHostFlag;
    {
        stringstream ss;
        ss << host << ":" << port;
        strHostFlag = ss.str();
    }

    boost::shared_ptr<TTransport> socket(new TSocket(host, port));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    THBaseServiceClient client(protocol);

    try {
        transport->open();
        if (transport->isOpen()) {
            cout << "连接hbase thrift成功" << endl;
        } else {
            cout << "连接hbase thrift失败" << endl;
            return -1;
        }

        // 读文件写到hbase
        cout << "start write" << endl;
        string strFilePath("/home/test/.vim/bundle/YouCompleteMe/third_party/ycmd/clang_archives/clang+llvm-4.0.0-x86_64-linux-gnu-ubuntu-14.04.tar.xz");
        fstream fs(strFilePath.c_str(), fstream::binary | fstream::in);
        if (!fs.is_open()) {
            cout << "failed to open file " << strFilePath << endl;
            return -1;
        }

        const int BUFFER_SIZE = 1024*1024*2;
        shared_ptr<char> spBuf(new char[BUFFER_SIZE], default_delete<char[]>());
        fs.rdbuf()->pubseekoff(0, fs.beg);
        fs.rdbuf()->sgetn(spBuf.get(), BUFFER_SIZE);
        fs.close();

        string str(spBuf.get(), BUFFER_SIZE);
        random_device rd;

        const long loop_count = 10000L;
        time_t begin = time(nullptr);
        hash<string> hash_str;
        for (int i = 0; i < loop_count; ++i) {
            time_t now = time(nullptr);
            stringstream ssrow;
            auto now_clock = chrono::system_clock::now();

            ssrow << salt << now_clock.time_since_epoch().count();

            TColumnValue columnVal;
            columnVal.family = "c";
            columnVal.value = str;
            columnVal.timestamp = now;

            // this_thread::sleep_for (chrono::seconds(1));

            TPut put;
            put.row = ssrow.str();
            reverse(put.row.begin(), put.row.end());
            // CC << put.row << endl;
            // exit(0);
            // put.timestamp = now;
            put.columnValues.push_back(columnVal);

            // CC << put.row << endl;

            // 接口调用时间
            {
                client.put("test", put);
                auto _now = time(nullptr);
                if (_now - now > 1)  {
                    CC << strHostFlag << " " << i <<  " 调用时间：" << _now - now << endl;
                }
            }
        }
        auto cost = time(nullptr) - begin;
        CC << strHostFlag << " cost: " << cost << " size: " << 1L * loop_count * BUFFER_SIZE << " byte" << endl;
        CC << strHostFlag << " " << (loop_count * BUFFER_SIZE * 1.0f) / cost / 1024 / 1024 << " m/sec" << endl;

    }
    catch (exception& e) {
        CC << e.what() << endl;
    }

    return 0;
}

int main() {
    vector<thread> threads;
    threads.push_back(thread(put_handle, "", "132.224.229.13", 9090));
    threads.push_back(thread(put_handle, "", "132.224.229.13", 9090));

    threads.push_back(thread(put_handle, "", "132.224.229.14", 9090));
    threads.push_back(thread(put_handle, "", "132.224.229.14", 9090));

    threads.push_back(thread(put_handle, "", "132.224.229.15", 9090));
    threads.push_back(thread(put_handle, "", "132.224.229.15", 9090));

    for (auto& th : threads) {
        th.join();
    }
    return 0;
}
