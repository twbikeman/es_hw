#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("hello_world");
MODULE_LICENSE("GPL");

static int hello_init(void) {
  prink(KERN_INFO "hello world\n");
  return 0;
}

static void hello_exit(void) {
  prink(KERN_INFO "Bye !\n");
}

module_init(hello_init);
moduel_exit(hello_exit);
