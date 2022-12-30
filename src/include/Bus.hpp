#include <stdint.h>
#include <vector>
#ifndef _BUS_H
#define _BUS_H

namespace NESBox
{
    class Hardware;

    class Bus
    {
    private:
        std::vector<Hardware*> system_hardware;
        uint16_t component_count;
        uint16_t address_range;

    public:
        Bus(uint16_t addressable_range, uint8_t component_limit);
        ~Bus();

        uint16_t GetAddressableRange();

        void write_address(uint16_t address, uint8_t value);
        uint8_t read_address(uint16_t address);
    };

    class Hardware
    {
    protected:
        uint16_t min_address;
        uint16_t max_address;

        Bus* hardware_bus;

    public:
        uint16_t* address_range;

        Hardware(uint16_t min_address, uint16_t max_address) :
            address_range(new uint16_t[max_address - min_address])
        {}

        uint16_t* GetAddressRange();

        void WriteAddress(uint16_t address, uint8_t value);
        uint8_t ReadAddress(uint16_t address);

        virtual void Write(uint16_t address, uint8_t value)
        {

        }
    };
}

#endif