;; Auto-generated. Do not edit!


(when (boundp 'baxter_core_msgs::ITBState)
  (if (not (find-package "BAXTER_CORE_MSGS"))
    (make-package "BAXTER_CORE_MSGS"))
  (shadow 'ITBState (find-package "BAXTER_CORE_MSGS")))
(unless (find-package "BAXTER_CORE_MSGS::ITBSTATE")
  (make-package "BAXTER_CORE_MSGS::ITBSTATE"))

(in-package "ROS")
;;//! \htmlinclude ITBState.msg.html


(defclass baxter_core_msgs::ITBState
  :super ros::object
  :slots (_buttons _up _down _left _right _wheel _innerLight _outerLight ))

(defmethod baxter_core_msgs::ITBState
  (:init
   (&key
    ((:buttons __buttons) (make-array 4 :initial-element nil :element-type :object))
    ((:up __up) nil)
    ((:down __down) nil)
    ((:left __left) nil)
    ((:right __right) nil)
    ((:wheel __wheel) 0)
    ((:innerLight __innerLight) nil)
    ((:outerLight __outerLight) nil)
    )
   (send-super :init)
   (setq _buttons __buttons)
   (setq _up __up)
   (setq _down __down)
   (setq _left __left)
   (setq _right __right)
   (setq _wheel (round __wheel))
   (setq _innerLight __innerLight)
   (setq _outerLight __outerLight)
   self)
  (:buttons
   (&optional __buttons)
   (if __buttons (setq _buttons __buttons)) _buttons)
  (:up
   (&optional __up)
   (if __up (setq _up __up)) _up)
  (:down
   (&optional __down)
   (if __down (setq _down __down)) _down)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:wheel
   (&optional __wheel)
   (if __wheel (setq _wheel __wheel)) _wheel)
  (:innerLight
   (&optional __innerLight)
   (if __innerLight (setq _innerLight __innerLight)) _innerLight)
  (:outerLight
   (&optional __outerLight)
   (if __outerLight (setq _outerLight __outerLight)) _outerLight)
  (:serialization-length
   ()
   (+
    ;; bool[4] _buttons
    (* 1    4)
    ;; bool _up
    1
    ;; bool _down
    1
    ;; bool _left
    1
    ;; bool _right
    1
    ;; uint8 _wheel
    1
    ;; bool _innerLight
    1
    ;; bool _outerLight
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool[4] _buttons
     (dotimes (i 4)
       (if (elt _buttons i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; bool _up
       (if _up (write-byte -1 s) (write-byte 0 s))
     ;; bool _down
       (if _down (write-byte -1 s) (write-byte 0 s))
     ;; bool _left
       (if _left (write-byte -1 s) (write-byte 0 s))
     ;; bool _right
       (if _right (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _wheel
       (write-byte _wheel s)
     ;; bool _innerLight
       (if _innerLight (write-byte -1 s) (write-byte 0 s))
     ;; bool _outerLight
       (if _outerLight (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool[4] _buttons
   (dotimes (i (length _buttons))
     (setf (elt _buttons i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; bool _up
     (setq _up (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _down
     (setq _down (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _left
     (setq _left (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _right
     (setq _right (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _wheel
     (setq _wheel (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _innerLight
     (setq _innerLight (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _outerLight
     (setq _outerLight (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get baxter_core_msgs::ITBState :md5sum-) "fd86ad89da05230247c94b4d8e7ed306")
(setf (get baxter_core_msgs::ITBState :datatype-) "baxter_core_msgs/ITBState")
(setf (get baxter_core_msgs::ITBState :definition-)
      "bool[4] buttons
bool    up
bool    down
bool    left
bool    right
uint8   wheel

# true if the inner light is on, false if not
bool innerLight

# true if the outer light is on, false if not
bool outerLight

")



(provide :baxter_core_msgs/ITBState "fd86ad89da05230247c94b4d8e7ed306")


