#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/utsname.h>
#include <linux/loop.h>

struct student
{
  int ID;
  int age;
  char name[50];
};

struct student Students[10];

int index=0;

void uptime(void);
void getSystemInfo(void);
void add(struct student);
void list(void);

/* This function is called when the module is loaded. */
int simple_init(void)
{
       struct student yo;
       int i;
       int n=10;
       uptime();
       getSystemInfo();
       yo.age=20;
       strcpy(yo.name,"Edgar Fabricio Barba Flores");
       for(i=1; i<=n; i++)
       {
         yo.ID=i;
         add(yo); 
       }
       list();
       printk( "Loading Module\n");
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk( "Removing Module\n");
}
void uptime() {
  printk("Uptime: %i\n", jiffies_to_msecs(get_jiffies_64())/1000);
}


// This function gets the general system information
void getSystemInfo(){  
  struct new_utsname *buf;
  buf = utsname();

  printk("Nodename: %s\n",buf->nodename);
  printk("Machine: %s\n",buf->machine);
  printk("Sysname: %s\n",buf->sysname);
  printk("Release: %s\n",buf->release);
  printk("Version: %s\n",buf->version);
#ifdef __linux__
  printk("Domain Name: %s\n", buf->domainname); // GNU extension
#endif
}

void add(struct student newStudent)
{
  Students[index]=newStudent;
  index++;
}
void list()
{
  int i;
  printk("ID\tAge:\tName:\t\n");
  for (i=0; i<index; i++)
  {
    printk("%i\t%i\t%s\n", Students[i].ID, Students[i].age, Students[i].name);
  }
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

