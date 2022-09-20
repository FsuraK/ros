# include<ros/ros.h>
# include<geometry_msgs/Twist.h>
# include<std_srvs/Trigger.h>


ros::Publisher turtle_vel_pub;
bool pubCommand = false;

bool callback(std_srvs::Trigger::Request &req,std_srvs::Trigger::Response &res)
{
    pubCommand = !pubCommand;
    ROS_INFO("callback sucess! command = [%s]",pubCommand == true?"yes":"no");

    // response
    res.success = true;
    res.message = "change turtle state...";
    return true;

}

// void publish()

int main(int argc,char ** argv)
{
    ros::init(argc,argv,"turtle_command_server");
    ros::NodeHandle n;

    ros::ServiceServer command_service = n.advertiseService("/turtle_service",callback);
    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    ros::Rate loop_rate(10);
    ROS_INFO("READY!");

    while (ros::ok())
    {
        ros::spinOnce();
        if (pubCommand)
        {
            geometry_msgs::Twist vel;
            vel.linear.x = 0.5;
            vel.angular.z = 0.2;
            turtle_vel_pub.publish(vel);
        }
        loop_rate.sleep();

    }
    return 0;
}