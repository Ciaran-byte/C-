#pragma once
#include<iostream>
#include <string>

using namespace std;

//请求类型
enum class RequestType
{
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3
};

//请求
class Request
{
	string description;
	RequestType reqType;
public:
	Request(const string& desc,RequestType type)
		:description(desc), reqType(type){}

	RequestType getReqType()const { return reqType; }
	const string& getDescription()const
	{
		return description;
	}
};


//职责链的抽象
class ChainHandler
{
	ChainHandler* nextChain; //请求处理链表
	void sendRequestToNextHandler(const Request& req)
	{
		if (nextChain != nullptr)
		{
			nextChain->handle(req);
		}
	}
protected:
	virtual bool canHandleRequest(const Request& req) = 0;
	virtual void processRequest(const Request& req) = 0;
public:
	ChainHandler() { nextChain = nullptr; }
	void setNextChain(ChainHandler* next) { nextChain =next; }
	void handle(const Request& req)
	{
		if (canHandleRequest(req))
			processRequest(req);
		else
			sendRequestToNextHandler(req);
	}
};

//具体的职责链
class Handler1 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request& req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER1;
	 }

	void processRequest(const Request& req)override
	{
		cout << "Handler1 is handle request" << req.getDescription() << endl;
	}
};


class Handler2 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request& req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER2;
	}

	void processRequest(const Request& req)override
	{
		cout << "Handler1 is handle request" << req.getDescription() << endl;
	}
};

class Handler3 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request& req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER3;
	}

	void processRequest(const Request& req)override
	{
		cout << "Handler1 is handle request" << req.getDescription() << endl;
	}
};


//使用职责链
void process()
{
	Handler1 h1;
	Handler2 h2;
	Handler3 h3;
	
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);

	//req这个对象，只有被传递到h3才能被处理。
	Request req("process task...", RequestType::REQ_HANDLER3);

	h1.handle(req);

	

}