#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/regs-gpio.h>
#include <asm/hardware.h>
static int first_dev_open(struct inode *node,struct file *file)
{

	printk("Test Kernel is Open");
	return 0;
}
static ssize_t first_dev_write(struct file *, const char __user *, size_t, loff_t *)
{
	printk("Test Kernel is Wirte");
	return 0;
}
static struct file_operations fops={
	.owner	=THIS_MODULE,
	.open	=first_dev_open,
	.write	=first_dev_write,
}

//��ʼ������
static int first_dev_init(void)
{
	//�豸�� �豸��,Ӳ���豸�ṹ��
	register_chrdev(111, "first_dev",&first_dev_fops);
		// ע��
	return 0;
}

static void first_dev_exit(void)
{
	unregister_chrdev(111,"first_dev");
}

// �����������
module_init(first_dev_init);
// �����������
module_exit(first_dev_exit);
//GPLЭ��
MODULE_LICENSE("GPL");
