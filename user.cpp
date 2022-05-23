#include "user.h"

user::user(string namee, string password, string country, string government, string nationalId, int age, int dosesTaken, char gender, bool isVaccinated)
{
    this->name = namee;
    this->password = password;
    this->country = country;
    this->government = government;
    this->nationalId=nationalId ;
    this->age = age;
    this->dosesTaken = dosesTaken;
    this->gender = gender;
    this->isVaccinated = isVaccinated;
}

user::user()
{

}

bool user::ispass(string pass)
{
    return password == pass;
}



void user::display()
{
    cout << "UserName: " << name << endl;
    cout << "National ID : " << nationalId << endl;
    if (dosesTaken)
        cout << "Queued for Second dose"<<endl;
    else
        cout << "Queued for first dose"<<endl;
    
}
// Setters
void user::setID(string S) {
    if (S.size() == 13) {
        nationalId = S;
    }
}

void user::setName(string name)
{
    this->name = name;
}

void user::setPass(string password)
{
    this->password = password;
}

void user::setGender(char gender)
{
    this->gender = gender;
}

void user::setAge(int age)
{
    this->age = age;
}

void user::setGov(string gov)
{
    government = gov;
}

void user::setDosesTaken(int dosesTaken)
{
    this->dosesTaken = dosesTaken;
}

void user::setIsVacc(bool isVac)
{
    isVaccinated = isVac;
}

// getters
string user::getId()
{
    return nationalId;
}

string user::getName()
{
    return name;
}

string user::getPass()
{
    return password;
}

string user::getGender()
{
    return gender;
}

int user::getAge()
{
    return age;
}

string user::getGov()
{
    return government;
}

int user::getDosesTaken()
{
    return dosesTaken;
}

bool user::getIsVacc()
{
    return isVaccinated;
}

void user::Update()
{
    int choice;
    string newName, newPass, newGov, newCntry;
    int newAge;
    while (true)
    {
        cout << "Please Choose Informations You Want To Edit : " << endl;
        cout << "1-) Name \n2-) Password \n3-)age \n4-) Government \n5-) Country" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Please Enter The New Name : ";
            cin >> newName;
            name = newName;
        }
        else if (choice == 2) {
            cout << "Please Enter The New Password: ";
            cin >> newPass;
            password = newPass;
        }
        else if (choice == 3) {
            cout << "Please Enter The New Age: ";
            cin >> newAge;
            age = newAge;
        }
        else if (choice == 4) {
            cout << "Please Enter The New Government: ";
            cin >> newGov;
            government = newGov;
        }
        else if (choice == 5) {
            cout << "Please Enter The New Country: ";
            cin >> newCntry;
            country = newCntry;
        }
        else {
            return ;
        }
    }
    cout << "****INFORMATION UPDATED******" << endl;
}
 
