## Subscribers & Messages 
##### 하루 최소 1코스 힘내자 
---

> ### 개념 정리
- Topic이란
    - node가 정보를 쓰거나 읽을 수 있는 채널
    - 이때 Publisher에서 정보를 발행했으므로 읽을 수 있는 도구가 필요하다.
    - 이것이 바로 Subscriber(구독자)이다!

- Subscriber python script 예시
``` py
#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32 

def callback(msg): 
  print (msg.data) # 매개변수 데이터 출력

rospy.init_node('topic_subscriber') # 노드 생성
sub = rospy.Subscriber('/counter', Int32, callback) # 토픽, 데이터 타입, 출력 함수
rospy.spin()
```

> ### 1. 