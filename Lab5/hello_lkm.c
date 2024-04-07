#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(){
    printk(KERN_ALERT "Hello from kernel world\n");
    return 0;
}

static void __exit hello_exit(){
    printk(KERB_ALERT "Goodbye from kernel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CE3103");
MODULE_DESCRIPTION("Simple Hello module");
MODULE_VERSION("V1");