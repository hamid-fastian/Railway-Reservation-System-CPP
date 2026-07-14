#include"Classes.h"
int main()
{
	int choice;
	bool check;
	Passenger p;
	cout << "==================================\n";
	cout << "===\n";
	cout << "      RAILWAY RESERVATION SYSTEM\n";
	cout << "==================================\n";
	cout << "===\n";
	while (true)
	{
		cout << "\n======> MAIN MENU <======\n";
		cout << "1.login\n";
		cout << "2.Register\n";
		cout << "3.Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		if (choice == 1)
		{
			check = p.login();
		}
		else if (choice == 2)
		{
			p.registerUser();
		}
		else if (choice == 3)
		{
			cout << "\n==================================\n";
			cout << "===\n";
			cout << "         THANK YOU\n";
			cout << "==================================\n";
			cout << "===\n\n";
			cout << "Thank you for using the Railway\nReservation System.\n";
			cout << "Have a safe journey!\n\n";
			cout << "=========> Exiting Program... <=========\n";
			break;
		}
		else
		{
			cout << "=======> Invalid choice <=======\n";
		}
	}
	system("pause");
	return 0;
}