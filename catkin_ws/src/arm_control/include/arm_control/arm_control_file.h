#include <pr2_controller_interface/controller.h>
#include <pr2_mechanism_model/joint.h>
#include <ros/ros.h>
#include <arm_control_pkg/SetAmplitude.h>

namespace arm_control_ns{

class MyControllerClass: public pr2_controller_interface::Controller
{
private:
  bool setAmplitude(my_controller_pkg::SetAmplitude::Request& req,
                    my_controller_pkg::SetAmplitude::Response& resp);

  pr2_mechanism_model::JointState* joint_state_;
  double init_pos_;
  double amplitude_;
  ros::ServiceServer srv_;

public:
  virtual bool init(pr2_mechanism_model::RobotState *robot,
                    ros::NodeHandle &n);
  virtual void starting();
  virtual void update();
  virtual void stopping();
};
} 
