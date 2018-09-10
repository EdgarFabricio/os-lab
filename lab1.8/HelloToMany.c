/**
 * A simple pthread program illustrating POSIX scheduling.
 *
 * Figure 6.8
 *
 * To compile:
 *
 *	gcc HelloToMany.c -o HelloToMany -lpthread
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013.
 */

#include <pthread.h>
#include <stdio.h>
//#define NUM_THREADS 10

/* the thread runs in this function */
void *runner(void *param); 
typedef struct
{
	int pid;
	int iter;
}params;

main(int argc, char *argv[])
{
	int NUM_THREADS= atoi(argv[1]);
	int i, scope;
	params args[NUM_THREADS];
	pthread_t tid[NUM_THREADS]; 	/* the thread identifier */
	pthread_attr_t attr; 		/* set of attributes for the thread */

	/* get the default attributes */
	pthread_attr_init(&attr);

	/* first inquire on the current scope */
	if (pthread_attr_getscope(&attr,&scope) != 0)
		fprintf(stderr, "Unable to get scheduling scope.\n");
	else {
		if (scope == PTHREAD_SCOPE_PROCESS)
			printf("PTHREAD_SCOPE_PROCESS\n");
		else if (scope == PTHREAD_SCOPE_SYSTEM)
			printf("PTHREAD_SCOPE_SYSTEM\n");
		else 
			fprintf(stderr,"Illegal scope value.\n");
	}
	
	/* set the scheduling algorithm to PCS or SCS */
	if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0)
		printf("unable to set scheduling policy.\n");

	/* create the threads */
	for (i = 0; i < NUM_THREADS; i++) 
	{
		args[i].iter=i;
		args[i].pid=i+4;
		printf("I am main thread. Created thread (%i), in iteration %i...\n", args[i].pid, args[i].iter);
		pthread_create(&tid[i],&attr,runner,(void *)(&args[i])); 
		//pthread_join(tid[i], NULL);
		if (!(i%(4)))
		{
			sleep(1);
		}
	}
	/**
	 * Now join on each thread
	 */
	for (i = 0; i < NUM_THREADS; i++) 
	{
		//printf("%ia\n", i);
		pthread_join(tid[i], NULL);
	}
}

/**
 * The thread will begin control in this function.
 */
void *runner(void *param) 
{
	/* do some work ... */
	params *tid;
	tid = (params *)param;
	printf("Hello from thread %i. I was crated in iteration %i.\n", tid->pid, tid->iter);
	
	pthread_exit(0);
}

