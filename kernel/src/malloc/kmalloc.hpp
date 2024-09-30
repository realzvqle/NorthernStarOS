#ifndef KMALLOC_HPP_INCLUDED
#define KMALLOC_HPP_INCLUDED




#include <stddef.h>
#include <stdint.h>

#define MEMORY_SIZE 10960  


typedef struct Block {
    size_t size;       
    struct Block* next; 
} Block;

class memalloc {
    private:
        size_t align_size(size_t size);
    public:
        void heap_init();
        void* alloc(size_t size);
        void free(void* ptr);

};

















#endif