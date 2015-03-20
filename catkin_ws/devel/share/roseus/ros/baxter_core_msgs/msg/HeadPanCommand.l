;; Auto-generated. Do not edit!


(when (boundp 'baxter_core_msgs::HeadPanCommand)
  (if (not (find-package "BAXTER_CORE_MSGS"))
    (make-package "BAXTER_CORE_MSGS"))
  (shadow 'HeadPanCommand (find-package "BAXTER_CORE_MSGS")))
(unless (find-package "BAXTER_CORE_MSGS::HEADPANCOMMAND")
  (make-package "BAXTER_CORE_MSGS::HEADPANCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude HeadPanCommand.msg.html


(defclass baxter_core_msgs::HeadPanCommand
  :super ros::object
  :slots (_target _speed ))

(defmethod baxter_core_msgs::HeadPanCommand
  (:init
   (&key
    ((:target __target) 0.0)
    ((:speed __speed) 0)
    )
   (send-super :init)
   (setq _target (float __target))
   (setq _speed (round __speed))
   self)
  (:target
   (&optional __target)
   (if __target (setq _target __target)) _target)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; float32 _target
    4
    ;; int32 _speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _target
       (sys::poke _target (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _speed
       (write-long _speed s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _target
     (setq _target (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _speed
     (setq _speed (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get baxter_core_msgs::HeadPanCommand :md5sum-) "990c3757495fec1dbde36b9b559e7bae")
(setf (get baxter_core_msgs::HeadPanCommand :datatype-) "baxter_core_msgs/HeadPanCommand")
(setf (get baxter_core_msgs::HeadPanCommand :definition-)
      "#Header header
float32 target # radians for target, 0 str
int32 speed # between 0 and 100, 100 = max


")



(provide :baxter_core_msgs/HeadPanCommand "990c3757495fec1dbde36b9b559e7bae")


