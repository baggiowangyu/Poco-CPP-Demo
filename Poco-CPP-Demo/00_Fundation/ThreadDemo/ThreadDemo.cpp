// ThreadDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Poco/Thread.h"
#include "Poco/Runnable.h"


class MyThreadRunnable : public Poco::Runnable
{
public:
	MyThreadRunnable(const char *str, int i)
		: str_val_(str)
		, int_val_(i)
		, need_exit_(false)
	{

	}

	~MyThreadRunnable(){}

public:
	void Stop() { need_exit_ = true; }

public:
	virtual void run()
	{
		// 这里是线程运行实体
		while (!need_exit_)
		{
			std::cout<<"This is thread function ..."<<std::endl;
			std::cout<<"Parameters : "<<str_val_.c_str()<<" "<<int_val_<<std::endl;
			Sleep(1000);
		}
	}

public:
	std::string str_val_;
	int int_val_;

private:
	bool need_exit_;
};


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		MyThreadRunnable runnable("123", 456);
		Poco::Thread my_thread;
		my_thread.start(runnable);

		system("pause");
		runnable.Stop();
		my_thread.join();
	}
	catch (Poco::Exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	
	system("pause");
	return 0;
}

