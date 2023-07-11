#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 100
typedef struct stu
{
    char name[10];
    int num;
}STU;

STU* sort(STU* form,int size)
{
for(int k = 0;k < size;k++)
{
    int j,i;
    for(int i = 0;i < size - 1;i++)
    {
        STU max = form[0];
        for(int j = i+1;j < size;j++)
        {
              if(form[j].num > form[i].num)
        {
            int t = form[i].num;
            char y[10];
            for(int w = 0;w < sizeof(form[i].name);w++)
            {
                y[w] = form[i].name[w];
            }
             
            form[i].num = form[j].num;
            strcpy(form[i].name,form[j].name);
            form[j].num = t;
            strcpy(form[j].name,y);
            max = form[i];

        } 
        }
      

    }
}

return form;
}


int main()
{
int l;
STU* form = (STU* )malloc(sizeof(STU) * N);
printf("请输入该学生的名字和分数：\n");
for(l = 0;;l++)
{
    int a;
    a = scanf("%s%d",form[l].name,&(form[l].num));
    if(a == -1) break;
}
STU* q = sort(form,l);
for(int i = 0,count = 1;i < l;i++,count++)
{
    printf("第%d名  %s: %d  \n",count,q->name,q->num);
    ++q;
}
}