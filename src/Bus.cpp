#include <Bus.hpp>

namespace NESBox
{
    /*
        Bus Definitions
    */
    Bus::Bus(uint16_t addressable_range, uint8_t component_limit) :
        address_range(addressable_range)
    {
        for (Hardware* h : system_hardware)
        {
            h = nullptr;
        }
    }
    Bus::~Bus()
    {
        for (Hardware* h : system_hardware)
        {
            delete h;
        }
    }

    uint16_t Bus::GetAddressableRange()
    {
        return this->address_range;
    }

    void Bus::write_address(uint16_t address, uint8_t value)
    {
        for (Hardware* h : system_hardware)
        {
            uint16_t min_addr = h->GetAddressRange()[0];
            uint16_t max_addr = h->GetAddressRange()[1];
            if ((address >= min_addr) && (address <= max_addr))
            {
                h->address_range[address - min_addr] = value;
            }
        }
    }

    uint8_t Bus::read_address(uint16_t address)
    {
        for (Hardware* h : system_hardware)
        {
            uint16_t min_addr = h->GetAddressRange()[0];
            uint16_t max_addr = h->GetAddressRange()[1];
            if ((address >= min_addr) && (address <= max_addr))
            {
                return h->address_range[address - min_addr];
            }
        }
    }

    /*
        Hardware Definition
    */
    uint16_t* Hardware::GetAddressRange()
    {
        uint16_t out[2];
        out[0] = this->min_address;
        out[1] = this->max_address;
        return out;
    }

    void Hardware::WriteAddress(uint16_t address, uint8_t value)
    {
        if (address > 0x0000 && address < hardware_bus->GetAddressableRange())
        {
            hardware_bus->write_address(address, value);
        }
    }

    uint8_t Hardware::ReadAddress(uint16_t address)
    {
        hardware_bus->read_address(address);
    }
}