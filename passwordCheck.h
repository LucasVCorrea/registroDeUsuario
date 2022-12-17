#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H

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
#endif
