// ApplicationDemo.cpp : �������̨Ӧ�ó������ڵ㡣
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
 * �����Լ���Ӧ����
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

		// ����ִ����س�ʼ�����������������ָ���������ļ���
		//loadConfiguration();

		// ��ʼ����־
		std::string name = "log_";
		name.append(Poco::DateTimeFormatter::format(Poco::Timestamp(), "%Y%m%d%H%M%S"));
		name.append(".log");

		Poco::AutoPtr<Poco::FileChannel> fileChannel(new Poco::FileChannel);
		fileChannel->setProperty("path", name);
		fileChannel->setProperty("rotation", "1 M");
		fileChannel->setProperty("archive", "timestamp");

		// ÿ����־��ʱ���ʽ
		Poco::AutoPtr<Poco::PatternFormatter> patternFormatter(new Poco::PatternFormatter());
		patternFormatter->setProperty("pattern","%Y %m %d %H:%M:%S %s(%l): %t");

		//��ʼ����Channel
		Poco::AutoPtr<Poco::Channel> channel = new Poco::FormattingChannel(patternFormatter,fileChannel);
		logger().setChannel(channel);

		std::cout<<"MyApplication::initialize()"<<std::endl;
	}

	void uninitialize()
	{
		// ����ִ����ط���ʼ��
		Poco::Util::Application::uninitialize();
		std::cout<<"MyApplication::uninitialize()"<<std::endl;
	}

	int main(const std::vector<std::string>& args)
	{
		// ������ʵ�ʵ�ҵ���߼�
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
	// ʹ�ô˿�ܣ���ζ��һ�����̿���ִ�ж��Ӧ��
	MyApplication app;
	app.run();

	std::cout<<"Press \"Enter\" key to continue ...";
	getchar();
	return 0;
}

