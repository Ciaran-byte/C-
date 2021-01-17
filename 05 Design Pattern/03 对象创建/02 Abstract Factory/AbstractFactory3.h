#pragma once

//�԰���2�Ľ�������ǽ����������ŵ�һ�����н���ʵ��
//��Ϊ�����������������

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


//-----------------����----------------
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


//���ݷ�����
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