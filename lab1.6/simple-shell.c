/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <linux/types.h>
#include <stdio.h>
#include <unistd.h>



#define MAX_LINE		80 /* 80 chars per line, per command */

int main(void)
{
	char *args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
	char command[MAX_LINE];
	char *str;
	int should_run = 1;
	
	int i, upper;
		
    while (should_run){   
        printf("osh>");
	//printf("a\n");
        //fflush(stdout);
        //fflush(stdin);
        
	upper=0;

	//printf("Algo:\n");
	fgets(command, MAX_LINE, stdin);
	//scanf("%s", command);
	//strcpy(command,"ls -l");
	printf("%s\n",command);
	
	str= strtok(command," ");
	printf("check point\n");
	i=0;
	//printf("%d\n", i);
	while(str!=NULL)//strcmp(str, "\n")!=0)
	{
		printf("%s", str);
		//printf("check point\n");
		args[i]=str;
		printf("%s", args[i]);
		if(strcmp(str, "&")==0)
		{
			upper=1;
		}
		str = strtok(NULL, " ");
		i++;
	}
	//args[i]=NULL;
	
	pid_t pid= fork();

	printf("check point 2\n"); 
	printf("%s\n", args[8]);
	printf("check point 3\n");	
	if(pid==0)
	{
		execvp(args[0], args);
		should_run=0;
	}
	else if(pid>0)
	{
	  if(!(upper))
	  {
	    wait();
	  }
	}
        /**
         * After reading user input, the steps are:
         * (1) fork a child process
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait()
         */
    }
    
	return 0;
}
