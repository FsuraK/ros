前面无论是给海龟发布Twist消息，还是订阅海龟的位置Pose消息，但这是事先定义好的消息（如：位置），如果需要使用其他消息，比如，海龟的角度等等...需要自己定义，这就是话题消息的存在意义。

ros::init(argc,argv,"person_publisher")
其中，"person_publisher"是节点名称，该句初始化告诉rosMaster，向其注册。当收发双方通过master建立联系后，则不再需要master，可以直接联系。

ros::NodeHandle n
创建句柄，句柄是来管理节点资源的。python中不需要创建节点句柄。

ros::Publisher person_info_pub = n.advertise<learing_topic::person>("/person_info",10,latch：可选)
其中，person_info_pub是发布者，learing_topic::person是发布的消息的数据类型，然后，向/person_info中发布话题，10是队列长度。latch是可选当，bool类型，默认为false，当为true时，表示:保留publisher发布的最后一条消息/数据，每当下一个订阅者订阅到发布者时，会将这条数据发送给订阅者，任意一个新连接的订阅者，都会接收到这个数据。

自定义头文件：
在include后会有个/的文件夹，右键新建.h文件，此外，如果其他cpp文件调用了此头文件，还需要在cmakelist中如下位置，将include解除注释：
inlude_directories(
include
  ${catkin_INCLUDE_DIRS}
)

设计源文件：赵虚左 p143





