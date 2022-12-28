#include <iostream>
#include "passwordCheck.h"

using namespace std;

void writeOnFile(string usernameToFile, string passwordToFile){
	ofstream userFile;
	userFile.open("REGISTER_FILES.txt", ios::app);
	userFile << usernameToFile << '-' << passwordToFile <<' '<< endl;
	userFile.close();
	
}

bool isLoggedIn(string username, string password){
	int currentLine = 0;
	string	line = "";
	ifstream read("REGISTER_FILES.txt");
	string usernameOnFile, passwordOnFile;
	
	while (getline(read, line)) {
		bool userFind = false;
		bool passFind = false;
		currentLine++;
		stringstream inputString(line);
		getline(inputString, usernameOnFile,'-');
		getline(inputString, passwordOnFile,' ');
		//cout << line << endl;
		if((username == usernameOnFile)){	
			userFind = true;

		}
		if((password == passwordOnFile)){
			passFind = true;

		}
		
		if (userFind && passFind) {
			return true;
			break;
		}
		
		line = "";
	}
	cout << currentLine << endl;
	read.close();
	return false;
}


int main(){
	char choice;
	cout << "=================================" << endl;
	cout << "1: Register\n2: Log in\n3: Exit\nYour choice: ";cin >> choice;
	cout << "=================================" << endl;
	if(choice == '1')
	{
		string username, password;
		
		cout <<	"select an username: "; cin >> username;
		bool userAlreadyExist = usernameExists(username);
		while (userAlreadyExist) {
			cout <<	"\nusername already exists. Try anotherone: "; cin >> username;
			userAlreadyExist = usernameExists(username);
		}
		
		cout <<	"select a password: "; cin >> password;
		bool passwordVerified = mainPasswordCheck(password);
		while (!passwordVerified) {
			cout <<	"\nselect another password: "; cin >> password;
			passwordVerified = mainPasswordCheck(password);
				
		}
		
		writeOnFile(username, password);
		//borrar la hora y el dia viejos
		cout << "Registration was succesfull.\n";
		main();
	}
	
	else if (choice == '2'){
		string usernameLogged, passwordLogged;

		cout << "enter your username: "; cin >> usernameLogged;
		cout << "enter your password: "; cin >> passwordLogged;
		
		bool userHasLogged = isLoggedIn(usernameLogged, passwordLogged);
		
		if (!userHasLogged){
			cout << "\nUsername or password does not match.\n";
		}
		
		else{
			char userChoice;
			string newPassword;
			cout << "\nYou are logged in.\n==================" << endl;
			cout << "*1 - change password\n*2 - Exit" << endl << "==================" << endl;
			cout << "Your choice: "; cin >> userChoice;
			if (userChoice == '1'){
				cout << "select new password: "; cin >> newPassword;
				bool passwordVerified = mainPasswordCheck(newPassword);
				while (!passwordVerified) {
					cout <<	"\nselect another password: "; cin >> newPassword;
					passwordVerified = mainPasswordCheck(newPassword);
				}
				changePassword(usernameLogged, newPassword);
				cout << "password succesfully changed" << endl;
			}
			
			else if(userChoice == '2'){
				cout << "chau" << endl;
			}
		}
		main();
	}
	
	else if(choice == '3'){
		cout << "logged out successfully";
	//	writeTime();
	}
	
	else{
		cout << "non valid option";
		return 1;
	}

	return 0;
}
