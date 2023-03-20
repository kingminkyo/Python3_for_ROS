ros launch: ROS 프로그램을 실행시키기 위한 명령어

roslaunch <package_name> <launch_file>

여기서 package 파일이란?

ROS는 프로그램을 구성하기 위해 패키지를 사용하는데, 이 프로그램이 포함하는 모든 파일을 패키지로 간주한다.


구조

launch file: 실행 파일

src: 소스 파일(cpp, py)

CMakeLists.txt: 컴파일을 위한 cmake 규칙

package.txt 패키지 정보 및 종속성

roscd: 쉘에서 패키지 이름이 있는 위치로 경로 이동

roscd <package_name> 


launch 이란? 실행을 위한 ROS의 파일
매개 변수 및 remap을 설정하기 위한 태그로 구성됨

구조

pkg: 패키지 이름

type: 파일의 이름 및 확장자(py, cpp)

name: Node의 이름

output: 파일의 출력을 print할 채널