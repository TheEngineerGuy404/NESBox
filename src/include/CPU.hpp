#include "Bus.hpp"
#include <string>
#ifndef _CPU_H
#define _CPU_H


namespace NESBox
{
    // Bit Selection List
    const uint8_t BITSELECT[]
    {
        0xFF-0x01,
        0xFF-0x02,
        0xFF-0x04,
        0xFF-0x08,
        0xFF-0x10,
        0xFF-0x20,
        0xFF-0x40,
        0xFF-0x80
    };

    class CPU : protected Hardware
    {
    private:
        /*
            Registers
        */

        // Main Register
        uint8_t accumulator;

        // Index Register
        uint8_t x;
        uint8_t y;
        uint8_t stack_ptr;

        // Program counter
        uint16_t pgrm_counter;

        // Status register
        bool status[];
        

    public:
        CPU();
        ~CPU();
        uint8_t Instruction(uint8_t instruction);   
    };
}

#endif