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
```py
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
- Data가 많아 불편할 수 있는 경우 사용 asdasdasdas


> 팁

    source devel/setup.bash
- 패키지 생성 등 무언가 변할 경우 쉘 새로고침 명령어!
 

---
> ## Messages 란?
---
- 위 사례에서 Topic을 통해 message를 발행했다.
- 위에서는 정수 타입(Int32) 메시지만 있었으나, 실제 ROS에서는 다양한 타입의 메시지를 발행한다.
- 메시지는 .msg 파일로 정의되며 패키지 디렉토리 내부에 있다.

```
$ rosmsg show <message>
```
- 위 명령을 통해 메시지 정보를 볼 수 있다!

---
cmd_vel에 대한 실습 내용 추가 예정

