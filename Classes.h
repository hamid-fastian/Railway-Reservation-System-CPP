#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

class Person {
protected:
	string name;
	string gender;
	string phone;
	string username;
	string password;
	string loggedInUser;
	int age;
public:
	Person();
	void registerUser();
	bool login();
	bool passengerLogin();
	bool adminLogin();
	void displayProfile();
	void updateProfile(); 
};

class Passenger:public Person {
protected:

public:
	void searchTrain();
	void bookTicket();
	void ViewMyTicket();
	void CancelTicket();
};

class Admin :public Person {
protected:
public:
	void ViewAllTrains();
	void AddTrain();
	void UpdateTrain();
	void DeleteTrain();
	void ViewAllReservations();
	void ViewRegisterUser();
};
