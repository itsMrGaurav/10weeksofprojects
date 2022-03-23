#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "prompt.h"

// password update
void update_password(std::string username) {

	// set file pointer to the beginning of the file
	std::fstream fin;
	fin.open("./.user/data.csv", std::ios::in);

	// prompt for a new password
	std::string new_password, user;
	std::cout<<"||| New Password:  ";
	std::cin>>new_password;

	if (new_password == ""){
		return;
	}

	// repeat the same process as in login
	// and store all but one needs to be updated  
	// into separate file
	std::fstream temp;
	temp.open("./.user/temp_data.csv", std::ios::out);
	while(getline(fin, user)){

		std::stringstream s1(user);
		std::vector<std::string> v;
		std::string word;
		while(getline(s1, word, ',')){
			v.push_back(word);
		}

		// checks if username matches
		// if not ,copy the whole user to new file
		// else update the entry
		if (v[0] != username){
			temp<<user<<'\n';
		} else {
			temp<<username<<','<<new_password<<'\n';
		}
	}
	std::cout<<"|| Password Updated!! "<<std::endl;

	temp.close();
	fin.close();

	// at last delete the old file 
	// and rename the temp data file to data file
	remove("./.user/data.csv");
	rename("./.user/temp_data.csv", "./.user/data.csv");
	return;
}


void login(){

	std::string line, user, username, password;
	std::vector<std::string> user_data = prompt();

	// create a file object
	std::fstream fin;

	// open the target file for reading
	fin.open("./.user/data.csv" ,std::ios::in);

	
	// separate the contents of the file using 
	// newline as delimiter and store it in user
	// variable
	while(getline(fin, user)){

		// separate the user data using comma 
		// as delimiter and store it inside a vector
		std::stringstream s1(user);
		std::vector<std::string> v;
		std::string word;
		while(getline(s1, word, ',')){
			v.push_back(word);
		}

		// verify the user filled data with 
		// available data
		if (v[0] == user_data[0] && v[1] == user_data[1]) {
			std::cout<<"|| Log in successful!"<<std::endl;
			char temp;

			// prompt to be shown once logged in
			while(true){				
				std::cout<<"\n||| 1. Update Password 2. Back - ";
				std::cin>>temp;
				switch (temp) {
					case '1':
						fin.close();
						update_password(user_data[0]);
						return;
					case '2':
						return;
				}
			}
		}
	}
	std::cout<<"|| Record Not Found !"<<std::endl;
	return;
}
