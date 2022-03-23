#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "prompt.h"

void registeration() {

	// get new data
	std::vector<std::string> user_data = prompt();

	// open the target file 
	std::fstream fio;
	fio.open("./.user/data.csv", std::ios::app);

	// write into the file
	fio<<user_data[0]<<","<<user_data[1]<<'\n';

	// close the file
	fio.close();

	std::cout<<"|| Registration successful !!"<<std::endl;
}
