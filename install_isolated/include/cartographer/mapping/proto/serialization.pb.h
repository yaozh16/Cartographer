// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cartographer/mapping/proto/serialization.proto

#ifndef PROTOBUF_cartographer_2fmapping_2fproto_2fserialization_2eproto__INCLUDED
#define PROTOBUF_cartographer_2fmapping_2fproto_2fserialization_2eproto__INCLUDED

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
#include "cartographer/mapping/proto/sparse_pose_graph.pb.h"
#include "cartographer/mapping/proto/submap.pb.h"
#include "cartographer/mapping/proto/trajectory_node_data.pb.h"
// @@protoc_insertion_point(includes)

namespace cartographer {
namespace mapping {
namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
void protobuf_AssignDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
void protobuf_ShutdownFile_cartographer_2fmapping_2fproto_2fserialization_2eproto();

class Submap;
class Node;
class SerializedData;

// ===================================================================

class Submap : public ::google::protobuf::Message {
 public:
  Submap();
  virtual ~Submap();

  Submap(const Submap& from);

  inline Submap& operator=(const Submap& from) {
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
  static const Submap& default_instance();

  void Swap(Submap* other);

  // implements Message ----------------------------------------------

  Submap* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Submap& from);
  void MergeFrom(const Submap& from);
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

  // optional .cartographer.mapping.proto.SubmapId submap_id = 1;
  inline bool has_submap_id() const;
  inline void clear_submap_id();
  static const int kSubmapIdFieldNumber = 1;
  inline const ::cartographer::mapping::proto::SubmapId& submap_id() const;
  inline ::cartographer::mapping::proto::SubmapId* mutable_submap_id();
  inline ::cartographer::mapping::proto::SubmapId* release_submap_id();
  inline void set_allocated_submap_id(::cartographer::mapping::proto::SubmapId* submap_id);

  // optional .cartographer.mapping.proto.Submap2D submap_2d = 2;
  inline bool has_submap_2d() const;
  inline void clear_submap_2d();
  static const int kSubmap2DFieldNumber = 2;
  inline const ::cartographer::mapping::proto::Submap2D& submap_2d() const;
  inline ::cartographer::mapping::proto::Submap2D* mutable_submap_2d();
  inline ::cartographer::mapping::proto::Submap2D* release_submap_2d();
  inline void set_allocated_submap_2d(::cartographer::mapping::proto::Submap2D* submap_2d);

  // optional .cartographer.mapping.proto.Submap3D submap_3d = 3;
  inline bool has_submap_3d() const;
  inline void clear_submap_3d();
  static const int kSubmap3DFieldNumber = 3;
  inline const ::cartographer::mapping::proto::Submap3D& submap_3d() const;
  inline ::cartographer::mapping::proto::Submap3D* mutable_submap_3d();
  inline ::cartographer::mapping::proto::Submap3D* release_submap_3d();
  inline void set_allocated_submap_3d(::cartographer::mapping::proto::Submap3D* submap_3d);

  // @@protoc_insertion_point(class_scope:cartographer.mapping.proto.Submap)
 private:
  inline void set_has_submap_id();
  inline void clear_has_submap_id();
  inline void set_has_submap_2d();
  inline void clear_has_submap_2d();
  inline void set_has_submap_3d();
  inline void clear_has_submap_3d();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::cartographer::mapping::proto::SubmapId* submap_id_;
  ::cartographer::mapping::proto::Submap2D* submap_2d_;
  ::cartographer::mapping::proto::Submap3D* submap_3d_;
  friend void  protobuf_AddDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_AssignDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_ShutdownFile_cartographer_2fmapping_2fproto_2fserialization_2eproto();

  void InitAsDefaultInstance();
  static Submap* default_instance_;
};
// -------------------------------------------------------------------

class Node : public ::google::protobuf::Message {
 public:
  Node();
  virtual ~Node();

  Node(const Node& from);

  inline Node& operator=(const Node& from) {
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
  static const Node& default_instance();

  void Swap(Node* other);

  // implements Message ----------------------------------------------

  Node* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Node& from);
  void MergeFrom(const Node& from);
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

  // optional .cartographer.mapping.proto.NodeId node_id = 1;
  inline bool has_node_id() const;
  inline void clear_node_id();
  static const int kNodeIdFieldNumber = 1;
  inline const ::cartographer::mapping::proto::NodeId& node_id() const;
  inline ::cartographer::mapping::proto::NodeId* mutable_node_id();
  inline ::cartographer::mapping::proto::NodeId* release_node_id();
  inline void set_allocated_node_id(::cartographer::mapping::proto::NodeId* node_id);

  // optional .cartographer.mapping.proto.TrajectoryNodeData node_data = 5;
  inline bool has_node_data() const;
  inline void clear_node_data();
  static const int kNodeDataFieldNumber = 5;
  inline const ::cartographer::mapping::proto::TrajectoryNodeData& node_data() const;
  inline ::cartographer::mapping::proto::TrajectoryNodeData* mutable_node_data();
  inline ::cartographer::mapping::proto::TrajectoryNodeData* release_node_data();
  inline void set_allocated_node_data(::cartographer::mapping::proto::TrajectoryNodeData* node_data);

  // @@protoc_insertion_point(class_scope:cartographer.mapping.proto.Node)
 private:
  inline void set_has_node_id();
  inline void clear_has_node_id();
  inline void set_has_node_data();
  inline void clear_has_node_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::cartographer::mapping::proto::NodeId* node_id_;
  ::cartographer::mapping::proto::TrajectoryNodeData* node_data_;
  friend void  protobuf_AddDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_AssignDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_ShutdownFile_cartographer_2fmapping_2fproto_2fserialization_2eproto();

  void InitAsDefaultInstance();
  static Node* default_instance_;
};
// -------------------------------------------------------------------

class SerializedData : public ::google::protobuf::Message {
 public:
  SerializedData();
  virtual ~SerializedData();

  SerializedData(const SerializedData& from);

  inline SerializedData& operator=(const SerializedData& from) {
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
  static const SerializedData& default_instance();

  void Swap(SerializedData* other);

  // implements Message ----------------------------------------------

  SerializedData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SerializedData& from);
  void MergeFrom(const SerializedData& from);
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

  // optional .cartographer.mapping.proto.Submap submap = 1;
  inline bool has_submap() const;
  inline void clear_submap();
  static const int kSubmapFieldNumber = 1;
  inline const ::cartographer::mapping::proto::Submap& submap() const;
  inline ::cartographer::mapping::proto::Submap* mutable_submap();
  inline ::cartographer::mapping::proto::Submap* release_submap();
  inline void set_allocated_submap(::cartographer::mapping::proto::Submap* submap);

  // optional .cartographer.mapping.proto.Node node = 2;
  inline bool has_node() const;
  inline void clear_node();
  static const int kNodeFieldNumber = 2;
  inline const ::cartographer::mapping::proto::Node& node() const;
  inline ::cartographer::mapping::proto::Node* mutable_node();
  inline ::cartographer::mapping::proto::Node* release_node();
  inline void set_allocated_node(::cartographer::mapping::proto::Node* node);

  // @@protoc_insertion_point(class_scope:cartographer.mapping.proto.SerializedData)
 private:
  inline void set_has_submap();
  inline void clear_has_submap();
  inline void set_has_node();
  inline void clear_has_node();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::cartographer::mapping::proto::Submap* submap_;
  ::cartographer::mapping::proto::Node* node_;
  friend void  protobuf_AddDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_AssignDesc_cartographer_2fmapping_2fproto_2fserialization_2eproto();
  friend void protobuf_ShutdownFile_cartographer_2fmapping_2fproto_2fserialization_2eproto();

  void InitAsDefaultInstance();
  static SerializedData* default_instance_;
};
// ===================================================================


// ===================================================================

// Submap

// optional .cartographer.mapping.proto.SubmapId submap_id = 1;
inline bool Submap::has_submap_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Submap::set_has_submap_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Submap::clear_has_submap_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Submap::clear_submap_id() {
  if (submap_id_ != NULL) submap_id_->::cartographer::mapping::proto::SubmapId::Clear();
  clear_has_submap_id();
}
inline const ::cartographer::mapping::proto::SubmapId& Submap::submap_id() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.Submap.submap_id)
  return submap_id_ != NULL ? *submap_id_ : *default_instance_->submap_id_;
}
inline ::cartographer::mapping::proto::SubmapId* Submap::mutable_submap_id() {
  set_has_submap_id();
  if (submap_id_ == NULL) submap_id_ = new ::cartographer::mapping::proto::SubmapId;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.Submap.submap_id)
  return submap_id_;
}
inline ::cartographer::mapping::proto::SubmapId* Submap::release_submap_id() {
  clear_has_submap_id();
  ::cartographer::mapping::proto::SubmapId* temp = submap_id_;
  submap_id_ = NULL;
  return temp;
}
inline void Submap::set_allocated_submap_id(::cartographer::mapping::proto::SubmapId* submap_id) {
  delete submap_id_;
  submap_id_ = submap_id;
  if (submap_id) {
    set_has_submap_id();
  } else {
    clear_has_submap_id();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.Submap.submap_id)
}

// optional .cartographer.mapping.proto.Submap2D submap_2d = 2;
inline bool Submap::has_submap_2d() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Submap::set_has_submap_2d() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Submap::clear_has_submap_2d() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Submap::clear_submap_2d() {
  if (submap_2d_ != NULL) submap_2d_->::cartographer::mapping::proto::Submap2D::Clear();
  clear_has_submap_2d();
}
inline const ::cartographer::mapping::proto::Submap2D& Submap::submap_2d() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.Submap.submap_2d)
  return submap_2d_ != NULL ? *submap_2d_ : *default_instance_->submap_2d_;
}
inline ::cartographer::mapping::proto::Submap2D* Submap::mutable_submap_2d() {
  set_has_submap_2d();
  if (submap_2d_ == NULL) submap_2d_ = new ::cartographer::mapping::proto::Submap2D;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.Submap.submap_2d)
  return submap_2d_;
}
inline ::cartographer::mapping::proto::Submap2D* Submap::release_submap_2d() {
  clear_has_submap_2d();
  ::cartographer::mapping::proto::Submap2D* temp = submap_2d_;
  submap_2d_ = NULL;
  return temp;
}
inline void Submap::set_allocated_submap_2d(::cartographer::mapping::proto::Submap2D* submap_2d) {
  delete submap_2d_;
  submap_2d_ = submap_2d;
  if (submap_2d) {
    set_has_submap_2d();
  } else {
    clear_has_submap_2d();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.Submap.submap_2d)
}

// optional .cartographer.mapping.proto.Submap3D submap_3d = 3;
inline bool Submap::has_submap_3d() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Submap::set_has_submap_3d() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Submap::clear_has_submap_3d() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Submap::clear_submap_3d() {
  if (submap_3d_ != NULL) submap_3d_->::cartographer::mapping::proto::Submap3D::Clear();
  clear_has_submap_3d();
}
inline const ::cartographer::mapping::proto::Submap3D& Submap::submap_3d() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.Submap.submap_3d)
  return submap_3d_ != NULL ? *submap_3d_ : *default_instance_->submap_3d_;
}
inline ::cartographer::mapping::proto::Submap3D* Submap::mutable_submap_3d() {
  set_has_submap_3d();
  if (submap_3d_ == NULL) submap_3d_ = new ::cartographer::mapping::proto::Submap3D;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.Submap.submap_3d)
  return submap_3d_;
}
inline ::cartographer::mapping::proto::Submap3D* Submap::release_submap_3d() {
  clear_has_submap_3d();
  ::cartographer::mapping::proto::Submap3D* temp = submap_3d_;
  submap_3d_ = NULL;
  return temp;
}
inline void Submap::set_allocated_submap_3d(::cartographer::mapping::proto::Submap3D* submap_3d) {
  delete submap_3d_;
  submap_3d_ = submap_3d;
  if (submap_3d) {
    set_has_submap_3d();
  } else {
    clear_has_submap_3d();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.Submap.submap_3d)
}

// -------------------------------------------------------------------

// Node

// optional .cartographer.mapping.proto.NodeId node_id = 1;
inline bool Node::has_node_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Node::set_has_node_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Node::clear_has_node_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Node::clear_node_id() {
  if (node_id_ != NULL) node_id_->::cartographer::mapping::proto::NodeId::Clear();
  clear_has_node_id();
}
inline const ::cartographer::mapping::proto::NodeId& Node::node_id() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.Node.node_id)
  return node_id_ != NULL ? *node_id_ : *default_instance_->node_id_;
}
inline ::cartographer::mapping::proto::NodeId* Node::mutable_node_id() {
  set_has_node_id();
  if (node_id_ == NULL) node_id_ = new ::cartographer::mapping::proto::NodeId;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.Node.node_id)
  return node_id_;
}
inline ::cartographer::mapping::proto::NodeId* Node::release_node_id() {
  clear_has_node_id();
  ::cartographer::mapping::proto::NodeId* temp = node_id_;
  node_id_ = NULL;
  return temp;
}
inline void Node::set_allocated_node_id(::cartographer::mapping::proto::NodeId* node_id) {
  delete node_id_;
  node_id_ = node_id;
  if (node_id) {
    set_has_node_id();
  } else {
    clear_has_node_id();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.Node.node_id)
}

// optional .cartographer.mapping.proto.TrajectoryNodeData node_data = 5;
inline bool Node::has_node_data() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Node::set_has_node_data() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Node::clear_has_node_data() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Node::clear_node_data() {
  if (node_data_ != NULL) node_data_->::cartographer::mapping::proto::TrajectoryNodeData::Clear();
  clear_has_node_data();
}
inline const ::cartographer::mapping::proto::TrajectoryNodeData& Node::node_data() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.Node.node_data)
  return node_data_ != NULL ? *node_data_ : *default_instance_->node_data_;
}
inline ::cartographer::mapping::proto::TrajectoryNodeData* Node::mutable_node_data() {
  set_has_node_data();
  if (node_data_ == NULL) node_data_ = new ::cartographer::mapping::proto::TrajectoryNodeData;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.Node.node_data)
  return node_data_;
}
inline ::cartographer::mapping::proto::TrajectoryNodeData* Node::release_node_data() {
  clear_has_node_data();
  ::cartographer::mapping::proto::TrajectoryNodeData* temp = node_data_;
  node_data_ = NULL;
  return temp;
}
inline void Node::set_allocated_node_data(::cartographer::mapping::proto::TrajectoryNodeData* node_data) {
  delete node_data_;
  node_data_ = node_data;
  if (node_data) {
    set_has_node_data();
  } else {
    clear_has_node_data();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.Node.node_data)
}

// -------------------------------------------------------------------

// SerializedData

// optional .cartographer.mapping.proto.Submap submap = 1;
inline bool SerializedData::has_submap() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SerializedData::set_has_submap() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SerializedData::clear_has_submap() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SerializedData::clear_submap() {
  if (submap_ != NULL) submap_->::cartographer::mapping::proto::Submap::Clear();
  clear_has_submap();
}
inline const ::cartographer::mapping::proto::Submap& SerializedData::submap() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.SerializedData.submap)
  return submap_ != NULL ? *submap_ : *default_instance_->submap_;
}
inline ::cartographer::mapping::proto::Submap* SerializedData::mutable_submap() {
  set_has_submap();
  if (submap_ == NULL) submap_ = new ::cartographer::mapping::proto::Submap;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.SerializedData.submap)
  return submap_;
}
inline ::cartographer::mapping::proto::Submap* SerializedData::release_submap() {
  clear_has_submap();
  ::cartographer::mapping::proto::Submap* temp = submap_;
  submap_ = NULL;
  return temp;
}
inline void SerializedData::set_allocated_submap(::cartographer::mapping::proto::Submap* submap) {
  delete submap_;
  submap_ = submap;
  if (submap) {
    set_has_submap();
  } else {
    clear_has_submap();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.SerializedData.submap)
}

// optional .cartographer.mapping.proto.Node node = 2;
inline bool SerializedData::has_node() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SerializedData::set_has_node() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SerializedData::clear_has_node() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SerializedData::clear_node() {
  if (node_ != NULL) node_->::cartographer::mapping::proto::Node::Clear();
  clear_has_node();
}
inline const ::cartographer::mapping::proto::Node& SerializedData::node() const {
  // @@protoc_insertion_point(field_get:cartographer.mapping.proto.SerializedData.node)
  return node_ != NULL ? *node_ : *default_instance_->node_;
}
inline ::cartographer::mapping::proto::Node* SerializedData::mutable_node() {
  set_has_node();
  if (node_ == NULL) node_ = new ::cartographer::mapping::proto::Node;
  // @@protoc_insertion_point(field_mutable:cartographer.mapping.proto.SerializedData.node)
  return node_;
}
inline ::cartographer::mapping::proto::Node* SerializedData::release_node() {
  clear_has_node();
  ::cartographer::mapping::proto::Node* temp = node_;
  node_ = NULL;
  return temp;
}
inline void SerializedData::set_allocated_node(::cartographer::mapping::proto::Node* node) {
  delete node_;
  node_ = node;
  if (node) {
    set_has_node();
  } else {
    clear_has_node();
  }
  // @@protoc_insertion_point(field_set_allocated:cartographer.mapping.proto.SerializedData.node)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace mapping
}  // namespace cartographer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cartographer_2fmapping_2fproto_2fserialization_2eproto__INCLUDED
