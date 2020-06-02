#include "CEdit.h"

void CEdit::Show_Info(const char fileName[], string data1, string data2, string data3, string data4) //Показати інформацію
{
	fstream cinf(fileName); //Відкрити файл для зчитування
	while (!cinf)
	{
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	cout << setw(20) << left << data1 << setw(20) << data2 << setw(20) << data3 << setw(20) << data4 << endl; //Вивід шапки таблиці
	while (!cinf.eof())
	{
		cinf >> info_1 >> info_2 >> info_3 >> info_4; //Зчитування даних з файлу для виводу
		if (!cinf.eof())
			cout << setw(20) << left << info_1 << setw(20) << info_2 << setw(20) << info_3 << setw(20) << info_4 << endl; //Вивід даних
	}
	cinf.close(); //Закрити файл для зчитування
};

void CEdit::Write_Info(const char fileName[], string data1, string data2, string data3, string data4) //Записати інформацію
{
	cout << data1;
	cin >> info_1;
	cout << data2;
	cin >> info_2;
	cout << data3;
	cin >> info_3;
	cout << data4;
	cin >> info_4;
	fstream couf(fileName, ios::app); //Відкрити файл для запису
	if (!couf)
	{
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	couf << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << endl; //Запис
	cout << "Data was successfully writen." << endl;
	system("pause");
	couf.close();
};

void CEdit::Find_Info(const char fileName[]) //Знайти інформацію
{
	cout << "information to find : "; //Ввести інформацію для пошуку
	cin >> findinfo_;
	fstream cinf(fileName); //Відкрити файл для зчитування
	while (!cinf)
	{
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	while (!cinf.eof())
	{
		cinf >> info_;
		if (findinfo_ == info_)
		{
			cout << "information was successfully found." << endl;
			isFound = true;
		}
	}
	if (!isFound)
		cout << "Not found!" << endl;
	system("pause");
	cinf.close(); //Закрити файл для зчитування
};

void CEdit::Edit_Info(const char fileName[], const char fileName1[]) //Редагувати інформацію
{
	cout << "information to edit : "; //Ввести слово, яке треба замінити
	cin >> edinfo_;
	cout << "information to replace by : "; //Ввести слово, яким замінити
	cin >> repinfo_;
	fstream cinf(fileName); //Відкрити файл для зчитування
	while (!cinf)
	{
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	fstream couf(fileName1, ios::out); //Відкрити файл перезапису
	if (!couf)
	{
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	while (!cinf.eof())
	{
		cinf >> info_1 >> info_2 >> info_3 >> info_4; //Зчитування даних з файлу для виводу
		if (edinfo_ == info_1)
		{
			info_1 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_2)
		{
			info_2 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_3)
		{
			info_3 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_4)
		{
			info_4 = repinfo_;
			isFound = true;
		}
		if (!cinf.eof())
			couf << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << '\n'; //Перезапис
	}
	if (!isFound)
		cout << "Not found!" << endl;
	else
		cout << "Data was successfully edited." << endl;
	system("pause");
	cinf.close(); //Закрити файл для рзчитування
	couf.close(); //Закрити файл для перезапису
	remove(fileName);
	rename(fileName1, fileName);
};

void CEdit::Delete_Info(const char fileName[]) //Видалити інформацію
{
	fstream couf(fileName, ios::out); //Відкрити файл для видалення
	cout << "Data was successfully deleted." << endl;
	system("pause");
	couf.close();
};