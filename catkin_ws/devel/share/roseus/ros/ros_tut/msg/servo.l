;; Auto-generated. Do not edit!


(when (boundp 'ros_tut::servo)
  (if (not (find-package "ROS_TUT"))
    (make-package "ROS_TUT"))
  (shadow 'servo (find-package "ROS_TUT")))
(unless (find-package "ROS_TUT::SERVO")
  (make-package "ROS_TUT::SERVO"))

(in-package "ROS")
;;//! \htmlinclude servo.msg.html


(defclass ros_tut::servo
  :super ros::object
  :slots (_first _second _third ))

(defmethod ros_tut::servo
  (:init
   (&key
    ((:first __first) 0)
    ((:second __second) 0)
    ((:third __third) 0)
    )
   (send-super :init)
   (setq _first (round __first))
   (setq _second (round __second))
   (setq _third (round __third))
   self)
  (:first
   (&optional __first)
   (if __first (setq _first __first)) _first)
  (:second
   (&optional __second)
   (if __second (setq _second __second)) _second)
  (:third
   (&optional __third)
   (if __third (setq _third __third)) _third)
  (:serialization-length
   ()
   (+
    ;; int16 _first
    2
    ;; int16 _second
    2
    ;; int16 _third
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _first
       (write-word _first s)
     ;; int16 _second
       (write-word _second s)
     ;; int16 _third
       (write-word _third s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _first
     (setq _first (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _second
     (setq _second (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _third
     (setq _third (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get ros_tut::servo :md5sum-) "a857454193b3801feabc5fd6d0dba368")
(setf (get ros_tut::servo :datatype-) "ros_tut/servo")
(setf (get ros_tut::servo :definition-)
      "int16 first
int16 second
int16 third

")



(provide :ros_tut/servo "a857454193b3801feabc5fd6d0dba368")


