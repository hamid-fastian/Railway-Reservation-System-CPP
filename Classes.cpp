#include"Classes.h"

Person::Person()
{
	name = "";
	gender = "";
	username = "";
	phone = "";
	password = "";
	age = 0;
}

void Person::registerUser() 
{
	cin.ignore();
	cout << "Enter your name:";
	getline(cin, name);
	cout << "Enter your age:";
	cin >> age;
	cin.ignore();
	cout << "Enter your gender:";
	getline(cin, gender);
	cout << "Enter your phone number:";
	getline(cin, phone);
	cout << "Enter your username:";
	getline(cin, username);
	cout << "Enter your password:";
	getline(cin, password);
	bool found;
	do
	{
		found = false;
		ifstream Ifile;
		Ifile.open("user.txt", ios::in);
		if (!Ifile.is_open())
		{
			cout << "Error!! File isn't open  for reading purpose\n";
			return;
		}
		string tname, tgender, tusername, tphone, tpassword,header;
		int tempAge;
		getline(Ifile, header);
		while (Ifile >> tname >> tempAge >> tgender >> tphone >> tusername >> tpassword)
		{
			if (tusername == username)
			{
				found = true;
				cout << "\n=======> Username already exits <=======\n";
				cout << "Enter another username:";
				getline(cin, username);
				break;
			}
		}
		Ifile.close();
	} while (found);
	ofstream file;
	file.open("user.txt", ios::app);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open for writing purpose\n";
	}
	file << left << setw(25) << name << setw(15) << age << setw(15) << gender << setw(15) << phone << setw(15) << username << setw(15) << password << endl;
	file.close();
	cout << "\n=======> Registration Successfully completed <=======\n";
}

bool Person::login()
{
	Passenger p;
	Admin a;
	int ch;
	cout << "=====> LOGIN <======\n";
	cout << "1.Passenger Login\n";
	cout << "2.Admin Login\n";
	cout << "3.Back\n";
	cout << "Enter your choice:";
	cin >> ch;
	if (ch == 1)
	{
		cout << "\n========== Passenger Login ==========\n";
		if (p.passengerLogin())
		{
			
			int choice;
			cout << "\n==================================\n";
			cout << "===\n";
			cout << "       PASSENGER PANEL\n";
			cout << "==================================\n";
			cout << "===\n";
			cout << "1.Book Ticket\n";
			cout << "2.View My Tickets\n";
			cout << "3.Cancel Ticket\n";
			cout << "4.Search Train\n";
			cout << "5.Display Profile\n";
			cout << "6.Update Profile\n";
			cout << "7.logout\n";
			cout << "Enter your choice:";
			cin >> choice;
			if (choice == 1)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         BOOK TICKET\n";
				cout << "==================================\n";
				cout << "===\n";
				p.bookTicket();
				
			}
			else if (choice == 2)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         VIEW MY TICKET\n";
				cout << "==================================\n";
				cout << "===\n";
				p.ViewMyTicket();
			}
			else if (choice == 3)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         CANCEL TICKET\n";
				cout << "==================================\n";
				cout << "===\n";
				p.CancelTicket();
			}
			else if(choice == 4)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         SEARCH TRAIN\n";
				cout << "==================================\n";
				cout << "===\n";
				p.searchTrain();
				
			}
			else if (choice==5)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         MY PROFILE\n";
				cout << "==================================\n";
				cout << "===\n";
				p.displayProfile();
			}
			else if (choice == 6)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "        Update PROFILE\n";
				cout << "==================================\n";
				cout << "===\n";
				cout << "\n=======> Note: You are only allowed to change your Phone and Passsword <=======\n";
				p.updateProfile();
				cout << "\n=========== Your Profile Has Been Updated ===========\n";

			}
			else if (choice == 7)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "             LOGOUT\n";
				cout << "==================================\n";
				cout << "===\n";
				return false;
			}
			else
			{
				cout << "\n======> Invalid choice <======\n";
			}
		}
	}
	else if (ch == 2)
	{
		cout << "\n========== ADMIN Login ==========\n";
		int choice;
		if (a.adminLogin())
		{
			
			cout << "\n==================================\n";
			cout << "===\n";
			cout << "          ADMIN PANEL\n";
			cout << "==================================\n";
			cout << "===\n";
			cout << "1.Add Train\n";
			cout << "2.View All Trains\n";
			cout << "3.Update Train\n";
			cout << "4.Delete Train\n";
			cout << "5.View All Reservations\n";
			cout << "6.View All Registered Users\n";
			cout << "7.logout\n";
			cout << "Enter your choice:";
			cin >> choice;
			if (choice == 1)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "          Add Train\n";
				cout << "==================================\n";
				cout << "===\n";
				a.AddTrain();
			}
			else if (choice == 2)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         View All Trains\n";
				cout << "==================================\n";
				cout << "===\n";
				a.ViewAllTrains();
			}
			else if (choice == 3)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         Update Train\n";
				cout << "==================================\n";
				cout << "===\n";
				a.UpdateTrain();
			}
			else if (choice == 4)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "         Delete Train\n";
				cout << "==================================\n";
				cout << "===\n";
				a.DeleteTrain();
			}
			else if (choice == 5)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "        View All Reservations\n";
				cout << "==================================\n";
				cout << "===\n";
				a.ViewAllReservations();
			}
			else if (choice == 6)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "        View Register User\n";
				cout << "==================================\n";
				cout << "===\n";
				a.ViewRegisterUser();
			}
			else if(choice==7)
			{
				cout << "\n==================================\n";
				cout << "===\n";
				cout << "             LOGOUT\n";
				cout << "==================================\n";
				cout << "===\n";
				return false;
			}
			else
			{
				cout << "\n======> Invalid choice <======\n";
			}
		}
	}
	else if(ch==3)
	{
		return false;
	}
}

bool Person:: passengerLogin()
{
	bool check = true;
	string uname, upassword, header;
	string tname, tgender, tusername, tphone, tpassword;
	int tempAge;
	cin.ignore();
	cout << "Enter Username:";
	getline(cin, uname);
	cout << "Enter password:";
	getline(cin, upassword);
	ifstream file;
	file.open("user.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open for reading purpose\n";
		return false;
	}
	getline(file, header);
	while (file >> tname >> tempAge >> tgender >> tphone >> tusername >> tpassword)
	{
		if ((tusername == uname) && (tpassword == upassword))
		{
			loggedInUser = uname;
			check = false;
			return true;
			break;
		}
	}
	if (check)
	{
		cout << "=======> Incorrect username or password <=======\n";
		return false;
	}
	file.close();
}

bool Person::adminLogin()
{
	bool check = true;
	string aId, aName, aPhone, aUname, aPassword;
	string L_A_Name, L_A_Password;
	cin.ignore();
	cout << "Enter Username:";
	getline(cin, L_A_Name);
	cout << "Enter password:";
	getline(cin, L_A_Password);
	ifstream file;
	file.open("admin.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open for reading purpose\n";
		return false;
	}
	while (file >> aId >> aName >> aPhone >> aUname >> aPassword)
	{
		if ((L_A_Name == aUname) && (L_A_Password == aPassword))
		{
			check = false;
			return true;
			break;
		}
	}
	if (check)
	{
		cout << "=======> Incorrect username or password <========\n";
		return false;
	}
	file.close();
}

void Person::displayProfile()
{
	ifstream file;
	string tname, tgender, tusername, tphone, tpassword,header;
	int tempAge;
	file.open("user.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open for reading purpose\n";
		return;
	}
	getline(file, header);
	while (file >> tname >> tempAge >> tgender >> tphone >> tusername >> tpassword)
	{
		if (loggedInUser == tusername)
		{
			cout << "Name     :"<<tname<<endl;
			cout << "Age      :"<<tempAge<<endl;
			cout << "Gender   :"<<tgender<<endl;
			cout << "Phone    :"<<tphone<<endl;
			cout << "Username :"<<tusername<<endl;
			break;
		}
	}
	file.close();
}

void Person::updateProfile()
{
	string tname, tgender, tusername, tphone, tpassword;
	int tempAge;
	string nName, ngender, nUsername, nphone, npassword, header;
	int ntempAge;
	ifstream file;
	file.open("user.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	ofstream nfile;
	nfile.open("temp.txt", ios::app);
	if (!nfile.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	getline(file, header);
	nfile << header<<endl<<endl;
	while (file >> tname >> tempAge >> tgender >> tphone >> tusername >> tpassword)
	{
		if (loggedInUser == tusername)
		{
			nName = tname;
			ntempAge = tempAge;
			ngender = tgender;
			nUsername = tusername;
			cin.ignore();
			cout << "Enter New phone number:";
			getline(cin, nphone);
			cout << "Enter New password:";
			getline(cin, npassword);
			nfile << left << setw(25) << nName << setw(15) << ntempAge << setw(15) << ngender << setw(15) << nphone << setw(15) << nUsername << setw(15) << npassword << endl;
		}
		else
		{
			nfile << left << setw(25) << tname << setw(15) << tempAge << setw(15) << tgender << setw(15) << tphone << setw(15) << tusername << setw(15) << tpassword << endl;
		}
	}
	file.close();
	nfile.close();
	remove("user.txt");
	rename("temp.txt", "user.txt");
}

void Passenger::searchTrain()
{
	bool check=true;
	string sourse, destination,header;
	string TrainID, TrainName, tempSource, tempDestination, DepartureTime, ArrivalTime, TotalSeats, AvailableSeats, Fare;
	ifstream file;
	file.open("trains.txt", ios::in);
	if (!file.is_open())
	{
		cout << "trains.txt is not open\n";
	}
	cin.ignore();
	cout << "Enter Train Sourse:";
	getline(cin, sourse);
	cout << "Enter Train Destination:";
	getline(cin, destination);
	getline(file, header);
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	cout << left
		<< setw(15) << "TrainID"
		<< setw(20) << "TrainName"
		<< setw(15) << "Source"
		<< setw(18) << "Destination"
		<< setw(18) << "DepartureTime"
		<< setw(18) << "ArrivalTime"
		<< setw(15) << "TotalSeats"
		<< setw(18) << "AvailableSeats"
		<< setw(10) << "Fare" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	while (file >> TrainID >> TrainName >> tempSource >> tempDestination >> DepartureTime >> ArrivalTime >> TotalSeats >> AvailableSeats >> Fare)
	{
		if (tempSource == sourse && tempDestination == destination)
		{
			
			cout << left
				<< setw(15) << TrainID
				<< setw(20) << TrainName
				<< setw(15) << tempSource
				<< setw(18) << destination
				<< setw(18) << DepartureTime
				<< setw(18) << ArrivalTime
				<< setw(15) << TotalSeats
				<< setw(18) << AvailableSeats
				<< setw(10) << Fare << endl;
			check = false;
		}
	}
	if (check)
	{
		cout << "\n========> No Train Exist With this Sourse and Destination <========\n";
	}
	file.close();
}

void Passenger::bookTicket()
{
	bool check = true;
	string sourse, destination, header,date;
	string TrainID, TrainName, tempSource, tempDestination, DepartureTime, ArrivalTime;
	int TotalSeats, AvailableSeats, Fare;
	ifstream file;
	file.open("trains.txt", ios::in);
	if (!file.is_open())
	{
		cout << "trains.txt is not open\n";
	}
	cin.ignore();
	cout << "Enter Train Sourse:";
	getline(cin, sourse);
	cout << "Enter Train Destination:";
	getline(cin, destination);
	getline(file, header);
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	cout << left
		<< setw(15) << "TrainID"
		<< setw(20) << "TrainName"
		<< setw(15) << "Source"
		<< setw(18) << "Destination"
		<< setw(18) << "DepartureTime"
		<< setw(18) << "ArrivalTime"
		<< setw(15) << "TotalSeats"
		<< setw(18) << "AvailableSeats"
		<< setw(10) << "Fare" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	while (file >> TrainID >> TrainName >> tempSource >> tempDestination >> DepartureTime >> ArrivalTime >> TotalSeats >> AvailableSeats >> Fare)
	{
		if (tempSource == sourse && tempDestination == destination)
		{
			
			cout << left
				<< setw(15) << TrainID
				<< setw(20) << TrainName
				<< setw(15) << tempSource
				<< setw(18) << destination
				<< setw(18) << DepartureTime
				<< setw(18) << ArrivalTime
				<< setw(15) << TotalSeats
				<< setw(18) << AvailableSeats
				<< setw(10) << Fare << endl;
			check = false;
			
		}
	}
	if (check)
	{
		cout << "\n========> No Train is Available for this Sourse and Destination <========\n";
		return;
	}
	file.close();
	
	
	string tID,reservationID;;
	int seats,totalfare;
	bool ch = true;
	cout << "\nEnter Train ID:";
	getline(cin, tID);
	ifstream nfile;
	nfile.open("trains.txt", ios::in);
	if (!nfile.is_open())
	{
		cout << "trains.txt is not open\n";
	}
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	getline(nfile, header);
	while (nfile >> TrainID >> TrainName >> tempSource >> tempDestination >> DepartureTime >> ArrivalTime >> TotalSeats >> AvailableSeats >> Fare)
	{
		if (TrainID==tID)
		{

			cout << left
				<< setw(15) << TrainID
				<< setw(20) << TrainName
				<< setw(15) << tempSource
				<< setw(18) << destination
				<< setw(18) << DepartureTime
				<< setw(18) << ArrivalTime
				<< setw(15) << TotalSeats
				<< setw(18) << AvailableSeats
				<< setw(10) << Fare << endl;
			ch = false;
			break;
		}
	}
	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "------------------------------" << endl;
	if (ch)
	{
		cout << "\n========> No Train Exist With this Sourse and Destination <========\n";
		return;
	}
	nfile.close();
	cout << "Enter number of seats:";
	cin >> seats;
	if (AvailableSeats >= seats)
	{
		
		
		ifstream rfile;
		rfile.open("reservations.txt",ios::in);

		string header;
		getline(rfile, header);   

		string rid, username, trainid, source, destination;
		string date, bookedSeats, totalFare, status;

		string lastID = "";

		while (rfile >> rid >> username >> trainid >> source >> destination
			>> date >> bookedSeats >> totalFare >> status)
		{
			lastID = rid;
		}
		rfile.close();
		if (lastID == "")
		{
			reservationID = "R001";
		}
		else
		{
			int number = stoi(lastID.substr(1));
			number++;

			if (number < 10)
				reservationID = "R00" + to_string(number);
			else if (number < 100)
				reservationID = "R0" + to_string(number);
			else
				reservationID = "R" + to_string(number);
		}
	}
	else
	{
		cout << "\n=======> Seats are not Available <=========\n";
		return;
	}
	cin.ignore();
	cout << "Enter Journey Date(DD/MM//YY):";
	getline(cin, date);
	totalfare = Fare * seats;
	ofstream rfile;
	rfile.open("reservations.txt", ios::app);
	if (!rfile.is_open())
	{
		cout << "========> Reservation.txt is not open  <==========\n";
	}
	rfile << left
		<< setw(18) << reservationID
		<< setw(18) << loggedInUser
		<< setw(12) << tID
		<< setw(15) << sourse
		<< setw(18) << destination
		<< setw(18) << date
		<< setw(15) << seats
		<< setw(15) << totalfare
		<< setw(12) << "Booked"
		<< endl;
	rfile.close();
	string nTrainID, nTrainName, ntempSource, ntempDestination, nDepartureTime, nArrivalTime, nheader;
	int nTotalSeats, nAvailableSeats, nFare;
	ifstream pfile;
	pfile.open("trains.txt", ios::in);
	if (!pfile.is_open())
	{
		cout << "Error!! (trains.txt) File isn't open\n";
		return;
	}
	ofstream tfile;
	tfile.open("temptrain.txt", ios::app);
	if (!tfile.is_open())
	{
		cout << "Error!!(temptrain.txt) File isn't open\n";
		return;
	}
	getline(pfile, nheader);
	tfile << nheader << endl << endl;
	while (pfile >> nTrainID >> nTrainName >> ntempSource >> ntempDestination >> nDepartureTime >> nArrivalTime>> nTotalSeats>> nAvailableSeats>> nFare)
	{
		if (nTrainID == tID)
		{
			nAvailableSeats -= seats;
			tfile << left << setw(15) << nTrainID << setw(20) << nTrainName << setw(15) << ntempSource << setw(18) << ntempDestination << setw(18) << nDepartureTime << setw(18) << nArrivalTime<<setw(15)<< nTotalSeats<<setw(18) <<nAvailableSeats<<setw(12)<< nFare << endl;
		}
		else
		{
			tfile << left << setw(15) << nTrainID << setw(20) << nTrainName << setw(15) << ntempSource << setw(18) << ntempDestination << setw(18) << nDepartureTime << setw(18) << nArrivalTime << setw(15) << nTotalSeats << setw(18) << nAvailableSeats << setw(12) << nFare << endl;
		}
	}
	pfile.close();
	tfile.close();
	remove("trains.txt");
	rename("temptrain.txt", "trains.txt");
	cout << "\n=========== Your Ticket Has Been Booked ===========\n";
}

void Passenger::ViewMyTicket()
{
	string rID, rName, rTID, rSource, rDestination, rDate, rStatus,header;
	int  rSeats, rFare;
	bool found = false;
	ifstream file;
	file.open("reservations.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! (reservations.txt) isn't open\n";
		return;
	}
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	cout << left
		<< setw(18) << "ReservationID"
		<< setw(18) << "Username"
		<< setw(12) << "TrainID"
		<< setw(15) << "Source"
		<< setw(18) << "Destination"
		<< setw(15) << "JourneyDate"
		<< setw(15) << "SeatsBooked"
		<< setw(15) << "Fare"
		<< setw(12) << "Status" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	getline(file, header);
	while (file >> rID >> rName >> rTID >> rSource >> rDestination >> rDate >> rSeats >> rFare >> rStatus)
	{
		
		if (loggedInUser == rName)
		{
			cout << left
				<< setw(18) << rID
				<< setw(18) << rName
				<< setw(12) << rTID
				<< setw(15) << rSource
				<< setw(18) << rDestination
				<< setw(15) << rDate
				<< setw(15) << rSeats
				<< setw(15) << rFare
				<< setw(12) << rStatus << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "\n=======> No Ticket booked with this Username <=======\n";
		return;
	}
	file.close();
}

void Passenger::CancelTicket()
{
	string rID, rName, rTID, rSource, rDestination, rDate, rStatus,fheader;
	int rSeats, rFare;

	string reservationID;
	bool found = false;

	ifstream file("reservations.txt",ios::in);
	ofstream temp("temp.txt",ios::out);
	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	getline(file, fheader);
	while (file >> rID >> rName >> rTID >> rSource >> rDestination >> rDate >> rSeats >> rFare >> rStatus)
	{

		if (loggedInUser == rName)
		{
			cout << left
				<< setw(18) << rID
				<< setw(18) << rName
				<< setw(12) << rTID
				<< setw(15) << rSource
				<< setw(18) << rDestination
				<< setw(15) << rDate
				<< setw(15) << rSeats
				<< setw(15) << rFare
				<< setw(12) << rStatus << endl;
			found = true;
		}
	}
	cout << "Enter Reservation ID: ";
	cin >> reservationID;
	file.close();
	ifstream newfile("reservations.txt", ios::in);
	getline(newfile, fheader);
	temp << fheader << endl;
	if (!newfile.is_open() || !temp.is_open())
	{
		cout << "Error opening file.\n";
		return;
	}
	
	string header;
	getline(newfile, header);
	temp << header << endl;

	string trainID = "";
	int seats = 0;

	while (newfile >> rID >> rName >> rTID >> rSource >> rDestination
		>> rDate >> rSeats >> rFare >> rStatus)
	{
		if (rID == reservationID && rName == loggedInUser)
		{
			found = true;

			trainID = rTID;
			seats = rSeats;
			rStatus = "Cancelled";
			temp << left
				<< setw(18) << rID
				<< setw(18) << rName
				<< setw(12) << rTID
				<< setw(15) << rSource
				<< setw(18) << rDestination
				<< setw(15) << rDate
				<< setw(15) << rSeats
				<< setw(15) << rFare
				<< setw(15) << rStatus
				<< endl;
		}
		else
		{
			temp << left
				<< setw(18) << rID
				<< setw(18) << rName
				<< setw(12) << rTID
				<< setw(15) << rSource
				<< setw(18) << rDestination
				<< setw(15) << rDate
				<< setw(15) << rSeats
				<< setw(15) << rFare
				<< setw(15) << rStatus
				<< endl;
		}
	}
	newfile.close();
	temp.close();
	remove("reservations.txt");
	rename("temp.txt", "reservations.txt");
	if (!found)
	{
		cout << "\n=======> Reservation ID not found <=======\n";
		return;
	}
	ifstream tfile("trains.txt");
	ofstream tempfile("tempTrain.txt");
	if (!tfile.is_open() || !tempfile.is_open())
	{
		cout << "Error opening trains file.\n";
		return;
	}
	string theader;
	getline(tfile, theader);
	tempfile << theader << endl<<endl;
	string TrainID, TrainName, Source, Destination;
	string DepartureTime, ArrivalTime;
	int TotalSeats, AvailableSeats, Fare;
	while (tfile >> TrainID >> TrainName >> Source >> Destination>> DepartureTime >> ArrivalTime >> TotalSeats>> AvailableSeats >> Fare)
	{
		if (TrainID == trainID)
		{
			AvailableSeats += seats;
		}
		tempfile << left
			<< setw(15) << TrainID
			<< setw(20) << TrainName
			<< setw(15) << Source
			<< setw(18) << Destination
			<< setw(18) << DepartureTime
			<< setw(18) << ArrivalTime
			<< setw(15) << TotalSeats
			<< setw(18) << AvailableSeats
			<< setw(10) << Fare
			<< endl;
	}
	tfile.close();
	tempfile.close();
	remove("trains.txt");
	rename("tempTrain.txt", "trains.txt");
	cout << "\n=======> Ticket Cancelled Successfully <=======\n";
}

void Admin::ViewAllTrains()
{
	string header,id,tname,sourse,destination,departure,arrival;
	int totalSeats, AvailableSeats, Fare;
	ifstream file;
	file.open("trains.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File doesn't open\n";
		return;
	}
	getline(file, header);
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	cout << left
		<< setw(18) << "TrainID"
		<< setw(18) << "TrainName"
		<< setw(12) << "Source"
		<< setw(15) << "Destination"
		<< setw(18) << "DepartureTime"
		<< setw(15) << "ArrivalTime"
		<< setw(15) << "TotalSeats"
		<< setw(15) << "AvailableSeats"
		<< setw(12) << "Fare" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	while (file >> id >> tname >> sourse >> destination >> departure >> arrival >> totalSeats >> AvailableSeats >> Fare)
	{
		cout << left
			<< setw(18) << id
			<< setw(18) << tname
			<< setw(12) << sourse
			<< setw(15) << destination
			<< setw(18) << departure
			<< setw(15) << arrival
			<< setw(15) << totalSeats
			<< setw(15) << AvailableSeats
			<< setw(12) << Fare << endl;
	}
	file.close();
}

void Admin::AddTrain()
{
	string header,id, tname, sourse, destination, departure, arrival;
	int totalSeats, AvailableSeats, Fare;
	string TID, Tname, Tsourse, Tdestination, Tdeparture, Tarrival;
	int TtotalSeats, TAvailableSeats, TFare;
	cin.ignore();
	cout << "Enter Train ID:";
	getline(cin, id);
	cout << "Enter Train Name:";
	getline(cin, tname);
	cout << "Enter Train Sourse:";
	getline(cin, sourse);
	cout << "Enter Train Destination:";
	getline(cin, destination);
	cout << "Enter Train Departure Time (00:00_AM\PM):";
	getline(cin, departure);
	cout << "Enter Train Arrival Time:";
	getline(cin, arrival);
	cout << "Enter Total Seats:";
	cin>>totalSeats;
	AvailableSeats = totalSeats;
	cout << "Enter Train Fare:";
	cin >> Fare;
	bool found;
	bool added = false;
	do
	{
		found = false;
		ifstream Ifile;
		Ifile.open("trains.txt", ios::in);
		if (!Ifile.is_open())
		{
			cout << "Error!! File isn't open  for reading purpose\n";
			return;
		}
		getline(Ifile, header);
		while (Ifile >> TID >> Tname >> Tsourse >> Tdestination >> Tdeparture >> Tarrival >> TtotalSeats >> TAvailableSeats >> TFare)
		{
			if (TID == id)
			{
				found = true;
				cout << "\n=======> TrainID already exits <=======\n";
				cin.ignore();
				cout << "Enter another TrainID:";
				getline(cin,id);
				added = true;
				break;
			}
		}
		Ifile.close();
	} while (found);
	ofstream file;
	file.open("trains.txt", ios::app);
	if (!file.is_open())
	{
		cout << "Error!! File doesn't Open\n";
		return;
	}
	file << left
		<< setw(12) << id
		<< setw(25) << tname
		<< setw(15) << sourse
		<< setw(19) << destination
		<< setw(17) << departure
		<< setw(17) << arrival
		<< setw(15) << totalSeats
		<< setw(19) << AvailableSeats
		<< setw(10) << Fare
		<< endl;
	file.close();
	if (!added)
	{
		cout << "\n=======> Train Added Successfully <=======\n";
	}
}

void Admin::UpdateTrain()
{
	string header, id, tname, sourse, destination, departure, arrival;
	int totalSeats, AvailableSeats, Fare;
	string TID;
	int NewtotalSeats, TAvailableSeats,Bookedseats;
	ViewAllTrains();
	cin.ignore();
	cout << "\nEnter Train ID Which you want to Update:";
	getline(cin, TID);
	ifstream file;
	file.open("trains.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	ofstream nfile;
	nfile.open("temp.txt", ios::out);
	if (!nfile.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	getline(file, header);
	nfile << header << endl << endl;
	while (file >> id >> tname >> sourse >> destination >> departure >> arrival>> totalSeats>> AvailableSeats>> Fare)
	{
		if (TID == id)
		{
			id = TID;
			cout << "Enter Train Name:";
			getline(cin, tname);
			cout << "Enter Train Sourse:";
			getline(cin, sourse);
			cout << "Enter Train Destination:";
			getline(cin, destination);
			cout << "Enter Train Departure Time (00:00_AM\PM):";
			getline(cin, departure);
			cout << "Enter Train Arrival Time:";
			getline(cin, arrival);
			Bookedseats = totalSeats - AvailableSeats;
			cout << "Enter Total Seats:";
			cin >> NewtotalSeats;
		    
			AvailableSeats = NewtotalSeats - Bookedseats;
			if (NewtotalSeats < Bookedseats)
			{
				cout << "=========> Total Seats cannot be less than Booked seats <=========\n";
				return;
			}
			cout << "Enter Fare:";
			cin >> Fare;
			nfile << left
				<< setw(12) << id
				<< setw(25) << tname
				<< setw(15) << sourse
				<< setw(19) << destination
				<< setw(17) << departure
				<< setw(17) << arrival
				<< setw(15) << NewtotalSeats
				<< setw(19) << AvailableSeats
				<< setw(10) << Fare
				<< endl;
		}
		else
		{
			nfile << left
				<< setw(12) << id
				<< setw(25) << tname
				<< setw(15) << sourse
				<< setw(19) << destination
				<< setw(17) << departure
				<< setw(17) << arrival
				<< setw(15) << totalSeats
				<< setw(19) << AvailableSeats
				<< setw(10) << Fare
				<< endl;
		}
	}
	file.close();
	nfile.close();
	remove("trains.txt");
	rename("temp.txt", "trains.txt");

	cout << "\n=======> Train Updated Successfully <=======\n";
}

void Admin::DeleteTrain()
{
	string header, id, tname, sourse, destination, departure, arrival;
	int totalSeats, AvailableSeats, Fare;
	string TID;
	bool found = false;
	bool deleted = false;
	ViewAllTrains();
	cin.ignore();
	cout << "\nEnter Train ID Which you want to Delete:";
	getline(cin, TID);
	ifstream file;
	file.open("trains.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	ofstream nfile;
	nfile.open("temp.txt", ios::out);
	if (!nfile.is_open())
	{
		cout << "Error!! File isn't open\n";
		return;
	}
	getline(file, header);
	nfile << header << endl << endl;
	while (file >> id >> tname >> sourse >> destination >> departure >> arrival >> totalSeats >> AvailableSeats >> Fare)
	{
		if (TID == id)
		{
			found = true;
			if ((totalSeats - AvailableSeats) > 0)
			{
				cout << "\n=======> Train cannot be deleted because bookings exist <=======\n";
			}
			else
			{
				deleted = true;
				continue;
			}
			
		}
		else
		{
			nfile << left
				<< setw(12) << id
				<< setw(25) << tname
				<< setw(15) << sourse
				<< setw(19) << destination
				<< setw(17) << departure
				<< setw(17) << arrival
				<< setw(15) << totalSeats
				<< setw(19) << AvailableSeats
				<< setw(10) << Fare
				<< endl;
		}
	}
	file.close();
	nfile.close();
	if (!found)
	{
		remove("temp.txt");
		cout << "\n=======> Train ID not found <=======\n";
	}
	
	if(deleted)
	{
		remove("trains.txt");
		rename("temp.txt", "trains.txt");
		cout << "\n=======> Train Deleted Successfully <=======\n";
	}
}


void Admin::ViewAllReservations()
{
	string rID, rName, rTID, rSource, rDestination, rDate, rStatus, header;
	int  rSeats, rFare;
	bool found = false;
	ifstream file;
	file.open("reservations.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! (reservations.txt) isn't open\n";
		return;
	}
	cout << "\n---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	cout << left
		<< setw(18) << "ReservationID"
		<< setw(18) << "Username"
		<< setw(12) << "TrainID"
		<< setw(15) << "Source"
		<< setw(18) << "Destination"
		<< setw(15) << "JourneyDate"
		<< setw(15) << "SeatsBooked"
		<< setw(15) << "Fare"
		<< setw(12) << "Status" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------"
		<< "----------------------" << endl;
	getline(file, header);
	while (file >> rID >> rName >> rTID >> rSource >> rDestination >> rDate >> rSeats >> rFare >> rStatus)
	{
		cout << left
			<< setw(18) << rID
			<< setw(18) << rName
			<< setw(12) << rTID
			<< setw(15) << rSource
			<< setw(18) << rDestination
			<< setw(15) << rDate
			<< setw(15) << rSeats
			<< setw(15) << rFare
			<< setw(12) << rStatus << endl;
	}
	file.close();
}

void Admin::ViewRegisterUser()
{
	string Name,Age,Gender,Phone,Username,Password,header;
	ifstream file;
	file.open("user.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Error!! (reservations.txt) isn't open\n";
		return;
	}
	cout << "\n------------------------------------------------------------------------------" << endl;
	cout << left
		<< setw(18) << "Name"
		<< setw(18) << "Age"
		<< setw(12) << "Gender"
		<< setw(15) << "Phone"
		<< setw(18) << "Username"<< endl;

	cout << "------------------------------------------------------------------------------" << endl;
	getline(file, header);
	while (file >> Name >> Age >> Gender >> Phone >> Username )
	{
		cout << left
			<< setw(18) << Name
			<< setw(18) << Age
			<< setw(12) << Gender
			<< setw(15) << Phone
			<< setw(18) << Username << endl;
	}
	file.close();
}