catkin_create_pkg <package_name> <package_dependecies>

- package_dependecies에는 rospy나 roscpp

rospack list | grep my_package

- my_package의 이름을 갖는 패키지의 리스트 나열



## ROS에서 dev와 devel은 각각 다음과 같은 의미를 가집니다.

- dev: dev는 develop의 준말로, ROS 패키지를 개발하기 위한 디렉토리입니다. dev 디렉토리는 보통 src 디렉토리의 하위 디렉토리로 위치합니다. dev 디렉토리에는 패키지의 소스 코드, 빌드 스크립트, 런치 파일 등이 포함됩니다. dev 디렉토리는 패키지를 개발하는 동안에만 사용되고, 패키지를 빌드한 후에는 사용되지 않습니다.

- devel: devel은 development environment의 준말로, ROS 패키지를 빌드한 후에 생성되는 디렉토리입니다. devel 디렉토리는 보통 catkin_make 명령어를 사용하여 빌드된 후에 생성됩니다. devel 디렉토리에는 빌드된 패키지의 실행 파일, 라이브러리, 헤더 파일 등이 포함됩니다. devel 디렉토리는 패키지를 빌드한 후에 사용되며, 패키지를 실행하거나 테스트할 때 사용됩니다.

따라서 dev 디렉토리는 패키지를 개발하는 동안에만 필요하고, devel 디렉토리는 패키지를 빌드한 후에 실행할 때 필요합니다. ROS 패키지를 개발하고 빌드할 때, 보통 dev 디렉토리에 패키지 소스 코드를 작성하고 catkin_make 명령어를 사용하여 패키지를 빌드합니다. 이후에는 devel 디렉토리에 빌드된 패키지 실행 파일 등이 생성되므로, 패키지를 실행하거나 테스트할 때는 source devel/setup.bash 명령어를 사용하여 devel 디렉토리를 활성화해야 합니다.