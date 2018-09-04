
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char str[20];

	char *p[3];
	p[0]="ls";
	p[1]="-l";
	p[2]=NULL;//"\n";
	//printf("%s\n", p[0]);
	/*pid_t pid=fork();
	p= strtok(str, " ");
	printf("%d\n", pid);
	printf("%s\n", p);*/
	/*if(NULL != strtok(NULL, ""))
	{
	  printf("si");
	}*/
	/*if (pid==0)
	{
		p=strtok(NULL, "");
		printf("%s\n", p);
	}
	else if(pid>0)
	{
		wait();
		do
		{
			printf("%s\n",p);
			if(strcmp(p, "&")==0)
			{
				printf("checked\n");
			}
			p=strtok(NULL, " ");
		}while(p!=NULL);
	}*/
	//execvp(p[0], p);

	printf("\nAlgo:");
	fgets(str, 20, stdin);
	printf("%i",str);
	if(strcmp(str, "\r")==0)
	{
		printf("Smn");
	}
	return 0;
}
