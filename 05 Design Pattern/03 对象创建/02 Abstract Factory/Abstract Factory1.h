#pragma once


//���ݷ��ʲ�Ĵ���

//��Ҫ����������ǣ��ô����ܹ�֧�ֶ������ݿ�
class EmployeeDA0
{
public:
	vector<EmployeeD0> GetEmployees()
	{
		SqlConnection* connection = new SqlConnection();

		connection->ConnectionString = "...";

		SqlCommand* command = new SqlCommand();

		command->CommandText = "...";

		SqlDataReader* reader = command->ExecuteReader();
		while (reader->Read())
		{

		}
	}

};