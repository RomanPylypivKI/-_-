#include "CFinances.h"

char CFinances::Finances(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //Прочитати інформацію з файлу
	{
		Show_Info("Finances.txt", "Date", "Income($)", "Expense($)", "Total($)");
		system("pause");
		return UserMenuChoice = 'f';
	}

	if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
	{
		Write_Info("Finances.txt", "Date : ", "Income($) : ", "Expense($) : ", "Total($) : ");
		return UserMenuChoice = 'f';
	}
	if (UserMenuChoice == '3') //Знайти інформацію
	{
		Find_Info("Finances.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
	{
		Edit_Info("Finances.txt", "Finances1.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
	{
		Delete_Info("Finances.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
		exit(0);
	else
		return UserMenuChoice = 'f';
}