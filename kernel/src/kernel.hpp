#ifndef KERNEL_HPP_INCLUDED
#define KERNEL_HPP_INCLUDED






#include "HAL/hal.hpp"

class kernel : public HAL {
    public:
        void kernel_suicide(char* error);
};




#endif