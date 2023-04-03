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


