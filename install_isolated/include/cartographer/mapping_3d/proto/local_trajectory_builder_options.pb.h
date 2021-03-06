// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cartographer/mapping_3d/proto/local_trajectory_builder_options.proto

#ifndef PROTOBUF_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto__INCLUDED
#define PROTOBUF_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "cartographer/mapping_3d/proto/motion_filter_options.pb.h"
#include "cartographer/sensor/proto/adaptive_voxel_filter_options.pb.h"
#include "cartographer/mapping_2d/scan_matching/proto/real_time_correlative_scan_matcher_options.pb.h"
#include "cartographer/mapping_3d/proto/submaps_options.pb.h"
#include "cartographer/mapping_3d/scan_matching/proto/ceres_scan_matcher_options.pb.h"
// @@protoc_insertion_point(includes)

namespace cartographer {
namespace mapping_3d {
namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();
void protobuf_AssignDesc_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();
void protobuf_ShutdownFile_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();

class LocalTrajectoryBuilderOptions;

// ===================================================================

class LocalTrajectoryBuilderOptions : public ::google::protobuf::Message {
 public:
  LocalTrajectoryBuilderOptions();
  virtual ~LocalTrajectoryBuilderOptions();

  LocalTrajectoryBuilderOptions(const LocalTrajectoryBuilderOptions& from);

  inline LocalTrajectoryBuilderOptions& operator=(const LocalTrajectoryBuilderOptions& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LocalTrajectoryBuilderOptions& default_instance();

  void Swap(LocalTrajectoryBuilderOptions* other);

  // implements Message ----------------------------------------------

  LocalTrajectoryBuilderOptions* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LocalTrajectoryBuilderOptions& from);
  void MergeFrom(const LocalTrajectoryBuilderOptions& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional float min_range = 1;
  inline bool has_min_range() const;
  inline void clear_min_range();
  static const int kMinRangeFieldNumber = 1;
  inline float min_range() const;
  inline void set_min_range(float value);

  // optional float max_range = 2;
  inline bool has_max_range() const;
  inline void clear_max_range();
  static const int kMaxRangeFieldNumber = 2;
  inline float max_range() const;
  inline void set_max_range(float value);

  // optional int32 scans_per_accumulation = 3;
  inline bool has_scans_per_accumulation() const;
  inline void clear_scans_per_accumulation();
  static const int kScansPerAccumulationFieldNumber = 3;
  inline ::google::protobuf::int32 scans_per_accumulation() const;
  inline void set_scans_per_accumulation(::google::protobuf::int32 value);

  // optional float voxel_filter_size = 4;
  inline bool has_voxel_filter_size() const;
  inline void clear_voxel_filter_size();
  static const int kVoxelFilterSizeFieldNumber = 4;
  inline float voxel_filter_size() const;
  inline void set_voxel_filter_size(float value);

  // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions high_resolution_adaptive_voxel_filter_options = 5;
  inline bool has_high_resolution_adaptive_voxel_filter_options() const;
  inline void clear_high_resolution_adaptive_voxel_filter_options();
  static const int kHighResolutionAdaptiveVoxelFilterOptionsFieldNumber = 5;
  inline const ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions& high_resolution_adaptive_voxel_filter_options() const;
  inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* mutable_high_resolution_adaptive_voxel_filter_options();
  inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* release_high_resolution_adaptive_voxel_filter_options();
  inline void set_allocated_high_resolution_adaptive_voxel_filter_options(::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* high_resolution_adaptive_voxel_filter_options);

  // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions low_resolution_adaptive_voxel_filter_options = 12;
  inline bool has_low_resolution_adaptive_voxel_filter_options() const;
  inline void clear_low_resolution_adaptive_voxel_filter_options();
  static const int kLowResolutionAdaptiveVoxelFilterOptionsFieldNumber = 12;
  inline const ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions& low_resolution_adaptive_voxel_filter_options() const;
  inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* mutable_low_resolution_adaptive_voxel_filter_options();
  inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* release_low_resolution_adaptive_voxel_filter_options();
  inline void set_allocated_low_resolution_adaptive_voxel_filter_options(::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* low_resolution_adaptive_voxel_filter_options);

  // optional bool use_online_correlative_scan_matching = 13;
  inline bool has_use_online_correlative_scan_matching() const;
  inline void clear_use_online_correlative_scan_matching();
  static const int kUseOnlineCorrelativeScanMatchingFieldNumber = 13;
  inline bool use_online_correlative_scan_matching() const;
  inline void set_use_online_correlative_scan_matching(bool value);

  // optional .cartographer.mapping_2d.scan_matching.proto.RealTimeCorrelativeScanMatcherOptions real_time_correlative_scan_matcher_options = 14;
  inline bool has_real_time_correlative_scan_matcher_options() const;
  inline void clear_real_time_correlative_scan_matcher_options();
  static const int kRealTimeCorrelativeScanMatcherOptionsFieldNumber = 14;
  inline const ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions& real_time_correlative_scan_matcher_options() const;
  inline ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* mutable_real_time_correlative_scan_matcher_options();
  inline ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* release_real_time_correlative_scan_matcher_options();
  inline void set_allocated_real_time_correlative_scan_matcher_options(::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* real_time_correlative_scan_matcher_options);

  // optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 6;
  inline bool has_ceres_scan_matcher_options() const;
  inline void clear_ceres_scan_matcher_options();
  static const int kCeresScanMatcherOptionsFieldNumber = 6;
  inline const ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions& ceres_scan_matcher_options() const;
  inline ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* mutable_ceres_scan_matcher_options();
  inline ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* release_ceres_scan_matcher_options();
  inline void set_allocated_ceres_scan_matcher_options(::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* ceres_scan_matcher_options);

  // optional .cartographer.mapping_3d.proto.MotionFilterOptions motion_filter_options = 7;
  inline bool has_motion_filter_options() const;
  inline void clear_motion_filter_options();
  static const int kMotionFilterOptionsFieldNumber = 7;
  inline const ::cartographer::mapping_3d::proto::MotionFilterOptions& motion_filter_options() const;
  inline ::cartographer::mapping_3d::proto::MotionFilterOptions* mutable_motion_filter_options();
  inline ::cartographer::mapping_3d::proto::MotionFilterOptions* release_motion_filter_options();
  inline void set_allocated_motion_filter_options(::cartographer::mapping_3d::proto::MotionFilterOptions* motion_filter_options);

  // optional double imu_gravity_time_constant = 15;
  inline bool has_imu_gravity_time_constant() const;
  inline void clear_imu_gravity_time_constant();
  static const int kImuGravityTimeConstantFieldNumber = 15;
  inline double imu_gravity_time_constant() const;
  inline void set_imu_gravity_time_constant(double value);

  // optional int32 rotational_histogram_size = 17;
  inline bool has_rotational_histogram_size() const;
  inline void clear_rotational_histogram_size();
  static const int kRotationalHistogramSizeFieldNumber = 17;
  inline ::google::protobuf::int32 rotational_histogram_size() const;
  inline void set_rotational_histogram_size(::google::protobuf::int32 value);

  // optional .cartographer.mapping_3d.proto.SubmapsOptions submaps_options = 8;
  inline bool has_submaps_options() const;
  inline void clear_submaps_options();
  static const int kSubmapsOptionsFieldNumber = 8;
  inline const ::cartographer::mapping_3d::proto::SubmapsOptions& submaps_options() const;
  inline ::cartographer::mapping_3d::proto::SubmapsOptions* mutable_submaps_options();
  inline ::cartographer::mapping_3d::proto::SubmapsOptions* release_submaps_options();
  inline void set_allocated_submaps_options(::cartographer::mapping_3d::proto::SubmapsOptions* submaps_options);

  // @@protoc_insertion_point(class_scope:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions)
 private:
  inline void set_has_min_range();
  inline void clear_has_min_range();
  inline void set_has_max_range();
  inline void clear_has_max_range();
  inline void set_has_scans_per_accumulation();
  inline void clear_has_scans_per_accumulation();
  inline void set_has_voxel_filter_size();
  inline void clear_has_voxel_filter_size();
  inline void set_has_high_resolution_adaptive_voxel_filter_options();
  inline void clear_has_high_resolution_adaptive_voxel_filter_options();
  inline void set_has_low_resolution_adaptive_voxel_filter_options();
  inline void clear_has_low_resolution_adaptive_voxel_filter_options();
  inline void set_has_use_online_correlative_scan_matching();
  inline void clear_has_use_online_correlative_scan_matching();
  inline void set_has_real_time_correlative_scan_matcher_options();
  inline void clear_has_real_time_correlative_scan_matcher_options();
  inline void set_has_ceres_scan_matcher_options();
  inline void clear_has_ceres_scan_matcher_options();
  inline void set_has_motion_filter_options();
  inline void clear_has_motion_filter_options();
  inline void set_has_imu_gravity_time_constant();
  inline void clear_has_imu_gravity_time_constant();
  inline void set_has_rotational_histogram_size();
  inline void clear_has_rotational_histogram_size();
  inline void set_has_submaps_options();
  inline void clear_has_submaps_options();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  float min_range_;
  float max_range_;
  ::google::protobuf::int32 scans_per_accumulation_;
  float voxel_filter_size_;
  ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* high_resolution_adaptive_voxel_filter_options_;
  ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* low_resolution_adaptive_voxel_filter_options_;
  ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* real_time_correlative_scan_matcher_options_;
  ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* ceres_scan_matcher_options_;
  bool use_online_correlative_scan_matching_;
  ::google::protobuf::int32 rotational_histogram_size_;
  ::cartographer::mapping_3d::proto::MotionFilterOptions* motion_filter_options_;
  double imu_gravity_time_constant_;
  ::cartographer::mapping_3d::proto::SubmapsOptions* submaps_options_;
  friend void  protobuf_AddDesc_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();
  friend void protobuf_AssignDesc_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();
  friend void protobuf_ShutdownFile_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto();

  void InitAsDefaultInstance();
  static LocalTrajectoryBuilderOptions* default_instance_;
};
// ===================================================================


// ===================================================================

// LocalTrajectoryBuilderOptions

// optional float min_range = 1;
inline bool LocalTrajectoryBuilderOptions::has_min_range() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_min_range() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_min_range() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LocalTrajectoryBuilderOptions::clear_min_range() {
  min_range_ = 0;
  clear_has_min_range();
}
inline float LocalTrajectoryBuilderOptions::min_range() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.min_range)
  return min_range_;
}
inline void LocalTrajectoryBuilderOptions::set_min_range(float value) {
  set_has_min_range();
  min_range_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.min_range)
}

// optional float max_range = 2;
inline bool LocalTrajectoryBuilderOptions::has_max_range() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_max_range() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_max_range() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LocalTrajectoryBuilderOptions::clear_max_range() {
  max_range_ = 0;
  clear_has_max_range();
}
inline float LocalTrajectoryBuilderOptions::max_range() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.max_range)
  return max_range_;
}
inline void LocalTrajectoryBuilderOptions::set_max_range(float value) {
  set_has_max_range();
  max_range_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.max_range)
}

// optional int32 scans_per_accumulation = 3;
inline bool LocalTrajectoryBuilderOptions::has_scans_per_accumulation() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_scans_per_accumulation() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_scans_per_accumulation() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LocalTrajectoryBuilderOptions::clear_scans_per_accumulation() {
  scans_per_accumulation_ = 0;
  clear_has_scans_per_accumulation();
}
inline ::google::protobuf::int32 LocalTrajectoryBuilderOptions::scans_per_accumulation() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.scans_per_accumulation)
  return scans_per_accumulation_;
}
inline void LocalTrajectoryBuilderOptions::set_scans_per_accumulation(::google::protobuf::int32 value) {
  set_has_scans_per_accumulation();
  scans_per_accumulation_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.scans_per_accumulation)
}

// optional float voxel_filter_size = 4;
inline bool LocalTrajectoryBuilderOptions::has_voxel_filter_size() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_voxel_filter_size() {
  _has_bits_[0] |= 0x00000008u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_voxel_filter_size() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void LocalTrajectoryBuilderOptions::clear_voxel_filter_size() {
  voxel_filter_size_ = 0;
  clear_has_voxel_filter_size();
}
inline float LocalTrajectoryBuilderOptions::voxel_filter_size() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.voxel_filter_size)
  return voxel_filter_size_;
}
inline void LocalTrajectoryBuilderOptions::set_voxel_filter_size(float value) {
  set_has_voxel_filter_size();
  voxel_filter_size_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.voxel_filter_size)
}

// optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions high_resolution_adaptive_voxel_filter_options = 5;
inline bool LocalTrajectoryBuilderOptions::has_high_resolution_adaptive_voxel_filter_options() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_high_resolution_adaptive_voxel_filter_options() {
  _has_bits_[0] |= 0x00000010u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_high_resolution_adaptive_voxel_filter_options() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void LocalTrajectoryBuilderOptions::clear_high_resolution_adaptive_voxel_filter_options() {
  if (high_resolution_adaptive_voxel_filter_options_ != NULL) high_resolution_adaptive_voxel_filter_options_->::cartographer::sensor::proto::AdaptiveVoxelFilterOptions::Clear();
  clear_has_high_resolution_adaptive_voxel_filter_options();
}
inline const ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions& LocalTrajectoryBuilderOptions::high_resolution_adaptive_voxel_filter_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.high_resolution_adaptive_voxel_filter_options)
  return high_resolution_adaptive_voxel_filter_options_ != NULL ? *high_resolution_adaptive_voxel_filter_options_ : *default_instance_->high_resolution_adaptive_voxel_filter_options_;
}
inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* LocalTrajectoryBuilderOptions::mutable_high_resolution_adaptive_voxel_filter_options() {
  set_has_high_resolution_adaptive_voxel_filter_options();
  if (high_resolution_adaptive_voxel_filter_options_ == NULL) high_resolution_adaptive_voxel_filter_options_ = new ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.high_resolution_adaptive_voxel_filter_options)
  return high_resolution_adaptive_voxel_filter_options_;
}
inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* LocalTrajectoryBuilderOptions::release_high_resolution_adaptive_voxel_filter_options() {
  clear_has_high_resolution_adaptive_voxel_filter_options();
  ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* temp = high_resolution_adaptive_voxel_filter_options_;
  high_resolution_adaptive_voxel_filter_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_high_resolution_adaptive_voxel_filter_options(::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* high_resolution_adaptive_voxel_filter_options) {
  delete high_resolution_adaptive_voxel_filter_options_;
  high_resolution_adaptive_voxel_filter_options_ = high_resolution_adaptive_voxel_filter_options;
  if (high_resolution_adaptive_voxel_filter_options) {
    set_has_high_resolution_adaptive_voxel_filter_options();
  } else {
    clear_has_high_resolution_adaptive_voxel_filter_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.high_resolution_adaptive_voxel_filter_options)
}

// optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions low_resolution_adaptive_voxel_filter_options = 12;
inline bool LocalTrajectoryBuilderOptions::has_low_resolution_adaptive_voxel_filter_options() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_low_resolution_adaptive_voxel_filter_options() {
  _has_bits_[0] |= 0x00000020u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_low_resolution_adaptive_voxel_filter_options() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void LocalTrajectoryBuilderOptions::clear_low_resolution_adaptive_voxel_filter_options() {
  if (low_resolution_adaptive_voxel_filter_options_ != NULL) low_resolution_adaptive_voxel_filter_options_->::cartographer::sensor::proto::AdaptiveVoxelFilterOptions::Clear();
  clear_has_low_resolution_adaptive_voxel_filter_options();
}
inline const ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions& LocalTrajectoryBuilderOptions::low_resolution_adaptive_voxel_filter_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.low_resolution_adaptive_voxel_filter_options)
  return low_resolution_adaptive_voxel_filter_options_ != NULL ? *low_resolution_adaptive_voxel_filter_options_ : *default_instance_->low_resolution_adaptive_voxel_filter_options_;
}
inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* LocalTrajectoryBuilderOptions::mutable_low_resolution_adaptive_voxel_filter_options() {
  set_has_low_resolution_adaptive_voxel_filter_options();
  if (low_resolution_adaptive_voxel_filter_options_ == NULL) low_resolution_adaptive_voxel_filter_options_ = new ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.low_resolution_adaptive_voxel_filter_options)
  return low_resolution_adaptive_voxel_filter_options_;
}
inline ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* LocalTrajectoryBuilderOptions::release_low_resolution_adaptive_voxel_filter_options() {
  clear_has_low_resolution_adaptive_voxel_filter_options();
  ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* temp = low_resolution_adaptive_voxel_filter_options_;
  low_resolution_adaptive_voxel_filter_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_low_resolution_adaptive_voxel_filter_options(::cartographer::sensor::proto::AdaptiveVoxelFilterOptions* low_resolution_adaptive_voxel_filter_options) {
  delete low_resolution_adaptive_voxel_filter_options_;
  low_resolution_adaptive_voxel_filter_options_ = low_resolution_adaptive_voxel_filter_options;
  if (low_resolution_adaptive_voxel_filter_options) {
    set_has_low_resolution_adaptive_voxel_filter_options();
  } else {
    clear_has_low_resolution_adaptive_voxel_filter_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.low_resolution_adaptive_voxel_filter_options)
}

// optional bool use_online_correlative_scan_matching = 13;
inline bool LocalTrajectoryBuilderOptions::has_use_online_correlative_scan_matching() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_use_online_correlative_scan_matching() {
  _has_bits_[0] |= 0x00000040u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_use_online_correlative_scan_matching() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void LocalTrajectoryBuilderOptions::clear_use_online_correlative_scan_matching() {
  use_online_correlative_scan_matching_ = false;
  clear_has_use_online_correlative_scan_matching();
}
inline bool LocalTrajectoryBuilderOptions::use_online_correlative_scan_matching() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.use_online_correlative_scan_matching)
  return use_online_correlative_scan_matching_;
}
inline void LocalTrajectoryBuilderOptions::set_use_online_correlative_scan_matching(bool value) {
  set_has_use_online_correlative_scan_matching();
  use_online_correlative_scan_matching_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.use_online_correlative_scan_matching)
}

// optional .cartographer.mapping_2d.scan_matching.proto.RealTimeCorrelativeScanMatcherOptions real_time_correlative_scan_matcher_options = 14;
inline bool LocalTrajectoryBuilderOptions::has_real_time_correlative_scan_matcher_options() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_real_time_correlative_scan_matcher_options() {
  _has_bits_[0] |= 0x00000080u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_real_time_correlative_scan_matcher_options() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void LocalTrajectoryBuilderOptions::clear_real_time_correlative_scan_matcher_options() {
  if (real_time_correlative_scan_matcher_options_ != NULL) real_time_correlative_scan_matcher_options_->::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions::Clear();
  clear_has_real_time_correlative_scan_matcher_options();
}
inline const ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions& LocalTrajectoryBuilderOptions::real_time_correlative_scan_matcher_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.real_time_correlative_scan_matcher_options)
  return real_time_correlative_scan_matcher_options_ != NULL ? *real_time_correlative_scan_matcher_options_ : *default_instance_->real_time_correlative_scan_matcher_options_;
}
inline ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* LocalTrajectoryBuilderOptions::mutable_real_time_correlative_scan_matcher_options() {
  set_has_real_time_correlative_scan_matcher_options();
  if (real_time_correlative_scan_matcher_options_ == NULL) real_time_correlative_scan_matcher_options_ = new ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.real_time_correlative_scan_matcher_options)
  return real_time_correlative_scan_matcher_options_;
}
inline ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* LocalTrajectoryBuilderOptions::release_real_time_correlative_scan_matcher_options() {
  clear_has_real_time_correlative_scan_matcher_options();
  ::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* temp = real_time_correlative_scan_matcher_options_;
  real_time_correlative_scan_matcher_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_real_time_correlative_scan_matcher_options(::cartographer::mapping_2d::scan_matching::proto::RealTimeCorrelativeScanMatcherOptions* real_time_correlative_scan_matcher_options) {
  delete real_time_correlative_scan_matcher_options_;
  real_time_correlative_scan_matcher_options_ = real_time_correlative_scan_matcher_options;
  if (real_time_correlative_scan_matcher_options) {
    set_has_real_time_correlative_scan_matcher_options();
  } else {
    clear_has_real_time_correlative_scan_matcher_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.real_time_correlative_scan_matcher_options)
}

// optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 6;
inline bool LocalTrajectoryBuilderOptions::has_ceres_scan_matcher_options() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_ceres_scan_matcher_options() {
  _has_bits_[0] |= 0x00000100u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_ceres_scan_matcher_options() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void LocalTrajectoryBuilderOptions::clear_ceres_scan_matcher_options() {
  if (ceres_scan_matcher_options_ != NULL) ceres_scan_matcher_options_->::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions::Clear();
  clear_has_ceres_scan_matcher_options();
}
inline const ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions& LocalTrajectoryBuilderOptions::ceres_scan_matcher_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.ceres_scan_matcher_options)
  return ceres_scan_matcher_options_ != NULL ? *ceres_scan_matcher_options_ : *default_instance_->ceres_scan_matcher_options_;
}
inline ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* LocalTrajectoryBuilderOptions::mutable_ceres_scan_matcher_options() {
  set_has_ceres_scan_matcher_options();
  if (ceres_scan_matcher_options_ == NULL) ceres_scan_matcher_options_ = new ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.ceres_scan_matcher_options)
  return ceres_scan_matcher_options_;
}
inline ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* LocalTrajectoryBuilderOptions::release_ceres_scan_matcher_options() {
  clear_has_ceres_scan_matcher_options();
  ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* temp = ceres_scan_matcher_options_;
  ceres_scan_matcher_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_ceres_scan_matcher_options(::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions* ceres_scan_matcher_options) {
  delete ceres_scan_matcher_options_;
  ceres_scan_matcher_options_ = ceres_scan_matcher_options;
  if (ceres_scan_matcher_options) {
    set_has_ceres_scan_matcher_options();
  } else {
    clear_has_ceres_scan_matcher_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.ceres_scan_matcher_options)
}

// optional .cartographer.mapping_3d.proto.MotionFilterOptions motion_filter_options = 7;
inline bool LocalTrajectoryBuilderOptions::has_motion_filter_options() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_motion_filter_options() {
  _has_bits_[0] |= 0x00000200u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_motion_filter_options() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void LocalTrajectoryBuilderOptions::clear_motion_filter_options() {
  if (motion_filter_options_ != NULL) motion_filter_options_->::cartographer::mapping_3d::proto::MotionFilterOptions::Clear();
  clear_has_motion_filter_options();
}
inline const ::cartographer::mapping_3d::proto::MotionFilterOptions& LocalTrajectoryBuilderOptions::motion_filter_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.motion_filter_options)
  return motion_filter_options_ != NULL ? *motion_filter_options_ : *default_instance_->motion_filter_options_;
}
inline ::cartographer::mapping_3d::proto::MotionFilterOptions* LocalTrajectoryBuilderOptions::mutable_motion_filter_options() {
  set_has_motion_filter_options();
  if (motion_filter_options_ == NULL) motion_filter_options_ = new ::cartographer::mapping_3d::proto::MotionFilterOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.motion_filter_options)
  return motion_filter_options_;
}
inline ::cartographer::mapping_3d::proto::MotionFilterOptions* LocalTrajectoryBuilderOptions::release_motion_filter_options() {
  clear_has_motion_filter_options();
  ::cartographer::mapping_3d::proto::MotionFilterOptions* temp = motion_filter_options_;
  motion_filter_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_motion_filter_options(::cartographer::mapping_3d::proto::MotionFilterOptions* motion_filter_options) {
  delete motion_filter_options_;
  motion_filter_options_ = motion_filter_options;
  if (motion_filter_options) {
    set_has_motion_filter_options();
  } else {
    clear_has_motion_filter_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.motion_filter_options)
}

// optional double imu_gravity_time_constant = 15;
inline bool LocalTrajectoryBuilderOptions::has_imu_gravity_time_constant() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_imu_gravity_time_constant() {
  _has_bits_[0] |= 0x00000400u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_imu_gravity_time_constant() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void LocalTrajectoryBuilderOptions::clear_imu_gravity_time_constant() {
  imu_gravity_time_constant_ = 0;
  clear_has_imu_gravity_time_constant();
}
inline double LocalTrajectoryBuilderOptions::imu_gravity_time_constant() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.imu_gravity_time_constant)
  return imu_gravity_time_constant_;
}
inline void LocalTrajectoryBuilderOptions::set_imu_gravity_time_constant(double value) {
  set_has_imu_gravity_time_constant();
  imu_gravity_time_constant_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.imu_gravity_time_constant)
}

// optional int32 rotational_histogram_size = 17;
inline bool LocalTrajectoryBuilderOptions::has_rotational_histogram_size() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_rotational_histogram_size() {
  _has_bits_[0] |= 0x00000800u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_rotational_histogram_size() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void LocalTrajectoryBuilderOptions::clear_rotational_histogram_size() {
  rotational_histogram_size_ = 0;
  clear_has_rotational_histogram_size();
}
inline ::google::protobuf::int32 LocalTrajectoryBuilderOptions::rotational_histogram_size() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.rotational_histogram_size)
  return rotational_histogram_size_;
}
inline void LocalTrajectoryBuilderOptions::set_rotational_histogram_size(::google::protobuf::int32 value) {
  set_has_rotational_histogram_size();
  rotational_histogram_size_ = value;
  // @@protoc_insertion_point(field_set:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.rotational_histogram_size)
}

// optional .cartographer.mapping_3d.proto.SubmapsOptions submaps_options = 8;
inline bool LocalTrajectoryBuilderOptions::has_submaps_options() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void LocalTrajectoryBuilderOptions::set_has_submaps_options() {
  _has_bits_[0] |= 0x00001000u;
}
inline void LocalTrajectoryBuilderOptions::clear_has_submaps_options() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void LocalTrajectoryBuilderOptions::clear_submaps_options() {
  if (submaps_options_ != NULL) submaps_options_->::cartographer::mapping_3d::proto::SubmapsOptions::Clear();
  clear_has_submaps_options();
}
inline const ::cartographer::mapping_3d::proto::SubmapsOptions& LocalTrajectoryBuilderOptions::submaps_options() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.submaps_options)
  return submaps_options_ != NULL ? *submaps_options_ : *default_instance_->submaps_options_;
}
inline ::cartographer::mapping_3d::proto::SubmapsOptions* LocalTrajectoryBuilderOptions::mutable_submaps_options() {
  set_has_submaps_options();
  if (submaps_options_ == NULL) submaps_options_ = new ::cartographer::mapping_3d::proto::SubmapsOptions;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.submaps_options)
  return submaps_options_;
}
inline ::cartographer::mapping_3d::proto::SubmapsOptions* LocalTrajectoryBuilderOptions::release_submaps_options() {
  clear_has_submaps_options();
  ::cartographer::mapping_3d::proto::SubmapsOptions* temp = submaps_options_;
  submaps_options_ = NULL;
  return temp;
}
inline void LocalTrajectoryBuilderOptions::set_allocated_submaps_options(::cartographer::mapping_3d::proto::SubmapsOptions* submaps_options) {
  delete submaps_options_;
  submaps_options_ = submaps_options;
  if (submaps_options) {
    set_has_submaps_options();
  } else {
    clear_has_submaps_options();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping_3d.proto.LocalTrajectoryBuilderOptions.submaps_options)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace mapping_3d
}  // namespace cartographer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cartographer_2fmapping_5f3d_2fproto_2flocal_5ftrajectory_5fbuilder_5foptions_2eproto__INCLUDED
