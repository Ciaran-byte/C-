#pragma once


//数据访问层的代码

//需要解决的问题是，该代码能够支持多种数据库
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