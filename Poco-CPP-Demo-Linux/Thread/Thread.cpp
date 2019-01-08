#include <iostream>
#include <stdio.h>
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/Event.h"

using namespace std;

class MyThreadRunnable : public Poco::Runnable
{
public:
	MyThreadRunnable(const char *str, int i)
		: str_val_(str)
		, int_val_(i)
		, need_exit_(false)
	{

	}

	~MyThreadRunnable() {}

public:
	void Stop() { need_exit_ = true; }

public:
	virtual void run()
	{
		Poco::Event thread_event;
		// 这里是线程运行实体
		while(!need_exit_)
		{
			std::cout << "This is thread function ..." << std::endl;
			std::cout << "Parameters : " << str_val_.c_str() << " " << int_val_ << std::endl;
			//Sleep(1000);
			try
			{
				thread_event.wait(1000);
			}
			catch(Poco::Exception e)
			{
				std::cout << e.what() << std::endl;
			}
			
		}
	}

public:
	std::string str_val_;
	int int_val_;

private:
	bool need_exit_;
};

int main(int argc, char *argv[])
{
	try
	{
		MyThreadRunnable runnable("123", 456);
		Poco::Thread my_thread;
		my_thread.start(runnable);

		std::cout << "Please press \"Enter\" stop thread ...";
		getchar();
		runnable.Stop();
		my_thread.join();
	}
	catch (Poco::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "Please press \"Enter\" continue ...";
	getchar();
	return 0;
}