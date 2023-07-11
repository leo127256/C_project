#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> 
int main(void)
{
 pid_t id = fork();
 if(id < 0)
{
    perror("id");
    return 1;
}
else if(id > 0)
{
  // wait(NULL);
  // while(waitpid(-1,NULL,WNOHANG == 0)){
  //   sleep(3);
  //   printf("waiting......\n");
  // }
  
  printf("parent[%d],sleeping 15s.......\n",getpid());
  sleep(15);
}
else if(id == 0){//子进程
    printf("child[%d] is sleeping 5s more...\n", getpid());
    sleep(5);
    exit(0);
}
while(1)
{
  printf("不负责任的......\n");
  sleep(1);
}


    return 0;
}