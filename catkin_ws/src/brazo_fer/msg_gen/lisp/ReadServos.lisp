; Auto-generated. Do not edit!


(cl:in-package brazo_fer-msg)


;//! \htmlinclude ReadServos.msg.html

(cl:defclass <ReadServos> (roslisp-msg-protocol:ros-message)
  ((posicion
    :reader posicion
    :initarg :posicion
    :type brazo_fer-msg:Servos
    :initform (cl:make-instance 'brazo_fer-msg:Servos))
   (estado
    :reader estado
    :initarg :estado
    :type brazo_fer-msg:Servos
    :initform (cl:make-instance 'brazo_fer-msg:Servos))
   (corriente
    :reader corriente
    :initarg :corriente
    :type brazo_fer-msg:Servos
    :initform (cl:make-instance 'brazo_fer-msg:Servos)))
)

(cl:defclass ReadServos (<ReadServos>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadServos>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadServos)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name brazo_fer-msg:<ReadServos> is deprecated: use brazo_fer-msg:ReadServos instead.")))

(cl:ensure-generic-function 'posicion-val :lambda-list '(m))
(cl:defmethod posicion-val ((m <ReadServos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:posicion-val is deprecated.  Use brazo_fer-msg:posicion instead.")
  (posicion m))

(cl:ensure-generic-function 'estado-val :lambda-list '(m))
(cl:defmethod estado-val ((m <ReadServos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:estado-val is deprecated.  Use brazo_fer-msg:estado instead.")
  (estado m))

(cl:ensure-generic-function 'corriente-val :lambda-list '(m))
(cl:defmethod corriente-val ((m <ReadServos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader brazo_fer-msg:corriente-val is deprecated.  Use brazo_fer-msg:corriente instead.")
  (corriente m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadServos>) ostream)
  "Serializes a message object of type '<ReadServos>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'posicion) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'estado) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'corriente) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadServos>) istream)
  "Deserializes a message object of type '<ReadServos>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'posicion) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'estado) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'corriente) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadServos>)))
  "Returns string type for a message object of type '<ReadServos>"
  "brazo_fer/ReadServos")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadServos)))
  "Returns string type for a message object of type 'ReadServos"
  "brazo_fer/ReadServos")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadServos>)))
  "Returns md5sum for a message object of type '<ReadServos>"
  "eb601df5ba86278a5ceaf5eea9e7da64")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadServos)))
  "Returns md5sum for a message object of type 'ReadServos"
  "eb601df5ba86278a5ceaf5eea9e7da64")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadServos>)))
  "Returns full string definition for message of type '<ReadServos>"
  (cl:format cl:nil "Servos posicion~%Servos estado~%Servos corriente~%~%================================================================================~%MSG: brazo_fer/Servos~%int16 base~%int16 arti1~%int16 arti2~%int16 arti3~%int16 pinza~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadServos)))
  "Returns full string definition for message of type 'ReadServos"
  (cl:format cl:nil "Servos posicion~%Servos estado~%Servos corriente~%~%================================================================================~%MSG: brazo_fer/Servos~%int16 base~%int16 arti1~%int16 arti2~%int16 arti3~%int16 pinza~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadServos>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'posicion))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'estado))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'corriente))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadServos>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadServos
    (cl:cons ':posicion (posicion msg))
    (cl:cons ':estado (estado msg))
    (cl:cons ':corriente (corriente msg))
))
