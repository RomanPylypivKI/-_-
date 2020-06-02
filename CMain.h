#include "CPrimary.h"
#include "CGoods.h"
#include "CIngredientsList.h"
#include "CFinances.h"
#include "CShop.h"

class CMain : public CPrimary, public CGoods, public CIngredientsList, public CFinances, public CShop
{
private:
	char UserMenuChoice;
	string name;
public:
	void GetChoiceMenu();
	void GetUserName();
	void StartMenu();
	void AuthorizationMenu();
	void MainMenu();
	void info_Menu(string dirName, string name);
	int Menu();
};