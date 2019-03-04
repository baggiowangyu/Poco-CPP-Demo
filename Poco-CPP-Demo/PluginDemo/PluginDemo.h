#ifndef _PluginDemo_H_
#define _PluginDemo_H_

#include "AbstractPlugin.h"
#include "Poco/ClassLibrary.h"

class PluginDemo : public AbstractPlugin
{
public:
	std::string name() const
	{
		return "PluginDemo";
	}

	int sum(int a, int b)
	{
		return a + b;
	}
};



#endif//_PluginDemo_H_
