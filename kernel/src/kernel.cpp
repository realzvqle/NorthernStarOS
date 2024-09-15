

#include "uart.hpp"


extern "C" void kmain(){
    uart urt;
    urt.print("Hello");
}