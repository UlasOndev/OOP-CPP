#include "cStrTools.h"

namespace sdds {
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    int strCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
  
    int strnCmp(const char* s1, const char* s2, int len) {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = 0;
    }

    int strLen(const char* str) {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    const char* strStr(const char* str1, const char* str2) {
        const char* faddress = nullptr;
        int i, flen = strLen(str2), slen = strLen(str1);
        char lowerStr1[100]; 
        char lowerStr2[100]; 

        toLowerCaseAndCopy(lowerStr1, str1);
        toLowerCaseAndCopy(lowerStr2, str2);

        for (i = 0; i <= slen - flen && strnCmp(&lowerStr1[i], lowerStr2, flen); i++);
        if (i <= slen - flen) faddress = &str1[i];
        return faddress;
    }
  
    int isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    int isSpace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }
 
    void trim(char word[]) {
        int i;
        while (word[0] && !isAlpha(word[0])) {
            strCpy(word, word + 1);
        }
        i = strLen(word);
        while (i && !isAlpha(word[i - 1])) {
            word[i-- - 1] = 0;
        }
    }

    void toLowerCaseAndCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = toLower(source[i]);
        }
        des[j] = 0;
    }
}
