#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sysinfo.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
	struct sysinfo t_info;
       printk( "Loading Module\n" +t_info.uptime);
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk( "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

