// MongoDBDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Poco/DateTime.h"
#include "Poco/ObjectPool.h"
#include "Poco/MongoDB/InsertRequest.h"
#include "Poco/MongoDB/QueryRequest.h"
#include "Poco/MongoDB/DeleteRequest.h"
#include "Poco/MongoDB/GetMoreRequest.h"
#include "Poco/MongoDB/PoolableConnectionFactory.h"
#include "Poco/MongoDB/Database.h"
#include "Poco/MongoDB/Cursor.h"
#include "Poco/MongoDB/ObjectId.h"
#include "Poco/MongoDB/Binary.h"
#include "Poco/Net/NetException.h"
#include "Poco/UUIDGenerator.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int errCode = 0;
	std::string errStr;

	// 连接到mongodb
	std::string mongodb_ip = "127.0.0.1";
	int mongodb_port = 27017;

	try
	{
		//// 这里我们尝试使用连接池
		//Poco::Net::SocketAddress mongodb_address(mongodb_ip, mongodb_port);
		//Poco::PoolableObjectFactory<Poco::MongoDB::Connection, Poco::MongoDB::Connection::Ptr> factory(mongodb_address);
		//Poco::ObjectPool<Poco::MongoDB::Connection, Poco::MongoDB::Connection::Ptr> pool(factory, 10, 15);	// 常备连接数10，最大连接数15

		//Poco::MongoDB::PooledConnection pooled_connection(pool);

		Poco::MongoDB::Connection::Ptr mongo = new Poco::MongoDB::Connection(mongodb_ip, mongodb_port);

		// 尝试插入操作
		Poco::MongoDB::Document::Ptr person_info = new Poco::MongoDB::Document();
		person_info->add("name", "wangyu");
		person_info->add("sex", "male");
		person_info->add("age", 18);

		Poco::DateTime now;
		person_info->add("create_time", now.timestamp());

		// 插入记录请求
		Poco::MongoDB::InsertRequest request("my.user");
		request.documents().push_back(person_info);

		Poco::MongoDB::ResponseMessage response;
		//Poco::MongoDB::Connection::Ptr connection = (Poco::MongoDB::Connection::Ptr)pooled_connection;
		Poco::MongoDB::Connection::Ptr connection = mongo;
		connection->sendRequest(request);

		// 查询请求
		Poco::MongoDB::QueryRequest query_request("my.user");
		query_request.selector().add("name", "wangyu");
		query_request.setNumberToReturn(1);

		mongo->sendRequest(query_request, response);

		Poco::MongoDB::Document::Ptr doc = NULL;
		if (response.documents().size() >= 0)
		{
			doc = response.documents()[0];
		}

		
	}
	catch(Poco::Net::NetException e)
	{
		errCode = e.code();
		errStr = e.displayText();
	}
	catch(Poco::Exception e)
	{
		errCode = e.code();
		errStr = e.displayText();
	}

	return 0;
}

