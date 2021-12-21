#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LKM with array function by Mark");

static short int shorts = 1;
static int ints = 1337;
static long int intlongs = 9999;
static char *strings = "Hey!";
static int intArray[2] = { -1, -1};
static int array_argc = 0;

module_param(shorts, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(shorts, "Um numero inteiro bem curto!");
module_param(ints, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(ints, "Um inteiro");
module_param(intlongs, long, S_IRUSR);
MODULE_PARM_DESC(intlongs, "Um inteiro longo!");
module_param(strings, charp, 0000);
MODULE_PARM_DESC(strings, "Uma string de caracteres");
module_param_array(intArray, int, &array_argc, 0000);
MODULE_PARM_DESC(intArray, "Uma matriz de inteiros");

static int __init lkm_array_init(void) {
	int i;
	printk(KERN_INFO "Ola a todos!\n============\n");
	printk(KERN_INFO "shorts é um número inteiro curto: %hd\n", shorts);
	printk(KERN_INFO "ints é um inteiro: %d\n", ints);
	printk(KERN_INFO "intlongs é um inteiro longo: %ld\n", intlongs);
	printk(KERN_INFO "strings é uma string: %s\n", strings);
	for (i = 0; i < (sizeof intArray / sizeof (int)); i++) {
		printk(KERN_INFO "intArray[%d] = %d\n", i, intArray[i]);
	}

	printk(KERN_INFO "Obteve %d argumentos para intArray.\n", array_argc);
	return 0;
}

static void __exit lkm_array_exit(void) {
	printk(KERN_INFO "Estou saindo! :)\n");
}

module_init(lkm_array_init);
module_exit(lkm_array_exit);
