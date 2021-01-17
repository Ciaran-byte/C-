#pragma once
#include<iostream>
#include<map>
using namespace std;
class Font
{
private:
	string key;
public:
	Font(const string& key){} //创建字体对象
};

//创建一个共享池
class FontFactory
{
private:
	map<string, Font*> fontPool;
public:
	Font* GetFone(const string& key)
	{
		map<string, Font*>::iterator item = fontPool.find(key);
		if (item != fontPool.end())
		{
			return fontPool[key];
		}
		else
		{
			Font* font = new Font(key);
			fontPool[key] = font;
			return font;
		}
	}

	void clear()
	{

	}
};