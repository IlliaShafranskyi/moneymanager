#include <iostream>
#include <fstream>

void add_expensive(std::string name_expensive, int summ) {

		std::string name_file = "expenses/" + name_expensive;
		bool res = isExist(name_file);
		if(res) {
				int tmp = readFromFile(name_file);
				summ += tmp;
				writeToFile(name_file, summ);
		}
		else {
				std::cout << "not exist" << std::endl;
				add_first_expense_to_file(name_expensive, summ);
		}

}
void add_first_expense_to_file(std::string name, int summ) {
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

int readFromFile(std::string name_file) {
		std::ifstream in(name_file);
		std::string tmp_sum;
		getline(in, tmp_sum);
		int str_to_int = std::stoi(tmp_sum);
		in.close();


		return str_to_int;
}

void writeToFile(std::string name_file, int number) {
		std::ofstream out;
		out.open(name_file);
		out << number << std::endl;
		out.close();
		
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
										add_expensive("food.txt", summ);
										break;
						}
				}
		}
}


