#include<stdio.h>
int main()
{
int pid;

pid= fork();

if (pid<0){
printf("Fork failed\n");
}

else if (pid == 0){/* child process */
printf("This is child process\n");
//execlp("/bin/ls","ls",NULL);
}

else{
wait(NULL);
printf("This is parent process\n");
}
}
