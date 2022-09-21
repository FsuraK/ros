# include<ros/ros.h>
# include<learing_service/person.h>

bool callback(learing_service::person::Request &req,learing_service::person::Response &rep)
{
    ROS_INFO("service finish");
    rep.result = "okkk";
    return true;
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"person_server");
    ros::NodeHandle n;
    
    ros::ServiceServer person_service = n.advertiseService("/show_person",callback);

    ROS_INFO("Ready to provide service");
    ros::spin();
    
    return 0;

}