#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

bool mainPasswordCheck(std::string passwordToCheck){
	bool passwordVerified, containNumber, containUpper;
	if (passwordToCheck.length() < 6){
		std::cout << "password must be at least 6 characters long.\n";
		return false;
	}
	
	for (int i = 0; i < passwordToCheck.length(); i++){
		if (isdigit(passwordToCheck[i]) ){
			containNumber = true;
		}
		
		if (isupper(passwordToCheck[i]) ) {
			containUpper = true;
		}
	}
	
	if(containUpper && containNumber) {
		passwordVerified = true;
	}
	
	else{
		std::cout << "\npassword must contain at least a number an a capital letter." << std::endl;
	}
	return passwordVerified;
}

bool usernameExists(std::string username) {
	std::string	line = "";
	std::ifstream read("REGISTER_FILES.txt");
	std::string usernameOnFile;
	
	while (getline(read, line)) {
		std::string r = line.substr(0, 4);
		std::stringstream inputString(line);
		getline(inputString, usernameOnFile,'-');
		// si la linea empieza con "last tim..." borrar el renglon
		//std::cout<< r << std::endl;
		//if(r == "last"){
		//	line.replace(0,4,"NOPE");
		//}
		if((username == usernameOnFile)){	
			
			return true;
		}
	}
	read.close();
	return false;
}

void writeTime(){
	time_t currentTime = time(0);	
	char* dt = ctime(&currentTime);
	std::ofstream file;
	file.open("REGISTER_FILES.txt", std::ios::app);
	file << "last modification on "<< dt;
	file.close();
	
}

int writeNewFile(const char *file_name,std::string usernameOnFile, std::string passwordOnFile){
	std::ofstream userFile;
	userFile.open(file_name, std::ios::app);
	userFile << usernameOnFile << '-' << passwordOnFile <<' '<< std::endl;
	userFile.close();
	return 0;
}

void changePassword(std::string username, std::string password){
	int currentLine = 0;
	std::string	line = "";
	std::ifstream read("REGISTER_FILES.txt");
	std::string usernameOnFile, passwordOnFile;

	while (getline(read, line)) {
		std::stringstream inputString(line);
		getline(inputString, usernameOnFile,'-');
		getline(inputString, passwordOnFile,' ');
		if((username == usernameOnFile)){	
			passwordOnFile = password;	
		}
		writeNewFile("nuevo.txt", usernameOnFile, passwordOnFile);
		line = "";
	}
	read.close();
	remove("REGISTER_FILES.txt");
	rename("nuevo.txt", "REGISTER_FILES.txt");
	
}
#endif
