#pragma once
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
    class LabelMaker {
        int numLabels;
        Label* labels;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif //!SDDS_LABELMAKER_H
