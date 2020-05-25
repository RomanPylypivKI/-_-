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
	void Show_Info(const char fileName[], string data1, string data2, string data3, string data4) //Показати інформацію
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
	}
	void Write_Info(const char fileName[], string data1, string data2, string data3, string data4) //Записати інформацію
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
	}
	void Find_Info(const char fileName[]) //Знайти інформацію
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
	}
	void Edit_Info(const char fileName[], const char fileName1[]) //Редагувати інформацію
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
	}
	void Delete_Info(const char fileName[]) //Видалити інформацію
	{
		fstream couf(fileName, ios::out); //Відкрити файл для видалення
		cout << "Data was successfully deleted." << endl;
		system("pause");
		couf.close();
	}
};

class CPrimary : public CEdit
{
public:
	char Primary(char UserMenuChoice, string name)
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
	}
};

class CGoods : public CEdit
{
public:
	char Goods(char UserMenuChoice, string name)
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
};

class CIngredientsList : public CEdit
{
public:
	char IngredientsList(char UserMenuChoice, string name)
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
};

class CFinances : public CEdit
{
public:
	char Finances(char UserMenuChoice, string name)
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
};

class CShop : public CEdit
{
public:
	char Shop(char UserMenuChoice, string name)
	{
		char i = '1';
		double num;
		double tnum = 0;
		string b;
		double price = 0;
		double total = 0;
		system("cls"); //Очистити екран
		while (i == '1')
		{
			system("cls"); //Очистити екран
			cout << left;
			cout << "#================================================================================#" << endl;
			cout << "# Ice cream production management -> Shopping menu" << setw(32) << " : " << "#" << endl;
			cout << "#================================================================================#" << endl << endl;
			Show_Info("IceCream.txt", "Goods", "Rating(1-5)", "Total number(kg)", "ID");
			system("pause");
			cout << "Goods: ";
			cin >> b;
			cout << "If you buy in bulk the price for 1 kg is 50 UAH" << endl;
			cout << "Enter the number(kg): ";
			cin >> num;
			price = num * 50;
			total += price;
			tnum += num;
			cout << "Price: " << price << endl;
			fstream couf("Shop.txt", ios::app); //Відкрити файл для запису
			couf << setw(9) << b << ' ' << setw(9) << 50 << ' ' << setw(9) << num << ' ' << setw(9) << price << endl;
			cout << "1. Choose more - press '1'" << endl << "2. End the purchase - press '2'" << endl << "Back - press 'b'" << endl << "Quit - press 'q'" << endl <<"# ";
			cin >> i;
		}
		if (i == 'b')
		{
			Delete_Info("Shop.txt");
			return UserMenuChoice = 'b';
		}
		else if (i == 'q')
		{
			exit(0);
		}
		else
		{
			system("cls"); //Очистити екран
			cout << "#==================================Your check==================================#" << endl;
			Show_Info("Shop.txt", "Goods", "Price per 1 kg(UAH)", "Total number(kg)", "Price(UAH)");
			cout << setw(20) << "Total:" << setw(20) << "50" << setw(20) << tnum << setw(20) << total << endl;
			cout << "#==============================================================================#" << endl;
			system("pause");
			Delete_Info("Shop.txt");
			exit(0);
		}
	}
};


class CMain : public CPrimary, public CGoods, public CIngredientsList, public CFinances, public CShop
{
private:
	char UserMenuChoice;
	string name;
public:
	void GetChoiceMenu()////
	{
		cout << "# ";
		cin >> UserMenuChoice;
	}
	void GetUserName()////
	{
		cout << "# Enter your name : "; //Ввід ім'я користувача
		cin >> name;
	}
	void StartMenu() ////
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
	}
	void AuthorizationMenu()////
	{
		system("cls"); //Очистити екран
		cout << left;
		cout << "#========================================#" << endl;
		cout << "# " << setw(38) << "Authorization menu: " << " #" << endl; //Меню авторизації
	}
	void MainMenu()
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
	}////
	void info_Menu(string dirName, string name)
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
	}////
	void shop_Menu(string dirName)
	{
		system("cls"); //Очистити екран
		cout << left;
		cout << "#================================================================================#" << endl;
		cout << "# Ice cream production management ->" << dirName << setw(32) << " : " << "#" << endl;
		cout << "#================================================================================#" << endl << endl;
	}////
	int Main()
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
				{	info_Menu("Primary information", name);
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
	}
};

int main()
{
	CMain main;
	main.Main();
	return 0;
}
