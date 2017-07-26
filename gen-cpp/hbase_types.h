/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef hbase_TYPES_H
#define hbase_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace apache { namespace hadoop { namespace hbase { namespace thrift2 {

struct TDeleteType {
  enum type {
    DELETE_COLUMN = 0,
    DELETE_COLUMNS = 1
  };
};

extern const std::map<int, const char*> _TDeleteType_VALUES_TO_NAMES;

struct TDurability {
  enum type {
    SKIP_WAL = 1,
    ASYNC_WAL = 2,
    SYNC_WAL = 3,
    FSYNC_WAL = 4
  };
};

extern const std::map<int, const char*> _TDurability_VALUES_TO_NAMES;

struct TReadType {
  enum type {
    DEFAULT = 1,
    STREAM = 2,
    PREAD = 3
  };
};

extern const std::map<int, const char*> _TReadType_VALUES_TO_NAMES;

struct TCompareOp {
  enum type {
    LESS = 0,
    LESS_OR_EQUAL = 1,
    EQUAL = 2,
    NOT_EQUAL = 3,
    GREATER_OR_EQUAL = 4,
    GREATER = 5,
    NO_OP = 6
  };
};

extern const std::map<int, const char*> _TCompareOp_VALUES_TO_NAMES;

class TTimeRange;

class TColumn;

class TColumnValue;

class TColumnIncrement;

class TResult;

class TAuthorization;

class TCellVisibility;

class TGet;

class TPut;

class TDelete;

class TIncrement;

class TAppend;

class TScan;

class TMutation;

class TRowMutations;

class THRegionInfo;

class TServerName;

class THRegionLocation;

class TIOError;

class TIllegalArgument;


class TTimeRange : public virtual ::apache::thrift::TBase {
 public:

  TTimeRange(const TTimeRange&);
  TTimeRange& operator=(const TTimeRange&);
  TTimeRange() : minStamp(0), maxStamp(0) {
  }

  virtual ~TTimeRange() throw();
  int64_t minStamp;
  int64_t maxStamp;

  void __set_minStamp(const int64_t val);

  void __set_maxStamp(const int64_t val);

  bool operator == (const TTimeRange & rhs) const
  {
    if (!(minStamp == rhs.minStamp))
      return false;
    if (!(maxStamp == rhs.maxStamp))
      return false;
    return true;
  }
  bool operator != (const TTimeRange &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTimeRange & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TTimeRange &a, TTimeRange &b);

inline std::ostream& operator<<(std::ostream& out, const TTimeRange& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TColumn__isset {
  _TColumn__isset() : qualifier(false), timestamp(false) {}
  bool qualifier :1;
  bool timestamp :1;
} _TColumn__isset;

class TColumn : public virtual ::apache::thrift::TBase {
 public:

  TColumn(const TColumn&);
  TColumn& operator=(const TColumn&);
  TColumn() : family(), qualifier(), timestamp(0) {
  }

  virtual ~TColumn() throw();
  std::string family;
  std::string qualifier;
  int64_t timestamp;

  _TColumn__isset __isset;

  void __set_family(const std::string& val);

  void __set_qualifier(const std::string& val);

  void __set_timestamp(const int64_t val);

  bool operator == (const TColumn & rhs) const
  {
    if (!(family == rhs.family))
      return false;
    if (__isset.qualifier != rhs.__isset.qualifier)
      return false;
    else if (__isset.qualifier && !(qualifier == rhs.qualifier))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    return true;
  }
  bool operator != (const TColumn &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumn & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TColumn &a, TColumn &b);

inline std::ostream& operator<<(std::ostream& out, const TColumn& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TColumnValue__isset {
  _TColumnValue__isset() : timestamp(false), tags(false) {}
  bool timestamp :1;
  bool tags :1;
} _TColumnValue__isset;

class TColumnValue : public virtual ::apache::thrift::TBase {
 public:

  TColumnValue(const TColumnValue&);
  TColumnValue& operator=(const TColumnValue&);
  TColumnValue() : family(), qualifier(), value(), timestamp(0), tags() {
  }

  virtual ~TColumnValue() throw();
  std::string family;
  std::string qualifier;
  std::string value;
  int64_t timestamp;
  std::string tags;

  _TColumnValue__isset __isset;

  void __set_family(const std::string& val);

  void __set_qualifier(const std::string& val);

  void __set_value(const std::string& val);

  void __set_timestamp(const int64_t val);

  void __set_tags(const std::string& val);

  bool operator == (const TColumnValue & rhs) const
  {
    if (!(family == rhs.family))
      return false;
    if (!(qualifier == rhs.qualifier))
      return false;
    if (!(value == rhs.value))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    if (__isset.tags != rhs.__isset.tags)
      return false;
    else if (__isset.tags && !(tags == rhs.tags))
      return false;
    return true;
  }
  bool operator != (const TColumnValue &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumnValue & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TColumnValue &a, TColumnValue &b);

inline std::ostream& operator<<(std::ostream& out, const TColumnValue& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TColumnIncrement__isset {
  _TColumnIncrement__isset() : amount(true) {}
  bool amount :1;
} _TColumnIncrement__isset;

class TColumnIncrement : public virtual ::apache::thrift::TBase {
 public:

  TColumnIncrement(const TColumnIncrement&);
  TColumnIncrement& operator=(const TColumnIncrement&);
  TColumnIncrement() : family(), qualifier(), amount(1LL) {
  }

  virtual ~TColumnIncrement() throw();
  std::string family;
  std::string qualifier;
  int64_t amount;

  _TColumnIncrement__isset __isset;

  void __set_family(const std::string& val);

  void __set_qualifier(const std::string& val);

  void __set_amount(const int64_t val);

  bool operator == (const TColumnIncrement & rhs) const
  {
    if (!(family == rhs.family))
      return false;
    if (!(qualifier == rhs.qualifier))
      return false;
    if (__isset.amount != rhs.__isset.amount)
      return false;
    else if (__isset.amount && !(amount == rhs.amount))
      return false;
    return true;
  }
  bool operator != (const TColumnIncrement &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumnIncrement & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TColumnIncrement &a, TColumnIncrement &b);

inline std::ostream& operator<<(std::ostream& out, const TColumnIncrement& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TResult__isset {
  _TResult__isset() : row(false) {}
  bool row :1;
} _TResult__isset;

class TResult : public virtual ::apache::thrift::TBase {
 public:

  TResult(const TResult&);
  TResult& operator=(const TResult&);
  TResult() : row() {
  }

  virtual ~TResult() throw();
  std::string row;
  std::vector<TColumnValue>  columnValues;

  _TResult__isset __isset;

  void __set_row(const std::string& val);

  void __set_columnValues(const std::vector<TColumnValue> & val);

  bool operator == (const TResult & rhs) const
  {
    if (__isset.row != rhs.__isset.row)
      return false;
    else if (__isset.row && !(row == rhs.row))
      return false;
    if (!(columnValues == rhs.columnValues))
      return false;
    return true;
  }
  bool operator != (const TResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TResult &a, TResult &b);

inline std::ostream& operator<<(std::ostream& out, const TResult& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TAuthorization__isset {
  _TAuthorization__isset() : labels(false) {}
  bool labels :1;
} _TAuthorization__isset;

class TAuthorization : public virtual ::apache::thrift::TBase {
 public:

  TAuthorization(const TAuthorization&);
  TAuthorization& operator=(const TAuthorization&);
  TAuthorization() {
  }

  virtual ~TAuthorization() throw();
  std::vector<std::string>  labels;

  _TAuthorization__isset __isset;

  void __set_labels(const std::vector<std::string> & val);

  bool operator == (const TAuthorization & rhs) const
  {
    if (__isset.labels != rhs.__isset.labels)
      return false;
    else if (__isset.labels && !(labels == rhs.labels))
      return false;
    return true;
  }
  bool operator != (const TAuthorization &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TAuthorization & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TAuthorization &a, TAuthorization &b);

inline std::ostream& operator<<(std::ostream& out, const TAuthorization& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TCellVisibility__isset {
  _TCellVisibility__isset() : expression(false) {}
  bool expression :1;
} _TCellVisibility__isset;

class TCellVisibility : public virtual ::apache::thrift::TBase {
 public:

  TCellVisibility(const TCellVisibility&);
  TCellVisibility& operator=(const TCellVisibility&);
  TCellVisibility() : expression() {
  }

  virtual ~TCellVisibility() throw();
  std::string expression;

  _TCellVisibility__isset __isset;

  void __set_expression(const std::string& val);

  bool operator == (const TCellVisibility & rhs) const
  {
    if (__isset.expression != rhs.__isset.expression)
      return false;
    else if (__isset.expression && !(expression == rhs.expression))
      return false;
    return true;
  }
  bool operator != (const TCellVisibility &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCellVisibility & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCellVisibility &a, TCellVisibility &b);

inline std::ostream& operator<<(std::ostream& out, const TCellVisibility& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TGet__isset {
  _TGet__isset() : columns(false), timestamp(false), timeRange(false), maxVersions(false), filterString(false), attributes(false), authorizations(false) {}
  bool columns :1;
  bool timestamp :1;
  bool timeRange :1;
  bool maxVersions :1;
  bool filterString :1;
  bool attributes :1;
  bool authorizations :1;
} _TGet__isset;

class TGet : public virtual ::apache::thrift::TBase {
 public:

  TGet(const TGet&);
  TGet& operator=(const TGet&);
  TGet() : row(), timestamp(0), maxVersions(0), filterString() {
  }

  virtual ~TGet() throw();
  std::string row;
  std::vector<TColumn>  columns;
  int64_t timestamp;
  TTimeRange timeRange;
  int32_t maxVersions;
  std::string filterString;
  std::map<std::string, std::string>  attributes;
  TAuthorization authorizations;

  _TGet__isset __isset;

  void __set_row(const std::string& val);

  void __set_columns(const std::vector<TColumn> & val);

  void __set_timestamp(const int64_t val);

  void __set_timeRange(const TTimeRange& val);

  void __set_maxVersions(const int32_t val);

  void __set_filterString(const std::string& val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_authorizations(const TAuthorization& val);

  bool operator == (const TGet & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    if (__isset.timeRange != rhs.__isset.timeRange)
      return false;
    else if (__isset.timeRange && !(timeRange == rhs.timeRange))
      return false;
    if (__isset.maxVersions != rhs.__isset.maxVersions)
      return false;
    else if (__isset.maxVersions && !(maxVersions == rhs.maxVersions))
      return false;
    if (__isset.filterString != rhs.__isset.filterString)
      return false;
    else if (__isset.filterString && !(filterString == rhs.filterString))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.authorizations != rhs.__isset.authorizations)
      return false;
    else if (__isset.authorizations && !(authorizations == rhs.authorizations))
      return false;
    return true;
  }
  bool operator != (const TGet &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TGet & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TGet &a, TGet &b);

inline std::ostream& operator<<(std::ostream& out, const TGet& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TPut__isset {
  _TPut__isset() : timestamp(false), attributes(false), durability(false), cellVisibility(false) {}
  bool timestamp :1;
  bool attributes :1;
  bool durability :1;
  bool cellVisibility :1;
} _TPut__isset;

class TPut : public virtual ::apache::thrift::TBase {
 public:

  TPut(const TPut&);
  TPut& operator=(const TPut&);
  TPut() : row(), timestamp(0), durability((TDurability::type)0) {
  }

  virtual ~TPut() throw();
  std::string row;
  std::vector<TColumnValue>  columnValues;
  int64_t timestamp;
  std::map<std::string, std::string>  attributes;
  TDurability::type durability;
  TCellVisibility cellVisibility;

  _TPut__isset __isset;

  void __set_row(const std::string& val);

  void __set_columnValues(const std::vector<TColumnValue> & val);

  void __set_timestamp(const int64_t val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_durability(const TDurability::type val);

  void __set_cellVisibility(const TCellVisibility& val);

  bool operator == (const TPut & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(columnValues == rhs.columnValues))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.durability != rhs.__isset.durability)
      return false;
    else if (__isset.durability && !(durability == rhs.durability))
      return false;
    if (__isset.cellVisibility != rhs.__isset.cellVisibility)
      return false;
    else if (__isset.cellVisibility && !(cellVisibility == rhs.cellVisibility))
      return false;
    return true;
  }
  bool operator != (const TPut &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TPut & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPut &a, TPut &b);

inline std::ostream& operator<<(std::ostream& out, const TPut& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TDelete__isset {
  _TDelete__isset() : columns(false), timestamp(false), deleteType(true), attributes(false), durability(false) {}
  bool columns :1;
  bool timestamp :1;
  bool deleteType :1;
  bool attributes :1;
  bool durability :1;
} _TDelete__isset;

class TDelete : public virtual ::apache::thrift::TBase {
 public:

  TDelete(const TDelete&);
  TDelete& operator=(const TDelete&);
  TDelete() : row(), timestamp(0), deleteType((TDeleteType::type)1), durability((TDurability::type)0) {
    deleteType = (TDeleteType::type)1;

  }

  virtual ~TDelete() throw();
  std::string row;
  std::vector<TColumn>  columns;
  int64_t timestamp;
  TDeleteType::type deleteType;
  std::map<std::string, std::string>  attributes;
  TDurability::type durability;

  _TDelete__isset __isset;

  void __set_row(const std::string& val);

  void __set_columns(const std::vector<TColumn> & val);

  void __set_timestamp(const int64_t val);

  void __set_deleteType(const TDeleteType::type val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_durability(const TDurability::type val);

  bool operator == (const TDelete & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    if (__isset.deleteType != rhs.__isset.deleteType)
      return false;
    else if (__isset.deleteType && !(deleteType == rhs.deleteType))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.durability != rhs.__isset.durability)
      return false;
    else if (__isset.durability && !(durability == rhs.durability))
      return false;
    return true;
  }
  bool operator != (const TDelete &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDelete & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDelete &a, TDelete &b);

inline std::ostream& operator<<(std::ostream& out, const TDelete& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TIncrement__isset {
  _TIncrement__isset() : attributes(false), durability(false), cellVisibility(false) {}
  bool attributes :1;
  bool durability :1;
  bool cellVisibility :1;
} _TIncrement__isset;

class TIncrement : public virtual ::apache::thrift::TBase {
 public:

  TIncrement(const TIncrement&);
  TIncrement& operator=(const TIncrement&);
  TIncrement() : row(), durability((TDurability::type)0) {
  }

  virtual ~TIncrement() throw();
  std::string row;
  std::vector<TColumnIncrement>  columns;
  std::map<std::string, std::string>  attributes;
  TDurability::type durability;
  TCellVisibility cellVisibility;

  _TIncrement__isset __isset;

  void __set_row(const std::string& val);

  void __set_columns(const std::vector<TColumnIncrement> & val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_durability(const TDurability::type val);

  void __set_cellVisibility(const TCellVisibility& val);

  bool operator == (const TIncrement & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(columns == rhs.columns))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.durability != rhs.__isset.durability)
      return false;
    else if (__isset.durability && !(durability == rhs.durability))
      return false;
    if (__isset.cellVisibility != rhs.__isset.cellVisibility)
      return false;
    else if (__isset.cellVisibility && !(cellVisibility == rhs.cellVisibility))
      return false;
    return true;
  }
  bool operator != (const TIncrement &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TIncrement & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TIncrement &a, TIncrement &b);

inline std::ostream& operator<<(std::ostream& out, const TIncrement& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TAppend__isset {
  _TAppend__isset() : attributes(false), durability(false), cellVisibility(false) {}
  bool attributes :1;
  bool durability :1;
  bool cellVisibility :1;
} _TAppend__isset;

class TAppend : public virtual ::apache::thrift::TBase {
 public:

  TAppend(const TAppend&);
  TAppend& operator=(const TAppend&);
  TAppend() : row(), durability((TDurability::type)0) {
  }

  virtual ~TAppend() throw();
  std::string row;
  std::vector<TColumnValue>  columns;
  std::map<std::string, std::string>  attributes;
  TDurability::type durability;
  TCellVisibility cellVisibility;

  _TAppend__isset __isset;

  void __set_row(const std::string& val);

  void __set_columns(const std::vector<TColumnValue> & val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_durability(const TDurability::type val);

  void __set_cellVisibility(const TCellVisibility& val);

  bool operator == (const TAppend & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(columns == rhs.columns))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.durability != rhs.__isset.durability)
      return false;
    else if (__isset.durability && !(durability == rhs.durability))
      return false;
    if (__isset.cellVisibility != rhs.__isset.cellVisibility)
      return false;
    else if (__isset.cellVisibility && !(cellVisibility == rhs.cellVisibility))
      return false;
    return true;
  }
  bool operator != (const TAppend &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TAppend & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TAppend &a, TAppend &b);

inline std::ostream& operator<<(std::ostream& out, const TAppend& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TScan__isset {
  _TScan__isset() : startRow(false), stopRow(false), columns(false), caching(false), maxVersions(true), timeRange(false), filterString(false), batchSize(false), attributes(false), authorizations(false), reversed(false), cacheBlocks(false), colFamTimeRangeMap(false), readType(false), limit(false) {}
  bool startRow :1;
  bool stopRow :1;
  bool columns :1;
  bool caching :1;
  bool maxVersions :1;
  bool timeRange :1;
  bool filterString :1;
  bool batchSize :1;
  bool attributes :1;
  bool authorizations :1;
  bool reversed :1;
  bool cacheBlocks :1;
  bool colFamTimeRangeMap :1;
  bool readType :1;
  bool limit :1;
} _TScan__isset;

class TScan : public virtual ::apache::thrift::TBase {
 public:

  TScan(const TScan&);
  TScan& operator=(const TScan&);
  TScan() : startRow(), stopRow(), caching(0), maxVersions(1), filterString(), batchSize(0), reversed(0), cacheBlocks(0), readType((TReadType::type)0), limit(0) {
  }

  virtual ~TScan() throw();
  std::string startRow;
  std::string stopRow;
  std::vector<TColumn>  columns;
  int32_t caching;
  int32_t maxVersions;
  TTimeRange timeRange;
  std::string filterString;
  int32_t batchSize;
  std::map<std::string, std::string>  attributes;
  TAuthorization authorizations;
  bool reversed;
  bool cacheBlocks;
  std::map<std::string, TTimeRange>  colFamTimeRangeMap;
  TReadType::type readType;
  int32_t limit;

  _TScan__isset __isset;

  void __set_startRow(const std::string& val);

  void __set_stopRow(const std::string& val);

  void __set_columns(const std::vector<TColumn> & val);

  void __set_caching(const int32_t val);

  void __set_maxVersions(const int32_t val);

  void __set_timeRange(const TTimeRange& val);

  void __set_filterString(const std::string& val);

  void __set_batchSize(const int32_t val);

  void __set_attributes(const std::map<std::string, std::string> & val);

  void __set_authorizations(const TAuthorization& val);

  void __set_reversed(const bool val);

  void __set_cacheBlocks(const bool val);

  void __set_colFamTimeRangeMap(const std::map<std::string, TTimeRange> & val);

  void __set_readType(const TReadType::type val);

  void __set_limit(const int32_t val);

  bool operator == (const TScan & rhs) const
  {
    if (__isset.startRow != rhs.__isset.startRow)
      return false;
    else if (__isset.startRow && !(startRow == rhs.startRow))
      return false;
    if (__isset.stopRow != rhs.__isset.stopRow)
      return false;
    else if (__isset.stopRow && !(stopRow == rhs.stopRow))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    if (__isset.caching != rhs.__isset.caching)
      return false;
    else if (__isset.caching && !(caching == rhs.caching))
      return false;
    if (__isset.maxVersions != rhs.__isset.maxVersions)
      return false;
    else if (__isset.maxVersions && !(maxVersions == rhs.maxVersions))
      return false;
    if (__isset.timeRange != rhs.__isset.timeRange)
      return false;
    else if (__isset.timeRange && !(timeRange == rhs.timeRange))
      return false;
    if (__isset.filterString != rhs.__isset.filterString)
      return false;
    else if (__isset.filterString && !(filterString == rhs.filterString))
      return false;
    if (__isset.batchSize != rhs.__isset.batchSize)
      return false;
    else if (__isset.batchSize && !(batchSize == rhs.batchSize))
      return false;
    if (__isset.attributes != rhs.__isset.attributes)
      return false;
    else if (__isset.attributes && !(attributes == rhs.attributes))
      return false;
    if (__isset.authorizations != rhs.__isset.authorizations)
      return false;
    else if (__isset.authorizations && !(authorizations == rhs.authorizations))
      return false;
    if (__isset.reversed != rhs.__isset.reversed)
      return false;
    else if (__isset.reversed && !(reversed == rhs.reversed))
      return false;
    if (__isset.cacheBlocks != rhs.__isset.cacheBlocks)
      return false;
    else if (__isset.cacheBlocks && !(cacheBlocks == rhs.cacheBlocks))
      return false;
    if (__isset.colFamTimeRangeMap != rhs.__isset.colFamTimeRangeMap)
      return false;
    else if (__isset.colFamTimeRangeMap && !(colFamTimeRangeMap == rhs.colFamTimeRangeMap))
      return false;
    if (__isset.readType != rhs.__isset.readType)
      return false;
    else if (__isset.readType && !(readType == rhs.readType))
      return false;
    if (__isset.limit != rhs.__isset.limit)
      return false;
    else if (__isset.limit && !(limit == rhs.limit))
      return false;
    return true;
  }
  bool operator != (const TScan &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TScan & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TScan &a, TScan &b);

inline std::ostream& operator<<(std::ostream& out, const TScan& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TMutation__isset {
  _TMutation__isset() : put(false), deleteSingle(false) {}
  bool put :1;
  bool deleteSingle :1;
} _TMutation__isset;

class TMutation : public virtual ::apache::thrift::TBase {
 public:

  TMutation(const TMutation&);
  TMutation& operator=(const TMutation&);
  TMutation() {
  }

  virtual ~TMutation() throw();
  TPut put;
  TDelete deleteSingle;

  _TMutation__isset __isset;

  void __set_put(const TPut& val);

  void __set_deleteSingle(const TDelete& val);

  bool operator == (const TMutation & rhs) const
  {
    if (__isset.put != rhs.__isset.put)
      return false;
    else if (__isset.put && !(put == rhs.put))
      return false;
    if (__isset.deleteSingle != rhs.__isset.deleteSingle)
      return false;
    else if (__isset.deleteSingle && !(deleteSingle == rhs.deleteSingle))
      return false;
    return true;
  }
  bool operator != (const TMutation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TMutation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TMutation &a, TMutation &b);

inline std::ostream& operator<<(std::ostream& out, const TMutation& obj)
{
  obj.printTo(out);
  return out;
}


class TRowMutations : public virtual ::apache::thrift::TBase {
 public:

  TRowMutations(const TRowMutations&);
  TRowMutations& operator=(const TRowMutations&);
  TRowMutations() : row() {
  }

  virtual ~TRowMutations() throw();
  std::string row;
  std::vector<TMutation>  mutations;

  void __set_row(const std::string& val);

  void __set_mutations(const std::vector<TMutation> & val);

  bool operator == (const TRowMutations & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(mutations == rhs.mutations))
      return false;
    return true;
  }
  bool operator != (const TRowMutations &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRowMutations & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRowMutations &a, TRowMutations &b);

inline std::ostream& operator<<(std::ostream& out, const TRowMutations& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _THRegionInfo__isset {
  _THRegionInfo__isset() : startKey(false), endKey(false), offline(false), split(false), replicaId(false) {}
  bool startKey :1;
  bool endKey :1;
  bool offline :1;
  bool split :1;
  bool replicaId :1;
} _THRegionInfo__isset;

class THRegionInfo : public virtual ::apache::thrift::TBase {
 public:

  THRegionInfo(const THRegionInfo&);
  THRegionInfo& operator=(const THRegionInfo&);
  THRegionInfo() : regionId(0), tableName(), startKey(), endKey(), offline(0), split(0), replicaId(0) {
  }

  virtual ~THRegionInfo() throw();
  int64_t regionId;
  std::string tableName;
  std::string startKey;
  std::string endKey;
  bool offline;
  bool split;
  int32_t replicaId;

  _THRegionInfo__isset __isset;

  void __set_regionId(const int64_t val);

  void __set_tableName(const std::string& val);

  void __set_startKey(const std::string& val);

  void __set_endKey(const std::string& val);

  void __set_offline(const bool val);

  void __set_split(const bool val);

  void __set_replicaId(const int32_t val);

  bool operator == (const THRegionInfo & rhs) const
  {
    if (!(regionId == rhs.regionId))
      return false;
    if (!(tableName == rhs.tableName))
      return false;
    if (__isset.startKey != rhs.__isset.startKey)
      return false;
    else if (__isset.startKey && !(startKey == rhs.startKey))
      return false;
    if (__isset.endKey != rhs.__isset.endKey)
      return false;
    else if (__isset.endKey && !(endKey == rhs.endKey))
      return false;
    if (__isset.offline != rhs.__isset.offline)
      return false;
    else if (__isset.offline && !(offline == rhs.offline))
      return false;
    if (__isset.split != rhs.__isset.split)
      return false;
    else if (__isset.split && !(split == rhs.split))
      return false;
    if (__isset.replicaId != rhs.__isset.replicaId)
      return false;
    else if (__isset.replicaId && !(replicaId == rhs.replicaId))
      return false;
    return true;
  }
  bool operator != (const THRegionInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const THRegionInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(THRegionInfo &a, THRegionInfo &b);

inline std::ostream& operator<<(std::ostream& out, const THRegionInfo& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TServerName__isset {
  _TServerName__isset() : port(false), startCode(false) {}
  bool port :1;
  bool startCode :1;
} _TServerName__isset;

class TServerName : public virtual ::apache::thrift::TBase {
 public:

  TServerName(const TServerName&);
  TServerName& operator=(const TServerName&);
  TServerName() : hostName(), port(0), startCode(0) {
  }

  virtual ~TServerName() throw();
  std::string hostName;
  int32_t port;
  int64_t startCode;

  _TServerName__isset __isset;

  void __set_hostName(const std::string& val);

  void __set_port(const int32_t val);

  void __set_startCode(const int64_t val);

  bool operator == (const TServerName & rhs) const
  {
    if (!(hostName == rhs.hostName))
      return false;
    if (__isset.port != rhs.__isset.port)
      return false;
    else if (__isset.port && !(port == rhs.port))
      return false;
    if (__isset.startCode != rhs.__isset.startCode)
      return false;
    else if (__isset.startCode && !(startCode == rhs.startCode))
      return false;
    return true;
  }
  bool operator != (const TServerName &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TServerName & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TServerName &a, TServerName &b);

inline std::ostream& operator<<(std::ostream& out, const TServerName& obj)
{
  obj.printTo(out);
  return out;
}


class THRegionLocation : public virtual ::apache::thrift::TBase {
 public:

  THRegionLocation(const THRegionLocation&);
  THRegionLocation& operator=(const THRegionLocation&);
  THRegionLocation() {
  }

  virtual ~THRegionLocation() throw();
  TServerName serverName;
  THRegionInfo regionInfo;

  void __set_serverName(const TServerName& val);

  void __set_regionInfo(const THRegionInfo& val);

  bool operator == (const THRegionLocation & rhs) const
  {
    if (!(serverName == rhs.serverName))
      return false;
    if (!(regionInfo == rhs.regionInfo))
      return false;
    return true;
  }
  bool operator != (const THRegionLocation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const THRegionLocation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(THRegionLocation &a, THRegionLocation &b);

inline std::ostream& operator<<(std::ostream& out, const THRegionLocation& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TIOError__isset {
  _TIOError__isset() : message(false) {}
  bool message :1;
} _TIOError__isset;

class TIOError : public ::apache::thrift::TException {
 public:

  TIOError(const TIOError&);
  TIOError& operator=(const TIOError&);
  TIOError() : message() {
  }

  virtual ~TIOError() throw();
  std::string message;

  _TIOError__isset __isset;

  void __set_message(const std::string& val);

  bool operator == (const TIOError & rhs) const
  {
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const TIOError &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TIOError & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(TIOError &a, TIOError &b);

inline std::ostream& operator<<(std::ostream& out, const TIOError& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TIllegalArgument__isset {
  _TIllegalArgument__isset() : message(false) {}
  bool message :1;
} _TIllegalArgument__isset;

class TIllegalArgument : public ::apache::thrift::TException {
 public:

  TIllegalArgument(const TIllegalArgument&);
  TIllegalArgument& operator=(const TIllegalArgument&);
  TIllegalArgument() : message() {
  }

  virtual ~TIllegalArgument() throw();
  std::string message;

  _TIllegalArgument__isset __isset;

  void __set_message(const std::string& val);

  bool operator == (const TIllegalArgument & rhs) const
  {
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const TIllegalArgument &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TIllegalArgument & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(TIllegalArgument &a, TIllegalArgument &b);

inline std::ostream& operator<<(std::ostream& out, const TIllegalArgument& obj)
{
  obj.printTo(out);
  return out;
}

}}}} // namespace

#endif
