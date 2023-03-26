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
