;; Auto-generated. Do not edit!


(when (boundp 'baxter_core_msgs::HeadState)
  (if (not (find-package "BAXTER_CORE_MSGS"))
    (make-package "BAXTER_CORE_MSGS"))
  (shadow 'HeadState (find-package "BAXTER_CORE_MSGS")))
(unless (find-package "BAXTER_CORE_MSGS::HEADSTATE")
  (make-package "BAXTER_CORE_MSGS::HEADSTATE"))

(in-package "ROS")
;;//! \htmlinclude HeadState.msg.html


(defclass baxter_core_msgs::HeadState
  :super ros::object
  :slots (_pan _isPanning _isNodding ))

(defmethod baxter_core_msgs::HeadState
  (:init
   (&key
    ((:pan __pan) 0.0)
    ((:isPanning __isPanning) nil)
    ((:isNodding __isNodding) nil)
    )
   (send-super :init)
   (setq _pan (float __pan))
   (setq _isPanning __isPanning)
   (setq _isNodding __isNodding)
   self)
  (:pan
   (&optional __pan)
   (if __pan (setq _pan __pan)) _pan)
  (:isPanning
   (&optional __isPanning)
   (if __isPanning (setq _isPanning __isPanning)) _isPanning)
  (:isNodding
   (&optional __isNodding)
   (if __isNodding (setq _isNodding __isNodding)) _isNodding)
  (:serialization-length
   ()
   (+
    ;; float32 _pan
    4
    ;; bool _isPanning
    1
    ;; bool _isNodding
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _pan
       (sys::poke _pan (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _isPanning
       (if _isPanning (write-byte -1 s) (write-byte 0 s))
     ;; bool _isNodding
       (if _isNodding (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _pan
     (setq _pan (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _isPanning
     (setq _isPanning (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isNodding
     (setq _isNodding (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get baxter_core_msgs::HeadState :md5sum-) "a7a905cb9138493d35f02b3c35b9d65b")
(setf (get baxter_core_msgs::HeadState :datatype-) "baxter_core_msgs/HeadState")
(setf (get baxter_core_msgs::HeadState :definition-)
      "float32 pan
bool isPanning
bool isNodding

")



(provide :baxter_core_msgs/HeadState "a7a905cb9138493d35f02b3c35b9d65b")


