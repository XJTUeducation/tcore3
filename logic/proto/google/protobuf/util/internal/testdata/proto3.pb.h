// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/util/internal/testdata/proto3.proto

#ifndef PROTOBUF_INCLUDED_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto
#define PROTOBUF_INCLUDED_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto 

namespace protobuf_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto
namespace google {
namespace protobuf {
namespace testing {
class Proto3Message;
class Proto3MessageDefaultTypeInternal;
extern Proto3MessageDefaultTypeInternal _Proto3Message_default_instance_;
}  // namespace testing
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
template<> ::google::protobuf::testing::Proto3Message* Arena::CreateMaybeMessage<::google::protobuf::testing::Proto3Message>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
namespace testing {

enum Proto3Message_NestedEnum {
  Proto3Message_NestedEnum_FOO = 0,
  Proto3Message_NestedEnum_BAR = 1,
  Proto3Message_NestedEnum_BAZ = 2,
  Proto3Message_NestedEnum_Proto3Message_NestedEnum_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Proto3Message_NestedEnum_Proto3Message_NestedEnum_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Proto3Message_NestedEnum_IsValid(int value);
const Proto3Message_NestedEnum Proto3Message_NestedEnum_NestedEnum_MIN = Proto3Message_NestedEnum_FOO;
const Proto3Message_NestedEnum Proto3Message_NestedEnum_NestedEnum_MAX = Proto3Message_NestedEnum_BAZ;
const int Proto3Message_NestedEnum_NestedEnum_ARRAYSIZE = Proto3Message_NestedEnum_NestedEnum_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto3Message_NestedEnum_descriptor();
inline const ::std::string& Proto3Message_NestedEnum_Name(Proto3Message_NestedEnum value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto3Message_NestedEnum_descriptor(), value);
}
inline bool Proto3Message_NestedEnum_Parse(
    const ::std::string& name, Proto3Message_NestedEnum* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto3Message_NestedEnum>(
    Proto3Message_NestedEnum_descriptor(), name, value);
}
// ===================================================================

class Proto3Message : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.testing.Proto3Message) */ {
 public:
  Proto3Message();
  virtual ~Proto3Message();

  Proto3Message(const Proto3Message& from);

  inline Proto3Message& operator=(const Proto3Message& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Proto3Message(Proto3Message&& from) noexcept
    : Proto3Message() {
    *this = ::std::move(from);
  }

  inline Proto3Message& operator=(Proto3Message&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Proto3Message& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Proto3Message* internal_default_instance() {
    return reinterpret_cast<const Proto3Message*>(
               &_Proto3Message_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Proto3Message* other);
  friend void swap(Proto3Message& a, Proto3Message& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Proto3Message* New() const final {
    return CreateMaybeMessage<Proto3Message>(NULL);
  }

  Proto3Message* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Proto3Message>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Proto3Message& from);
  void MergeFrom(const Proto3Message& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Proto3Message* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Proto3Message_NestedEnum NestedEnum;
  static const NestedEnum FOO =
    Proto3Message_NestedEnum_FOO;
  static const NestedEnum BAR =
    Proto3Message_NestedEnum_BAR;
  static const NestedEnum BAZ =
    Proto3Message_NestedEnum_BAZ;
  static inline bool NestedEnum_IsValid(int value) {
    return Proto3Message_NestedEnum_IsValid(value);
  }
  static const NestedEnum NestedEnum_MIN =
    Proto3Message_NestedEnum_NestedEnum_MIN;
  static const NestedEnum NestedEnum_MAX =
    Proto3Message_NestedEnum_NestedEnum_MAX;
  static const int NestedEnum_ARRAYSIZE =
    Proto3Message_NestedEnum_NestedEnum_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  NestedEnum_descriptor() {
    return Proto3Message_NestedEnum_descriptor();
  }
  static inline const ::std::string& NestedEnum_Name(NestedEnum value) {
    return Proto3Message_NestedEnum_Name(value);
  }
  static inline bool NestedEnum_Parse(const ::std::string& name,
      NestedEnum* value) {
    return Proto3Message_NestedEnum_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // .google.protobuf.testing.Proto3Message.NestedEnum enum_value = 1;
  void clear_enum_value();
  static const int kEnumValueFieldNumber = 1;
  ::google::protobuf::testing::Proto3Message_NestedEnum enum_value() const;
  void set_enum_value(::google::protobuf::testing::Proto3Message_NestedEnum value);

  // @@protoc_insertion_point(class_scope:google.protobuf.testing.Proto3Message)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int enum_value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Proto3Message

// .google.protobuf.testing.Proto3Message.NestedEnum enum_value = 1;
inline void Proto3Message::clear_enum_value() {
  enum_value_ = 0;
}
inline ::google::protobuf::testing::Proto3Message_NestedEnum Proto3Message::enum_value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.testing.Proto3Message.enum_value)
  return static_cast< ::google::protobuf::testing::Proto3Message_NestedEnum >(enum_value_);
}
inline void Proto3Message::set_enum_value(::google::protobuf::testing::Proto3Message_NestedEnum value) {
  
  enum_value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.testing.Proto3Message.enum_value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace testing
}  // namespace protobuf
}  // namespace google

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::google::protobuf::testing::Proto3Message_NestedEnum> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::google::protobuf::testing::Proto3Message_NestedEnum>() {
  return ::google::protobuf::testing::Proto3Message_NestedEnum_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_google_2fprotobuf_2futil_2finternal_2ftestdata_2fproto3_2eproto