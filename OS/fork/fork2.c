#include <sys/types.h>
#include<stdio.h>
int main()
{
int p1,p2;
p1 = fork();
p2 = fork();
printf("%d\n",p1);
printf("%d\n",p2);
printf("Hello world\n");
}

/*
Output
14993
14994
Hello world
14993
0
Hello world
0
14995
Hello world
0
0
Hello world
*/
