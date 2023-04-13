```
#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16

def motor():
    rospy.init_node('motor', anonymous=True)
    pub = rospy.Publisher('xycar_motor', Int16, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        speed = 70
        angle = 90
        pub.publish(angle)
        pub.publish(speed)
        rate.sleep()

if __name__ == '__main__':
    try:
        motor()
    except rospy.ROSInterruptException:
        pass

```
Arduino 코드:

c++
Copy code
#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;
int angle = 90, speed = 70;

void motor_cb(const std_msgs::Int16& cmd_msg)
{
    if (cmd_msg.data < -50) cmd_msg.data = -50;
    if (cmd_msg.data > 50) cmd_msg.data = 50;

    if (cmd_msg.data <= 0) {
        speed = 1000 + (cmd_msg.data * -20);
        angle = 90;
    } else {
        speed = 70;
        angle = 90 - (cmd_msg.data * 1.8);
    }
}

ros::Subscriber<std_msgs::Int16> sub("xycar_motor", motor_cb);

void setup()
{
    pinMode(2, OUTPUT);
    nh.initNode();
    nh.subscribe(sub);
}

void loop()
{
    digitalWrite(2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(2, LOW);
    delayMicroseconds(20000 - speed);
    nh.spinOnce();
}