#pragma once
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {
    class Label {
        char frame[9];
        char* content;

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* contentArg);
        ~Label();
        void setFrame(const char* frameArg);
        void setContent(const char* contentArg);
        void readLabel();
        std::ostream& printLabel() const;
        void text(const char* contentArg);
    };
}

#endif //!SDDS_LABEL_H
