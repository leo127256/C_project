#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
int The_Position_of_Chess_add(int x,int y)  //判断玩家的棋子位置
{
    if(x == 1 && y == 1)
    {
        return 24;
    }
    else if (x == 1 && y == 2)
    {
        return 30;
    }
    else if (x == 1 && y == 3)
    {
        return 36;
    }
    else if (x == 2 && y == 1)
    {
        return 64;
    }
    else if (x == 2 && y == 2)
    {
        return 70;
    }
    else if (x == 2 && y == 3)
    {
        return 76;
    }
    else if (x == 3 && y == 1)
    {
        return 104;
    }
    else if (x == 3 && y == 2)
    {
        return 110;
    }
    else if (x == 3 && y == 3)
    {
        return 116;
    }
}

int Victory_Rules(char player1_chess[9][3],char player2_chess[9][3])  //游戏机制
{
//规则1
    for(int i = 0;i < 7;i++)
    {
        if(player1_chess[i][0] == player1_chess[i+1][0] && player1_chess[i+1][0] == player1_chess[i+2][0])
        {
            if(player1_chess[i][1] + 1 == player1_chess[i+1][1] && player1_chess[i+1][1] + 1 ==player1_chess[i+2][1])
            {
                return 10;
            }
        }
    }

    for(int i = 0;i < 7;i++)
    {
        if(player2_chess[i][0] == player2_chess[i+1][0] && player2_chess[i+1][0] == player2_chess[i+2][0])
        {
            if(player2_chess[i][1] + 1 == player2_chess[i+1][1] && player2_chess[i+1][1] + 1 ==player2_chess[i+2][1])
            {
                return 0;
            }
        }
    }
//规则2
int mark1 = 0;
int mark2 = 0;
int mark3 = 0;
int mark4 = 0;
int mark5 = 0;
int mark6 = 0;

for(int i = 0;i < 9;i++)
{
    if(player1_chess[i][1] == '1')
        mark1++;
    if(player1_chess[i][1] == '2')
        mark2++;    
    if(player1_chess[i][1] == '3')
        mark3++;
    if(player2_chess[i][1] == '1')
        mark4++;
    if(player2_chess[i][1] == '2')
        mark5++;
    if(player2_chess[i][1] == '3')
        mark6++;
}
if(mark1 == 3 || mark2 == 3 || mark3 == 3)
    return 10;
if(mark4 == 3 || mark5 == 3 || mark6 == 3)
    return 0;
//规则3
for(int i = 0;i < 9;i++)
{
    if(strcmp(player1_chess[i],"11") == 0)
        for(int k = 0;k < 9;k++)
            if(strcmp(player1_chess[k],"22") == 0)
                for(int j = 0;j < 9;j++)
                    if(strcmp(player1_chess[j],"33") == 0)
                        return 10;
    if (strcmp(player1_chess[i],"13") == 0)
        for(int k = 0;k < 9;k++)
            if(strcmp(player1_chess[k],"22") == 0)
                for(int j = 0;j < 9;j++)
                    if(strcmp(player1_chess[j],"31") == 0)
                        return 10;
    if(strcmp(player2_chess[i],"11") == 0)
        for(int k = 0;k < 9;k++)
            if(strcmp(player2_chess[k],"22") == 0)
                for(int j = 0;j < 9;j++)
                    if(strcmp(player2_chess[j],"33") == 0)
                        return 0;
    if(strcmp(player2_chess[i],"13") == 0)
        for(int k = 0;k < 9;k++)
            if(strcmp(player2_chess[k],"22") == 0)
                for(int j = 0;j < 9;j++)
                    if(strcmp(player2_chess[j],"31") == 0)
                        return 0;
}
//平局 
int count = 0;
for(int i = 0;i < 9;i++)
{
    if(player1_chess[i][0] != '\0')
        count++;
    if(player2_chess[i][0] != '\0')
        count++;
    if(count == 9)
        return 11;
}
}

int determine(int *a,int *b)  //是否输入x,y有误
{
unsigned int x,y;
if(*a > 3 || *a <= 0 || *b <= 0 || *b > 3)
{
    printf("\n重新输入;\n");
    fflush(stdin);
    scanf("%d%d",&x,&y);
    for(;x > 3 || x <= 0 || y <= 0 || y > 3;)
    {
        printf("\n重新输入;\n");
        scanf("%d%d",&x,&y);
    }
    *a = x;
    *b = y;
}
}

char* AI(unsigned int* x,unsigned int* y)
{
srand((unsigned int)time(NULL));
*x = rand() % 3 + 1;
*y = rand() % 3 + 1;
}

void Chess_Array_Add(char chess[9][3],unsigned int x,unsigned int y)  //把玩家棋子的位置添加到该玩家的棋子数列中
{
char string[3];
for(int i = 0;i < 9;i++)
{
    if(strcmp(chess[i],"\0") == 0)
    {
        sprintf(chess[i],"%u",x);
        sprintf(string,"%u",y);
        strcat(chess[i],string);
        break;
    }
}
}

int Comparison_of_all_chess_pieces(char player1_chess[9][3],char player2_chess[9][3],int x,int y)  //所有棋子的占得到的位置是否和这玩家输入的一样
{
char string1[3];
char string2[3];
sprintf(string1,"%u",x);
sprintf(string2,"%u",y);
strcat(string1,string2);
for(int i = 0;i<9;i++)
{
    if(strcmp(player1_chess[i],string1) == 0)
    return 1;
}
for(int i = 0;i<9;i++)
{
    if(strcmp(player2_chess[i],string1) == 0)
    return 1;
}
return 0;
}

void sort(char player1_chess[9][3],char player2_chess[9][3])  //给两个玩家的棋子排序,方便计算胜负
{
   
    char swap[3];
    
    for(int i = 0;i < 9 - 1;i++) 
    for(int k = i + 1;k < 9;k++)
    {
        if(strcmp(player2_chess[i],player2_chess[k]) > 0)
        {
            for(int j = 0;j < 3;j++)
            {
                swap[j] = player2_chess[i][j];
            }
            for(int j = 0;j < 3;j++)
            {
                player2_chess[i][j] = player2_chess[k][j];
            }
            for(int n = 0;n < 3;n++)
            {
                player2_chess[k][n] = swap[n];
            }
        }
       
    }

    memset(swap,'\0',sizeof(swap));

    for(int i = 0;i < 9 - 1;i++) 
    for(int k = i + 1;k < 9;k++)
    {
        if(strcmp(player1_chess[i],player1_chess[k]) > 0)
        {
            for(int j = 0;j < sizeof(swap)/sizeof(swap[0]);j++)
            {
                swap[j] = player1_chess[i][j];
            }
            for(int j = 0;j < 3;j++)
            {
                player1_chess[i][j] = player1_chess[k][j];
            }
            for(int n = 0;n < 3;n++)
            {
                player1_chess[k][n] = swap[n];
            }
        }
       
    }
}

int main()
{
unsigned int x;
unsigned int y;
char player1_chess[9][3];
char player2_chess[9][3];
unsigned int choice;
memset(player2_chess,'\0',sizeof(player2_chess));
memset(player1_chess,'\0',sizeof(player1_chess)); 
char aaa[] = "\n-------------------\n|     |     |     |\n-------------------\n|     |     |     |\n-------------------\n|     |     |     |\n-------------------\n";
char *checkerboard;
checkerboard = aaa;
printf("--------------JJ杰哥围棋JJ--------------\n");
printf("---------(1)AI对战---(2)双人对战---------\n");
printf("选择你需要玩的模式: ");
scanf("%u",&choice);
while(choice != 1 && choice != 2)
{
    printf("选择你需要玩的模式: ");
    scanf("%u",&choice);
}
if(choice == 1)
{
    printf("%s",checkerboard);
    while(1)
    {
    printf("输入你输入的围棋的位置 (x,y) : ");
    scanf("%d%d",&x,&y);
    fflush(stdin);
    determine(&x,&y);
    while(Comparison_of_all_chess_pieces(player1_chess,player2_chess,x,y))
    {
        // printf("重复！\n");
        printf("重复,输入你输入的围棋的位置 (x,y) : ");
        scanf("%d%d",&x,&y);
    }
    Chess_Array_Add(player1_chess,x,y);
    sort(player1_chess,player2_chess);
    checkerboard[The_Position_of_Chess_add(x,y)] = 'X';
    printf("%s",checkerboard);
    if(Victory_Rules(player1_chess,player2_chess)== 10)
    {
        printf("\nYou Win!!");
        exit(1);
    }
    if(Victory_Rules(player1_chess,player2_chess)== 11)
    {
        printf("\nDogfall!!");
        exit(1);
    }
    AI(&x,&y);
    sleep(1);
    printf("\nAI思考中......\n");
    sleep(1);
    while(Comparison_of_all_chess_pieces(player1_chess,player2_chess,x,y))
    {
        // printf("重复！\n");
        AI(&x,&y);
    }
    Chess_Array_Add(player2_chess,x,y);
    sort(player1_chess,player2_chess);
    checkerboard[The_Position_of_Chess_add(x,y)] = 'O';
    printf("AI准备出棋......\n");
    sleep(1);
    printf("%s",checkerboard);
    Victory_Rules(player1_chess,player2_chess);
    if(Victory_Rules(player1_chess,player2_chess) == 0)
    {
        printf("\nYou Lose!!");
        exit(1);
    }
    if(Victory_Rules(player1_chess,player2_chess)== 11)
    {
        printf("\nDogfall!!");
        exit(1);
    }
    }
}
if(choice == 2)
{
    printf("%s",checkerboard);
    while(1)
    {
        printf("player1输入你的围棋的位置(x,y): ");
        fflush(stdin);
        scanf("%d%d",&x,&y);
        determine(&x,&y);  //是否输入x,y有误
        while(Comparison_of_all_chess_pieces(player1_chess,player2_chess,x,y))  //所有棋子的占得到的位置是否和这玩家输入的一样
        {
            // printf("重复！\n");
            printf("重复,输入你输入的围棋的位置 (x,y) : ");
            scanf("%d%d",&x,&y);
        }
        Chess_Array_Add(player1_chess,x,y);  //把棋子的位置放进这玩家的计算数组中
        sort(player1_chess,player2_chess);  //棋子位置的排序
        checkerboard[The_Position_of_Chess_add(x,y)] = 'X';  //放棋
        sleep(1);
        printf("\n正在布局中......\n");
        sleep(1);
        printf("准备出棋......\n");
        sleep(1);
        printf("%s",checkerboard);

        if(Victory_Rules(player1_chess,player2_chess)== 10)  //判断胜负
        {
            printf("\nPlayer1 Win!!");
            exit(1);
        }
        if(Victory_Rules(player1_chess,player2_chess)== 11)  //判断胜负
        {
            printf("\nDogfall!!");
            exit(1);
        }


        printf("player2输入你的围棋的位置(x,y): ");
        fflush(stdin);
        scanf("%d%d",&x,&y);
        determine(&x,&y);  //是否输入x,y有误
        while(Comparison_of_all_chess_pieces(player1_chess,player2_chess,x,y))  //所有棋子的占得到的位置是否和这玩家输入的一样
        {
            // printf("重复！\n");
            printf("重复,输入你输入的围棋的位置 (x,y) : ");
            scanf("%d%d",&x,&y);
        }
        Chess_Array_Add(player2_chess,x,y);  //把棋子的位置放进这玩家的计算数组中
        sort(player1_chess,player2_chess);   //棋子位置的排序
        checkerboard[The_Position_of_Chess_add(x,y)] = 'O';  //放棋
        sleep(1);
        printf("\n正在布局中......\n");
        sleep(1);
        printf("准备出棋......\n");
        sleep(1);
        printf("%s",checkerboard);
        Victory_Rules(player1_chess,player2_chess);
        if(Victory_Rules(player1_chess,player2_chess) == 0)  //判断胜负  
        {
            printf("\nPlayer2 Win!!");
            exit(1);
        }
        if(Victory_Rules(player1_chess,player2_chess)== 11)  //判断胜负
        {
            printf("\nDogfall!!");
            exit(1);
        }
        }
    }

return 0;
}

