#include <iostream>
#include <fstream>

void login() {
		printf("\033c");

		std::string login, password;
		std::cout << "Enter your login - ";
		std::cin >> login;
		std::cout << "Enter your password - ";
		std::cin >> password;

		std::ifstream out(login);
		if(out) {
				std::string tmp_password, tmp_login;
				getline(out, tmp_login);
				getline(out, tmp_password);

				if(login == tmp_login && password == tmp_password) {
						std::cout << "Success enter" << std::endl;
						out.close();
						main_menu();
				}
				else {
						std::cout << "Invalid password" << std::endl;
				}
		}
		else {
				std::cout << "User is not found" << std::endl;
		}
		out.close();
}
