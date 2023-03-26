## Subscribers & Messages 
##### 하루 최소 1코스 힘내자 
---

> ### Subscribers 개요
- Topic이란(복습 차원)
    - node가 정보를 쓰거나 읽을 수 있는 채널
    - 이때 Publisher에서 정보를 발행했으므로 읽을 수 있는 도구가 필요하다.
    - 이것이 바로 Subscriber(구독자)이다!

- Subscriber python script 예시
``` py
#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32 

def callback(msg): #파라미터를 받는 함수 정의
  print (msg.data) # msg 파라미터 내의 값 data 출력

rospy.init_node('topic_subscriber') # 노드 이름 정의
sub = rospy.Subscriber('/counter', Int32, callback) # /counter 토픽을 수신할 Subscriber 객체 만들기
rospy.spin() #루프 형성
```
- Publisher 스크립트와 다른 점
  - callback 함수를 정의한다.
  - 반복 루프를 while문 대신 spin을 사용한다.

---
> ## odom topic 활용 실습 예시
---
- odom topic은 로봇의 주행 거리 측정값을 발행할 수 있는 토픽이다.


- odom topic의 정보
```
user:~$ rostopic info /odom
Type: nav_msgs/Odometry

Publishers:
 * /gazebo (http://2_simulation:38221/)

Subscribers: None
```
- Odometry 메시지를 사용하는 것을 포착! 그렇다면 이 정보도 확인할 수 있다.
``` 
user:~$ rosmsg info nav_msgs/Odometry
std_msgs/Header header
  uint32 seq
  time stamp
  string frame_id
string child_frame_id
geometry_msgs/PoseWithCovariance pose
  geometry_msgs/Pose pose
    geometry_msgs/Point position
      float64 x
      float64 y
      float64 z
    geometry_msgs/Quaternion orientation
      float64 x
      float64 y
      float64 z
      float64 w
  float64[36] covariance
geometry_msgs/TwistWithCovariance twist
  geometry_msgs/Twist twist
    geometry_msgs/Vector3 linear
      float64 x
      float64 y
      float64 z
    geometry_msgs/Vector3 angular
      float64 x
      float64 y
      float64 z
  float64[36] covariance
  ```

