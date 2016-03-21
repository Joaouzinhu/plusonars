#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

std_msgs::FLoat32 valor_front;
std_msgs::FLoat32 valor_left;
std_msgs::FLoat32 valor_right;
std_msgs::FLoat32 compara_lados;

geometry_msgs::Twist velocidade;

void callback_front(const std_msgs::Float32ConstPtr &msg1)
{
    valor_front.data= msg1->data;
}
void callback_left(const std_msgs::Float32ConstPtr &msg2)
{
    valor_left.data= msg2->data;
}
void callback_right(const std_msgs::Float32ConstPtr &msg3)
{
    valor_right.data= msg3->data;
}
void navegacao()
{
    if((valor_left !=0)||(valor_right !=0))
    {
        
        if(valor_left>valor_right)
            velocidade.angular.z = 0.5;
        if(valor_left<valor_right)
            velocidade.angular.z = -0.5;
        
    }
    
    velocidade.linear.x = 0.5;
    velocidade.angular.z = 0;
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"controlsonar");
    
    ros::NodeHandle node;
    
    ros::Publisher pub_sonar;
    pub_Sonar = node.advertise<geometry_msgs::Twist>("ros_Sonar",1);
    
    ros::Subscriber sub_sonarF = node.subscribe("/vrep/vehicle/frontSonar",1,callback_front);
    ros::Subscriber sub_sonarL = node.subscribe("/vrep/vehicle/leftSonar",1,callback_left);
    ros::Subscriber sub_sonarR = node.subscribe("/vrep/vehicle/rightSonar",1,callback_right);
    
    while(ros::ok())
    {
        
    }
    ros::spin();
}