#!/usr/bin/env python
# -*- coding: utf-8 -*-
#该例程将发布/person_info话题，自定义消息类型learning_topic::Person

import rospy
from test_topic.msg import person

def velocity_publisher():
    #ROS节点初始化
    rospy.init_node('publisher',anonymous=True)
    #创建一个Publisher，发布名为/person_info的topic,消息类型为learning_topic::Person,队列长度为10
    person_info_pub=rospy.Publisher('/person_info',person,queue_size=10)
    #设置循环频率
    rate=rospy.Rate(10)
    while not rospy.is_shutdown():
        #初始化learning_topic::Peson类型的消息
        person_msg=person()
        person_msg.name="ZhangJian";
        person_msg.age=20;
        person_msg.sex=person.male;
        #发布消息
        person_info_pub.publish(person_msg)
        rospy.loginfo("Publish person message[%s,%d,%d]",person_msg.name,person_msg.age,person_msg.sex)
        #按照循环频率延时
        rate.sleep()
if __name__ == '__main__':
    try:
        velocity_publisher()
    except rospy.ROSInteruptException:
        pass
