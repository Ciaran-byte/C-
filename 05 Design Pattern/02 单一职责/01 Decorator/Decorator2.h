#pragma once
/**
* @file Decorator2.h
*  @brief �ô���ģ���������������
*
* */


//�Ѽ��ܲ����ͻ��������ȡ��������������ʱ��������ʹ���ĸ���
//�汾2��ȱ�����ڣ����еĺ����඼��һ��Stream*�����뻹���Ե���Щ���࣬���ԵĲ���Ӧ�ü�����ȡ����

//ҵ�����
class Stream
{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//������--�ļ���
class FileStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//���ļ���
	}

	virtual void Seek(int position)
	{
		//��λ�ļ���
	}
	virtual void Write(char data)
	{
		//д�ļ���
	}
};

//������--������
class NetworkStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//��������
	}

	virtual void Seek(int position)
	{
		//��λ������
	}
	virtual void Write(char data)
	{
		//д������
	}
};
//������:��������Խ��кϲ���ֻҪ���ڲ�����������ʱ�ض��弴��
//�������ּ̳�Stream������Stream������Ϊ��(1)�����麯���ṹ�������ԣ�2���ܹ�ʹ�ö�̬����
class CrytoStream:public Stream
{
	Stream* stream;//= new FileStream();
public:

	CrytoStream(Stream* stream):stream(stream){}
	
	virtual char Read(int number)
	{
		//����ļ��ܲ���
		stream->Read(number);//���ļ�����
		//����ļ��ܲ���
	}

	virtual void Seek(int position)
	{
		//����ļ��ܲ���
		stream->Seek(position);
		//����ļ��ܲ���
	}

	virtual void Write(char data)
	{
		//����ļ��ܲ���
		stream->Write(data);
		//����ļ��ܲ���
	}
};




//������--�������л���
class BufferStream:public Stream
{
	Stream* stream;
public:
	BufferStream(Stream* stream) :stream(stream) {}

	virtual char Read(int number)
	{
		//����Ļ������
		stream->Read(number);//����
		//����Ļ������
	}

	virtual void Seek(int position)
	{
		//����Ļ������
		stream->Seek(position);
		//����Ļ������
	}

	virtual void Write(char data)
	{
		//����Ļ������
		stream->Write(data);
		//����Ļ������
	}
};






void Process()
{
	//����ʱװ��
	FileStream *s1= new FileStream(); //�ļ���
	CrytoStream* s2 = new CrytoStream(s1); //�����ļ���
	BufferStream* s3 = new BufferStream(s1); //�����ļ���

	BufferStream* s4 = new BufferStream(s2); //���ܻ����ļ���
}