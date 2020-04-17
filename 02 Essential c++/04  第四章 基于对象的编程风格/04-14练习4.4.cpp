#include<iostream>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;

class UserProfile
{
public:
	enum uLevel
	{
		beginner,
		intermediate,
		advanced,
		guru
	};

	//用户的初始化
	UserProfile(string login,uLevel level=beginner);
	UserProfile();

	//运算符重载
	bool operator ==(const UserProfile& rhs)
	{
		return _login == rhs._login;
	}
	bool operator !=(const UserProfile& rhs)
	{
		return !(*this == rhs);
	}
	//输出私有变量
	inline string login() { return _login; }
	inline uLevel level() { return _level; }
	inline int times_logged() { return _times_logged; }
	inline int guess() { return _guess_time; }
	inline int correct_time() { return _correct_time; }


private:
	string _login;
	uLevel _level;
	int _times_logged;
	int _guess_time;
	int _correct_time;

	
};

UserProfile::UserProfile()
{
	_login = "guest";
	static int id=0;
	char buffer[16];
	_itoa_s(id++, buffer, 10);
	_login += buffer;

	_guess_time = 0;
	_correct_time = 0;
	_times_logged = 1;

	_level = beginner;
}
UserProfile::UserProfile(string login, uLevel level ):_login(login),_level(level)
{
	_guess_time = 0;
	_correct_time = 0;
	_times_logged = 1;

	
}

ostream& operator<<(ostream& os, UserProfile& rhs)
{
	os << rhs.login() << " "
		<< rhs.level() << " "
		<< rhs.times_logged() << " "
		<< rhs.guess() << " "
		<< rhs.correct_time() << endl;
	return os;
}

int main()
{

	UserProfile a;
	cout << a;
	UserProfile b;
	cout << b;


}

