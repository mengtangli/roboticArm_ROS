// Generated by gencpp from file baxter_core_msgs/OpenCameraRequest.msg
// DO NOT EDIT!


#ifndef BAXTER_CORE_MSGS_MESSAGE_OPENCAMERAREQUEST_H
#define BAXTER_CORE_MSGS_MESSAGE_OPENCAMERAREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <baxter_core_msgs/CameraSettings.h>

namespace baxter_core_msgs
{
template <class ContainerAllocator>
struct OpenCameraRequest_
{
  typedef OpenCameraRequest_<ContainerAllocator> Type;

  OpenCameraRequest_()
    : name()
    , settings()  {
    }
  OpenCameraRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , settings(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef  ::baxter_core_msgs::CameraSettings_<ContainerAllocator>  _settings_type;
  _settings_type settings;




  typedef boost::shared_ptr< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> const> ConstPtr;

}; // struct OpenCameraRequest_

typedef ::baxter_core_msgs::OpenCameraRequest_<std::allocator<void> > OpenCameraRequest;

typedef boost::shared_ptr< ::baxter_core_msgs::OpenCameraRequest > OpenCameraRequestPtr;
typedef boost::shared_ptr< ::baxter_core_msgs::OpenCameraRequest const> OpenCameraRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace baxter_core_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'baxter_core_msgs': ['/home/eeit/roboarm/catkin_ws/src/baxter_common/baxter_core_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c4194eee32741c5a98ef8da9666fa6c9";
  }

  static const char* value(const ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc4194eee32741c5aULL;
  static const uint64_t static_value2 = 0x98ef8da9666fa6c9ULL;
};

template<class ContainerAllocator>
struct DataType< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "baxter_core_msgs/OpenCameraRequest";
  }

  static const char* value(const ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string          name\n\
CameraSettings  settings\n\
\n\
================================================================================\n\
MSG: baxter_core_msgs/CameraSettings\n\
int32           width\n\
int32           height\n\
float32         fps\n\
CameraControl[] controls\n\
\n\
================================================================================\n\
MSG: baxter_core_msgs/CameraControl\n\
int32   id\n\
int32   value\n\
\n\
int32 CAMERA_CONTROL_EXPOSURE=100\n\
int32 CAMERA_CONTROL_GAIN=101\n\
int32 CAMERA_CONTROL_WHITE_BALANCE_R=102\n\
int32 CAMERA_CONTROL_WHITE_BALANCE_G=103\n\
int32 CAMERA_CONTROL_WHITE_BALANCE_B=104\n\
int32 CAMERA_CONTROL_WINDOW_X=105\n\
int32 CAMERA_CONTROL_WINDOW_Y=106\n\
int32 CAMERA_CONTROL_FLIP=107\n\
int32 CAMERA_CONTROL_MIRROR=108\n\
int32 CAMERA_CONTROL_RESOLUTION_HALF=109\n\
";
  }

  static const char* value(const ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.settings);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct OpenCameraRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::baxter_core_msgs::OpenCameraRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "settings: ";
    s << std::endl;
    Printer< ::baxter_core_msgs::CameraSettings_<ContainerAllocator> >::stream(s, indent + "  ", v.settings);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BAXTER_CORE_MSGS_MESSAGE_OPENCAMERAREQUEST_H
