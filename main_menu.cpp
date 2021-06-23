#include <iostream>
#include <fstream>


void add_first_expense_to_file(std::string name, int summ, int balance);
int readFromFile(std::string name_file);
void writeToFile(std::string name_file, int number);
bool isExist(std::string file_name);

void add_expensive(std::string name_expensive, int summ, int balance) {

		std::string name_file = "expenses/" + name_expensive;
		bool res = isExist(name_file);
		if(res) {
				int tmp = readFromFile(name_file);
				summ += tmp;
				balance -= summ;
				writeToFile(name_file, summ);
				writeToFile("balance.txt", balance);

		}
		else {
				add_first_expense_to_file(name_expensive, summ, balance);
		}

}
void add_first_expense_to_file(std::string name, int summ, int balance) {
		std::ofstream out;
		std::string dest = "expenses/" + name;
		out.open(dest);
		if(out.is_open()) {
				balance -= summ;
				out << summ << std::endl;
		}
		else {
				std::cout << "failed" << std::endl;
		}
		out.close();
		writeToFile("balance.txt", balance);
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
		int balance = readFromFile("balance.txt");

		printf("\033c");
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
										add_expensive("food.txt", summ, balance);
										break;
								case (2):
										add_expensive("transport.txt", summ, balance);
										break;
								case (3):
										add_expensive("recreation.txt", summ, balance);
										break;
								case (4):
										add_expensive("health.txt", summ, balance);
										break;
								case (5):
										add_expensive("gifts.txt", summ, balance);
										break;
								case (6):
										add_expensive("others.txt", summ, balance);
										break;
						}
				}
		}
}


