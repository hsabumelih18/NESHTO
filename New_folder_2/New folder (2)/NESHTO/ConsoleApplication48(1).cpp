#include <iostream>

using namespace std;
struct GAME
	//declaring the structure GAME
{
	string Platform;
	string Name;
	string ReleaseDate;
	string Specification;
	float price;
	bool bought;
};

//data
int id = 1;
float wallet = 0;
//declaring two general variables
bool MakingGame(GAME* games, int& size, string platform, string name, string releaseDate, string specification, float price)
//Creating the constructor of one game
{
	if (size > 99)
	{
		return false;
	}
	//checking if it is 
	games[size].Platform = platform;
	games[size].Name = name;
	games[size].ReleaseDate = releaseDate;
	games[size].Specification = specification;
	games[size++].price = price;
	if (wallet >= price)
		//keeping the wallet in mind while creating the game
	{
		wallet = wallet - price;
		return true;
	}
	else
	{
		for (int i = id; i <= size; i++)
		{
			games[i] = games[i + 1];
		}
		size--;
		//if you don't have enough money, the game is removed from your list
		return false;

	}
}
void AddMoney()
{
	int newMoney;
	cout << "How much money do you want to add?" << endl << "Add:";
	cin >> newMoney;
	wallet = newMoney + wallet;
	cout << "Money added!" << endl << endl;
}

void RemoveGame(GAME* games, int& size, int index)
//declaring the function for removing a game
{
	cout << "Choose the index of the game you want to remove from the cart(the first number is the index) \n\n";
	cin >> index;
	for (int i = index; i <= size; i++)
	{
		games[i] = games[i + 1];
	}
	size--;
}

//presentation
void ShowAllGames(GAME* games, int& size)
//
{
	string message = "\nList of all the games you have: \n";
	cout << message;
	cout << "Choose a game by its number (the first number).\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << " " << i + 1 << ". " << games[i].Platform << " , " << games[i].Name << " , " << games[i].ReleaseDate << " , " << games[i].Specification << " , ";
		if (games[i].price == 0)
		{
			cout << "FREE";
		}
		else cout << games[i].price;

	}
}
void SeeMoney()
//declaring a function that let's you see your money
{
	if (wallet <= 0)
	{
		cout << "Sorry! You can't add less than 1 dollar in your balance.";
	}
	cout << "Your balance is " << wallet << "$ !" << endl;
}

void EnterGameDetails(GAME* games, int& size)
//declaring the function that actually creates the game
{
k:
	cout << "OK, now enter your game data in this order:\n" << endl;
	string platform, name, releaseDate, specification;
	float  price;
	cout << "\nPlatform: ";
	cin >> platform;
	cout << "\nThe abriviation of the Game you want to buy: ";
	cin >> name;
	cout << "\nRelease date: ";
	cin >> releaseDate;
	cout << "\nSpecification: ";
	cin >> specification;
	cout << "\nPrice: ";
	cin >> price;
	//inputting the main components that define a game
	if (price < 0)
	{
		cout << "Invalid input, please try again!";
		goto k;
	}
	if (MakingGame(games, size, platform, name, releaseDate, specification, price))
	{
		cout << "Successfully purchased! " << endl;
	}
	else
	{
		cout << "Sorry, you don't have enough money!" << endl << "Try adding some more! " << endl;
	}
	//checking if the inputs are correct

}

bool MainMenu(GAME* games, int& size)
//declaring the main menu
{
	int id = 1;
	cout << "\nList: \n 1.Add money to your wallet.\n 2.See your balance.\n 3.Purchase a game. \n 4.See all games. \n 5.Return a game. \n 6.Quit \n\n";


	int n;
	cin >> n;
	switch (n)
		//declaring the switch for the menu(a.k.a the list)
	{
		{
	case 1:
	{
		AddMoney();
		//letting the client input the money they want to add
		return true;

	}
	case 2:
	{
		SeeMoney();
		//letting you see your money
		return true;
	}
	case 3:
	{
		EnterGameDetails(games, size);
		//letting the person declare the components of the game
		return true;
	}


	case 4:
	{
		ShowAllGames(games, size);
		//you can see how many games you have 
		return true;
	}
	case 5:
	{
		cout << "Choose the game you wish to return:";
		ShowAllGames(games, size);
		//showing the all the games
		RemoveGame(games, size, id);
		//inputs the number of the game you want to remove from the list
		return true;
	}
	case 6:
		//the quit case
	{
		return false;
		//returning false to stop the menu function
	}
	default:
	{
		cout << "Error. Please enter again." << endl;
		return true;
	}

		}
	}
}

/*******************/

int main()
//declaring the main function
{
	GAME games[500];
	//declaring the main gamess array
	int size = 0;
	cout << "Hello!\nWelcome to GameZone!\nChoose an option from the main menu down below. \n\n";
	while (MainMenu(games, size));
	cout << "OK! Have a nice day!\n";
}