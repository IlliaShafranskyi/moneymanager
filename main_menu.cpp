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

void statistics(int balance) {
		printf("\033c");
		std::cout << "--------STATISTICS--------" << std::endl;
		std::cout << std::endl;
		std::cout << "Balance = " << balance << std::endl;
		std::cout << std::endl;
		std::string files_names[6] = {"food", "transport", "recreation", "health", "gifts", "others"};
		for(int i = 0; i < 6; i++) {
				if(isExist("expenses/"+files_names[i]+".txt")) {
						int num_from_file = readFromFile("expenses/"+files_names[i]+".txt");
						std::cout << files_names[i] << " - " << num_from_file << std::endl;
				}
				else {
						std::cout << files_names[i] << " - " << 0 << std::endl;
				}
		}
		std::cout << std::endl;
		std::cout << "--------STATISTICS--------" << std::endl;
		std::cout << std::endl;
}
void add_history(std::string category, int summ) {
		std::ofstream out("history.txt", std::ios::app);
		if(out.is_open()) {
				out << category << " - " << summ << std::endl;
		}
		out.close();
}
void show_history() {
		printf("\033c");
		std::cout << "--------HISTORY--------" << std::endl;
		std::cout << std::endl;
		std::string line;

		std::ifstream in("history.txt"); 
		if (in.is_open()) {
	
				while (getline(in, line))
				{
					std::cout << line << std::endl;
				}
		}
		in.close();
		std::cout << std::endl;
		std::cout << "--------HISTORY--------" << std::endl;
		std::cout << std::endl;
}

void main_menu() {
		int balance = readFromFile("balance.txt");

		printf("\033c");
		std::cout << "WELCOME TO THE MONEY MANAGER" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::string action;
		while(action != "Q") {
				std::cout << "------------------------" << std::endl;
				std::cout << "| X - add an expense" << std::endl;
				std::cout << "| S - show the statistic" << std::endl;
				std::cout << "| H - history" << std::endl;
				std::cout << "| Q - quit" << std::endl;
				std::cout << "------------------------"<< std::endl;
				std::cout << std::endl;
				std::cout << "What is your action - ";
				std::cin >> action;

				if(action == "X") {
						printf("\033c");
						int choose_category;
						int summ;
						std::cout << std::endl;
						std::cout << std::endl;
						std::cout << "Adding an expense..." << std::endl;
						std::cout << "-------------------------" << std::endl;
						std::cout << std::endl;
						std::cout << "1.Food" << std::endl;
						std::cout << "2.Transport" << std::endl;
						std::cout << "3.Recreation(restaurants, cinema etc)" << std::endl;
						std::cout << "4.Health" << std::endl;
						std::cout << "5.Gifts" << std::endl;
						std::cout << "6.Other stuff" << std::endl;
						std::cout << std::endl;
						std::cout << "-------------------------" << std::endl;
						std::cout << std::endl;
						std::cout << "Choose the category(type a number): ";
						std::cin >> choose_category;
				
						std::cout << std::endl;
						std::cout << "Type a summ: ";
						std::cin >> summ;
						std::cout << std::endl;
						std::cout << std::endl;

						printf("\033c");
						std::cout << "Added!" << std::endl;

						switch(choose_category) {
								case (1):
										add_expensive("food.txt", summ, balance);
										add_history("food", summ);
										break;
								case (2):
										add_expensive("transport.txt", summ, balance);
										add_history("transport", summ);
										break;
								case (3):
										add_expensive("recreation.txt", summ, balance);
										add_history("recreation", summ);
										break;
								case (4):
										add_expensive("health.txt", summ, balance);
										add_history("health", summ);
										break;
								case (5):
										add_expensive("gifts.txt", summ, balance);
										add_history("gifts", summ);
										break;
								case (6):
										add_expensive("others.txt", summ, balance);
										add_history("others", summ);
										break;
						}
				}
				else if(action == "S") {
						statistics(balance);
				}
				else if(action == "H") {
						show_history();
				}
		}
}


