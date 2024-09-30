#ifndef TERMINAL_HPP_INCLUDED
#define TERMINAL_HPP_INCLUDED









#include "../text.hpp"



class terminal : text{
    private:
        int i = 3;
        int j = 0;
    public:
        void print(const char* status);
};






#endif