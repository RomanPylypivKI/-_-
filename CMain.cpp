#include "CMain.h"

void CMain::GetChoiceMenu()////
{
	cout << "# ";
	cin >> UserMenuChoice;
};

void CMain::GetUserName()////
{
	cout << "# Enter your name : "; //Ввід ім'я користувача
	cin >> name;
};

void CMain::StartMenu() ////
{
	system("cls"); //Очищення екрану

	//Стартове меню:

	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Ice cream production management : " << " #" << endl;
	cout << "# " << setw(38) << "Main menu - press 'm'" << " #" << endl; //Перехід в головне меню
	cout << "# " << setw(38) << "Shoping menu - press 's'" << " #" << endl; //Перехід в головне меню
	cout << "# " << setw(38) << "Quit - press 'q'" << " #" << endl; //Вихід з програми кнопкою
	cout << "#========================================#" << endl << endl;
};

void CMain::AuthorizationMenu()////
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Authorization menu: " << " #" << endl; //Меню авторизації
};

void CMain::MainMenu()
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "User: " << name << endl;
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Ice cream production management -> Main menu : " << " #" << "\n";
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Primary information - press 'p'" << " #" << endl; //Перехід в розділ основної інформації 
	cout << "# " << setw(52) << "Goods - press 'g'" << " #" << endl; //Перехід до списку товарів
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(52) << "Ingredients list - press 'i'" << " #" << endl; //Перехід в таблицю інгредієнтів
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(52) << "Finances - press 'f'" << " #" << endl; //Перехід в розділ фінансів 
	cout << "# " << setw(52) << "Back - press 'b'" << " #" << endl; //Повернення до попереднього меню 
	cout << "# " << setw(52) << "Quit - press 'q'" << " #" << endl; //Вихід з програми 
	cout << "#======================================================#" << endl << endl;
};

void CMain::info_Menu(string dirName, string name)
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "User: " << name << endl;
	cout << "#================================================================================#" << endl;
	cout << "# Ice cream production management -> Main menu -> " << setw(28) << dirName << " : " << "#" << endl;
	cout << "#================================================================================#" << endl;
	cout << "# " << setw(78) << "Show data - press '1'" << " #" << endl; //Показати інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Write data - press '2'" << " #" << endl; //Записати інформацію
	cout << "# " << setw(78) << "Find data - press '3'" << " #" << endl; //Знайти інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Edit data - press '4'" << " #" << endl; //Знайти інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Delete data - press '5'" << " #" << endl; //Видалити інформацію
	cout << "# " << setw(78) << "Back - press 'b'" << " #" << endl; //Повернутися до попереднього меню
	cout << "# " << setw(78) << "Quit - press 'q'" << " #" << endl; //Вихід з програми кнопкою 'q'
	cout << "#================================================================================#" << endl << endl;
};

int CMain::Menu()
{
	while (true)
	{
		StartMenu(); //Стартове меню
		GetChoiceMenu();
		if ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //Перехід в меню авторизації
		{
			AuthorizationMenu(); //Меню авторизації
			GetUserName();
		}
		while ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //Перехід в головне меню
		{
			MainMenu();
			GetChoiceMenu();
			while ((UserMenuChoice == 'p') || (UserMenuChoice == 'P')) //Перехід в розділ основної інформації
			{
				info_Menu("Primary information", name);
				GetChoiceMenu();
				UserMenuChoice = Primary(UserMenuChoice, name);
			}
			while ((UserMenuChoice == 'g') || (UserMenuChoice == 'G')) //Перехід до таблиці з товаром
			{
				info_Menu("Ice cream list", name);
				GetChoiceMenu();
				UserMenuChoice = Goods(UserMenuChoice, name);
			}
			while ((UserMenuChoice == 'i') || (UserMenuChoice == 'I')) //Перехід до таблиці з інгредієнтами
			{
				info_Menu("Ingredients list", name);
				GetChoiceMenu();
				UserMenuChoice = IngredientsList(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'f') || (UserMenuChoice == 'F')) && (name == "admin")) //Перехід в розділ фінансів
			{
				info_Menu("Finances", name);
				GetChoiceMenu();
				UserMenuChoice = Finances(UserMenuChoice, name);
			}
			if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
				break;
			if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
				exit(0);
			else
				UserMenuChoice = 'm';
		}
		while ((UserMenuChoice == 's') || (UserMenuChoice == 'S')) //перехід в меню закупок
		{
			UserMenuChoice = Shop(UserMenuChoice, name);
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
	}
};