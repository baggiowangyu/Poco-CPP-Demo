// ApplicationDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "Poco/DateTimeFormatter.h"
#include "Poco/FileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/Timestamp.h"
#include "Poco/PatternFormatter.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"


/**
 * 定义自己的应用类
 */
class MyApplication : public Poco::Util::Application
{
public:
	MyApplication() {}
	~MyApplication() {}

public:
	void initialize(Poco::Util::Application& self)
	{
		Poco::Util::Application::initialize(self);

		// 这里执行相关初始化，例如在这里加载指定的配置文件？
		//loadConfiguration();

		// 初始化日志
		std::string name = "log_";
		name.append(Poco::DateTimeFormatter::format(Poco::Timestamp(), "%Y%m%d%H%M%S"));
		name.append(".log");

		Poco::AutoPtr<Poco::FileChannel> fileChannel(new Poco::FileChannel);
		fileChannel->setProperty("path", name);
		fileChannel->setProperty("rotation", "1 M");
		fileChannel->setProperty("archive", "timestamp");

		// 每条日志的时间格式
		Poco::AutoPtr<Poco::PatternFormatter> patternFormatter(new Poco::PatternFormatter());
		patternFormatter->setProperty("pattern","%Y %m %d %H:%M:%S %s(%l): %t");

		//初始化　Channel
		Poco::AutoPtr<Poco::Channel> channel = new Poco::FormattingChannel(patternFormatter,fileChannel);
		logger().setChannel(channel);

		std::cout<<"MyApplication::initialize()"<<std::endl;
	}

	void uninitialize()
	{
		// 这里执行相关反初始化
		Poco::Util::Application::uninitialize();
		std::cout<<"MyApplication::uninitialize()"<<std::endl;
	}

	int main(const std::vector<std::string>& args)
	{
		// 这里是实际的业务逻辑
		logger().information("info.........................................................");
		logger().debug("debug.........................................................");
		logger().critical("critical.........................................................");
		logger().error("error.........................................................");
		logger().fatal("fatal.........................................................");

		std::cout<<"MyApplication::main(const std::vector<std::string>& args)"<<std::endl;
		return Poco::Util::Application::EXIT_OK;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	// 使用此框架，意味着一个进程可以执行多个应用
	MyApplication app;
	app.run();

	std::cout<<"Press \"Enter\" key to continue ...";
	getchar();
	return 0;
}

