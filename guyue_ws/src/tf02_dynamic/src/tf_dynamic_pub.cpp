# include <ros/ros.h>
# include <turtlesim/Pose.h>
# include <tf2_ros/transform_broadcaster.h>
# include <geometry_msgs/TransformStamped.h>
# include <tf2/LinearMath/Quaternion.h>
/*
发布方：需要知道海龟的位姿信息，转换成相对于窗体到坐标关系并发布。
                  如何获取位姿信息：先启动海龟节点
                  rostopic list----找到要查看的位姿话题
                  rostopic info 话题 ---查看话题info信息，可以看到type：消息
                  rosmsg info 上面看到的type --- msg的具体内容
        话题：/turtle1/pose
        消息：/turtlesim/Pose

流程：    1.头文件、初始化等常规步骤
                 2.创建订阅对象，订阅 /turtle1/pose
                 3.回调函数处理订阅到消息（目前来看，订阅方才需要回调函数）
                     回调函数：将位姿信息转换为坐标相对关系并发布
                 4.spin()
*/
void callback(const turtlesim::Pose::ConstPtr& pose)
{  
    //发布在callback内实现，因为只有我订阅到一个信息，才能发布一个信息
    //这里用了static：否则每次进入回调都会重新创建一个发布对象，不如一直使用同一个
    // 创建的pub类型是使用ros::TransformBroroadcast
    static tf2_ros::TransformBroadcaster pub;

    geometry_msgs::TransformStamped msg;
    msg.header.frame_id = "world";
    msg.header.stamp = ros::Time::now();
    msg.child_frame_id = "turtle1";
    // 坐标系偏移量------从海龟pose中获取
    msg.transform.translation.x = pose->x;
    msg.transform.translation.y = pose->y;
    msg.transform.translation.z = 0; //因为海龟节点是2D的，所以pose中没有z坐标，但tf需要有z，因此给0
    // 坐标系四元数---通过欧拉角获取------欧拉角：（俯仰角、翻转角、另一个角）
    /*
    海龟位姿信息(2D)中只有一个theta角度，这个实际上是z轴的旋转角，2D没有翻转与俯仰
    因此，海龟的欧拉角：  0  0  theta   四元数通过欧拉角转换即可
    使用欧拉角需要# include <tf2/LinearMath/Quaternion.h>
    */
   tf2::Quaternion qtn;
   qtn.setRPY(0,0,pose->theta);
    msg.transform.rotation.x = qtn.getX();
    msg.transform.rotation.x = qtn.getY();
    msg.transform.rotation.x = qtn.getZ();
    msg.transform.rotation.x = qtn.getW();

    // 发布
    pub.sendTransform(msg);
    ROS_INFO("pulish sucess! ");

}
int main(int argc,char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle n;
    // 先订阅海龟的位姿信息---一旦订阅到则进入回调
    ros::Subscriber sub = n.subscribe("/turtle1/pose",100,callback);
    ros::spin();

    return 0 ;
}





