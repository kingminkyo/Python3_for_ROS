## roslaunch <package_name> <launch_file>을 시작으로 알아보는 기본
---
>1. package 파일이란?
---
- ROS는 프로그램을 구성하기 위해 패키지를 사용하는데, 이 프로그램이 포함하는 모든 파일을 패키지로 간주한다.


>구조

- launch file: 실행 파일

- src: 소스 파일(cpp, py)

- CMakeLists.txt: 컴파일을 위한 cmake 규칙

- package.txt: 패키지 정보 및 종속성

- roscd: 쉘에서 패키지 이름이 있는 위치로 경로 이동


    
        roscd <package_name> % 패키지로 경로 이동



---
>2. launch 이란? 
---
- ros launch: ROS 프로그램을 실행시키기 위한 명령어

- 매개 변수 및 remap을 설정하기 위한 태그로 구성됨

>구조

- pkg: 패키지 이름

- type: 파일의 이름 및 확장자(py, cpp)

- name: Node의 이름

- output: 파일의 출력을 print할 채널

---

>3. Package의 생성
---
-  패키지를 생성하기 위해서는 특정 작업 공간에서 작업해야 한다.
- 이 작업 공간을 catkin이라 부른다.
- catkin 작업 공간은 하드 디스크의 디렉토리로 ROS에서 사용할 수 있도록 본인의 ROS 패키지가 있어야 사용 가능하다.

        catkin_ws % 캣킨의 표현


> catkin_ws 디렉토리에서 pkg 생성
- catkin_src 디렉토리로 이동 후 다음과 같은 명령어 입력
- roscd 명령을 통해 catkin의 쉽게 위치를 찾을 수 있다.

    catkin_create_pkg <package_name> <package_dependecies>


> pkg 확인 방법

    rospack list % 전체 리스트 확인
    rospack list | grep my_package % 내가 원하는 이름 필터링
    roscd my_package % 내가 원하는 패키지 위치로 이동
- 이렇게 하면 src 디렉토리를 포함한 패키지 구성 요소들이 생긴 것을 확인할 수 있다.

---
> 4. ROS 프로그램 만들기
---

- 생성된 패키지의 src 디렉토리에서 새로운 py 파일을 만든다.
- 여기서 주의할 점은 새 파일을 만들 때 IDE에서 만드는 방법과 쉘에서 touch 명령으로 만드는 방법이 있는데, 쉘에서 생성 시 실행 권한이 생기지 않으므로 chmod 명령을 써야 하는 번거로움이 있다.


        chmod +x name_of_the_file.py 


>   launch 파일 생성
- pkg 디렉토리에서 launch 디렉토리 및 파일 생성



        roscd my_package
        mkdir launch
        touch launch/my_package_launch_file.launch

- 셸 작업 명령이며 이는 IDE에서도 실행 가능

---
> 5. 노드란 !
---
- ROS에서 만들어지는 일련의 프로그램

        rosnode list 
    - 노드를 확인할 수 있는 명령
    - 이때 py 프로그램이 실행 중이 아니라면 노드 확인이 안 된다.

- 꿀팁: 파이썬 스크립트 상단에 #! 선언을 누락하면 roslaunch 오류가 생김

        rosnode info <node_name>
    실행 중인 노드 정보를 확인하는 명령어

---
> 6. 패키지 컴파일하기
---
- 생성한 ROS 패키지를 동작시키기 위해, 패키지를 Complie해야한다.

> 컴파일 방법
1. catkin make
- 전체 src 디렉토리를 컴파일하며, catkin_ws 디렉토리에서만 발생된다.
- 다른 디렉토리에서 시도하면 작동하지 않음.

        cd ~/catkin_ws
        catkin_make

- 컴파일 후 작업 공간(workspace)을 확보해야 한다.


        catkin_make --only-pkg-with-deps <package_name>
    - 특정 패키지만 컴파일하는 명령


---
>7. 파라미터 서버
---

-  파라미터 서버는 ROS에서 쓰이는 매개변수를 저장하는 디렉토리이다.

        rosparam list
    - 파라미터 서버 확인 방법


        rosparam get /camera/imager_rate
        rosparam set /camera/imager_rate 4.0
        rosparam get /camera/imager_rate

    - imager_rate 파라미터 값을 4로 수정하고 확인하는 과정

---
> 8. Roscore
---

- ROS에 관련된 모든 작업을 위해서, roscore는 동작하고 있어야 한다.
- roscore는 ROS 시스템을 관리하는 메인 프로세스이다.
- 명령어는 'roscore' 간단!

---
> 9. 환경변수 (Environment Variables)
---

- ROS는 리눅스의 환경변수를 사용하여 제대로 작동한다.

        export | grep ROS
        
    - ROS 관련 환경변수 확인 명령


