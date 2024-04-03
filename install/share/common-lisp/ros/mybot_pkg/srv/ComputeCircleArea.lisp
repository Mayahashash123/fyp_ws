; Auto-generated. Do not edit!


(cl:in-package mybot_pkg-srv)


;//! \htmlinclude ComputeCircleArea-request.msg.html

(cl:defclass <ComputeCircleArea-request> (roslisp-msg-protocol:ros-message)
  ((radius
    :reader radius
    :initarg :radius
    :type cl:float
    :initform 0.0))
)

(cl:defclass ComputeCircleArea-request (<ComputeCircleArea-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ComputeCircleArea-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ComputeCircleArea-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mybot_pkg-srv:<ComputeCircleArea-request> is deprecated: use mybot_pkg-srv:ComputeCircleArea-request instead.")))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <ComputeCircleArea-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mybot_pkg-srv:radius-val is deprecated.  Use mybot_pkg-srv:radius instead.")
  (radius m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ComputeCircleArea-request>) ostream)
  "Serializes a message object of type '<ComputeCircleArea-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'radius))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ComputeCircleArea-request>) istream)
  "Deserializes a message object of type '<ComputeCircleArea-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radius) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ComputeCircleArea-request>)))
  "Returns string type for a service object of type '<ComputeCircleArea-request>"
  "mybot_pkg/ComputeCircleAreaRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ComputeCircleArea-request)))
  "Returns string type for a service object of type 'ComputeCircleArea-request"
  "mybot_pkg/ComputeCircleAreaRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ComputeCircleArea-request>)))
  "Returns md5sum for a message object of type '<ComputeCircleArea-request>"
  "c314357897f85c5c2498418b07dbcead")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ComputeCircleArea-request)))
  "Returns md5sum for a message object of type 'ComputeCircleArea-request"
  "c314357897f85c5c2498418b07dbcead")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ComputeCircleArea-request>)))
  "Returns full string definition for message of type '<ComputeCircleArea-request>"
  (cl:format cl:nil "float64 radius~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ComputeCircleArea-request)))
  "Returns full string definition for message of type 'ComputeCircleArea-request"
  (cl:format cl:nil "float64 radius~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ComputeCircleArea-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ComputeCircleArea-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ComputeCircleArea-request
    (cl:cons ':radius (radius msg))
))
;//! \htmlinclude ComputeCircleArea-response.msg.html

(cl:defclass <ComputeCircleArea-response> (roslisp-msg-protocol:ros-message)
  ((area
    :reader area
    :initarg :area
    :type cl:float
    :initform 0.0))
)

(cl:defclass ComputeCircleArea-response (<ComputeCircleArea-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ComputeCircleArea-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ComputeCircleArea-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mybot_pkg-srv:<ComputeCircleArea-response> is deprecated: use mybot_pkg-srv:ComputeCircleArea-response instead.")))

(cl:ensure-generic-function 'area-val :lambda-list '(m))
(cl:defmethod area-val ((m <ComputeCircleArea-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mybot_pkg-srv:area-val is deprecated.  Use mybot_pkg-srv:area instead.")
  (area m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ComputeCircleArea-response>) ostream)
  "Serializes a message object of type '<ComputeCircleArea-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'area))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ComputeCircleArea-response>) istream)
  "Deserializes a message object of type '<ComputeCircleArea-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'area) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ComputeCircleArea-response>)))
  "Returns string type for a service object of type '<ComputeCircleArea-response>"
  "mybot_pkg/ComputeCircleAreaResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ComputeCircleArea-response)))
  "Returns string type for a service object of type 'ComputeCircleArea-response"
  "mybot_pkg/ComputeCircleAreaResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ComputeCircleArea-response>)))
  "Returns md5sum for a message object of type '<ComputeCircleArea-response>"
  "c314357897f85c5c2498418b07dbcead")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ComputeCircleArea-response)))
  "Returns md5sum for a message object of type 'ComputeCircleArea-response"
  "c314357897f85c5c2498418b07dbcead")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ComputeCircleArea-response>)))
  "Returns full string definition for message of type '<ComputeCircleArea-response>"
  (cl:format cl:nil "~%float64 area~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ComputeCircleArea-response)))
  "Returns full string definition for message of type 'ComputeCircleArea-response"
  (cl:format cl:nil "~%float64 area~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ComputeCircleArea-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ComputeCircleArea-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ComputeCircleArea-response
    (cl:cons ':area (area msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ComputeCircleArea)))
  'ComputeCircleArea-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ComputeCircleArea)))
  'ComputeCircleArea-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ComputeCircleArea)))
  "Returns string type for a service object of type '<ComputeCircleArea>"
  "mybot_pkg/ComputeCircleArea")