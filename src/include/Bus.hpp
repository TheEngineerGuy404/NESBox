#include <stdint.h>
#ifndef _BUS_H
#define _BUS_H

namespace NESBox
{
    class Hardware;

    class Bus
    {
    private:
        Hardware* system_hardware;

    public:
        Bus(uint16_t addressable_range);
        ~Bus();
    };

    class Hardware
    {
    protected:
        uint16_t min_address;
        uint16_t max_address;

        Bus* hardware_bus;

    public:
        void WriteAddress(uint16_t address, uint8_t value);
        uint8_t ReadAddress(uint16_t address);
    };
}

#endif