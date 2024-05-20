// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: src/proto/math.proto
// Protobuf C++ Version: 4.25.3

#ifndef GOOGLE_PROTOBUF_INCLUDED_src_2fproto_2fmath_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_src_2fproto_2fmath_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025003 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_src_2fproto_2fmath_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_src_2fproto_2fmath_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_src_2fproto_2fmath_2eproto;
namespace xrpc {
namespace math {
class Arguments;
struct ArgumentsDefaultTypeInternal;
extern ArgumentsDefaultTypeInternal _Arguments_default_instance_;
class MathRequest;
struct MathRequestDefaultTypeInternal;
extern MathRequestDefaultTypeInternal _MathRequest_default_instance_;
class MathResponse;
struct MathResponseDefaultTypeInternal;
extern MathResponseDefaultTypeInternal _MathResponse_default_instance_;
}  // namespace math
}  // namespace xrpc
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace xrpc {
namespace math {
enum MathOperation : int {
  Add = 0,
  Subtract = 1,
  Multiply = 2,
  Divide = 3,
  MathOperation_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  MathOperation_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool MathOperation_IsValid(int value);
extern const uint32_t MathOperation_internal_data_[];
constexpr MathOperation MathOperation_MIN = static_cast<MathOperation>(0);
constexpr MathOperation MathOperation_MAX = static_cast<MathOperation>(3);
constexpr int MathOperation_ARRAYSIZE = 3 + 1;
const ::google::protobuf::EnumDescriptor*
MathOperation_descriptor();
template <typename T>
const std::string& MathOperation_Name(T value) {
  static_assert(std::is_same<T, MathOperation>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to MathOperation_Name().");
  return MathOperation_Name(static_cast<MathOperation>(value));
}
template <>
inline const std::string& MathOperation_Name(MathOperation value) {
  return ::google::protobuf::internal::NameOfDenseEnum<MathOperation_descriptor,
                                                 0, 3>(
      static_cast<int>(value));
}
inline bool MathOperation_Parse(absl::string_view name, MathOperation* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MathOperation>(
      MathOperation_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class MathResponse final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:xrpc.math.MathResponse) */ {
 public:
  inline MathResponse() : MathResponse(nullptr) {}
  ~MathResponse() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR MathResponse(::google::protobuf::internal::ConstantInitialized);

  inline MathResponse(const MathResponse& from)
      : MathResponse(nullptr, from) {}
  MathResponse(MathResponse&& from) noexcept
    : MathResponse() {
    *this = ::std::move(from);
  }

  inline MathResponse& operator=(const MathResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline MathResponse& operator=(MathResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MathResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const MathResponse* internal_default_instance() {
    return reinterpret_cast<const MathResponse*>(
               &_MathResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(MathResponse& a, MathResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(MathResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MathResponse* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MathResponse* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MathResponse>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const MathResponse& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const MathResponse& from) {
    MathResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(MathResponse* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "xrpc.math.MathResponse";
  }
  protected:
  explicit MathResponse(::google::protobuf::Arena* arena);
  MathResponse(::google::protobuf::Arena* arena, const MathResponse& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResultFieldNumber = 1,
  };
  // optional float result = 1;
  bool has_result() const;
  void clear_result() ;
  float result() const;
  void set_result(float value);

  private:
  float _internal_result() const;
  void _internal_set_result(float value);

  public:
  // @@protoc_insertion_point(class_scope:xrpc.math.MathResponse)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    float result_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_src_2fproto_2fmath_2eproto;
};// -------------------------------------------------------------------

class Arguments final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:xrpc.math.Arguments) */ {
 public:
  inline Arguments() : Arguments(nullptr) {}
  ~Arguments() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Arguments(::google::protobuf::internal::ConstantInitialized);

  inline Arguments(const Arguments& from)
      : Arguments(nullptr, from) {}
  Arguments(Arguments&& from) noexcept
    : Arguments() {
    *this = ::std::move(from);
  }

  inline Arguments& operator=(const Arguments& from) {
    CopyFrom(from);
    return *this;
  }
  inline Arguments& operator=(Arguments&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Arguments& default_instance() {
    return *internal_default_instance();
  }
  static inline const Arguments* internal_default_instance() {
    return reinterpret_cast<const Arguments*>(
               &_Arguments_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Arguments& a, Arguments& b) {
    a.Swap(&b);
  }
  inline void Swap(Arguments* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Arguments* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Arguments* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Arguments>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Arguments& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Arguments& from) {
    Arguments::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Arguments* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "xrpc.math.Arguments";
  }
  protected:
  explicit Arguments(::google::protobuf::Arena* arena);
  Arguments(::google::protobuf::Arena* arena, const Arguments& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLhsFieldNumber = 1,
    kRhsFieldNumber = 2,
  };
  // float lhs = 1;
  void clear_lhs() ;
  float lhs() const;
  void set_lhs(float value);

  private:
  float _internal_lhs() const;
  void _internal_set_lhs(float value);

  public:
  // float rhs = 2;
  void clear_rhs() ;
  float rhs() const;
  void set_rhs(float value);

  private:
  float _internal_rhs() const;
  void _internal_set_rhs(float value);

  public:
  // @@protoc_insertion_point(class_scope:xrpc.math.Arguments)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    float lhs_;
    float rhs_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_src_2fproto_2fmath_2eproto;
};// -------------------------------------------------------------------

class MathRequest final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:xrpc.math.MathRequest) */ {
 public:
  inline MathRequest() : MathRequest(nullptr) {}
  ~MathRequest() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR MathRequest(::google::protobuf::internal::ConstantInitialized);

  inline MathRequest(const MathRequest& from)
      : MathRequest(nullptr, from) {}
  MathRequest(MathRequest&& from) noexcept
    : MathRequest() {
    *this = ::std::move(from);
  }

  inline MathRequest& operator=(const MathRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline MathRequest& operator=(MathRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MathRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const MathRequest* internal_default_instance() {
    return reinterpret_cast<const MathRequest*>(
               &_MathRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(MathRequest& a, MathRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(MathRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MathRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MathRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MathRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const MathRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const MathRequest& from) {
    MathRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(MathRequest* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "xrpc.math.MathRequest";
  }
  protected:
  explicit MathRequest(::google::protobuf::Arena* arena);
  MathRequest(::google::protobuf::Arena* arena, const MathRequest& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kArgumentsFieldNumber = 1,
    kOperationFieldNumber = 2,
  };
  // .xrpc.math.Arguments arguments = 1;
  bool has_arguments() const;
  void clear_arguments() ;
  const ::xrpc::math::Arguments& arguments() const;
  PROTOBUF_NODISCARD ::xrpc::math::Arguments* release_arguments();
  ::xrpc::math::Arguments* mutable_arguments();
  void set_allocated_arguments(::xrpc::math::Arguments* value);
  void unsafe_arena_set_allocated_arguments(::xrpc::math::Arguments* value);
  ::xrpc::math::Arguments* unsafe_arena_release_arguments();

  private:
  const ::xrpc::math::Arguments& _internal_arguments() const;
  ::xrpc::math::Arguments* _internal_mutable_arguments();

  public:
  // .xrpc.math.MathOperation operation = 2;
  void clear_operation() ;
  ::xrpc::math::MathOperation operation() const;
  void set_operation(::xrpc::math::MathOperation value);

  private:
  ::xrpc::math::MathOperation _internal_operation() const;
  void _internal_set_operation(::xrpc::math::MathOperation value);

  public:
  // @@protoc_insertion_point(class_scope:xrpc.math.MathRequest)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 1,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::xrpc::math::Arguments* arguments_;
    int operation_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_src_2fproto_2fmath_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Arguments

// float lhs = 1;
inline void Arguments::clear_lhs() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.lhs_ = 0;
}
inline float Arguments::lhs() const {
  // @@protoc_insertion_point(field_get:xrpc.math.Arguments.lhs)
  return _internal_lhs();
}
inline void Arguments::set_lhs(float value) {
  _internal_set_lhs(value);
  // @@protoc_insertion_point(field_set:xrpc.math.Arguments.lhs)
}
inline float Arguments::_internal_lhs() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.lhs_;
}
inline void Arguments::_internal_set_lhs(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.lhs_ = value;
}

// float rhs = 2;
inline void Arguments::clear_rhs() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.rhs_ = 0;
}
inline float Arguments::rhs() const {
  // @@protoc_insertion_point(field_get:xrpc.math.Arguments.rhs)
  return _internal_rhs();
}
inline void Arguments::set_rhs(float value) {
  _internal_set_rhs(value);
  // @@protoc_insertion_point(field_set:xrpc.math.Arguments.rhs)
}
inline float Arguments::_internal_rhs() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.rhs_;
}
inline void Arguments::_internal_set_rhs(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.rhs_ = value;
}

// -------------------------------------------------------------------

// MathRequest

// .xrpc.math.Arguments arguments = 1;
inline bool MathRequest::has_arguments() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.arguments_ != nullptr);
  return value;
}
inline void MathRequest::clear_arguments() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.arguments_ != nullptr) _impl_.arguments_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const ::xrpc::math::Arguments& MathRequest::_internal_arguments() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::xrpc::math::Arguments* p = _impl_.arguments_;
  return p != nullptr ? *p : reinterpret_cast<const ::xrpc::math::Arguments&>(::xrpc::math::_Arguments_default_instance_);
}
inline const ::xrpc::math::Arguments& MathRequest::arguments() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:xrpc.math.MathRequest.arguments)
  return _internal_arguments();
}
inline void MathRequest::unsafe_arena_set_allocated_arguments(::xrpc::math::Arguments* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.arguments_);
  }
  _impl_.arguments_ = reinterpret_cast<::xrpc::math::Arguments*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:xrpc.math.MathRequest.arguments)
}
inline ::xrpc::math::Arguments* MathRequest::release_arguments() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::xrpc::math::Arguments* released = _impl_.arguments_;
  _impl_.arguments_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::xrpc::math::Arguments* MathRequest::unsafe_arena_release_arguments() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:xrpc.math.MathRequest.arguments)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::xrpc::math::Arguments* temp = _impl_.arguments_;
  _impl_.arguments_ = nullptr;
  return temp;
}
inline ::xrpc::math::Arguments* MathRequest::_internal_mutable_arguments() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.arguments_ == nullptr) {
    auto* p = CreateMaybeMessage<::xrpc::math::Arguments>(GetArena());
    _impl_.arguments_ = reinterpret_cast<::xrpc::math::Arguments*>(p);
  }
  return _impl_.arguments_;
}
inline ::xrpc::math::Arguments* MathRequest::mutable_arguments() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::xrpc::math::Arguments* _msg = _internal_mutable_arguments();
  // @@protoc_insertion_point(field_mutable:xrpc.math.MathRequest.arguments)
  return _msg;
}
inline void MathRequest::set_allocated_arguments(::xrpc::math::Arguments* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::xrpc::math::Arguments*>(_impl_.arguments_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::xrpc::math::Arguments*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.arguments_ = reinterpret_cast<::xrpc::math::Arguments*>(value);
  // @@protoc_insertion_point(field_set_allocated:xrpc.math.MathRequest.arguments)
}

// .xrpc.math.MathOperation operation = 2;
inline void MathRequest::clear_operation() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.operation_ = 0;
}
inline ::xrpc::math::MathOperation MathRequest::operation() const {
  // @@protoc_insertion_point(field_get:xrpc.math.MathRequest.operation)
  return _internal_operation();
}
inline void MathRequest::set_operation(::xrpc::math::MathOperation value) {
  _internal_set_operation(value);
  // @@protoc_insertion_point(field_set:xrpc.math.MathRequest.operation)
}
inline ::xrpc::math::MathOperation MathRequest::_internal_operation() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::xrpc::math::MathOperation>(_impl_.operation_);
}
inline void MathRequest::_internal_set_operation(::xrpc::math::MathOperation value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.operation_ = value;
}

// -------------------------------------------------------------------

// MathResponse

// optional float result = 1;
inline bool MathResponse::has_result() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void MathResponse::clear_result() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.result_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline float MathResponse::result() const {
  // @@protoc_insertion_point(field_get:xrpc.math.MathResponse.result)
  return _internal_result();
}
inline void MathResponse::set_result(float value) {
  _internal_set_result(value);
  // @@protoc_insertion_point(field_set:xrpc.math.MathResponse.result)
}
inline float MathResponse::_internal_result() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.result_;
}
inline void MathResponse::_internal_set_result(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.result_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace math
}  // namespace xrpc


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::xrpc::math::MathOperation> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::xrpc::math::MathOperation>() {
  return ::xrpc::math::MathOperation_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_src_2fproto_2fmath_2eproto_2epb_2eh