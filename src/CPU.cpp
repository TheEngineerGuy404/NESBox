#include <CPU.hpp>

namespace NESBox
{
	uint8_t CPU::Instructions::ADCImmediate(CPU* cpu)
	// 2 bytes, 2 cycles
	{
		cpu->accumulator += cpu->ReadAddress(++pgrm_counter);
		return 2;
	}

	uint8_t CPU::Instruction(uint8_t instruction){
		switch(instruction){
				/*
					Storage Instructions
				*/
			case 0xA9: //LDA Immediate (2 bytes, 2 cycles)
				cycles += 2
				accumulator = hardware_bus->read_address(++pgrm_counter);	// 1
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 2
				break;
			case 0xA5: //LDA Zero Page (2 bytes, 3 cycles)
				accumulator = hardware_bus->read_address(			// 2
					hardware_bus->read_address(++pgrm_counter)		// 1
				);
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 3
				break;
			case 0xB5: //LDA Zero Page, X (2 bytes, 4 cycles)
				accumulator = hardware_bus->read_address(			// 3
					hardware_bus->read_address((++pgrm_counter) + x)	// 1,2
				);
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 4
				break;
			case 0xAD: //LDA Absolute (3 bytes, 4 cycles)
				uint16_t readingAddress =
					hardware_bus->read_address(++pgrm_counter) +		// 1
					(hardware_bus->read_address(++pgrm_counter) << 8);	// 2
				accumulator = hardware_bus->read_address(readingAddress);	// 3
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 4
				break;
			case 0xBD: //LDA Absolute, X (3 bytes, 4 or 5 cycles)
				uint16_t readingAddress =
					hardware_bus->read_address(++pgrm_counter) + x +	// 1,(2)
					(hardware_bus->read_address(++pgrm_counter) << 8);	// 3
				accumulator = hardware_bus->read_address(readingAddress);	// 4
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++; 						// 5
				break;
			case 0xB9: //LDA Absolute, Y (3 bytes, 4 or 5 cycles)
				uint16_t readingAddress =
					hardware_bus->read_address(++pgrm_counter) + y +	// 1,(2)
					(hardware_bus->read_address(++pgrm_counter) << 8);	// 3
				accumulator = hardware_bus->read_address(readingAddress);	// 4
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 5
				break;
			case 0xA1: //LDA Indirect, X (2 bytes, 6 cycles)
				uint16_t where = hardware_bus->read_address(			// 2
					(++pgrm_counter) + x);					// 1
				uint16_t readingAddress =
					(hardware_bus->read_address(where)) +			// 4
					(hardware_bus->read_address(++where) << 8);		// 3
				accumulator = hardware_bus->read_address(readingAddress);	// 5
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++; 						// 6
				break;
			case 0xB1: // LDA Indirect, Y (2 bytes, 5 or 6 cycles)
				uint16_t where = hardware_bus->read_address(
					(++pgrm_counter));					// 1
				uint16_t readingAddress =
					(hardware_bus->read_address(++where)) + y +		// 2,(3)
					(hardware_bus->read_address(where) << 8);		// 4
				accumulator = hardware_bus->read_address(readingAddress); 	// 5
				status[7] = accumulator < 0x80;
				status[1] = accumulator == 0x00;
				pgrm_counter++;							// 6
				break;
			case 0xA2: // LDX Immediate (2 bytes, 2 cycles)
				x = hardware_bus->read_address(++pgrm_counter);			// 1
				status[7] = x&BITSELECT[7];
				status[1] = x == 0x00;
				pgrm_counter++;							// 2
				break;
			case 0xA6: // LDX Zero Page (2 bytes, 3 cycles)
				x = hardware_bus->read_address(					// 2
					hardware_bus->read_address(++pgrm_counter)		// 1
				);
				status[7] = x&BITSELECT[7];
				status[1] = x == 0x00;
				pgrm_counter++;							// 3
				break;
			case 0xB6: // LDX Zero Page, X (2 bytes, 4 cycles)
				x = hardware_bus->read_address(					// 3
					hardware_bus->read_address(++pgrm_counter) + x		// 1,2
				);
				status[7] = x&BITSELECT[7];
				status[1] = x == 0x00;
				pgrm_counter++;							// 4
				break;
			case 0xAE: // LDX Absolute (3 bytes, 4 cycles)
				uint16_t readingAddress =
					hardware_bus->read_address(++pgrm_counter) +		// 1
					(hardware_bus->read_address(++pgrm_counter) << 8);	// 2
				x = hardware_bus->read_address(readingAddress);			// 3
				status[7] = x & BITSELECT[7];
				status[1] = x == 0x00;
				pgrm_counter++;							// 4
				break;
			case 0xBE:

				/*
					Math Instructions
				*/

			case 0x69: // ADC Immediate (2 bytes, 2 cycles)
				accumulator += instruction & 0x00FF;				// 1,2
				break;
			case 0x65: // ADC Zero-Page (2 bytes, 3 cycles)
				accumulator += hardware_bus->read_address(			// 1, 2, 3
					instruction & 0x00FF
				);
				break;
		}
};
}