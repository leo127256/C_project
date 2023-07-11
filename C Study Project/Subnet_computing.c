#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int main()
{
int n1,n2,n3,n4,mask,mask_n4,mask_n3;
int Office[100];
memset(Office,0,sizeof(Office));
int i,k,sum=0;
int scope;
bool find=true;
unsigned int count = 0;
printf("请输入1~8位的数字:  ");
scanf("%d",&n1);
printf("请输入9~16位的数字:  ");
scanf("%d",&n2);
printf("请输入17~24位的数字:  ");
scanf("%d",&n3);
printf("请输入25~32位的数字:  ");
scanf("%d",&n4);
fprintf(stdout,"请输入要规划多少个部门来使用这段IP:  ");
fscanf(stdin,"%d",&count);
for(int i = 0,l = count;i < count;i++,l--)
{

printf("[%c]部门所需的ip地址数量:  ",65 + count - l);
scanf("%d",&Office[i]);

}
// printf("A部门所需的ip地址数量: ");
// scanf("%d",&Office[0]);
// printf("B部门所需的ip地址数量: ");
// scanf("%d",&Office[1]);
// printf("C部门所需的ip地址数量: ");
// scanf("%d",&Office[2]);
// printf("D部门所需的ip地址数量: ");
// scanf("%d",&Office[3]);
// printf("所需的ip的子网掩码: ");
// scanf("%d",&mask);
int max = Office[0],t;
for(i = 0;Office[i] != 0;i++)
for(k = i+1;Office[k] != 0;k++)
{
 if(Office[i]<Office[k])
{
max = Office[k];
Office[k] = Office[i];
Office[i] = max;

}


} //先规划利用最多ip地址的部门
// for(i=0;i<4;i++)
// printf("%d",Office[i]);

for(i = 0;Office[i] != 0;i++)
{
for(k = 1;k < 33;k++)
{
  if(pow(2,k) >= (Office[i]+2))
 {  
    mask = 32-k;  //根据次方来决定分了多少位确定子网掩码位数
    sum++;
    printf("此部门需要%d个IP地址。\n",Office[i]);
    printf("第%d个子网的初始地址是: %d.%d.%d.%d/%d    \t",sum,n1,n2,n3,n4,mask);
    printf("第%d个子网的第一个可用地址是: %d.%d.%d.%d/%d    \t",sum,n1,n2,n3,n4+1,mask);
    scope = pow(2,k); //取值范围scope 英语牢记还是不行那备注吧
    n4 = scope+n4; 
   
    while(n4>=256 || n1>=256 || n2>=256 || n3>=256)
    {
     if(n4 >= 256) {n4 = n4-256;
     n3++;
     }
     if(n3 >= 256) {n3 = n3-256;
     n2++;
     }
     if(n2 >= 256) {n2 = n2-256;
     n1++;
     }
     if(n1 >= 256) 
     {  find = false;
        break;
     } //第一段八位二进制如果计算出来是256是绝对不可能的
    
    }
    if (n4-1 == -1)  //避免256是最后八位的情况
   { mask_n4 = 255;
     mask_n3 = n3-1; //按上面计算n4叠加等于0那必然n3加一但是这种情况是分了126以上到253的，是不会加一的。
     printf("第%d个子网的广播地址是: %d.%d.%d.%d/%d \n",sum,n1,n2,mask_n3,mask_n4,mask);
   }
    else
    printf("第%d个子网的广播地址是: %d.%d.%d.%d/%d \n",sum,n1,n2,n3,n4-1,mask);
     break;

    
 }
    if(!find)
    printf("\n你输入的IP地址可能有误,请仔细查看重新输入!\n");

 
}
}
}