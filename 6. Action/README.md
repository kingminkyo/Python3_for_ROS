## ROS Action에 대하여
---
> 복습

※ 늘 복습이 굉장히 중요하다 느낀다. ROS에서는 숙지해야 할 명령어가 많고 각 노드간의 역할, 구조를 파악하고 있어야 에러 없이 Execute될 수 있기 때문이다.

```
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
위 command를 해석해보자

- rosrun
    - Launch 파일 없이 ROS 프로그램을 실행할 수 있게 해주는 명령어

- teleop_twist_keyboard
    - ROS 프로그램이 있는 패키지의 이름

- teleop_twist_keyboard.py
    - 파이썬 실행 파일

---
> ## Action 이란?
---
- 서비스와 유사하게, 액션을 호출 시, 다른 노드에서 제공하는 어떤 기능을 받아온다.
- 다른 점은 서비스는 다른 서비스가 끝날 때까지 기다리지만, 액션은 다른 액션이 끝날 때까지 기다리지 않는다.

- 따라서 액션(Action) 은 다른 노드에 대한 비동기 호출이라 볼 수 있다.
---
> ## Action의 구조
---
- Action을 실행 후 rostopic list를 통해 확인 시 5개의 특정 Topic을 확인할 수 있다

아래는 예시
```
...
/ardrone_action_server/cancel
/ardrone_action_server/feedback
/ardrone_action_server/goal
/ardrone_action_server/result
/ardrone_action_server/status
...
```
---
> ## Action Server 호출하기
---
- Action Server를 호출한다는 점은 메시지를 보낸다는 것을 의미한다. 
- Action Server의 메시지는 goal, result, feedback 3개의 부분으로 나누어진다.

- 모든 Action 메시지는 패키지 내부 action 디렉토리에 정의된다.
ㅎ

확인 예시
```
roscd ardrone_as/action ; cat Ardrone.action
```
```
#goal for the drone
int32 nseconds  # the number of seconds the drone will be taking pictures
---
#result
sensor_msgs/CompressedImage[] allPictures # an array containing all the pictures taken along the nseconds
---
#feedback
sensor_msgs/CompressedImage lastImage  # the last image taken
```

※ 특이 사항
1.  Action은 Feedback을 제공한다
- feedback message는 어떻게 액션이 동작하는지 요청된 작업의 상태를 호출자에게 알리기 위해 주기적으로 만들어지는 메시지이다.


---
> ## Action Server python code 예시 분석

---
``` py
#! /usr/bin/env python
```
- 스크립트 실행을 위한 셔뱅(shebang) 코드
``` py
import rospy
import actionlib

from actionlib_tutorials.msg import FibonacciFeedback, FibonacciResult, FibonacciAction
```
- ROS에서 기본 제공하는 actionlib_tutorials 패키지에서 액션 메시지인 Fibonacci.action을 불러옴
```py
class FibonacciClass(object):

  _feedback = FibonacciFeedback()
  _result   = FibonacciResult()

```

- feedback과 result를 발행하기 위한 메시지 객체 생성

```py
  def __init__(self):
    self._as = actionlib.SimpleActionServer("fibonacci_as", FibonacciAction, self.goal_callback, False)
    self._as.start()
```

- 생성자에서 fibonacci_as라 불리는 액션 서버 생성
- 메시지로는 FibonacciAction 사용
- goal_callback이라는 콜백함수 사용(함수 내용 하단 정의)



```py

  def goal_callback(self, goal):
    r = rospy.Rate(1)
    success = True

    self._feedback.sequence = []
    self._feedback.sequence.append(0)
    self._feedback.sequence.append(1)
    

    rospy.loginfo('"fibonacci_as": Executing, creating fibonacci sequence of order %i with seeds %i, %i' % ( goal.order, self._feedback.sequence[0], self._feedback.sequence[1]))
    
    fibonacciOrder = goal.order
```
- 액션 서버가 호출되면 생성되는 콜백함수
- 피보나치 계산을 수행하는 역할
- 과정을 액션 서버 노드에 반환한다.

- 이 구간에서 피보나치 시퀀스를 초기화하고, 앞으로 서버에서 계산할 데이터를 사용자에게 보여질 수 있도록 print함


```py
    for i in range(1, fibonacciOrder):
      if self._as.is_preempt_requested():
        rospy.loginfo('The goal has been cancelled/preempted')

        self._as.set_preempted()
        success = False
        break

```
- action client에서 받은 값까지 계산하도록 loop 수행
- goal이 중단되면 메시지 출력과 함께 loop 중단

``` py
      # builds the next feedback msg to be sent
      self._feedback.sequence.append(self._feedback.sequence[i] + self._feedback.sequence[i-1])
      # publish the feedback
      self._as.publish_feedback(self._feedback)
      # the sequence is computed at 1 Hz frequency
      r.sleep()
    

```
- 피보나치 계산 수행
```py

    if success:
      self._result.sequence = self._feedback.sequence
      rospy.loginfo('Succeeded calculating the Fibonacci of order %i' % fibonacciOrder )
      self._as.set_succeeded(self._result)
```
- 계산이 성공적으로 마무리 되면 result에 계산한 값을 넣고 결과를 발행한다.


```py
if __name__ == '__main__':
  rospy.init_node('fibonacci')
  FibonacciClass()
  rospy.spin()
```
- 메인 함수



---
> ## Action message 정의 시 CMakeLists.txt 수정 사항
---
○ 패키지 내의 CMakeLists.txt에서 다음 4개 기능을 수정하여야 한다.

1. find_package()
```
find_package(catkin REQUIRED COMPONENTS
      # your packages are listed here
      actionlib_msgs
)
```
2. add_action_files() 
```
add_action_files(
      FILES
      Name.action
)
```
3. generate_messages()
```
generate_messages(
      DEPENDENCIES
      actionlib_msgs 
      # Your packages go here
)
```
4. catkin_package()
```
catkin_package(
      CATKIN_DEPENDS
      rospy
      # Your package dependencies go here
)
```


---
> package.xml 수정 사항
- message를 컴파일하기 위한 모든 패키지에 대한 내용을 정의해야 한다.

- .action 파일에서 다른 패키지에 정의된 메시지를 사용할 때 이 내용을 첨부해야 한다.
- 예를 들어 nav_msgs/Odomoetry 메시지를 사용한다면 아래와 같이 정의한다.

```
<build_depend>nav_msgs<build_depend>
```

- 패키지 내 프로그램 실행을 위해 다른 패키지가 필요하다면, 다음과 같이 정의한다.

```
<build_export_depend>nav_msgs<build_export_depend>
<exec_depend>nav_msgs<exec_depend>
```
- 자체 액션 메시지를 만드는 경우 다음 내용을 정의한다.

```
<build_depend>actionlib_msgs</build_depend>
```
- 파이썬을 스크립트로 사용하는 경우 다음 내용을 정의한다.
```
<build_export_depend>rospy<build_export_depend>
<exec_depend>rospy<exec_depend>
```

- 위와 같은 수정이 끝난 후 아래와 같은 명령어를 사용하여 빌드해줘야 한다.

```
$ catkin_make
$ source devel/setup.bash
```

