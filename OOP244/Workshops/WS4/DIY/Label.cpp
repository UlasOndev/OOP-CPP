#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include <cstring>

using namespace std;

namespace sdds {
    Label::Label() {
        content = nullptr;
        setFrame("+-+|+-+|");
    }

    Label::Label(const char* frameArg) {
        content = nullptr;
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* contentArg) {
        content = nullptr;
        setFrame(frameArg);
        setContent(contentArg);
    }

    Label::~Label() {
        delete[] content;
    }

    void Label::setFrame(const char* frameArg) {
        strcpy(frame, frameArg);
    }

    void Label::setContent(const char* contentArg) {
        delete[] content;
        if (contentArg != nullptr) {
            int length = strlen(contentArg);
            content = new char[length + 1];
            strcpy(content, contentArg);
        }
        else {
            content = nullptr;
        }
    }

    void Label::readLabel() {
        char input[71];
        cin.getline(input, 71);
        setContent(input);
    }

    ostream& Label::printLabel() const {
        if (content == nullptr) {
            return cout;
        }
        else {
            int length = strlen(content);
            cout << frame[0];
            for (int i = 0; i < length + 2; i++) {
                cout << frame[1];
            }
            cout << frame[2] << endl;

            cout << frame[7] << ' ';
            for (int i = 0; i < length; i++) {
                cout << ' ';
            }
            cout << ' ' << frame[3] << endl;

            cout << frame[7] << ' ';
            cout << content << ' ';
            cout << frame[3] << endl;

            cout << frame[7] << ' ';
            for (int i = 0; i < length; i++) {
                cout << ' ';
            }
            cout << ' ' << frame[3] << endl;

            cout << frame[6];
            for (int i = 0; i < length + 2; i++) {
                cout << frame[5];
            }
            cout << frame[4];

            return cout;
        }
    }
    void Label::text(const char* contentArg) {
        setContent(contentArg);
    }
}
