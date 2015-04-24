;; Auto-generated. Do not edit!


(when (boundp 'arm_control::servo)
  (if (not (find-package "ARM_CONTROL"))
    (make-package "ARM_CONTROL"))
  (shadow 'servo (find-package "ARM_CONTROL")))
(unless (find-package "ARM_CONTROL::SERVO")
  (make-package "ARM_CONTROL::SERVO"))

(in-package "ROS")
;;//! \htmlinclude servo.msg.html


(defclass arm_control::servo
  :super ros::object
  :slots (_first _second _third _forth _fifth ))

(defmethod arm_control::servo
  (:init
   (&key
    ((:first __first) 0)
    ((:second __second) 0)
    ((:third __third) 0)
    ((:forth __forth) 0)
    ((:fifth __fifth) 0)
    )
   (send-super :init)
   (setq _first (round __first))
   (setq _second (round __second))
   (setq _third (round __third))
   (setq _forth (round __forth))
   (setq _fifth (round __fifth))
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
  (:forth
   (&optional __forth)
   (if __forth (setq _forth __forth)) _forth)
  (:fifth
   (&optional __fifth)
   (if __fifth (setq _fifth __fifth)) _fifth)
  (:serialization-length
   ()
   (+
    ;; int16 _first
    2
    ;; int16 _second
    2
    ;; int16 _third
    2
    ;; int16 _forth
    2
    ;; int16 _fifth
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
     ;; int16 _forth
       (write-word _forth s)
     ;; int16 _fifth
       (write-word _fifth s)
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
   ;; int16 _forth
     (setq _forth (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _fifth
     (setq _fifth (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get arm_control::servo :md5sum-) "418e6ef17161af8b9a9f73f67b2c84e6")
(setf (get arm_control::servo :datatype-) "arm_control/servo")
(setf (get arm_control::servo :definition-)
      "int16 first
int16 second
int16 third
int16 forth
int16 fifth

")



(provide :arm_control/servo "418e6ef17161af8b9a9f73f67b2c84e6")


