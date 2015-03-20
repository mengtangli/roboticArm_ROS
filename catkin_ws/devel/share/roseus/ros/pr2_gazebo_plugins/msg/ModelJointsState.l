;; Auto-generated. Do not edit!


(when (boundp 'pr2_gazebo_plugins::ModelJointsState)
  (if (not (find-package "PR2_GAZEBO_PLUGINS"))
    (make-package "PR2_GAZEBO_PLUGINS"))
  (shadow 'ModelJointsState (find-package "PR2_GAZEBO_PLUGINS")))
(unless (find-package "PR2_GAZEBO_PLUGINS::MODELJOINTSSTATE")
  (make-package "PR2_GAZEBO_PLUGINS::MODELJOINTSSTATE"))

(in-package "ROS")
;;//! \htmlinclude ModelJointsState.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass pr2_gazebo_plugins::ModelJointsState
  :super ros::object
  :slots (_model_pose _joint_names _joint_positions ))

(defmethod pr2_gazebo_plugins::ModelJointsState
  (:init
   (&key
    ((:model_pose __model_pose) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Pose :init) r)) r))
    ((:joint_names __joint_names) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:joint_positions __joint_positions) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _model_pose __model_pose)
   (setq _joint_names __joint_names)
   (setq _joint_positions __joint_positions)
   self)
  (:model_pose
   (&rest __model_pose)
   (if (keywordp (car __model_pose))
       (send* _model_pose __model_pose)
     (progn
       (if __model_pose (setq _model_pose (car __model_pose)))
       _model_pose)))
  (:joint_names
   (&optional __joint_names)
   (if __joint_names (setq _joint_names __joint_names)) _joint_names)
  (:joint_positions
   (&optional __joint_positions)
   (if __joint_positions (setq _joint_positions __joint_positions)) _joint_positions)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose[] _model_pose
    (apply #'+ (send-all _model_pose :serialization-length)) 4
    ;; string[] _joint_names
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _joint_names)) 4
    ;; float64[] _joint_positions
    (* 8    (length _joint_positions)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose[] _model_pose
     (write-long (length _model_pose) s)
     (dolist (elem _model_pose)
       (send elem :serialize s)
       )
     ;; string[] _joint_names
     (write-long (length _joint_names) s)
     (dolist (elem _joint_names)
       (write-long (length elem) s) (princ elem s)
       )
     ;; float64[] _joint_positions
     (write-long (length _joint_positions) s)
     (dotimes (i (length _joint_positions))
       (sys::poke (elt _joint_positions i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose[] _model_pose
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _model_pose (let (r) (dotimes (i n) (push (instance geometry_msgs::Pose :init) r)) r))
     (dolist (elem- _model_pose)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; string[] _joint_names
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_names (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _joint_names i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; float64[] _joint_positions
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_positions (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _joint_positions i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get pr2_gazebo_plugins::ModelJointsState :md5sum-) "f700a74958b6566fae4cd77fbb80ffd4")
(setf (get pr2_gazebo_plugins::ModelJointsState :datatype-) "pr2_gazebo_plugins/ModelJointsState")
(setf (get pr2_gazebo_plugins::ModelJointsState :definition-)
      "geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty
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

")



(provide :pr2_gazebo_plugins/ModelJointsState "f700a74958b6566fae4cd77fbb80ffd4")


