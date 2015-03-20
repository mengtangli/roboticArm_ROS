;; Auto-generated. Do not edit!


(when (boundp 'pr2_gazebo_plugins::SetModelsJointsStates)
  (if (not (find-package "PR2_GAZEBO_PLUGINS"))
    (make-package "PR2_GAZEBO_PLUGINS"))
  (shadow 'SetModelsJointsStates (find-package "PR2_GAZEBO_PLUGINS")))
(unless (find-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATES")
  (make-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATES"))
(unless (find-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATESREQUEST")
  (make-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATESREQUEST"))
(unless (find-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATESRESPONSE")
  (make-package "PR2_GAZEBO_PLUGINS::SETMODELSJOINTSSTATESRESPONSE"))

(in-package "ROS")

(defclass pr2_gazebo_plugins::SetModelsJointsStatesRequest
  :super ros::object
  :slots (_model_names _model_joints_states ))

(defmethod pr2_gazebo_plugins::SetModelsJointsStatesRequest
  (:init
   (&key
    ((:model_names __model_names) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:model_joints_states __model_joints_states) (let (r) (dotimes (i 0) (push (instance pr2_gazebo_plugins::ModelJointsState :init) r)) r))
    )
   (send-super :init)
   (setq _model_names __model_names)
   (setq _model_joints_states __model_joints_states)
   self)
  (:model_names
   (&optional __model_names)
   (if __model_names (setq _model_names __model_names)) _model_names)
  (:model_joints_states
   (&rest __model_joints_states)
   (if (keywordp (car __model_joints_states))
       (send* _model_joints_states __model_joints_states)
     (progn
       (if __model_joints_states (setq _model_joints_states (car __model_joints_states)))
       _model_joints_states)))
  (:serialization-length
   ()
   (+
    ;; string[] _model_names
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _model_names)) 4
    ;; pr2_gazebo_plugins/ModelJointsState[] _model_joints_states
    (apply #'+ (send-all _model_joints_states :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _model_names
     (write-long (length _model_names) s)
     (dolist (elem _model_names)
       (write-long (length elem) s) (princ elem s)
       )
     ;; pr2_gazebo_plugins/ModelJointsState[] _model_joints_states
     (write-long (length _model_joints_states) s)
     (dolist (elem _model_joints_states)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _model_names
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _model_names (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _model_names i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; pr2_gazebo_plugins/ModelJointsState[] _model_joints_states
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _model_joints_states (let (r) (dotimes (i n) (push (instance pr2_gazebo_plugins::ModelJointsState :init) r)) r))
     (dolist (elem- _model_joints_states)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(defclass pr2_gazebo_plugins::SetModelsJointsStatesResponse
  :super ros::object
  :slots (_success _status_message ))

(defmethod pr2_gazebo_plugins::SetModelsJointsStatesResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:status_message __status_message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _status_message (string __status_message))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:status_message
   (&optional __status_message)
   (if __status_message (setq _status_message __status_message)) _status_message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _status_message
    4 (length _status_message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _status_message
       (write-long (length _status_message) s) (princ _status_message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _status_message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status_message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass pr2_gazebo_plugins::SetModelsJointsStates
  :super ros::object
  :slots ())

(setf (get pr2_gazebo_plugins::SetModelsJointsStates :md5sum-) "b3f4760ee77e28f605915bcee447b72d")
(setf (get pr2_gazebo_plugins::SetModelsJointsStates :datatype-) "pr2_gazebo_plugins/SetModelsJointsStates")
(setf (get pr2_gazebo_plugins::SetModelsJointsStates :request) pr2_gazebo_plugins::SetModelsJointsStatesRequest)
(setf (get pr2_gazebo_plugins::SetModelsJointsStates :response) pr2_gazebo_plugins::SetModelsJointsStatesResponse)

(defmethod pr2_gazebo_plugins::SetModelsJointsStatesRequest
  (:response () (instance pr2_gazebo_plugins::SetModelsJointsStatesResponse :init)))

(setf (get pr2_gazebo_plugins::SetModelsJointsStatesRequest :md5sum-) "b3f4760ee77e28f605915bcee447b72d")
(setf (get pr2_gazebo_plugins::SetModelsJointsStatesRequest :datatype-) "pr2_gazebo_plugins/SetModelsJointsStatesRequest")
(setf (get pr2_gazebo_plugins::SetModelsJointsStatesRequest :definition-)
      "string[] model_names
pr2_gazebo_plugins/ModelJointsState[] model_joints_states

================================================================================
MSG: pr2_gazebo_plugins/ModelJointsState
geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty
string[] joint_names                                     # list of joint names
float64[] joint_positions                                 # list of desired joint positions, should match joint_names

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of postion and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
bool success
string status_message

")

(setf (get pr2_gazebo_plugins::SetModelsJointsStatesResponse :md5sum-) "b3f4760ee77e28f605915bcee447b72d")
(setf (get pr2_gazebo_plugins::SetModelsJointsStatesResponse :datatype-) "pr2_gazebo_plugins/SetModelsJointsStatesResponse")
(setf (get pr2_gazebo_plugins::SetModelsJointsStatesResponse :definition-)
      "string[] model_names
pr2_gazebo_plugins/ModelJointsState[] model_joints_states

================================================================================
MSG: pr2_gazebo_plugins/ModelJointsState
geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty
string[] joint_names                                     # list of joint names
float64[] joint_positions                                 # list of desired joint positions, should match joint_names

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of postion and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
bool success
string status_message

")



(provide :pr2_gazebo_plugins/SetModelsJointsStates "b3f4760ee77e28f605915bcee447b72d")


