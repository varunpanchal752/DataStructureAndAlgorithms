#include<stdio.h>
#define PI 3.1415
int main(){
    printf("Enter angle in degree\n");
    float angle_degree;
    scanf("%f",&angle_degree);
    float angle_radian = angle_degree*PI /180;
    float ans = 1;
    float temp = 1;
    int acc = 5;
    int i ;
    for( i=1;i<=2*acc;i+=2)
    {
        temp =temp*(-1)*angle_radian*angle_radian/(i*(i+1));
        ans= ans+temp;
    }
    printf("cos(%f)=%f\n",angle_degree,ans);
    return 0;
}