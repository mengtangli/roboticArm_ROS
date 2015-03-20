;; Auto-generated. Do not edit!


(when (boundp 'baxter_maintenance_msgs::CalibrateArmData)
  (if (not (find-package "BAXTER_MAINTENANCE_MSGS"))
    (make-package "BAXTER_MAINTENANCE_MSGS"))
  (shadow 'CalibrateArmData (find-package "BAXTER_MAINTENANCE_MSGS")))
(unless (find-package "BAXTER_MAINTENANCE_MSGS::CALIBRATEARMDATA")
  (make-package "BAXTER_MAINTENANCE_MSGS::CALIBRATEARMDATA"))

(in-package "ROS")
;;//! \htmlinclude CalibrateArmData.msg.html


(defclass baxter_maintenance_msgs::CalibrateArmData
  :super ros::object
  :slots ())

(defmethod baxter_maintenance_msgs::CalibrateArmData
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get baxter_maintenance_msgs::CalibrateArmData :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get baxter_maintenance_msgs::CalibrateArmData :datatype-) "baxter_maintenance_msgs/CalibrateArmData")
(setf (get baxter_maintenance_msgs::CalibrateArmData :definition-)
      "
")



(provide :baxter_maintenance_msgs/CalibrateArmData "d41d8cd98f00b204e9800998ecf8427e")


