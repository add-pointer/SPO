#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x15e85de1, "__register_chrdev" },
	{ 0xc4057e8, "__class_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x24328ec, "device_create" },
	{ 0x9d58499, "class_destroy" },
	{ 0x1dd8f880, "device_destroy" },
	{ 0xa5140fa, "class_unregister" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6093f1a5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A32A22EDE0B2197715D0FEB");
