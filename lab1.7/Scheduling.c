#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process
{
  unsigned char priority;
  int id;
  long time;
  char *name;
};
struct process queue[10];
void swap(int);

void fcfs()
{
  int i;
  printf("First come first served scheduling:\n");
  printf("Process id:\tname:\n");
  for(i=0; i<10; i++)
  {
    printf("%d\t\t%s\t%i\n", queue[i].id, queue[i].name);
  }
}
void sjf()
{
  int i;
  int j;
  printf("Shortest job first scheduling:\n");
  printf("Process id:\tname:\t\ttime:\n");
  //long next = queue[0].time; 
  for(i=0; i<9; i++)
  {
    for(j=0; j<(9-i); j++)
    {
      if(queue[j].time>queue[j+1].time)
      {
        swap(j);
      }
    }
  }
  for(i=0; i<10; i++)
  {
    printf("%d\t\t%s\t%i\n", queue[i].id, queue[i].name, queue[i].time);
  }
}
void priority()
{
  int i;
  int j;
  printf("Priority scheduling:\n");
  printf("Process id:\tname:\t\tPriority:\n");
  //long next = queue[0].time; 
  for(i=0; i<9; i++)
  {
    for(j=0; j<(9-i); j++)
    {
      if(queue[j].priority>queue[j+1].priority)
      {
        swap(j);
      }
    }
  }
  for(i=0; i<10; i++)
  {
    printf("%d\t\t%s\t%i\n", queue[i].id, queue[i].name, queue[i].priority);
  }
}
void RR(long q)
{
  int i=0;
  char flag=0;
  printf("Round robin scheduling:\n");
  printf("time quantum: %i\n", q);
  printf("Process id:\tname:\t\ttime left:\n");
  do
  {
    //printf("%d\n",i);
    if(queue[i].time>0)
    {
      printf("%d\t\t%s%i\t%d\n", queue[i].id, queue[i].name, i, queue[i].time);
      queue[i].time-=q;
      flag=1;
    }
    i++;
    if(i>10)
    {
      i=0;
      if(flag==0)
      {
        flag=2;
      }
      else
      {
        flag=0;
      }
    }
  }
  while(flag!=2);
}
void swap(int j)
{
  struct process tmp = queue[j];
  queue[j]=queue[j+1];
  queue[j+1]=tmp;
}
void initQueue()
{
  int i;
  //char *name;
  printf("Initial order:\n");
  printf("Process id:\tname:\t\tburst time:\t\tpriority:\n");
  //char *tmp[10];
  for(i=0; i<10; i++)
  {
    queue[i].time= 11-i;
    queue[i].id=i;
    queue[i].priority= (char)(5-i);
    //printf("%d ",queue[i].time);
    //queue[i].name= (char*)malloc(15);
    queue[i].name="Process_";
    printf("%d\t\t", queue[i].id);
    printf("%s",queue[i].name);
    char temp=(char)(i+0x30);
    printf("%c\t",temp);
    printf("%d\t\t\t",queue[i].time);
    printf("%d\n",queue[i].priority);
    //queue[i].name[8]='1';
    //strcat(&queue[i].name, "1");
    //printf("%c\n",queue[i].name[0]);
    //strlen(queue[i].name)-1
    //strcat(queue[i].name, temp);//(char*)("a"+"b"+(char)(i+0x30));
    //printf("%s\n", queue[i].name);
    //sprintf(queue[i].name, "Process %d",i);
  }
}
void main()
{
  initQueue();
  //fcfs();
  //sjf();
  //RR(1);
  //priority();
  printf("\nChoose a scheduling algorithm:\nf: first come first serve.\ns: shortest job first.\np: priority.\nr: round robin.\nChoose: ");
  unsigned char tmp;
  scanf("%i",tmp);
  printf("%i",tmp);
//fgets(tmp,1, stdin);
  if(tmp=='f')
  {
    fcfs();
  }
  else if(tmp=='s')
  {
    sjf();
  }
  else if(tmp=='p')
  {
    priority();
  }
  else if(tmp=='r')
  {
    long q;
    printf("Type the time quantum q: ");
    scanf("%i", q);
    RR(q-0x30);
  }
}
