

#include "uart.hpp"
#include "hal.hpp"







extern "C" void kmain(){
    uart urt;
    HAL hal;
    urt.print("Hello\n\n");
    while(1){
        char c = urt.getchar();
        if(c == 'p'){
            urt.print("Hello!");
        }
        else urt.print("hi");
    }

    hal.halt_system();
}