#ifndef CEdit__
#define CEdit__

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class CEdit
{
protected:
	string info_1, info_2, info_3, info_4, findinfo_, info_, repinfo_, edinfo_;
	bool isFound = false;
public:
	void Show_Info(const char fileName[], string data1, string data2, string data3, string data4); //Показати інформацію
	void Write_Info(const char fileName[], string data1, string data2, string data3, string data4); //Записати інформацію
	void Find_Info(const char fileName[]); //Знайти інформацію
	void Edit_Info(const char fileName[], const char fileName1[]); //Редагувати інформацію
	void Delete_Info(const char fileName[]); //Видалити інформацію
};
#endif