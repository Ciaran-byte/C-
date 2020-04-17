#include<iostream>
#include<vector>
using namespace std;
class num_sequence
{
public:
	//01 ����ָ����Ķ�����ָ��
	typedef void(num_sequence::* Ptr)(int pos);

	//02 ������¼�����д����˶���������
	inline static int num_of_sequence();

	//03 ͨ����������ָ����Ķ�����ָ��
	inline static Ptr ns_type(int index);

	//04 �趨����ָ��ָ���ĸ�����
	void set_seqence(Ptr seqPtr);
	//05 �������еĲ���ֵ����
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

//��ָ����ĺ��������ָ�붨���˱���
typedef  num_sequence::Ptr Ptr;

//static��Ķ���
const  int num_sequence::_num_sequence;
Ptr num_sequence::func[_num_sequence] =
{
	&num_sequence::Square,
	&num_sequence::Pentagonal,
	&num_sequence::Pell
};
vector<vector<int> > num_sequence::seq(_num_sequence);

//���ڵĺ���
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




