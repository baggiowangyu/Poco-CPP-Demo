// ActiveDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Poco/Activity.h"
#include "Poco/ActiveMethod.h"
#include "Poco/Thread.h"

//////////////////////////////////////////////////////////////////////////
//
// Activity 的一个实现范例
//
//////////////////////////////////////////////////////////////////////////
class MyActivity
{
public:
	MyActivity(): _activity(this, &MyActivity::runActivity)
	{}

	void start()
	{
		_activity.start();
	}

	void stop()
	{
		_activity.stop();
		_activity.wait();
	}

protected:
	void runActivity()
	{
		while (!_activity.isStopped())
		{
			std::cout<<"TestActivity() >>> Activity is running ..."<<std::endl;
			Poco::Thread::sleep(200);
		}
	}

private:
	Poco::Activity<MyActivity> _activity;
};

//////////////////////////////////////////////////////////////////////////
//
// Activity Methods 的一个实现范例
//
//////////////////////////////////////////////////////////////////////////
class MyActivotyMethod
{
public:
	MyActivotyMethod() : add(this, &MyActivotyMethod::addImpl){}

private:
	int addImpl(const std::pair<int, int>& args)
	{
		return args.first + args.second;
	}

public:
	Poco::ActiveMethod<int, std::pair<int, int>, MyActivotyMethod> add;
};

void TestActivity()
{
	MyActivity ac;
	ac.start();
	
	system("pause");
	ac.stop();
}

void TestActivityMethod()
{
	MyActivotyMethod am;
	Poco::ActiveResult<int> sum = am.add(std::make_pair(3, 6));
	sum.wait();
	std::cout<<"MyActivotyMethod.add result : "<<sum.data()<<std::endl;
	system("pause");
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestActivity();
	TestActivityMethod();

	return 0;
}

