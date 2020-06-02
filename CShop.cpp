#include "CShop.h"

char CShop::Shop(char UserMenuChoice, string name)
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
		cout << "1. Choose more - press '1'" << endl << "2. End the purchase - press '2'" << endl << "Back - press 'b'" << endl << "Quit - press 'q'" << endl << "# ";
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