#include "mmio.hpp"






volatile unsigned char mmio::mmio_read(volatile unsigned char* addr){
    return *addr;
}

void mmio::mmio_write(volatile unsigned char* addr, unsigned char value){
    *addr = value;
}