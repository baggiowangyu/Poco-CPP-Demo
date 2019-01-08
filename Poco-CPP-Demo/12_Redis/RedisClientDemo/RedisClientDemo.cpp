// RedisClientDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Poco/Redis/Client.h"
#include "Poco/Redis/Command.h"
#include "Poco/Redis/Type.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Poco::Redis::Client redis_client;

	try
	{
		// 连接到Redis
		redis_client.connect("127.0.0.1", 6379);

		// 执行插入
		Poco::Redis::Command setCommand = Poco::Redis::Command::set("name", "goldmsg");
		std::string ret = redis_client.execute<std::string>(setCommand);

		// 执行查询
		Poco::Redis::Command getCommand = Poco::Redis::Command::get("name");
		Poco::Redis::BulkString getValue = redis_client.execute<Poco::Redis::BulkString>(getCommand);

		// 删除KEY
		Poco::Redis::Command deleteCommand = Poco::Redis::Command::del("name");
		Poco::Int64 i64ret = redis_client.execute<Poco::Int64>(deleteCommand);

		// 执行查询
		getCommand = Poco::Redis::Command::get("name");
		getValue = redis_client.execute<Poco::Redis::BulkString>(getCommand);
		
		redis_client.disconnect();
	}
	catch (Poco::Exception e)
	{
		std::cout<<e.what()<<std::endl;
		redis_client.disconnect();
	}
	
	system("pause");
	return 0;
}

