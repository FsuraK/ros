# include <ros/ros.h>
# include "learing_topic/person.h"

void callback(const learing_topic::person::ConstPtr& msg)
{
    ROS_INFO("Subscriber INFO:name:%s age:%d sex:%d",msg->name.c_str(),msg->age,msg->sex);
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"person_subscriber");
    ros::NodeHandle n;
    ros::Subscriber person_info_sub = n.subscribe("/person_info",10,callback);
    ros::spin();
    return 0;
}