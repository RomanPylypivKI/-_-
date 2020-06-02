#include "CPrimary.h"

char CPrimary::Primary(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //Прочитати інформацію з файлу
	{
		Show_Info("Primary information.txt", "Company name", "Director", "Opening date", "Price($)");
		system("pause");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію, доступно тільки адміністратору
	{
		Write_Info("Primary information.txt", "Company name : ", "Director : ", "Opening date : ", "Price($) : ");
		return UserMenuChoice = 'p';
	}
	if (UserMenuChoice == '3') //Знайти інформацію
	{
		Find_Info("Primary information.txt");
		return UserMenuChoice = 'p';
	}

	if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
	{
		Edit_Info("Primary information.txt", "Primary information1.txt");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
	{
		Delete_Info("Primary information.txt");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
		exit(0);
	else
		return UserMenuChoice = 'p';
};