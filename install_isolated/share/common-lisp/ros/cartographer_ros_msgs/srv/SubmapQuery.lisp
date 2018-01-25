; Auto-generated. Do not edit!


(cl:in-package cartographer_ros_msgs-srv)


;//! \htmlinclude SubmapQuery-request.msg.html

(cl:defclass <SubmapQuery-request> (roslisp-msg-protocol:ros-message)
  ((trajectory_id
    :reader trajectory_id
    :initarg :trajectory_id
    :type cl:integer
    :initform 0)
   (submap_index
    :reader submap_index
    :initarg :submap_index
    :type cl:integer
    :initform 0))
)

(cl:defclass SubmapQuery-request (<SubmapQuery-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SubmapQuery-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SubmapQuery-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cartographer_ros_msgs-srv:<SubmapQuery-request> is deprecated: use cartographer_ros_msgs-srv:SubmapQuery-request instead.")))

(cl:ensure-generic-function 'trajectory_id-val :lambda-list '(m))
(cl:defmethod trajectory_id-val ((m <SubmapQuery-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:trajectory_id-val is deprecated.  Use cartographer_ros_msgs-srv:trajectory_id instead.")
  (trajectory_id m))

(cl:ensure-generic-function 'submap_index-val :lambda-list '(m))
(cl:defmethod submap_index-val ((m <SubmapQuery-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:submap_index-val is deprecated.  Use cartographer_ros_msgs-srv:submap_index instead.")
  (submap_index m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SubmapQuery-request>) ostream)
  "Serializes a message object of type '<SubmapQuery-request>"
  (cl:let* ((signed (cl:slot-value msg 'trajectory_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'submap_index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SubmapQuery-request>) istream)
  "Deserializes a message object of type '<SubmapQuery-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trajectory_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'submap_index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SubmapQuery-request>)))
  "Returns string type for a service object of type '<SubmapQuery-request>"
  "cartographer_ros_msgs/SubmapQueryRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SubmapQuery-request)))
  "Returns string type for a service object of type 'SubmapQuery-request"
  "cartographer_ros_msgs/SubmapQueryRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SubmapQuery-request>)))
  "Returns md5sum for a message object of type '<SubmapQuery-request>"
  "274558cc713c30123c26c8267e25946b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SubmapQuery-request)))
  "Returns md5sum for a message object of type 'SubmapQuery-request"
  "274558cc713c30123c26c8267e25946b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SubmapQuery-request>)))
  "Returns full string definition for message of type '<SubmapQuery-request>"
  (cl:format cl:nil "~%~%~%~%~%~%~%~%~%~%~%~%~%~%int32 trajectory_id~%int32 submap_index~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SubmapQuery-request)))
  "Returns full string definition for message of type 'SubmapQuery-request"
  (cl:format cl:nil "~%~%~%~%~%~%~%~%~%~%~%~%~%~%int32 trajectory_id~%int32 submap_index~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SubmapQuery-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SubmapQuery-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SubmapQuery-request
    (cl:cons ':trajectory_id (trajectory_id msg))
    (cl:cons ':submap_index (submap_index msg))
))
;//! \htmlinclude SubmapQuery-response.msg.html

(cl:defclass <SubmapQuery-response> (roslisp-msg-protocol:ros-message)
  ((submap_version
    :reader submap_version
    :initarg :submap_version
    :type cl:integer
    :initform 0)
   (textures
    :reader textures
    :initarg :textures
    :type (cl:vector cartographer_ros_msgs-msg:SubmapTexture)
   :initform (cl:make-array 0 :element-type 'cartographer_ros_msgs-msg:SubmapTexture :initial-element (cl:make-instance 'cartographer_ros_msgs-msg:SubmapTexture)))
   (error_message
    :reader error_message
    :initarg :error_message
    :type cl:string
    :initform ""))
)

(cl:defclass SubmapQuery-response (<SubmapQuery-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SubmapQuery-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SubmapQuery-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cartographer_ros_msgs-srv:<SubmapQuery-response> is deprecated: use cartographer_ros_msgs-srv:SubmapQuery-response instead.")))

(cl:ensure-generic-function 'submap_version-val :lambda-list '(m))
(cl:defmethod submap_version-val ((m <SubmapQuery-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:submap_version-val is deprecated.  Use cartographer_ros_msgs-srv:submap_version instead.")
  (submap_version m))

(cl:ensure-generic-function 'textures-val :lambda-list '(m))
(cl:defmethod textures-val ((m <SubmapQuery-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:textures-val is deprecated.  Use cartographer_ros_msgs-srv:textures instead.")
  (textures m))

(cl:ensure-generic-function 'error_message-val :lambda-list '(m))
(cl:defmethod error_message-val ((m <SubmapQuery-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cartographer_ros_msgs-srv:error_message-val is deprecated.  Use cartographer_ros_msgs-srv:error_message instead.")
  (error_message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SubmapQuery-response>) ostream)
  "Serializes a message object of type '<SubmapQuery-response>"
  (cl:let* ((signed (cl:slot-value msg 'submap_version)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'textures))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'textures))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error_message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error_message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SubmapQuery-response>) istream)
  "Deserializes a message object of type '<SubmapQuery-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'submap_version) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'textures) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'textures)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'cartographer_ros_msgs-msg:SubmapTexture))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'error_message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'error_message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SubmapQuery-response>)))
  "Returns string type for a service object of type '<SubmapQuery-response>"
  "cartographer_ros_msgs/SubmapQueryResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SubmapQuery-response)))
  "Returns string type for a service object of type 'SubmapQuery-response"
  "cartographer_ros_msgs/SubmapQueryResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SubmapQuery-response>)))
  "Returns md5sum for a message object of type '<SubmapQuery-response>"
  "274558cc713c30123c26c8267e25946b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SubmapQuery-response)))
  "Returns md5sum for a message object of type 'SubmapQuery-response"
  "274558cc713c30123c26c8267e25946b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SubmapQuery-response>)))
  "Returns full string definition for message of type '<SubmapQuery-response>"
  (cl:format cl:nil "int32 submap_version~%SubmapTexture[] textures~%string error_message~%~%~%================================================================================~%MSG: cartographer_ros_msgs/SubmapTexture~%# Copyright 2017 The Cartographer Authors~%#~%# Licensed under the Apache License, Version 2.0 (the \"License\");~%# you may not use this file except in compliance with the License.~%# You may obtain a copy of the License at~%#~%#      http://www.apache.org/licenses/LICENSE-2.0~%#~%# Unless required by applicable law or agreed to in writing, software~%# distributed under the License is distributed on an \"AS IS\" BASIS,~%# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.~%# See the License for the specific language governing permissions and~%# limitations under the License.~%~%uint8[] cells~%int32 width~%int32 height~%float64 resolution~%geometry_msgs/Pose slice_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SubmapQuery-response)))
  "Returns full string definition for message of type 'SubmapQuery-response"
  (cl:format cl:nil "int32 submap_version~%SubmapTexture[] textures~%string error_message~%~%~%================================================================================~%MSG: cartographer_ros_msgs/SubmapTexture~%# Copyright 2017 The Cartographer Authors~%#~%# Licensed under the Apache License, Version 2.0 (the \"License\");~%# you may not use this file except in compliance with the License.~%# You may obtain a copy of the License at~%#~%#      http://www.apache.org/licenses/LICENSE-2.0~%#~%# Unless required by applicable law or agreed to in writing, software~%# distributed under the License is distributed on an \"AS IS\" BASIS,~%# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.~%# See the License for the specific language governing permissions and~%# limitations under the License.~%~%uint8[] cells~%int32 width~%int32 height~%float64 resolution~%geometry_msgs/Pose slice_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SubmapQuery-response>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'textures) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:length (cl:slot-value msg 'error_message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SubmapQuery-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SubmapQuery-response
    (cl:cons ':submap_version (submap_version msg))
    (cl:cons ':textures (textures msg))
    (cl:cons ':error_message (error_message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SubmapQuery)))
  'SubmapQuery-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SubmapQuery)))
  'SubmapQuery-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SubmapQuery)))
  "Returns string type for a service object of type '<SubmapQuery>"
  "cartographer_ros_msgs/SubmapQuery")