#include "stdio.h"
#include <iostream>

void start_program() {
		std::string chose;
		printf("\033c");
		std::cout << "1. Sign in " << std::endl;
		std::cout << "2. Sign up " << std::endl;
		std::cout << "Enter the option (1 or 2): "; 
		std::cin >> chose;

		if(chose == "1") {
				login();
		}
		else if(chose == "2") {
				registration_form();
		}
}

