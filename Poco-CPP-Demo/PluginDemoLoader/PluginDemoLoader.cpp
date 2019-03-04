// PluginDemoLoader.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Poco\ClassLoader.h"
#include "Poco\Manifest.h"
#include "..\PluginDemo\AbstractPlugin.h"

typedef Poco::ClassLoader<AbstractPlugin> PluginLoader;
typedef Poco::Manifest<AbstractPlugin> PluginManifest;

int _tmain(int argc, _TCHAR* argv[])
{
	int errCode = 0;
	std::string errStr;

	try
	{
		PluginLoader loader;
		std::string libName("PluginDemo");
		libName += Poco::SharedLibrary::suffix(); // append .dll or .so
		loader.loadLibrary(libName);

		PluginLoader::Iterator it(loader.begin());
		PluginLoader::Iterator end(loader.end());
		for (; it != end; ++it)
		{
			std::cout << "lib path: " << it->first << std::endl;
			PluginManifest::Iterator itMan(it->second->begin());
			PluginManifest::Iterator endMan(it->second->end());
			for (; itMan != endMan; ++itMan)
				std::cout << itMan->name() << std::endl;
		}

		AbstractPlugin* pPluginA = loader.create("PluginDemo");
		std::cout << pPluginA->name() << std::endl;
		std::cout << pPluginA->sum(1, 3) <<std::endl;
		//loader.classFor("PluginA").autoDelete(pPluginA);
		loader.unloadLibrary(libName);
	}
	catch(Poco::Exception e)
	{
		errCode = e.code();
		errStr = e.displayText();
	}

	return 0;
}

