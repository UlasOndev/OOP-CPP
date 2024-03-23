#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"

using namespace std;

namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels) {
        numLabels = noOfLabels;
        labels = new Label[numLabels]; 
    }


    void LabelMaker::readLabels() {
        if (labels != nullptr) {
            cout << "Enter " << numLabels << " labels:" << endl;
            for (int i = 0; i < numLabels; i++) {
                cout << "Enter label number " << i + 1 << endl << "> ";
                labels[i].readLabel();
            }
        }
    }

    void LabelMaker::printLabels() {
        if (labels != nullptr) {
            for (int i = 0; i < numLabels; i++) {
                labels[i].printLabel();
                cout << endl;
            }
        }
    }

    LabelMaker::~LabelMaker() {
        delete[] labels;
    }
}
