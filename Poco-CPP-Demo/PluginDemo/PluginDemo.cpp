#include "PluginDemo.h"

// 这个宏必须在cpp文件里面实现，否则没有清单信息
POCO_BEGIN_MANIFEST(AbstractPlugin)
POCO_EXPORT_CLASS(PluginDemo)
POCO_END_MANIFEST

// optional set up and clean up functions
void pocoInitializeLibrary()
{
	std::cout << "PluginLibrary initializing" << std::endl;
}

void pocoUninitializeLibrary()
{
	std::cout << "PluginLibrary uninitializing" << std::endl;
}