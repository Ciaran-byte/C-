#pragma once

//���ݷ��ʲ�Ĵ���
//ʹ�ù���ģʽ�ķ�����������

//����Ŀǰ���������ʹ�ù���ģʽ��������ġ���Ϊ���������������ұ˴������
//�������������һ���õ���sql�ģ��ڶ����õ���mysql�ģ��ڸ��õ���oracle�ģ�����ϵͳ�ͻ�����


//------------------֧�ֲ�ͬ���ݿ����----------------
//����Ļ���
class IDBConnection
{

};

class IDBCommand
{

};

class IDBDataReader
{

};

//�������
class SqlConnection :public IDBConnection
{

};
class SqlCommand :public IDBCommand
{

};

class SqlDataReader :public IDBDataReader
{

};


//----------------------------����---------------------------
//����Ĺ���
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

//����Ĺ���
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


//---------------------���ݷ�����-------------------
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
		command->SetConnection(connection); //command��connection�������


		IDBDataReader* reader = dbDataReaderFactory->CreateDBDataReader();
		
		while (reader->Read())
		{

		}
	}

};