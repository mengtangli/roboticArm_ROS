// Generated by gencpp from file pr2_gazebo_plugins/ModelJointsState.msg
// DO NOT EDIT!


#ifndef PR2_GAZEBO_PLUGINS_MESSAGE_MODELJOINTSSTATE_H
#define PR2_GAZEBO_PLUGINS_MESSAGE_MODELJOINTSSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>

namespace pr2_gazebo_plugins
{
template <class ContainerAllocator>
struct ModelJointsState_
{
  typedef ModelJointsState_<ContainerAllocator> Type;

  ModelJointsState_()
    : model_pose()
    , joint_names()
    , joint_positions()  {
    }
  ModelJointsState_(const ContainerAllocator& _alloc)
    : model_pose(_alloc)
    , joint_names(_alloc)
    , joint_positions(_alloc)  {
    }



   typedef std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  _model_pose_type;
  _model_pose_type model_pose;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _joint_names_type;
  _joint_names_type joint_names;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _joint_positions_type;
  _joint_positions_type joint_positions;




  typedef boost::shared_ptr< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> const> ConstPtr;

}; // struct ModelJointsState_

typedef ::pr2_gazebo_plugins::ModelJointsState_<std::allocator<void> > ModelJointsState;

typedef boost::shared_ptr< ::pr2_gazebo_plugins::ModelJointsState > ModelJointsStatePtr;
typedef boost::shared_ptr< ::pr2_gazebo_plugins::ModelJointsState const> ModelJointsStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pr2_gazebo_plugins

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'pr2_gazebo_plugins': ['/home/eeit/roboarm/catkin_ws/src/pr2_gazebo_plugins/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'pr2_msgs': ['/opt/ros/indigo/share/pr2_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f700a74958b6566fae4cd77fbb80ffd4";
  }

  static const char* value(const ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf700a74958b6566fULL;
  static const uint64_t static_value2 = 0xae4cd77fbb80ffd4ULL;
};

template<class ContainerAllocator>
struct DataType< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pr2_gazebo_plugins/ModelJointsState";
  }

  static const char* value(const ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty\n\
string[] joint_names                                     # list of joint names\n\
float64[] joint_positions                                 # list of desired joint positions, should match joint_names\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.model_pose);
      stream.next(m.joint_names);
      stream.next(m.joint_positions);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ModelJointsState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator>& v)
  {
    s << indent << "model_pose[]" << std::endl;
    for (size_t i = 0; i < v.model_pose.size(); ++i)
    {
      s << indent << "  model_pose[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "    ", v.model_pose[i]);
    }
    s << indent << "joint_names[]" << std::endl;
    for (size_t i = 0; i < v.joint_names.size(); ++i)
    {
      s << indent << "  joint_names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.joint_names[i]);
    }
    s << indent << "joint_positions[]" << std::endl;
    for (size_t i = 0; i < v.joint_positions.size(); ++i)
    {
      s << indent << "  joint_positions[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.joint_positions[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PR2_GAZEBO_PLUGINS_MESSAGE_MODELJOINTSSTATE_H
