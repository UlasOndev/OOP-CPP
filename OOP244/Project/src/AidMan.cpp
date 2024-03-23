/* Citation and Sources...
Final Project Milestone 5
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Ulas Ondev 
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Perishable.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>

using namespace std;
namespace sdds {
	AidMan::AidMan(const char* filename) : mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
		if (filename != nullptr) {
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
		else {
			fileName = nullptr;
		}
	}

	AidMan::~AidMan() {
		delete[] fileName;
		fileName = nullptr;
		deallocate();

	}

	unsigned int AidMan::menu() const{

		cout << "Aid Management System" << endl;
		cout << "Date: " << date << endl;
		cout << "Data file: " << ((fileName) ? fileName : "No file") << "\n---------------------------------";

		return mainMenu.run();
	}

	void AidMan::run() {
		unsigned int choice{};
		ifstream ifstr;
		std::string inputFileName;
		do {
			choice = menu();

			if ((choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) && (fileName == nullptr)) {
				choice = 7; 
			}
			switch (choice) { 
			case 1:

				std::cout << "\n****List Items****\n";
				list();
				break;

			case 2:
				std::cout << "\n****Add Item****\n"; 
				addItem();
				break;
			case 3:
				std::cout << "\n****Remove Item****\n"; 
				removeItem();
				break;
			case 4:
				std::cout << "\n****Update Quantity****\n";
				updateQuantity();
				break;
			case 5:
				std::cout << "\n****Sort****\n";
				sortItems();
				break;
			case 6:
				std::cout << "\n****Ship Items****\n";
				shipItems();
				break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n";
				std::cout << "Enter file name: ";
				std::cin >> inputFileName;
				if (!inputFileName.empty()) {
					char* fileName = new char[inputFileName.length() + 1];
					ut.copyString(fileName, inputFileName.length() + 1, inputFileName.c_str());
					load(fileName);
					delete[] fileName;
				}
				else {
				}
				break;
			case 0:
				save();
				deallocate();
				std::cout << "Exiting Program!\n"; break;
			default:
				std::cout << "Invalid option!\n\n"; break;
			}

		} while (choice != 0);
		ifstr.close();
		
	}

	void AidMan::save(){
		if (fileName){
			ofstream FileWrite(fileName);
			
		if (FileWrite.is_open())
			{
				for (int i = 0; i < m_numItems; i++) {
					m_items[i]->save(FileWrite);
					FileWrite << std::endl;
				}
		}
			else {
				cout << "Failed to open " << fileName << " for writing!" << endl;
			}
			FileWrite.close();
		}
	}

	void AidMan::deallocate() {
		for (size_t i = m_numItems; i > 0;) {
			--i;
			delete m_items[i];
			m_items[i] = nullptr;
		}
		m_numItems = 0;
	}

	bool AidMan::load(const char* filename){
		save();
		deallocate();
		if (fileName){
			delete[] fileName;
			fileName = nullptr;
		}
		if (filename != nullptr && filename[0] != '\0') {
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
		ifstream ifstr(filename);
		if (!ifstr.is_open()){
			cout << "Failed to open " << filename << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << "\n> ";
			int choice = 0;
			cin >> choice;
			if (choice == 1){
				ofstream outfile(fileName);
				if (!outfile.is_open())
				{
					cout << "Failed to create new data file!" << endl;
					return false;
				}
				outfile.close();
			}
			else { fileName = nullptr; }
			return false;
		}
		m_numItems = 0;

		while (!ifstr.eof() && m_numItems < sdds_max_num_items){
			if (ifstr.peek() >= '1' && ifstr.peek() <= '3'){
				m_items[m_numItems] = new Perishable;
			}
			else if (ifstr.peek() >= '4' && ifstr.peek() <= '9'){
				m_items[m_numItems] = new Item;
			}
			else{
				ifstr.clear();
				ifstr.ignore(1000, '\n');
				continue;
			}

			m_items[m_numItems]->load(ifstr);

			if (*m_items[m_numItems]){
				m_numItems++;
			}
		}
		if (*this){
			cout << m_numItems << " records loaded!\n" << endl;

		}
		return (m_numItems > 0);
	}

	int AidMan::list(const char* sub_desc) const{
		int rowNum = 0;
		int number = 0;
		bool validInput = true;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < m_numItems; i++){

			if (sub_desc != nullptr) {
				if (strstr(m_items[i]->getItemDesc(), sub_desc) != nullptr) {
					m_items[i]->linear(true);
					cout << "   " << i + 1 << " | ";
					m_items[i]->display(cout);
					rowNum++;
					cout << endl;
				}
			}
			else {
				m_items[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				m_items[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;


		if (sub_desc == nullptr){
			do {
				cout << "Enter row number to display details or <ENTER> to continue:" << endl;
				cout << "> ";
				cin.ignore();
				if (cin.peek() == '\n') {

					cout << "\n";
					break;
				}
				cin >> number;
				if (number >= 1 && number <= rowNum) {
					m_items[number - 1]->linear(false);
					m_items[number - 1]->display(cout);
					cout << '\n' << '\n';

				}
				else {
					cout << "Invalid input. Please enter a valid row number." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				cin.get(); 

			} while (!validInput);
		}
		else if(sub_desc) {	}

		return rowNum;

	}

	int AidMan::search(int sku) const {
		for (int i = 0; i < m_numItems; ++i) {
			if (*m_items[i] == sku) {
				return i;
			}
		}
		return -1;
	}

	void AidMan::addItem() {
		if (m_numItems >= sdds_max_num_items) {
			std::cout << "Database full!" << std::endl;
			return;
		}

		std::cout << "1- Perishable" << std::endl;
		std::cout << "2- Non-Perishable" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "0- Exit" << std::endl;
		std::cout << "> ";

		int choice;
		std::cin >> choice;

		if (choice == 0) {
			std::cout << "Aborted" << std::endl;
			return;
		}

		iProduct* newItem = nullptr;

		if (choice == 1) {
			newItem = new Perishable();
		}
		else if (choice == 2) {
			newItem = new Item();
		}

		if (newItem) {
			int sku;
			std::cout << "SKU: ";
			std::cin >> sku;

			int foundIndex = search(sku);

			if (foundIndex != -1) {
				std::cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n" << std::endl;
				delete newItem;
			}
			else {
				newItem->read(std::cin);
				if (*newItem) {
					m_items[m_numItems++] = newItem;
					std::cout << std::endl;
				}
				else {
					std::cout << "Invalid item. Aborted." << std::endl;
					delete newItem;
				}
			}
		}
	}

	void AidMan::removeItem() {
		std::cout << "Item description: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		const char* temp = ut.getCString("", '\t');
		list(temp);

		delete[] temp;
		int sku;
		std::cout << "Enter SKU: ";
		std::cin >> sku;

		int index = search(sku);
		if (index == -1) {
			std::cout << "SKU not found!" << std::endl;
			return;
		}

		std::cout << "Following item will be removed: " << std::endl;
		m_items[index]->linear(false);
		m_items[index]->display(std::cout);

		int sure;
		std::cout << "\nAre you sure?\n1- Yes!\n0- Exit\n> ";
		std::cin >> sure;
		if (sure == 1) {
			delete m_items[index];
			for (int i = index; i < m_numItems - 1; ++i) {
				m_items[i] = m_items[i + 1];
			}
			m_items[m_numItems - 1] = nullptr;
			--m_numItems;
			std::cout << "Item removed!\n" << std::endl;
		}
		else {
			return;
		}
	}


	void AidMan::updateQuantity() {
		std::cout << "Item description: ";
		std::cin.ignore();
		const char* temp = ut.getCString("", '\t');
		list(temp);

		delete[] temp;

		int sku;
		std::cout << "Enter SKU: ";
		std::cin >> sku;

		int index = search(sku);

		if (index == -1) {
			std::cout << "SKU not found!" << std::endl;
			return;
		}

		int choice;
		std::cout << "1- Add\n2- Reduce\n0- Exit\n> ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			int currentQuantity = m_items[index]->qty();
			int neededQuantity = m_items[index]->qtyNeeded();
			if (currentQuantity >= neededQuantity) {
				std::cout << "Quantity Needed already fulfilled!\n" << std::endl;
				return;
			}

			int addQuantity = 0;
			do {
				if (addQuantity <= currentQuantity) {
					std::cout << "Quantity to add: ";
				}
				if (addQuantity > currentQuantity) {
					std::cout << "Value out of range [1<=val<=" << neededQuantity << "]: ";
				}
				std::cin >> addQuantity;
			} while (addQuantity < 1 || addQuantity >= neededQuantity);

			m_items[index]->operator+=(addQuantity);
			std::cout << addQuantity << " items added!\n" << std::endl;
			break;
		}
		case 2: {
			int reduceQuantity = 0;
			int currentQuantity = m_items[index]->qty();

			do {
				if (reduceQuantity < currentQuantity) {
					std::cout << "Quantity to reduce: ";
				}
				std::cin >> reduceQuantity;
				if (reduceQuantity > currentQuantity) {
					std::cout << "Value out of range [1<=val<=" << currentQuantity << "]: ";
				}
			} while (reduceQuantity < 1 || reduceQuantity > currentQuantity);

			if (currentQuantity == 0) {
				std::cout << "Quantity on hand is zero!" << std::endl;
				return;
			}

			m_items[index]->operator-=(reduceQuantity);
			std::cout << reduceQuantity << " items removed!\n" << std::endl;
			break;
		}
		default:
			std::cout << "Aborted!\n" << std::endl;
			break;
		}
	}

	void AidMan::sortItems() {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < m_numItems - 1; ++i) {
				if (m_items[i]->qtyNeeded() - m_items[i]->qty() <
					m_items[i + 1]->qtyNeeded() - m_items[i + 1]->qty()) {
					std::swap(m_items[i], m_items[i + 1]);
					sorted = false;
				}
			}
		}
		std::cout << "Sort completed!\n" << std::endl;
	}

	void AidMan::shipItems() {
		std::ofstream shippingOrderFile("shippingOrder.txt");
		if (!shippingOrderFile.is_open()) {
			std::cerr << "Failed to create the shipping order file!\n" << std::endl;
			return;
		}

		shippingOrderFile << "Shipping Order, Date: " << date << std::endl;
		shippingOrderFile << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
		shippingOrderFile << "-----+-------+-------------------------------------+------+------+---------+-----------\n";

		int shippedItems = 0;
		int count = 1;
		for (int i = 0; i < m_numItems; ++i) {
			if (m_items[i]->qty() == m_items[i]->qtyNeeded()) {
				m_items[i]->linear(true);
				shippingOrderFile << "   " << count << " | " << *m_items[i] << std::endl;
				m_items[i]->linear(false);
				count++;
				delete m_items[i];
				for (int j = i; j < m_numItems - 1; ++j) {
					m_items[j] = m_items[j + 1];
				}
				--m_numItems;
				++shippedItems;
				--i;
			}
		}

		shippingOrderFile << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		shippingOrderFile.close();

		std::cout << "Shipping Order for " << shippedItems << " times saved!\n" << std::endl;
	}

}

