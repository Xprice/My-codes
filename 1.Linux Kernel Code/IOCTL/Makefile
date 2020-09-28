#内核源代码路径
KERNEL_DIR=/home/zzy/GEC6818/6818GEC/kernel
#交叉编译器的路径(前缀)
CROSS_PATH=/home/zzy/GEC6818/6818GEC/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-

#编译成模块
obj-m      +=     cdd.o

default:
	$(MAKE) CROSS_COMPILE=$(CROSS_PATH) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod* *.ord* *.sy* .*cmd .tmp*
