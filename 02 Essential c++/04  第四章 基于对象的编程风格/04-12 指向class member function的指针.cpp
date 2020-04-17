#include<iostream>
#include<vector>
using namespace std;
class num_sequence
{
public:
	//01 定义指向类的对象函数指针
	typedef void(num_sequence::* Ptr)(int pos);

	//02 用来记录类中有储存了多少种数列
	inline static int num_of_sequence();

	//03 通过索引访问指向类的对象函数指针
	inline static Ptr ns_type(int index);

	//04 设定函数指针指向哪个函数
	void set_seqence(Ptr seqPtr);
	//05 各种数列的查找值函数
	void Square(int pos);
	void Pentagonal(int pos);
	void Pell(int pos);
	void display(int pos);
private:
	const static int _num_sequence = 3;
	Ptr _seqPtr = 0;
	 static Ptr func[_num_sequence];
	 vector<int>* _elem;
	 static vector<vector<int> > seq;
	

};

//将指向类的函数对象的指针定义了别名
typedef  num_sequence::Ptr Ptr;

//static类的定义
const  int num_sequence::_num_sequence;
Ptr num_sequence::func[_num_sequence] =
{
	&num_sequence::Square,
	&num_sequence::Pentagonal,
	&num_sequence::Pell
};
vector<vector<int> > num_sequence::seq(_num_sequence);

//类内的函数
 int num_sequence::num_of_sequence()
{
	return _num_sequence;
}
 inline  Ptr num_sequence::ns_type(int index)
 {
	 return func[index];
 }
 void num_sequence::set_seqence(Ptr seqPtr)
 {
	 _seqPtr = seqPtr;
 }

 void num_sequence::Square(int pos)
 {
	 _elem = &seq[0];
	 int size = _elem->size();
	 if (size<pos+1)
	 {
		 for (int i = size; i < pos+1; i++)
		 {
			 _elem->push_back((i+1) * (i+1));
		 }
	 }
	 cout << (*_elem)[pos]<<endl;
 }
 void num_sequence::Pentagonal(int pos)
 {
	 _elem = &seq[1];
	 int size = _elem->size();
	 if (size < pos + 1)
	 {
		 for (int i = size; i < pos + 1; i++)
		 {
			 _elem->push_back((i + 1) * (i + 2)/2);
		 }
	 }
	 cout << (*_elem)[pos]<<endl;
 }
 void num_sequence::Pell(int pos)
 {
	 _elem = &seq[2];
	 int size = _elem->size();
	 if (size < pos + 1)
	 {
		 for (int i = size; i < pos + 1; i++)
		 {
			 _elem->push_back((i + 1));
		 }
	 }
	 cout << (*_elem)[pos]<<endl;
 }

 void num_sequence::display(int pos)
 {
	 (*this.*_seqPtr)(pos);
 }

int main()
{
	num_sequence ns;
	const int pos = 8;
	for (int i = 0; i < num_sequence::num_of_sequence(); i++)
	{
		ns.set_seqence(num_sequence::ns_type(i));
		ns.display(pos);
	}

	return 0;
}




