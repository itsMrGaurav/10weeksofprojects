#pragma once

// prompt for taking input
std::vector<std::string> prompt(){
	std::vector<std::string> user_data;
	std::string username, password;
	std::cout<<"\n|| Username: ";
	std::cin>>username;
	std::cout<<"|| Password: ";
	std::cin>>password;
	user_data.push_back(username);
	user_data.push_back(password);
	return user_data;
}