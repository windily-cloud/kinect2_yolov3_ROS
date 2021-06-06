#coding=utf-8
import cv2
import motion_roadmap as mr
import numpy as np

# 图像路径，将 USER_NAME 改为计算机用户名
image_path = "./test.bmp"
# 利用cv2读取图像
img = cv2.imread(image_path)
# 当图像过大时，调整尺寸。建议对PRM或RRT: 500*500; 对人工势场法：100*100
img = cv2.resize(img,(500,500))
# 实例化 MotionRoadmap 对象，将图像img作为初始化参数传入
demo_1 = mr.MotionRoadmap(img)

# 设置起点和终点，为numpy.mat格式
demo_1.point_start = np.mat([5, 5])
demo_1.point_goal = np.mat([495, 495])

# 人工势场法,为了快速建立势场图，先调整图像尺寸
img = cv2.resize(img,(100,100))
demo_1.pf_planning()