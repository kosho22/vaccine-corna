#pragma once
#include<iostream>

using namespace std;
class user
{
public:
    string name;
    string password, country, government;
    string nationalId;
	int age;
	bool dosesTaken;
    string gender;
    bool isVaccinated;
	//static int m_count, f_count, dose1, dose2;
    // Constructor
    user(string name, string pass, string cntry, string gov, string natId, int age, int dosestaken, char gen, bool isVac);
	user();
    bool ispass(string pass);
    void display();

	//setters
	void setID(string S);
	void setName(string name);
	void setPass(string password);
	void setGender(char gender);
	void setAge(int age);
	void setGov(string gov);
	void setDosesTaken(int dosesTaken);
	void setIsVacc(bool isVac);

	//getters
	string getId() ;
	string getName();
	string getPass();
	string getGender();
	int getAge();
	string getGov();
	int getDosesTaken();
	bool getIsVacc();
	void Update();
};
