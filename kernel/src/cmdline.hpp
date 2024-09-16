#ifndef CMDLINE_HPP_INCLUDED
#define CMDLINE_HPP_INCLUDED









#include "text.hpp"



class cmdline : text{
    private:
        int i = 3;
        int j = 0;
    public:
        void print(char* status);
};






#endif