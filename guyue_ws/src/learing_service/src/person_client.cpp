# include<ros/ros.h>
# include<learing_service/person.h>
# include <iostream>
using namespace std;


int main(int argc,char** argv)
{
    
    ros::init(argc,argv,"person_client");
    ros::NodeHandle n;
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = n.serviceClient<learing_service::person>("/show_person");

    cout<<"please type your name:";
    string s;
    cin>>s ;
    learing_service::person srv;
    srv.request.name = s;
    srv.request.age =  20;
    srv.request.sex = learing_service::person::Request::male;

    ROS_INFO("call service to show [name:%s age:%d sex:%d]",
    srv.request.name.c_str(),srv.request.age,srv.request.sex);

    person_client.call(srv);

    ROS_INFO("call sucess! name:%s",srv.request.name.c_str());
    return 0;
}