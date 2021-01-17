#pragma once

//对案例2的解决方法是将三个工厂放到一个类中进行实现
//因为三个工厂具有相关性

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


//-----------------工厂----------------
class IDBFactory
{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDBDataReader* CreateDataReader() = 0;
};

class SqlFactory
{
public:
	virtual IDBConnection* CreateDBConnection()
	{
		return new SqlConnection();
	}

	virtual IDBCommand* CreateDBCommand()
	{
		return new SqlCommand();
	}

	virtual IDBDataReader* CreateDBDataReader()
	{
		return new SqlDataReader();
	}
};


//数据访问类
class EmployeeDA0
{
	IDBFactory* dbFactory;

public:
	vector<EmployeeD0> GetEmployees()
	{
		IDBConnection* connection = dbFactory->CreateDBConnection();

		connection->ConnectionString = "...";

		IDBCommand* command = dbFactory->CreateDBCommand();

		command->CommandText = "...";

		IDBDataReader* reader = dbFactory->CreateDataReader();
		while (reader->Read())
		{

		}
	}

};