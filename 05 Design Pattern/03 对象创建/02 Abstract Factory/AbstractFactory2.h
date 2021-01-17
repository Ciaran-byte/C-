#pragma once

//数据访问层的代码
//使用工厂模式的方法构建代码

//对于目前这个案例，使用工厂模式是有问题的。因为有三个工厂，而且彼此相关联
//如果三个工厂第一个用的是sql的，第二个用的是mysql的，第个用的是oracle的，整个系统就会乱套


//------------------支持不同数据库的类----------------
//抽象的基类
class IDBConnection
{

};

class IDBCommand
{

};

class IDBDataReader
{

};

//具体的类
class SqlConnection :public IDBConnection
{

};
class SqlCommand :public IDBCommand
{

};

class SqlDataReader :public IDBDataReader
{

};


//----------------------------工厂---------------------------
//抽象的工厂
class IDBConnectionFactory
{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
};


class IDBCommandFactory
{
public:
	virtual IDBCommand* CreateDBCommand() = 0;

};

class IDBDataReaderFactory
{
public:
	virtual IDBDataReader* CreateDBDataReader() = 0;


};

//具体的工厂
class SqlConnectionFactory :public IDBConnectionFactory
{
public:
	virtual IDBConnection* CreateDBConnection()
	{
		return new SqlConnection();
	}
};

class SqlCommandFactory :public IDBCommandFactory
{
public:
	virtual IDBCommand* CreateDBCommand()
	{
		return new SqlCommand();
	}
};

class SqlDataReaderFactory :public IDBDataReaderFactory
{
public:
	virtual IDBDataReader* CreateDBDataReader()
	{
		return new SqlDataReader();
	}

};


//---------------------数据访问类-------------------
class EmployeeDA0
{
	IDBConnectionFactory* dbConnectionFactory;
	IDBCommandFactory* dbCommandFactory;
	IDBDataReaderFactory* dbDataReaderFactory;


public:
	vector<EmployeeD0> GetEmployees()
	{
		IDBConnection* connection = dbConnectionFactory->CreateDBConnection();

		connection->ConnectionString("...");

		IDBCommand* command = dbCommandFactory->CreateDBCommand();

		command->CommandText("...");
		command->SetConnection(connection); //command和connection有相关性


		IDBDataReader* reader = dbDataReaderFactory->CreateDBDataReader();
		
		while (reader->Read())
		{

		}
	}

};