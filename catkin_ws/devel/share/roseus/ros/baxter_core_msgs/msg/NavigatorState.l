;; Auto-generated. Do not edit!


(when (boundp 'baxter_core_msgs::NavigatorState)
  (if (not (find-package "BAXTER_CORE_MSGS"))
    (make-package "BAXTER_CORE_MSGS"))
  (shadow 'NavigatorState (find-package "BAXTER_CORE_MSGS")))
(unless (find-package "BAXTER_CORE_MSGS::NAVIGATORSTATE")
  (make-package "BAXTER_CORE_MSGS::NAVIGATORSTATE"))

(in-package "ROS")
;;//! \htmlinclude NavigatorState.msg.html


(defclass baxter_core_msgs::NavigatorState
  :super ros::object
  :slots (_names _buttons _wheel _lights ))

(defmethod baxter_core_msgs::NavigatorState
  (:init
   (&key
    ((:names __names) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:buttons __buttons) (make-array 0 :initial-element nil :element-type :object))
    ((:wheel __wheel) 0)
    ((:lights __lights) (make-array 0 :initial-element nil :element-type :object))
    )
   (send-super :init)
   (setq _names __names)
   (setq _buttons __buttons)
   (setq _wheel (round __wheel))
   (setq _lights __lights)
   self)
  (:names
   (&optional __names)
   (if __names (setq _names __names)) _names)
  (:buttons
   (&optional __buttons)
   (if __buttons (setq _buttons __buttons)) _buttons)
  (:wheel
   (&optional __wheel)
   (if __wheel (setq _wheel __wheel)) _wheel)
  (:lights
   (&optional __lights)
   (if __lights (setq _lights __lights)) _lights)
  (:serialization-length
   ()
   (+
    ;; string[] _names
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _names)) 4
    ;; bool[] _buttons
    (* 1    (length _buttons)) 4
    ;; uint8 _wheel
    1
    ;; bool[] _lights
    (* 1    (length _lights)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _names
     (write-long (length _names) s)
     (dolist (elem _names)
       (write-long (length elem) s) (princ elem s)
       )
     ;; bool[] _buttons
     (write-long (length _buttons) s)
     (dotimes (i (length _buttons))
       (if (elt _buttons i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; uint8 _wheel
       (write-byte _wheel s)
     ;; bool[] _lights
     (write-long (length _lights) s)
     (dotimes (i (length _lights))
       (if (elt _lights i) (write-byte -1 s) (write-byte 0 s))
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _names
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _names (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _names i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; bool[] _buttons
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _buttons (let (r) (dotimes (i n) (push (instance object :init) r)) r))
     (dolist (elem- _buttons)
     (setq elem- (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; uint8 _wheel
     (setq _wheel (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool[] _lights
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _lights (let (r) (dotimes (i n) (push (instance object :init) r)) r))
     (dolist (elem- _lights)
     (setq elem- (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;;
   self)
  )

(setf (get baxter_core_msgs::NavigatorState :md5sum-) "626a2401ea06bafc2f1ecf16d05f1675")
(setf (get baxter_core_msgs::NavigatorState :datatype-) "baxter_core_msgs/NavigatorState")
(setf (get baxter_core_msgs::NavigatorState :definition-)
      "# buttons
string[] names
bool[] buttons

# wheel position
uint8   wheel

# true if the light is on, false if not
# lights map to button names
bool[] lights

")



(provide :baxter_core_msgs/NavigatorState "626a2401ea06bafc2f1ecf16d05f1675")


