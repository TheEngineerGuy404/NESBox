#include "Bus.hpp"
#ifndef _RAM_H
#define _RAM_H

namespace NESBox
{
    class RAM : public Hardware
    {
    private:
        uint8_t* memory;

    public:
        RAM(uint16_t min_address, uint16_t max_address, uint32_t size) :
            Hardware(min_address, max_address),
            memory(new uint8_t[size])
        {}
        ~RAM()
        {
            delete[] memory;
        }

        void Write(uint16_t address, uint8_t data)
        {
            memory[address] = data;
        }
    };
}

#endif