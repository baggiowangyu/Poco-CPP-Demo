// CacheDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Poco/Exception.h"
#include "Poco/AbstractCache.h"
#include "Poco/LRUCache.h"
#include "Poco/ExpireCache.h"

void LRUCacheDemo()
{
	try
	{
		Poco::LRUCache<std::string, __int64> lru_cache(5);

		std::cout<<"[LRUCacheʹ������] ���β���6��Ԫ�أ��鿴��һ��Ԫ���Ƿ����"<<std::endl;
		lru_cache.add("110", 1);
		bool bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

		lru_cache.add("210", 1);
		bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

		lru_cache.add("310", 1);
		bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

		lru_cache.add("410", 1);
		bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

		lru_cache.add("510", 1);
		bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

		lru_cache.add("610", 1);
		bret = lru_cache.has("110");
		std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;
	}
	catch (Poco::Exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	system("pause");
	return ;
}

void ExpireCacheDemo()
{
	try
	{
		Poco::ExpireCache<std::string, __int64> expire_cache(10 * 1000);

		std::cout<<"[ExpireCacheʹ������] ��������Ԫ�أ�ֻ����Ԫ��1���鿴10�������Ԫ���Ƿ񻹴���"<<std::endl;
		expire_cache.add("110", 1);
		expire_cache.add("210", 1);
		expire_cache.add("310", 1);

		__int64 update_val = 1;
		int index = 0;
		while (true)
		{
			if (index > 15)
				break;

			Sleep(1000);
			expire_cache.update("110", update_val);

			std::cout<<"=============================="<<index<<"==============================="<<std::endl;
			bool bret = expire_cache.has("110");
			std::cout<<"element '110' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;
			bret = expire_cache.has("210");
			std::cout<<"element '210' is "<<(bret ? " exist" : " not exist")<<" ..."<<std::endl;

			++index;
		}
	}
	catch (Poco::Exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	system("pause");
	return ;
}


int _tmain(int argc, _TCHAR* argv[])
{
	LRUCacheDemo();
	ExpireCacheDemo();
	return 0;
}

