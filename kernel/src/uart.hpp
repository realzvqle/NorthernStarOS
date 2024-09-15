#ifndef UART_HPP_INCLUDED
#define UART_HPP_INCLUDED







#include <stdint.h>
#include <stddef.h>
#include "mmio.hpp"


class uart : public mmio {
    private:
        volatile unsigned char* uart_mem = (volatile unsigned char *)0x10000000; 
    public:
        void putchar(char c);
        void print(const char * str);
        char getchar();
};




#endif