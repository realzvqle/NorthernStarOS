#ifndef MMIO_HPP_INCLUDED
#define MMIO_HPP_INCLUDED

#include <stdint.h>
#include <stddef.h>




class mmio{
    public:
        volatile unsigned char mmio_read(volatile unsigned char* addr);
        void mmio_write(volatile unsigned char* addr, unsigned char value);

};


#endif