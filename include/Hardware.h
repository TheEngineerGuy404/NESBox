#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    bool exec=true;
    uint8_t flags;
    uint16_t pc;
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t sptr;
    uint8_t cycles_todo;
    uint64_t UF_cycles; // Cycles Unaccounted For
} CPU_Register;

void NES_RunInstruction(uint8_t inst, cpu_registers* reg);


inline uint8_t NES_SetBitInByte(uint8_t byte, uint8_t bit_pos, uint8_t bit_val) {
    // BIT POS is 0-index from the RIGHT of the byte
    if bit_val
        return byte | (bit_val<<bit_pos)
    else
        return byte & !(bit_val<<bit_pos)
}