#include "PluginDemo.h"

// ����������cpp�ļ�����ʵ�֣�����û���嵥��Ϣ
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