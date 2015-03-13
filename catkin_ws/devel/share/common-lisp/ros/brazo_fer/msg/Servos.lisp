; Auto-generated. Do not edit!


(cl:in-package brazo_fer-msg)


;//! \htmlinclude Servos.msg.html

(cl:defclass <Servos> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type cl:fixnum
    :initform 0)
   (arti1
    :reader arti1
    :initarg :arti1
    :type cl:fixnum
    :initform 0)
   (arti2
    :reader arti2
    :initarg :arti2
    :type cl:fixnum
    :initform 0)
   (arti3
    :reader arti3
    :initarg :arti3
    :type cl:fixnum
    :initform 0)
   (pinza
    :reader pinza
    :initarg :pinza
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Servos (<Servos>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Servos>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Servos)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name brazo_fer-msg:<Servos> is deprecated: use brazo_fer-msg:Servos instead.")))

(cl:ensure-generic-function 'base-val :lambda-list '(m))
(cl:defmethod base-val ((m <Servos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:base-val is deprecated.  Use brazo_fer-msg:base instead.")
  (base m))

(cl:ensure-generic-function 'arti1-val :lambda-list '(m))
(cl:defmethod arti1-val ((m <Servos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:arti1-val is deprecated.  Use brazo_fer-msg:arti1 instead.")
  (arti1 m))

(cl:ensure-generic-function 'arti2-val :lambda-list '(m))
(cl:defmethod arti2-val ((m <Servos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:arti2-val is deprecated.  Use brazo_fer-msg:arti2 instead.")
  (arti2 m))

(cl:ensure-generic-function 'arti3-val :lambda-list '(m))
(cl:defmethod arti3-val ((m <Servos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:arti3-val is deprecated.  Use brazo_fer-msg:arti3 instead.")
  (arti3 m))

(cl:ensure-generic-function 'pinza-val :lambda-list '(m))
(cl:defmethod pinza-val ((m <Servos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:pinza-val is deprecated.  Use brazo_fer-msg:pinza instead.")
  (pinza m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Servos>) ostream)
  "Serializes a message object of type '<Servos>"
  (cl:let* ((signed (cl:slot-value msg 'base)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arti1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arti2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arti3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'pinza)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Servos>) istream)
  "Deserializes a message object of type '<Servos>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'base) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arti1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arti2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arti3) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pinza) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Servos>)))
  "Returns string type for a message object of type '<Servos>"
  "brazo_fer/Servos")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Servos)))
  "Returns string type for a message object of type 'Servos"
  "brazo_fer/Servos")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Servos>)))
  "Returns md5sum for a message object of type '<Servos>"
  "6be90daad19b44888c6ef8582506a939")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Servos)))
  "Returns md5sum for a message object of type 'Servos"
  "6be90daad19b44888c6ef8582506a939")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Servos>)))
  "Returns full string definition for message of type '<Servos>"
  (cl:format cl:nil "int16 base~%int16 arti1~%int16 arti2~%int16 arti3~%int16 pinza~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Servos)))
  "Returns full string definition for message of type 'Servos"
  (cl:format cl:nil "int16 base~%int16 arti1~%int16 arti2~%int16 arti3~%int16 pinza~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Servos>))
  (cl:+ 0
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Servos>))
  "Converts a ROS message object to a list"
  (cl:list 'Servos
    (cl:cons ':base (base msg))
    (cl:cons ':arti1 (arti1 msg))
    (cl:cons ':arti2 (arti2 msg))
    (cl:cons ':arti3 (arti3 msg))
    (cl:cons ':pinza (pinza msg))
))
