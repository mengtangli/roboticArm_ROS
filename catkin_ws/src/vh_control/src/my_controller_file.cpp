#include "../include/arm_control/arm_control_file.h"
#include <pluginlib/class_list_macros.h>

namespace arm_control_ns {


/// Controller initialization in non-realtime
bool MyControllerClass::init(pr2_mechanism_model::RobotState *robot,
                             ros::NodeHandle &n)
{
  std::string joint_name;
  if (!n.getParam("joint_name", joint_name))
  {
    ROS_ERROR("No joint given in namespace: '%s')",
              n.getNamespace().c_str());
    return false;
  }

  joint_state_ = robot->getJointState(joint_name);
  if (!joint_state_)
  {
    ROS_ERROR("MyController could not find joint named '%s'",
              joint_name.c_str());
    return false;
  }

  srv_ = n.advertiseService("set_amplitude",
                            &MyControllerClass::setAmplitude, this);

  amplitude_ = 0.5;
  return true;
}


/// Controller startup in realtime
void MyControllerClass::starting()
{
  init_pos_ = joint_state_->position_;
}


/// Controller update loop in realtime
void MyControllerClass::update()
{
  double desired_pos = init_pos_ + amplitude_ * sin(ros::Time::now().toSec());
  double current_pos = joint_state_->position_;
  joint_state_->commanded_effort_ = -10 * (current_pos - desired_pos);
}


/// Controller stopping in realtime
void MyControllerClass::stopping()
{}


/// Service call to set amplitude of sin
bool MyControllerClass::setAmplitude(my_controller_pkg::SetAmplitude::Request& req,
                                     my_controller_pkg::SetAmplitude::Response& resp)
{
  if (fabs(req.amplitude) < 2.0){
    amplitude_ = req.amplitude;
    ROS_INFO("Mycontroller: set amplitude too %f", req.amplitude);
  }
  else
    ROS_WARN("MyController: requested amplitude %f too large", req.amplitude);

  resp.amplitude = amplitude_;
  return true;
}
} // namespace

/// Register controller to pluginlib
PLUGINLIB_REGISTER_CLASS(MyControllerPlugin,
                         my_controller_ns::MyControllerClass,
                         pr2_controller_interface::Controller)r2_controller_interface::Controller)
