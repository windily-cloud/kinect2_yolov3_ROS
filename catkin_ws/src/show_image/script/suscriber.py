#!/usr/bin/env python
# -*- coding: utf-8 -*-
#该例程将订阅/person_info话题，自定义消息类型learning_topic::Person

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge

def personInfoCallback(imgmsg):
    rospy.loginfo("I get the image data!")
    bridge = CvBridge()
    img = bridge.imgmsg_to_cv2(imgmsg, "bgr8")
    cv2.imshow("listener", img)
    cv2.waitKey(3)

def person_subscriber():
    #ROS节点初始化
    rospy.init_node('person_subscriber',anonymous=True)
    #创建一个Subscriber，订阅名为/person_info的topic，注册回调函数personInfoCallback
    rospy.Subscriber("/kinect2/qhd/image_color",Image, personInfoCallback)
    #循环等待回调函数
    rospy.spin()
if __name__ == '__main__':
    person_subscriber()
