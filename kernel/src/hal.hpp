#ifndef HAL_HPP_INCLUDED
#define HAL_HPP_INCLUDED








class HAL {
    public:
        void halt_system();
        void kernel_suicide(char* error);
};












#endif