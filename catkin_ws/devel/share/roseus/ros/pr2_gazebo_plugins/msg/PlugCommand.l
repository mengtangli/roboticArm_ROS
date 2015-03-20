;; Auto-generated. Do not edit!


(when (boundp 'pr2_gazebo_plugins::PlugCommand)
  (if (not (find-package "PR2_GAZEBO_PLUGINS"))
    (make-package "PR2_GAZEBO_PLUGINS"))
  (shadow 'PlugCommand (find-package "PR2_GAZEBO_PLUGINS")))
(unless (find-package "PR2_GAZEBO_PLUGINS::PLUGCOMMAND")
  (make-package "PR2_GAZEBO_PLUGINS::PLUGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude PlugCommand.msg.html


(defclass pr2_gazebo_plugins::PlugCommand
  :super ros::object
  :slots (_ac_present _charge_rate _discharge_rate _charge ))

(defmethod pr2_gazebo_plugins::PlugCommand
  (:init
   (&key
    ((:ac_present __ac_present) nil)
    ((:charge_rate __charge_rate) 0.0)
    ((:discharge_rate __discharge_rate) 0.0)
    ((:charge __charge) 0.0)
    )
   (send-super :init)
   (setq _ac_present __ac_present)
   (setq _charge_rate (float __charge_rate))
   (setq _discharge_rate (float __discharge_rate))
   (setq _charge (float __charge))
   self)
  (:ac_present
   (&optional __ac_present)
   (if __ac_present (setq _ac_present __ac_present)) _ac_present)
  (:charge_rate
   (&optional __charge_rate)
   (if __charge_rate (setq _charge_rate __charge_rate)) _charge_rate)
  (:discharge_rate
   (&optional __discharge_rate)
   (if __discharge_rate (setq _discharge_rate __discharge_rate)) _discharge_rate)
  (:charge
   (&optional __charge)
   (if __charge (setq _charge __charge)) _charge)
  (:serialization-length
   ()
   (+
    ;; bool _ac_present
    1
    ;; float64 _charge_rate
    8
    ;; float64 _discharge_rate
    8
    ;; float64 _charge
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ac_present
       (if _ac_present (write-byte -1 s) (write-byte 0 s))
     ;; float64 _charge_rate
       (sys::poke _charge_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _discharge_rate
       (sys::poke _discharge_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _charge
       (sys::poke _charge (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ac_present
     (setq _ac_present (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _charge_rate
     (setq _charge_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _discharge_rate
     (setq _discharge_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _charge
     (setq _charge (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get pr2_gazebo_plugins::PlugCommand :md5sum-) "852b7035ee3e7fa6390824cf7b7e6dd1")
(setf (get pr2_gazebo_plugins::PlugCommand :datatype-) "pr2_gazebo_plugins/PlugCommand")
(setf (get pr2_gazebo_plugins::PlugCommand :definition-)
      "bool ac_present
float64 charge_rate
float64 discharge_rate
float64 charge

")



(provide :pr2_gazebo_plugins/PlugCommand "852b7035ee3e7fa6390824cf7b7e6dd1")


