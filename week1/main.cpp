#include <iostream>
#include <filesystem>
#include "includes/login.h"
#include "includes/registeration.h"

namespace fs = std::filesystem;
	
// runs on start of the application
void init() {

	// create a path for target dir and checks if it exists
	// create if dosen't exist
	fs::path p_dir = fs::path("./.user");
	if (!(fs::is_directory(p_dir))) {
		fs::create_directory(p_dir);
	}
}


int main(){
	init();
	while(true){
		std::cout<<"___________________________________"<<std::endl; 		
		std::cout<<"\n| press 1. Login 2. Register 0. Exit - ";
		char act;
		bool valid=false;
		while (!valid) {
			std::cin>>act;
			switch (act) {
				case '1':
					login();
					valid = true;
					break;
				case '2':
					registeration();
					valid = true;
					break;
				case '0':
					return 0;
				default:
					std::cout<<"|| Please Enter a valid command !- ";
					break;
			}		
		}
		std::cout<<"___________________________________"<<'\n'<<'\n'; 		
	}
	return 0;
}