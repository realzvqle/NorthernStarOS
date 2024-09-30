#ifndef KSTDLIB_H_INCLUDED
#define KSTDLIB_H_INCLUDED






#include <cstddef>


class kstdlib {
    public:
        char* strcat(char* destination, const char* source);
        char* itoa(int num, char* str);
        char* itohex(int num, char* str);
        bool strcmp(char* first_string, char* second_string);
        int atoi(const char* str);
        void slice_string(const char* sourcestring, char delimiter, char* firststring, char* secondstring, size_t firstsize, size_t secondsize);
        const char* os_version(); // idk why i added it in kstdlib, but ig let it be here lol
};







#endif