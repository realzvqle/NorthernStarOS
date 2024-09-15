#ifndef UART_HPP_INCLUDED
#define UART_HPP_INCLUDED







#include <stdint.h>
#include <stddef.h>



class uart{
    private:
        unsigned char * uart = (unsigned char *)0x10000000; 
    public:
        void putchar(char c);
        
        void print(const char * str);
};











#endif