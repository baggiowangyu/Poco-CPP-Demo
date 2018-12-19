// TimerDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Poco/Timer.h"

class MyTimer
{
public:
	void onTimer(Poco::Timer &timer)
	{
		std::cout<<"Invoke MyTimer::onTimer() ..."<<std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	MyTimer ti;
	Poco::Timer timer(250, 1000);
	timer.start(Poco::TimerCallback<MyTimer>(ti, &MyTimer::onTimer));

	system("pause");
	timer.stop();
	return 0;
}

