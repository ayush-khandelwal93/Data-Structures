#include<pthread.h>
#include<stdio.h>

int sum;
void * runner(void * param);

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	
	if(argc!=2)
	{
		printf("usage: a.out <integer value>\n");
	}
	
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);

	pthread_join(tid, NULL);
	printf("sum = %d\n",sum);
}

void * runner(void * param)
{
	int i, upper = atoi(param);
	sum = 0;
	for(i =1; i<=upper;i++)
		sum +=i;
	pthread_exit(0);
}

/*
Each thread has a set of attributes,
including stack size and scheduling information. The pthread attr t attr
declaration represents the attributes for the thread. We set the attributes in the
function call pthread attr init(&attr). Because we did not explicitly set
any attributes, we use the default attributes provided. (In Chapter 6, we discuss
some of the scheduling attributes provided by the Pthreads API.) A separate
thread is created with the pthread create() function call. In addition to
passing the thread identifier and the attributes for the thread, we also pass the
name of the function where the new thread will begin execution—in this case,
the runner() function. Last, we pass the integer parameter that was provided
on the command line, argv[1].
At this point, the program has two threads: the initial (or parent) thread
in main() and the summation (or child) thread performing the summation
operation in the runner() function. This program follows the fork-join strategy
described earlier: after creating the summation thread, the parent thread
will wait for it to terminate by calling the pthread join() function. The
summation thread will terminate when it calls the function pthread exit().
Once the summation thread has returned, the parent thread will output the
value of the shared data sum
*/
