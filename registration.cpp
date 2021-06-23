#include <iostream>
#include <fstream>

void registration_form() {

		printf("\033c");
		std::string login, password;
		std::cout << "Enter your login - ";
		std::cin >> login;
		std::cout << "Enter your password - ";
		std::cin >> password;

		std::ofstream out;	
		out.open(login);
		if(out.is_open()) {
				out << login << std::endl;
				out << password << std::endl;
		}
		out.close();
		
		int balance;
		printf("\033c");
		std::ofstream info_out;
		info_out.open("balance.txt");
		if(info_out.is_open()) {
				std::cout << "Enter your balance = ";
				std::cin >> balance;
				info_out <<  balance << std::endl;
		}	
		info_out.close();
		main_menu();
}
