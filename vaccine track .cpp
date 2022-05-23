#include<iostream>
#include "user.h"
#include <queue>
#include <vector>
using namespace std;
vector<user*> vec;
queue <user> swap_queue;
queue<user> first_dose;
queue<user> second_dose;

void insert();
void search_by_id();
void insert() {
	int n;
	user* patient = new user();



	cout << "user name =......";
	cin >> patient->name;

	cout << "password =......";
	cin >> patient->password;
	cout << "age =......";
	cin >> patient->age;
	cout << "is vaccinated =......";
	cin >> patient->isVaccinated;

	cout << "country =......";
	cin >> patient->country;
	cout << "government =......";
	cin >> patient->government;


	cout << "ID =......";
	cin >> patient->nationalId;

	cout << "gender =......(Male/Female)";
	cin >> patient->gender;
	//if (patient->gender == "Male")
	//	//patient->m_count++;
	//else if (patient->gender == "Female")
	//	//patient->f_count++;

	
	bool dose_flag=false;
	do{
		cout << "0:first dose , 1 : second dose" << endl;
		int tmp;
		cin >> tmp;
		patient->dosesTaken = tmp;
		if (tmp == 0) {
			first_dose.push(*patient);
			vec.push_back(patient);
			//patient->dose1++;
			cout << "You'll be vaccinated for first dose"<<endl;
			break;
		}
		else if (tmp == 1) {
			second_dose.push(*patient);
			vec.push_back(patient);
			//patient->dose2++;
			cout << "You'll be vaccinated for second dose"<<endl;
			break;
		}
		else {
			cout << "Enter Valid Input";
			dose_flag = true;
		}
	} while (dose_flag);
}
void login() {
	string Natid,pass;
	cout << "Enter National id" << endl;
	cin >> Natid;
	cout << "Enter Password" << endl;
	cin >> pass;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getId() == Natid && vec.at(i)->getPass()==pass ) {
			vec.at(i)->display();
		}
	}

}
void delete_user() {
	string id;
	bool tmp=true;
	cout << "Enter User ID" << endl;
	cin >> id;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getId() == id) {
			bool tmp = vec.at(i)->dosesTaken;
			vec.erase(vec.begin() + i);
			
			}
		}
	if (tmp) {
		while (!second_dose.empty()) {
		second_dose.pop();
		}
		for (int i = 0; i < vec.size(); i++) {
			if (vec.at(i)->dosesTaken == 1)
				second_dose.push(*vec.at(i));
			//Function swap for deleted dose in queue
		}
	}
}
void admin_login() {
	string username;
	string password;
	int choice;
	bool exit_flag=false;
	cout << "Enter Username" << endl;
	cin >> username;
	cout << "Enter password" << endl;
	cin >> password;
	if (username == "admin" && password == "admin") {
		for (int i = 0; i < vec.size(); i++) {
			vec.at(i)->display();
		}

		cout << "PRESS 1 TO DISPLAY CERTAIN USER"<<endl;
		cout << "PRESS 2 TO DELETE CERTAIN USER"<<endl;
		while (!exit_flag) {
			cin >> choice;
			switch (choice) {
			case 1:
				search_by_id();
				break;
			case 2:
				delete_user();
				break;
			default:
				exit_flag = true;
				break;
			}
		}

	}


}
void search_by_id() {
	string id;
	cout << "Enter Id"<<endl;
	cin >> id;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getId() == id) {
			vec.at(i)->display();
		}
	}
}
void menu() {
	bool exit_flag = false;
	int choice;

	while (!exit_flag) {
		cout << "MAIN MENU" << endl;
		cout << "PRESS 1 TO REGESTER"<<endl;
		cout << "PRESS 2 TO login" << endl;
		cout << "PRESS 3 TO login as admin" << endl;
		cout << "PRESS 4 TO exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			insert();
			break;
		case 2:
			login();
			break;
		case 3:
			admin_login();
			break;
		case 4:
			exit_flag = true;
			break;
		}

	}
}
int main() {


	menu();
}
