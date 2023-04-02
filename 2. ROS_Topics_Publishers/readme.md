 ## Topic: Publishers !
##### 즐거운 ROS공부 ^^;
---
> ## ○ 공부할 내용
---
1. ROS topic이 무엇이고, 어떻게 관리하는지
2. Publisher가 무엇이고, 어떻게 생성하는지
3. Topic message가 무엇이고, 어떻게 동작하는지
---
> ## 1. Topic Publisher
---
우선 아래 파이썬 스크립트를 살펴보자
``` py
#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32

rospy.init_node('topic_publisher')
pub = rospy.Publisher('/counter', Int32, queue_size=1)
rate = rospy.Rate(2)
count = Int32()
count.data = 0

while not rospy.is_shutdown():
    pub.publish(count)
    count.data += 1
    rate.sleep()
```

- pub이라는 Publisher 변수를 만들고, 이 date를 1씩 무한히 증가하는 정수로 게시했다.
- 이 코드가 로봇을 무언가 구동시켜주지는 않는다..
- 여기서 이해해야 하는 점은 Topic은 하나의 파이프의 개념이고, Node는 Topic을 사용하여 다른 Node에게 정보를 발행(Publish)한다는 점이다.

```
$ rostopic list | grep  '/counter'
$ rostopic info /counter
```
- 위 두 명령을 통해 각각 node의 나열, 정보를 확인할 수 있다.
```
$ rostopic echo /counter
```
- 이 명령을 통해 topic의 output을 실시간으로 확인 가능하다.
```
$ rostopic echo <topic_name> -n1
```
- 이 명령을 통해 마지막 메시지만 받을 수 있다.
- Data가 많아 불편할 수 있는 경우 사용 

```
user:~$ rostopic info /counter
Type: std_msgs/Int32

Publishers:
 * /topic_publisher (http://2_xterm:45847/)

Subscribers: None
```
- 위 코드에서 /counter 토픽의 메시지 타입을 Int32, 노드명을 /topic_publisher라고 해줬는데 이를 rostopic info 명령으로 확인 가능



> 팁

    source devel/setup.bash
- 패키지 생성 등 무언가 변할 경우 쉘 새로고침 명령어!
 

---
> ## Messages 란?
---
- 위 사례에서 Topic을 통해 message를 처리했다는 것을 볼 수 있다.
- 위에서는 정수 타입(Int32) 메시지만 있었으나, 실제 ROS에서는 다양한 타입의 메시지를 발행한다.
- 메시지는 .msg 파일로 정의되며 패키지 디렉토리 내부에 있다.

```
$ rosmsg show <message>
```
- 위 명령을 통해 메시지 정보를 볼 수 있다!
```
$ rosmsg show std_msgs/Int32
int32 data
```
```
user:/opt/ros/noetic/share/std_msgs/msg$ ls
Bool.msg            Float32MultiArray.msg  Int64.msg                UInt16.msg
Byte.msg            Float64.msg            Int64MultiArray.msg      UInt16MultiArray.msg
ByteMultiArray.msg  Float64MultiArray.msg  Int8.msg                 UInt32.msg
Char.msg            Header.msg             Int8MultiArray.msg       UInt32MultiArray.msg
ColorRGBA.msg       Int16.msg              MultiArrayDimension.msg  UInt64.msg
Duration.msg        Int16MultiArray.msg    MultiArrayLayout.msg     UInt64MultiArray.msg
Empty.msg           Int32.msg              String.msg               UInt8.msg
Float32.msg         Int32MultiArray.msg    Time.msg                 UInt8MultiArray.msg
```
- ROS에서는 다양한 메시지가 제공된다.
---
> ## cmd_vel Topic 및 Twist msg 사용 실습
---
- cmd_vel이란 로봇을 이동하는데 사용되는 토픽이다.

```
user:~$ rostopic info /cmd_velType: geometry_msgs/Twist

Publishers: None

Subscribers:
 * /gazebo (http://2_simulation:38221/)
```

- 여기서 cmd_vel은 메시지 타입으로 Twist를 사용하는 것을 볼 수 있는데, Twist의 정보를 보자

```
user:~$ rosmsg info geometry_msgs/Twist
geometry_msgs/Vector3 linear
  float64 x
  float64 y
  float64 z
geometry_msgs/Vector3 angular
  float64 x
  float64 y
  float64 z
```
- 여기서 실습에 사용할 로봇은 x축 직선운동, z축 각도운동을 한다고 가정한다.


```
# move_lobot.launch파일의 구성

<launch>
    <node pkg="exercise_31" type="move_robot.py" name="move_robot_node" output="screen" />
</launch>
```
- 패키지명/스크립트/노드명/출력 형태로 구성된 launch 파일 복습

```py
#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

rospy.init_node('move_robot_node')
pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
rate = rospy.Rate(2)
move = Twist()
move.linear.x = 0.5 #Move the robot with a linear velocity in the x axis
move.angular.z = 0.5 #Move the with an angular velocity in the z axis

while not rospy.is_shutdown(): 
  pub.publish(move)
  rate.sleep()
```
- Twist msg에서 각 값의 이동 단위는 m/s이다
- 이 스크립트의 결과는 로봇이 원운동을 한다.