#include "uart.hpp"





void uart::putchar(char c) {
    *uart = c;
    return;
}
        
void uart::print(const char * str) {
    while(*str != '\0') {
        putchar(*str);
        str++;
    }
    return;
}