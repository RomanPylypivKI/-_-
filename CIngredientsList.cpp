#include "CIngredientsList.h"

char CIngredientsList::IngredientsList(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //Прочитати інформацію з файлу
	{
		Show_Info("IngredientsList.txt", "Ingredients", "Volume(m^3)", "Weight(kg)", "ID");
		system("pause");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію, доступно тільки адміністратору
	{
		Write_Info("IngredientsList.txt", "Ingredients : ", "Volume(m^3) : ", "Weight(kg) : ", "ID : ");
		return UserMenuChoice = 'i';
	}
	if (UserMenuChoice == '3') //Знайти інформацію
	{
		Find_Info("IngredientsList.txt");
		return UserMenuChoice = 'i';
	}

	if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
	{
		Edit_Info("IngredientsList.txt", "IngredientsList.txt");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
	{
		Delete_Info("IngredientsList.txt");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
		exit(0);
	else
		return UserMenuChoice = 'i';
}