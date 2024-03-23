/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char*& name) {
      char temp[128];
      if (fscanf(fptr, "%127[^,],", temp) == 1) {
         name = new char[strlen(temp) + 1];
         strcpy(name, temp);
         return true;
      }
      return false;
   }

   bool read(int& empNo) {
      return fscanf(fptr, "%d,", &empNo) == 1;
   }

   bool read(double& salary) {
      return fscanf(fptr, "%lf,", &salary) == 1;
   }
}
