#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{

char *data;
struct Node* next;

}Node;

Node *addhead(char *data,Node **head)
{
Node *node = (Node *)malloc(sizeof(Node));
node->data = data;
node->next = *head;
*head = node;
return *head;
}

Node *addtail(char *data,Node **head)
{
Node *node = (Node *)malloc(sizeof(Node));

node->data = data;
node->next = NULL;
if(*head == NULL)
{
    *head = node;

}
else 
{
Node *tail;
tail=*head;
while(tail->next != NULL)
{
tail = tail->next;
}
tail->next = node;
}
return *head;
}



void del(Node**head,char *data)
{
Node *L = *head;
Node *pre = NULL;

while(L->data != data && L != NULL)
{
pre = L; 
L = L->next;
if(L == NULL)
{
    printf("删除失败!\n");
    return;
}
}
if(pre == NULL)
*head = L->next;
else
pre->next = L->next;


free(L);  
return ;
}


void print(Node *head)
{
Node *p = head;
int count = 1;
if(p ==NULL)
return ;
while (p->next != NULL)
{
    printf("%d.  %s\n",count,p->data);
    count++;
    p = p->next;
}
printf("%d.  %s\n",count,p->data);
return ;

}

void serach(Node* head,char *data)
{
Node* p = head;
while(p->data != data)
{

p = p->next;
if(p==NULL)
{
    printf("data is no exist!"); 
    return ;
}
}
if(p->data = data)
{
    printf("data is %s",p->data);
}
return ;
}

void headadd(Node **head,char (*data)[100])
{

for(int i=0;i<100;i++)
{
if(data[i][0] == '\0')
{
    break;
}
Node *p = (Node*)malloc(sizeof(Node)); 
p->data = data[i];
p->next = *head;
*head = p;
}
}

void insert(Node **head,char *data,int position) //自己创建的哦
{
Node *node = (Node *)malloc(sizeof(Node));
Node *p = *head;
Node *prev;
if(position == 1)  //头
{
node->data = data;
node->next = *head;
*head = node ; 
return ;
}
for(int i = 1;i < position;i++)
{
prev = p;
if(p == NULL)
{
    printf("插入失败!\n");
    return ;
}
p = p->next;

}
prev->next = node;
if(p == NULL)  //尾巴
{
node->data = data;
node->next = NULL;
}
node->data = data;
node->next = p;
}

int main()
{
Node *head = NULL;
// addtail("Go is shit!",&head);
// addtail("Python is shit!",&head);
// addhead("JavaScript is good programing!",&head);
// addtail("C+++ is shit!",&head);
// addhead("Java is best programing!!!",&head);
char b[10][100] = {"java","c++","python","javaScript"};
// headadd(&head,b);

// printf("%s\n",head->data);
insert(&head,"周其乐爱吃瓜~~~",1);
insert(&head,"JavaScript is good programing!",1);
insert(&head,"Java is best programing!!!",2);
insert(&head,"C+++ is shit!",4);
// del(&head,"Java is best programing!!!");
// printf("%s\n",(head->next)->data);
// printf("%s\n",((head->next)->next)->data);
// printf("%s\n",(((head->next)->next)->next)->data);
// printf("%s\n",((((head->next)->next)->next)->next)->data);
// serach(head,"Java is best programing!!!");
// char a[3][10]={"nihao","jintian"};
print(head);
return 0;

}