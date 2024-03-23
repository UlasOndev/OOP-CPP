#include <iostream>
#include <fstream>
#include <cstring>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

void sdds::phoneDir(const char* programTitle, const char* fileName) {
    cout << programTitle << " phone direcotry search" << endl;
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "-------------------------------------------------------" << endl;
        cout << fileName << " file not found!" << endl;
        cout << "Thank you for using " << programTitle << " directory." << endl;
        return;
    }

    char partialName[51];
    cout << "-------------------------------------------------------" << endl;
    cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;

    while (true) {
        cout << "> ";
        cin.getline(partialName, 51);

        if (strcmp(partialName, "!") == 0) {
            break;
        }

        bool found = false;
        char name[51], areaCode[4], prefix[4], number[5];

        while (file.getline(name, 51, '\t')) {
            file.getline(areaCode, 4, '\t');
            file.getline(prefix, 4, '\t');
            file.getline(number, 5, '\n');

            if (strStr(name, partialName)) {
                found = true;
                cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
            }
        }

        if (!found) {
        }

        cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;

        file.clear();
        file.seekg(0);
    }

    file.close();
    cout << "Thank you for using " << programTitle << " directory." << endl;
}

