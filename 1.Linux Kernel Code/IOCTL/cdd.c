#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#define HELLO_ONE _IO('k',0)
#define HELLO_TWO _IO('k',1)

#define CDD_MINOR 0

//设备号
dev_t dev;
//声明cdev
struct cdev cdd_cdev;
//设备类指针
struct class *cdd_class;
//设备指针
struct device *cdd_device;

//内核缓冲区
char data[128] = {};

/*
inode是文件的节点结构，用来存储文件静态信息
文件创建时，内核中就会有一个inode结构
file结构记录的是文件打开的信息
文件被打开时内核就会创建一个file结构
*/
int cdd_open(struct inode *inode, struct file *filp)
{
	printk("enter cdd_open!\n");

	return 0;
}

ssize_t cdd_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
	int ret;

	printk("enter cdd_read!\n");
	if(size>127)
		size = 127;//数据不够长，取最长的数据

	ret = copy_to_user(buf, data, size);
	if(ret)
		return -EFAULT;

	return size;
}

ssize_t cdd_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
	int ret;

	printk("enter cdd_write!\n");
	if(size>127)
		return -ENOMEM;//越界

	//拷贝数据
	ret = copy_from_user(data, buf, size);
	if(ret)
		return -EFAULT;

	printk("data = %s\n",data);

	return size;
}

long cdd_ioctl(struct file *filp, unsigned int cmd, unsigned long data)
{
	printk("enter cdd_ioctl!\n");

	//不同的命令对应不同的操作
	switch(cmd){
		case HELLO_ONE:
			printk("HELLO_ONE!\n");
			break;
		case HELLO_TWO:
			printk("HELLO_TWO!\n");
			break;
		default:
			return -EINVAL;
	}

	return 0;
}

int cdd_release(struct inode *inode, struct file *filp)
{
	printk("enter cdd_release!\n");

	return 0;
}

//声明操作函数集合
struct file_operations cdd_fops = {
	.owner = THIS_MODULE,
	.open = cdd_open,
	.read = cdd_read,
	.write = cdd_write,
	.unlocked_ioctl = cdd_ioctl,//ioctl接口
	.release = cdd_release,//对应用户close接口
};

//加载函数
int cdd_init(void)
{
	int ret;
	// 1.注册字符设备驱动
	ret = register_chrdev(0, "cdd_demo", &cdd_fops);
	if(ret<0){
		printk("register_chrdev failed!\n");
		goto failure_register_chrdev;
	}
	//构建设备号
	dev = MKDEV(ret,CDD_MINOR);

	printk("register_chrdev success!\n");

	// 3.注册设备类
	/*成功会在/sys/class目录下出现cdd_class子目录*/
	cdd_class = class_create(THIS_MODULE, "cdd_class");
	if(IS_ERR(cdd_class)){
		printk("class_create failed!\n");
		ret = PTR_ERR(cdd_class);
		goto failure_class_create;
	}

	// 4.创建设备文件
	cdd_device = device_create(cdd_class, NULL, dev,NULL, "cdd");
	if(IS_ERR(cdd_device)){
		printk("device_create failed!\n");
		ret = PTR_ERR(cdd_device);
		goto failure_device_create;
	}

	return 0;

failure_device_create:
	class_destroy(cdd_class);// 3
failure_class_create:
	unregister_chrdev(MAJOR(dev), "cdd_demo");// 2
failure_register_chrdev:
	return ret;
}

//卸载函数
void cdd_exit(void)
{
	//销毁设备文件
	device_destroy(cdd_class, dev);
	//注销设备类
	class_destroy(cdd_class);
	//注销字符设备驱动
	unregister_chrdev(MAJOR(dev), "cdd_demo");
}

//声明为模块的入口和出口
module_init(cdd_init);
module_exit(cdd_exit);


MODULE_LICENSE("GPL");//GPL模块许可证
MODULE_AUTHOR("zzy");//作者
MODULE_VERSION("1.0");//版本
MODULE_DESCRIPTION("charactor driver!");//描述信息
