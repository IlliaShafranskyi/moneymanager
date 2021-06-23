#include <iostream>
#include <fstream>

void add_expense_to_file(std::string name, int summ) {
		std::ofstream out;
		std::string dest = "expenses/" + name;
		out.open(dest);
		if(out.is_open()) {
				out << summ << std::endl;
		}
		else {
				std::cout << "failed" << std::endl;
		}
		out.close();
}

bool isExist(std::string file_name) {
		std::ifstream tmp(file_name);
		if(tmp) {
				return true;
		}
		else {
				return false;
		}
		
}

void main_menu() {

		std::ifstream info_user;
		info_user.open("info.txt");

		printf("\033c");
		int balance;
		std::cout << "WELCOME TO THE MONEY MANAGER" << std::endl;
		
		std::string action;
		while(action != "Q") {
				std::cout << "X - add an expense" << std::endl;
				std::cout << "S - show the statistic" << std::endl;
				std::cout << "Q - quit" << std::endl;
				std::cout << "What is your action - ";
				std::cin >> action;

				if(action == "X") {
						int choose_category;
						int summ;
						std::cout << "Adding an expense..." << std::endl;
						std::cout << "1.Food" << std::endl;
						std::cout << "2.Transport" << std::endl;
						std::cout << "3.Recreation(restaurants, cinema etc)" << std::endl;
						std::cout << "4.Health" << std::endl;
						std::cout << "5.Gifts" << std::endl;
						std::cout << "6.Other stuff" << std::endl;
						std::cout << "Choose the category(type a number): " << std::endl;
						std::cin >> choose_category;

						std::cout << "Type a summ: ";
						std::cin >> summ;


						switch(choose_category) {
								case (1):
										bool res = isExist("expenses/food.txt");
										if(res) {
												std::cout << "exist" << std::endl;
										}
										else {
												std::cout << "not exist" << std::endl;
												add_expense_to_file("food.txt", summ);
										}
										break;
						}
				}
		}
}


