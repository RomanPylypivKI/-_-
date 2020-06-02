#include "CGoods.h"

char CGoods::Goods(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //Прочитати інформацію з файлу
	{
		Show_Info("IceCream.txt", "Goods", "Rating(1-5)", "Total number(kg)", "ID");
		system("pause");
		return UserMenuChoice = 'g';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію, доступно тільки адміністратору
	{
		Write_Info("IceCream.txt", "Goods : ", "Rating(1-5) : ", "Total number(kg) : ", "ID : ");
		return UserMenuChoice = 'g';
	}
	if (UserMenuChoice == '3') //Знайти інформацію
	{
		Find_Info("IceCream.txt");
		return UserMenuChoice = 'g';
	}

	if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
	{
		Edit_Info("IceCream.txt", "IceCream.txt");
		return UserMenuChoice = 'g';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
	{
		Delete_Info("IceCream.txt");
		return UserMenuChoice = 'g';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
		exit(0);
	else
		return UserMenuChoice = 'g';
}