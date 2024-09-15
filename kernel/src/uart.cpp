#include "uart.hpp"



static char prevc;

void uart::putchar(char c) {
    mmio_write(uart_mem, c);
    return;
}
        
void uart::print(const char * str) {
    while(*str != '\0') {
        putchar(*str);
        str++;
    }
    return;
}

char uart::getchar(){
    while(1){
        char c = mmio_read(uart_mem);
        if(prevc == c) continue;
        if(c == NULL) continue;
        else{
            prevc = c;
            return c;
        } 
    }   
}