#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/unistd.h>
#include <asm/segment.h>
#include <linux/uaccess.h>
#include <asm/processor.h>
#include <linux/buffer_head.h>
#include <linux/slab.h>


MODULE_DESCRIPTION("hello_world");
MODULE_LICENSE("GPL");

struct file *filp = NULL;








static int hello_init(void) {
  
  struct kstat *stat;
  mm_segment_t oldfs;

  char buf[128];
  int i;
  loff_t pos;

  for (i = 0; i < 128; i++)
    buf[i] = 0;
  

  filp = filp_open("/home/che0520/es_hw/file/input.txt", O_RDONLY, 0); 
   if (IS_ERR(filp))
     printk("fail\n");
   else {
     printk(KERN_INFO "%p\n", filp);
     oldfs = get_fs();
     set_fs(KERNEL_DS);
     pos = 0;

     stat = (struct kstat *) kmalloc(sizeof(struct kstat), GFP_KERNEL);
     vfs_stat("/home/che0520/es_hw/file/input.txt", stat);
    
     printk(KERN_ALERT "%lld", stat->size);


     pos = (int)stat->size -1;

     for(i = pos; i >= 0; i--) {
       pos = i;
       vfs_read(filp, buf, 1, &pos);
       printk("read: %s", buf);
     }
         

     
     
    filp_close(filp, NULL);
     set_fs(oldfs);
   }
   printk(KERN_INFO "hello world\n");
   

    
  return 0;
}

static void hello_exit(void) {

    
  printk(KERN_INFO "Bye !\n");
}

module_init(hello_init);
module_exit(hello_exit);
