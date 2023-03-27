## Service in ROS(Client)
---
- 배우는 내용
1. 서비스란
2. 로봇의 서비스 관리 방법
3. 서비스 호출 방법
---
> ## 1. Topic과 Service, Action의 비교
---

- 레이저 센서가 있는 이동식 얼굴 인식 로봇이 있다고 가정해보자. 이때 로봇의 구성 요소는 다음과 같다.

    1. 레이저 센서 (Topic)
    2. 얼굴 인식 시스템 (Service)
    3. 네비게이션 시스템 (Action)

- Topic을 통해 레이저 센서로 값을 받아들이고 Service를 통해 이를 얼굴과 같은 특정 객체로 특정할 수 있다.
- 이때 Action을 통해 네비게이션 시스템은 로봇이 움직이기 위한 신호를 제공한다.

- 또한 Action은 목표 값까지에 대한 이동 과정의 피드백을 제공한다.

---
정리하자면
- Topic은 센서로부터 값을 받기 위해 사용
- Service는 받은 값을 가공(얼굴을 통해 이름 판정 등)하기 위해 사용(동기식)
- Action은 위 신호를 바탕으로 로봇을 움직이기 위해 사용(비동기식)


---

> ## 2. Service의 사용
---

- Service의 정보 확인 방법
```
user:~$ rosservice info /execute_trajectory
Node: /iri_wam_reproduce_trajectory
URI: rosrpc://1_xterm:37769
Type: iri_wam_reproduce_trajectory/ExecTraj
Args: file
```
- Node: Service를 제공하는 노드명

- Type: Service에서 사용하는 Message의 종류, 패키지명(pkg)/파일명(.msg)으로 구성된다.

- Args: 런타임 동안 노드나 launch 파일로 전달되는 어떠한 값을 나타낸다.

    - Argument(인수)는 Command line, launch file, ROS Parameter server등을 통해 노드나 launch file로 전달될 수 있다. 인수의 변경으로 소스 코드나 노드를 컴파일 할 필요 없이, 노드의 동작을 쉽게 수정할 수 있다. (Argument의 강력한 유연성!)


---
> 이해를 위한 실습 예시
1. launch 파일 실행
```
$ roslaunch iri_wam_aff_demo start_demo.launch
```
2. 이때 위 launch file은 2개의 node를 실행한다.
- /iri_wam_reproduce_trajectory
- /iri_wam_aff_demo

3. 설명
- 위에서 첫번째 노드는 /execute_trajectory service를 제공한다.
- 두번째 노드는 위에서 제공한 service를 호출한다.
- service가 호출될 때, 로봇은 무언가 이동을 시행한다.
---
왜 위와같이 설명하는가? start_demo.launch를 분석해보자

```
$ roscd iri_wam_aff_demo
$ cd launch/
$ cat start_demo.launch
```
※ roscd는 굉장히 강력한 기능이다! 위의 명령어를 통해 패키지가 있는 곳으로 이동할 수 있다. (패키지 이름 입력 필요) 

실행 결과는 다음과 같다.

``` 
<launch>

  <include file="$(find iri_wam_reproduce_trajectory)/launch/start_service.launch"/>

# launch file 실행 시 start_service.launch라는 다른 launch file도 호출한다.

# 지정된 패키지의 경로를 찾기 위해 특수한 명령어(find)를 사용했다.

  <node pkg ="iri_wam_aff_demo"
        type="iri_wam_aff_demo_node"
        name="iri_wam_aff_demo"
        output="screen">
  </node>

# 이 부분은 node를 실행하기 위함이다. 이는 로봇을 움직이기 위해 /execute_trajectory service를 호출한다.

</launch>
```
---
> Command를 통해 service 수동 호출
```
$ rosservice call /the_service_name TAB-TAB
```

- 여기서 TAB TAB은 Service message의 구조를 자동완성 시켜준다. 구조 내부에 값만 넣으면 된다.

---

> 추가 실습
1. roslaunch를 실행하고
```
$ roslaunch trajectory_by_name start_service.launch
```
2. service를 호출하면 다음과 같은 결과를 받을 수 있다.

```
$ rosservice call /trajectory_by_name "traj_name: 'get_food'"
success: True
status_message: "Successfully executed trajectory"
```
왜 이런 결과가 나오는지 한번 봅시다.

- launch file 분석
```
user:~$ roscd trajectory_by_name
user:/home/simulations/public_sim_ws/src/all/iri_wam/trajectory_by_name$ cdlaunch
user:/home/simulations/public_sim_ws/src/all/iri_wam/trajectory_by_name/launch$ ls start_service.launch
user:/home/simulations/public_sim_ws/src/all/iri_wam/trajectory_by_name/launch
$ cat start_service.launch
<launch>

    <include file="$(find iri_wam_reproduce_trajectory)/launch/start_service.launch" />

    <node pkg="trajectory_by_name" type="traj_by_name.py" name="traj_by_name_node" output="screen" />

</launch>
```
- 분석 결과
1. reproduce pkg의 start_service.launch를 실행하는 것을 확인
2. traj_by_name.py 스크립트를 실행

- 그렇다면 traj_by_name.py의 구조는?
```py
#! /usr/bin/env python

import rospy
import rospkg
from trajectory_by_name_srv.srv import TrajByName, TrajByNameResponse
from iri_wam_reproduce_trajectory.srv import ExecTraj, ExecTrajRequest

def my_callback(request):
    rospy.wait_for_service('/execute_trajectory')
    execute_trajectory_service_client = rospy.ServiceProxy('/execute_trajectory', ExecTraj) # Create the connection to the service
    execute_trajectory_request_object = ExecTrajRequest()
    rospack = rospkg.RosPack()
    trajectory_file_path = rospack.get_path('iri_wam_reproduce_trajectory')+ "/config/" + request.traj_name + ".txt"
    execute_trajectory_request_object.file = trajectory_file_path # Fill the variable file of this object with the desired file path
    result = execute_trajectory_service_client(execute_trajectory_request_object)
    response = TrajByNameResponse()
    response.success = True
    response.status_message = "Successfully executed trajectory"
    return response

rospy.init_node('traj_by_name_node')
my_service = rospy.Service('/trajectory_by_name', TrajByName , my_callback)# create the Service called my_service with the defined callback
rospy.spin() # maintain the service open.
```
