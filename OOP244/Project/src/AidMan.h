/* Citation and Sources...
Final Project Milestone 5
Module: AidMan
Filename: AidMan.h
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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
#include "Date.h"
#include"iProduct.h"
#include"Utils.h"
#include<cstring>
#include<fstream>

namespace sdds {
	const int sdds_max_num_items = 100;

	class AidMan {
		char* fileName; 
		Menu mainMenu; 
		Date date; 
		iProduct* m_items[sdds_max_num_items]; 
		int m_numItems{};

		// Private function to display menu options
		unsigned int menu() const;

	public:
		// Constructors and destructor
		AidMan(const char* file = nullptr);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();

		// Main functions
		void run(); // Runs the AidMan program
		void save(); // Saves data to a file
		bool load(const char* filename); // Loads data from a file
		int list(const char* sub_desc = nullptr) const; // Lists items with optional description
		int search(int sku) const; // Searches for an item by SKU
		void addItem(); // Adds an item
		void removeItem(); // Removes an item
		void updateQuantity(); // Updates item quantity
		void sortItems(); // Sorts items
		void shipItems(); // Ships items

		// Conversion operator to check if AidMan object is valid
		operator bool() const { return fileName && m_numItems; };

		// Function to deallocate memory
		void deallocate();
	};
}

#endif // !SDDS_AIDMAN_H