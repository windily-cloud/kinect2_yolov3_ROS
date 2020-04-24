// Generated by gencpp from file test_topic/person.msg
// DO NOT EDIT!


#ifndef TEST_TOPIC_MESSAGE_PERSON_H
#define TEST_TOPIC_MESSAGE_PERSON_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test_topic
{
template <class ContainerAllocator>
struct person_
{
  typedef person_<ContainerAllocator> Type;

  person_()
    : name()
    , sex(0)
    , age(0)  {
    }
  person_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , sex(0)
    , age(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef uint8_t _sex_type;
  _sex_type sex;

   typedef uint8_t _age_type;
  _age_type age;



  enum {
    unkonw = 0u,
    male = 1u,
    female = 2u,
  };


  typedef boost::shared_ptr< ::test_topic::person_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_topic::person_<ContainerAllocator> const> ConstPtr;

}; // struct person_

typedef ::test_topic::person_<std::allocator<void> > person;

typedef boost::shared_ptr< ::test_topic::person > personPtr;
typedef boost::shared_ptr< ::test_topic::person const> personConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_topic::person_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_topic::person_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_topic

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'test_topic': ['/home/xll/windily/cloud_ws/src/test_topic/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_topic::person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_topic::person_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_topic::person_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_topic::person_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_topic::person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_topic::person_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_topic::person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f523df5f672923005c184b91d515558c";
  }

  static const char* value(const ::test_topic::person_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf523df5f67292300ULL;
  static const uint64_t static_value2 = 0x5c184b91d515558cULL;
};

template<class ContainerAllocator>
struct DataType< ::test_topic::person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_topic/person";
  }

  static const char* value(const ::test_topic::person_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_topic::person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
uint8 sex\n\
uint8 age\n\
\n\
uint8 unkonw=0\n\
uint8 male=1\n\
uint8 female=2\n\
\n\
";
  }

  static const char* value(const ::test_topic::person_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_topic::person_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.sex);
      stream.next(m.age);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct person_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_topic::person_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_topic::person_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "sex: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sex);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_TOPIC_MESSAGE_PERSON_H
