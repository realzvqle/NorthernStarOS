

#include "uart.hpp"


extern "C" void kmain(){
    uart urt;
    urt.print("Hello\n\n");
    while(1){
        char c = urt.getchar();
        urt.print(&c);
    }
}