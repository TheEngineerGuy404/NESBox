#include "Bus.hpp"
#ifndef _CPU_H
#define _CPU_H

/*
    OPCODE():
        #do operation
        delay(delta - ((double)operationCycleTotal
            / 1000000)
*/

namespace NESBox
{
    // Bit Selection List
    const uint8_t BITSELECT[]
    {
        0x01,
        0x02,
        0x04,
        0x08,
        0x10,
        0x20,
        0x40,
        0x80
    };


    class CPU : public Hardware
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

        // Program Counter
        uint16_t pgrm_counter;

        // Status Register
        bool status[8];
        
        /* 
            Emulation Data
        */
        
        // Cycle Counter
        uint8_t cycles;

    protected:
        class Instructions
        {
            /* These instructions return
                the number of cycles performed. */

            /*
                Storage Instructions
            */
            // LDA =========================
            uint8_t LDAImmediate (CPU* cpu);
            uint8_t LDAZeroPage  (CPU* cpu);
            uint8_t LDAZeroPageX (CPU* cpu);
            uint8_t LDAAbsolute  (CPU* cpu);
            uint8_t LDAAbsoluteX (CPU* cpu);
            uint8_t LDAAbsoluteY (CPU* cpu);
            uint8_t LDAIndirectX (CPU* cpu);
            uint8_t LDAIndirectY (CPU* cpu);
            // LDX =========================
            uint8_t LDXImmediate (CPU* cpu);
            uint8_t LDXZeroPage  (CPU* cpu);
            uint8_t LDXZeroPageX (CPU* cpu);
            uint8_t LDXAbsolute  (CPU* cpu);
            uint8_t LDXAbsoluteX (CPU* cpu);
            // LDY =========================
            uint8_t LDYImmediate (CPU* cpu);
            uint8_t LDYZeroPage  (CPU* cpu);
            uint8_t LDYZeroPageX (CPU* cpu);
            uint8_t LDYAbsolute  (CPU* cpu);
            uint8_t LDYAbsoluteX (CPU* cpu);
            // STA =========================
            uint8_t STAZeroPage  (CPU* cpu);
            uint8_t STAZeroPageX (CPU* cpu);
            uint8_t STAAbsolute  (CPU* cpu);
            uint8_t STAAbsoluteX (CPU* cpu);
            uint8_t STAAbsoluteY (CPU* cpu);
            uint8_t STAIndirextX (CPU* cpu);
            uint8_t STAIndirectY (CPU* cpu);

            /*
                Math Instructions
            */
            // ADC ==========================
            uint8_t ADCImmediate (CPU* cpu);
            uint8_t ADCZeroPage  (CPU* cpu);
            uint8_t ADCZeroPageX (CPU* cpu);
            uint8_t ADCZeroPageY (CPU* cpu);
            uint8_t ADCAbsolute  (CPU* cpu);
            uint8_t ADCAbsoluteX (CPU* cpu);
            uint8_t ADCAbsoluteY (CPU* cpu);
            uint8_t ADCIndirectX (CPU* cpu);
            uint8_t ADCIndirectY (CPU* cpu);
        };

    public:
        CPU();
        ~CPU();
        uint8_t Instruction(uint8_t instruction);
    };
}

#endif