#include "uart.hpp"
#include "kmalloc.hpp"



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


memalloc mem;

char* uart::array_adder(size_t size) {
    char* array = (char*)mem.alloc(size);
    // if (!array) {
    //     return NULL;  
    // }

    for (int jj = 0; jj < size - 1; jj++) {
        array[jj] = '\0';  
    }
    static char former_char;

    int index = 0;
    while (index < (size - 1)) { 

        char character = getchar();
        // if(character == former_char){
        //     continue;
        // }
        if(character == NULL){

            continue;
        }
        if (character == 'P') {
            array[index] = '\0';  
            break;
        }
        array[index] = character; 
        char temp[2];
        temp[0] = character;
        temp[1] = '\0';  
        index++;
        print(temp);
        former_char = character;
        
    }

    if (index == (size - 1)) {
        array[size - 1] = '\0';  
    }

    return array;
}


char* uart::gets(int size){
    print("\n> ");
    char* result = array_adder(size);
    print("\n");
    print(result);
    return result;
}


