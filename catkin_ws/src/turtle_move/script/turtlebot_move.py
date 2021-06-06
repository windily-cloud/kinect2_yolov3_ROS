#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
#import cv2
#from cv_bridge import CvBridge
#from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from darknet_ros_msgs.msg import BoundingBoxes
'''
def object_position(bounding_box):
    rospy.loginfo("working")
    print(bounding_box.bounding_boxes[0])

rospy.init_node('TurtlebotTracker',anonymous=True)
bounding_boxes_topic = "/darknet_ros/bounding_boxes"
try:
    bounding_boxes_suscriber = rospy.Subscriber(bounding_boxes_topic, BoundingBoxes, object_position)
    rospy.spin()
except:
    print("I dont know!!!")

'''
class TurtlebotTracker():
    def __init__(self):
        self.angle_speed = 0.5
        self.goforwad_speed = 0
        self.xcenter = 490
        self.ycenter = 270
        self.color_topic = "/kinect2/qhd/image_color"
        self.depth_topic = "/kinect2/sd/image_depth"
        self.bounding_boxes_topic = "/darknet_ros/bounding_boxes"
        rospy.init_node('TurtlebotTracker',anonymous=True)

    def listener(self):
        bounding_boxes_suscriber = rospy.Subscriber(self.bounding_boxes_topic, BoundingBoxes, self.object_position)
        rospy.spin()

    def object_position(self, bounding_box):
        rospy.loginfo("working")
        bounding_messages_list = bounding_box.bounding_boxes
        for item in bounding_messages_list:
            #print(item)
            if str(item).split("\n")[6][7:]=="\"person\"":
                self.xmin = int(str(item).split("\n")[1][6:])
                self.ymin = int(str(item).split("\n")[2][6:])
                self.xmax = int(str(item).split("\n")[3][6:])
                self.ymax = int(str(item).split("\n")[4][6:])
                print(self.xmin,self.xmax)
        self.tracker()
    
    def tracker(self):
        rospy.loginfo("traker")
        control_pub = rospy.Publisher("/mobile_base/commands/velocity", Twist, queue_size=10)
        speed = Twist()
        rate = rospy.Rate(2)
        count =0
        while count!=3:
            print(self.xmin,self.xmax)
            speed.linear.x = self.goforwad_speed
            if (self.xmin + self.xmax)/2 < self.xcenter-20:
                speed.angular.z = self.angle_speed
            elif (self.xmin + self.xmax)/2 > self.xcenter+20:
                speed.angular.z = -self.angle_speed
            else:
                speed.angular.z = 0
            control_pub.publish(speed)
            rate.sleep()
            count += 1

if __name__ == "__main__":
    handle = TurtlebotTracker()
    handle.listener()
    #handle.tracker()
    