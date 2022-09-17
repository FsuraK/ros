# include <ros/ros.h>
# include "learing_topic/person.h"


int main(int argc,char ** argv)
{
    ros::init(argc,argv,"person_publisher");
    ros::NodeHandle n;
    ros::Publisher person_info_pub = n.advertise<learing_topic::person>("/person_info",10);
    ros::Rate loop_rate(2);

    int count = 0;
    int k = 0;
    while (ros::ok())
    {
        learing_topic::person person_msg;
        person_msg.name = "tom";
        person_msg.age = k;
        person_msg.sex = learing_topic::person::male;

        person_info_pub.publish(person_msg);

        ROS_INFO("pubulish person info:name:%s age:%d sex:%d",
        person_msg.name.c_str(),person_msg.age,person_msg.sex);
        k+=1;
        loop_rate.sleep();
    }


    return 0;
}

