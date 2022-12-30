#include <CPU.hpp>

namespace NESBox
{
    uint8_t CPU::Instruction(uint8_t instruction){
        switch(instruction){
            case 0xA9: //LDA Immediate
				accumulator = hardware_bus->read_address(++pgrm_counter);
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;
				break;
			case 0xA5: //LDA Zero Page
				accumulator = hardware_bus->read_address(
					hardware_bus->read_address(++pgrm_counter)
				);
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;
				break;
			case 0xB5: //LDA Zero Page, X
				accumulator = hardware_bus->read_address(
					hardware_bus->read_address(++pgrm_counter)
				);
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;
				break;
		}
    };
}