#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/StreamCopier.h"

using namespace std;

class GxxGmRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
	virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
	{
		int errCode = 0;
		std::string errStr = "";
		try
		{
			// 这里会接收到外部发来的请求
			std::string uri = request.getURI();
			//std::string host = request.getHost();
			std::string method = request.getMethod();

			// 读取发过来的数据
			// 读取数据
			std::istream &is = request.stream();

			std::ostringstream ostr;
			std::istream *ptr_rs = &is;
			Poco::StreamCopier::copyStream(*ptr_rs, ostr);

			std::string request_body = ostr.str();

			std::cout<<"Recevice request : "<<std::endl;
			std::cout<<method.c_str()<<" "/*<<host.c_str()*/<<uri.c_str()<<std::endl;

			if (request_body.size() > 0)
				std::cout<<request_body.c_str()<<std::endl;

			std::cout<<std::endl;

			// 响应信息
			response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
			std::ostream &out = response.send();
		}
		catch(Poco::Exception &ex)
		{
			errCode = ex.code();
			errStr = ex.displayText();

			std::cout<<"Recevice error... error code : "<<errCode<<". error message : "<<errStr.c_str()<<std::endl;
		}
	}
};

class GxxGmRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
	virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request)
	{
		return new GxxGmRequestHandler;
	}
};

class GxxGmServerApp : public Poco::Util::ServerApplication
{
protected:
	int main(const std::vector<std::string>& args)
	{
		int port = 9999;
		if (args.size() > 0)
			port = atoi(args[0].c_str());

		Poco::Net::HTTPServer server(new GxxGmRequestHandlerFactory, Poco::Net::ServerSocket(port), new Poco::Net::HTTPServerParams);
		server.start();
		waitForTerminationRequest();
		server.stop();

		return Poco::Util::Application::EXIT_OK;
	}
};

int main(int argc, char *argv[])
{
	GxxGmServerApp app;
	return app.run(argc, argv);
}