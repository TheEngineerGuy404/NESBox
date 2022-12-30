#include <cstdint>
#include <vector>
#include <string>


namespace NES
{
	class Clock;
	class CPU;
	class RAM;
	class Bus;

	class Clock
	{

	};

	class CPU
	{

	enum FLAGS
	{
		C = (1 << 0),
		Z = (1 << 1),
		I = (1 << 2),
		D = (1 << 3),
		B = (1 << 4),
		U = (1 << 5),
		V = (1 << 6),
		N = (1 << 7)
	};
	/*enum OPCODES
	{
		// Storage
		LDA,
		LDX,
		LDY,
		STA,
		STX,
		STY,
		TAX,
		TAY,
		TSX,
		TXA,
		TXS,
		TYA,

		// Math
		ADC,
		DEC,
		DEX,
		DEY,
		INC,
		INX,
		INY,
		SBC,

		// Bitwise
		AND,
		ASL,
		BIT,
		EOR,
		LSR,
		ORA,
		ROL,
		ROR,

		// Branch
		BCC,
		BCS,
		BEQ,
		BMI,
		BNE,
		BPL,
		BVC,
		BVS,

		// Jump
		JMP,
		JSR,
		RTI,
		RTS,

		// Registers
		CLC,
		CLD,
		CLI,
		CLV,
		CMP,
		CPX,
		CPY,
		SEC,
		SED,
		SEI,

		// Stack
		PHA,
		PHP,
		PLA,
		PLP,

		// System
		BRK,
		NOP,

		XXX
	};*/

	struct INSTRUCT6502
	{
		std::string name;
		uint8_t(CPU::* operation)(void) = nullptr;
		uint8_t(CPU::* addrmode)(void) = nullptr;
		uint8_t cycles = 0;
	};

	private:
		// Bus Pointer
		Bus* bus;

		// Internal CPU Wrappers
		void write(uint16_t a, uint8_t d);
		uint16_t read(uint16_t a, bool rd = false);

		void set_flag(FLAGS f, bool s);
		uint8_t get_flag(FLAGS f);

		uint8_t fetch();
		uint8_t fetched = 0x00;

		uint16_t addr_abs = 0x0000;
		uint16_t addr_rel = 0x00;
		uint8_t opcode = 0x00;
		uint8_t cycles = 0;
		std::vector<INSTRUCT6502> lookup;

	public:

		// Registers
		uint8_t x = 0x00;
		uint8_t y = 0x00;
		uint8_t status =         0x00;
		uint8_t accumulator =    0x00;
		uint8_t stack_ptr =      0x00;
		uint16_t pgrm_counter =  0x00;

		// Addressing Modes
		uint8_t IMP() { return 0x00; }; uint8_t IMM() { return 0x00; };
		uint8_t ZP0() { return 0x00; }; uint8_t ZPX() { return 0x00; };
		uint8_t ZPY() { return 0x00; }; uint8_t REL() { return 0x00; };
		uint8_t ABS() { return 0x00; }; uint8_t ABX() { return 0x00; };
		uint8_t ABY() { return 0x00; }; uint8_t IND() { return 0x00; };
		uint8_t IZX() { return 0x00; }; uint8_t IZY() { return 0x00; };

		// Opcodes
		uint8_t ADC() {return 0x00;};	uint8_t AND() {return 0x00;};	uint8_t ASL() {return 0x00;};	uint8_t BCC() {return 0x00;};
		uint8_t BCS() {return 0x00;};	uint8_t BEQ() {return 0x00;};	uint8_t BIT() {return 0x00;};	uint8_t BMI() {return 0x00;};
		uint8_t BNE() {return 0x00;};	uint8_t BPL() {return 0x00;};	uint8_t BRK() {return 0x00;};	uint8_t BVC() {return 0x00;};
		uint8_t BVS() {return 0x00;};	uint8_t CLC() {return 0x00;};	uint8_t CLD() {return 0x00;};	uint8_t CLI() {return 0x00;};
		uint8_t CLV() {return 0x00;};	uint8_t CMP() {return 0x00;};	uint8_t CPX() {return 0x00;};	uint8_t CPY() {return 0x00;};
		uint8_t DEC() {return 0x00;};	uint8_t DEX() {return 0x00;};	uint8_t DEY() {return 0x00;};	uint8_t EOR() {return 0x00;};
		uint8_t INC() {return 0x00;};	uint8_t INX() {return 0x00;};	uint8_t INY() {return 0x00;};	uint8_t JMP() {return 0x00;};
		uint8_t JSR() {return 0x00;};	uint8_t LDA() {return 0x00;};	uint8_t LDX() {return 0x00;};	uint8_t LDY() {return 0x00;};
		uint8_t LSR() {return 0x00;};	uint8_t NOP() {return 0x00;};	uint8_t ORA() {return 0x00;};	uint8_t PHA() {return 0x00;};
		uint8_t PHP() {return 0x00;};	uint8_t PLA() {return 0x00;};	uint8_t PLP() {return 0x00;};	uint8_t ROL() {return 0x00;};
		uint8_t ROR() {return 0x00;};	uint8_t RTI() {return 0x00;};	uint8_t RTS() {return 0x00;};	uint8_t SBC() {return 0x00;};
		uint8_t SEC() {return 0x00;};	uint8_t SED() {return 0x00;};	uint8_t SEI() {return 0x00;};	uint8_t STA() {return 0x00;};
		uint8_t STX() {return 0x00;};	uint8_t STY() {return 0x00;};	uint8_t TAX() {return 0x00;};	uint8_t TAY() {return 0x00;};
		uint8_t TSX() {return 0x00;};	uint8_t TXA() {return 0x00;};	uint8_t TXS() {return 0x00;};	uint8_t TYA() {return 0x00;};

		uint8_t XXX() { return 0x00; }


		// Extern Signal
		void CPUClock();
		void Reset();
		void IRQ();
		void NMI();

		CPU(Bus* bus);
		~CPU()
		{

		}

	};

	class RAM
	{
	public:
		RAM(Bus* bus) :
			bus(bus)
		{

		}

		uint32_t memsize = 64 * 1024;
		uint8_t* memory = new uint8_t[64 * 1024];
	private:
		Bus* bus;
	};

	class PPU
	{

	};

	class Bus
	{
	public:
		NES::CPU cpu = NES::CPU(this);
		NES::RAM ram = NES::RAM(this);

		Bus();
		~Bus()
		{

		}

		void Write(uint16_t addr, uint8_t data);
		uint16_t Read(uint16_t addr, bool readonly = false);
	};
};


int WinMain()
{


	return 0;
}



namespace NES
{
	// Bus Definition
	Bus::Bus()
	{
		for (uint32_t mem = 0; mem < ram.memsize; mem++)
		{
			ram.memory[mem] = 0x00;
		}
	}

	void Bus::Write(uint16_t addr, uint8_t data)
	{
		if (addr >= 0x0000 && addr <= 0xFFFF)
			ram.memory[addr] = data;
	}
	uint16_t Bus::Read(uint16_t addr, bool readonly)
	{
		if (addr >= 0x0000 && addr <= 0xFFFF)
			return ram.memory[addr];

		return 0x0000;
	}

	// CPU Definition
	CPU::CPU(Bus* bus) :
		bus(bus)
	{
		lookup =
		{
			{ "BRK", &CPU::BRK, &CPU::IMM, 7 },{ "ORA", &CPU::ORA, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 3 },{ "ORA", ORA, &CPU::ZP0, 3 },{ "ASL", &CPU::ASL, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PHP", &CPU::PHP, &CPU::IMP, 3 },{ "ORA", &CPU::ORA, &CPU::IMM, 2 },{ "ASL", &CPU::ASL, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ORA", &CPU::ORA, &CPU::ABS, 4 },{ "ASL", &CPU::ASL, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BPL", &CPU::BPL, &CPU::REL, 2 },{ "ORA", &CPU::ORA, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "ORA", ORA, &CPU::ZPX, 4 },{ "ASL", &CPU::ASL, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLC", &CPU::CLC, &CPU::IMP, 2 },{ "ORA", &CPU::ORA, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ORA", &CPU::ORA, &CPU::ABX, 4 },{ "ASL", &CPU::ASL, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
			{ "JSR", &CPU::JSR, &CPU::ABS, 6 },{ "AND", &CPU::AND, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "BIT", BIT, &CPU::ZP0, 3 },{ "AND", AND, &CPU::ZP0, 3 },{ "ROL", &CPU::ROL, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PLP", &CPU::PLP, &CPU::IMP, 4 },{ "AND", &CPU::AND, &CPU::IMM, 2 },{ "ROL", &CPU::ROL, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "BIT", &CPU::BIT, &CPU::ABS, 4 },{ "AND", &CPU::AND, &CPU::ABS, 4 },{ "ROL", &CPU::ROL, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BMI", &CPU::BMI, &CPU::REL, 2 },{ "AND", &CPU::AND, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "AND", AND, &CPU::ZPX, 4 },{ "ROL", &CPU::ROL, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SEC", &CPU::SEC, &CPU::IMP, 2 },{ "AND", &CPU::AND, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "AND", &CPU::AND, &CPU::ABX, 4 },{ "ROL", &CPU::ROL, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
			{ "RTI", &CPU::RTI, &CPU::IMP, 6 },{ "EOR", &CPU::EOR, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 3 },{ "EOR", EOR, &CPU::ZP0, 3 },{ "LSR", &CPU::LSR, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PHA", &CPU::PHA, &CPU::IMP, 3 },{ "EOR", &CPU::EOR, &CPU::IMM, 2 },{ "LSR", &CPU::LSR, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "JMP", &CPU::JMP, &CPU::ABS, 3 },{ "EOR", &CPU::EOR, &CPU::ABS, 4 },{ "LSR", &CPU::LSR, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BVC", &CPU::BVC, &CPU::REL, 2 },{ "EOR", &CPU::EOR, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "EOR", EOR, &CPU::ZPX, 4 },{ "LSR", &CPU::LSR, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLI", &CPU::CLI, &CPU::IMP, 2 },{ "EOR", &CPU::EOR, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "EOR", &CPU::EOR, &CPU::ABX, 4 },{ "LSR", &CPU::LSR, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
			{ "RTS", &CPU::RTS, &CPU::IMP, 6 },{ "ADC", &CPU::ADC, &CPU::IZX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 3 },{ "ADC", ADC, &CPU::ZP0, 3 },{ "ROR", &CPU::ROR, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "PLA", &CPU::PLA, &CPU::IMP, 4 },{ "ADC", &CPU::ADC, &CPU::IMM, 2 },{ "ROR", &CPU::ROR, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "JMP", &CPU::JMP, &CPU::IND, 5 },{ "ADC", &CPU::ADC, &CPU::ABS, 4 },{ "ROR", &CPU::ROR, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BVS", &CPU::BVS, &CPU::REL, 2 },{ "ADC", &CPU::ADC, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "ADC", ADC, &CPU::ZPX, 4 },{ "ROR", &CPU::ROR, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SEI", &CPU::SEI, &CPU::IMP, 2 },{ "ADC", &CPU::ADC, &CPU::ABY, 4 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "ADC", &CPU::ADC, &CPU::ABX, 4 },{ "ROR", &CPU::ROR, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
			{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "STA", &CPU::STA, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 6 },{ "STY", STY, &CPU::ZP0, 3 },{ "STA", STA, &CPU::ZP0, 3 },{ "STX", &CPU::STX, &CPU::ZP0, 3 },{ "???", &CPU::XXX, &CPU::IMP, 3 },{ "DEY", &CPU::DEY, &CPU::IMP, 2 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "TXA", &CPU::TXA, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "STY", &CPU::STY, &CPU::ABS, 4 },{ "STA", &CPU::STA, &CPU::ABS, 4 },{ "STX", &CPU::STX, &CPU::ABS, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
			{ "BCC", &CPU::BCC, &CPU::REL, 2 },{ "STA", &CPU::STA, &CPU::IZY, 6 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 6 },{ "STY", STY, &CPU::ZPX, 4 },{ "STA", STA, &CPU::ZPX, 4 },{ "STX", &CPU::STX, &CPU::ZPY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },{ "TYA", &CPU::TYA, &CPU::IMP, 2 },{ "STA", &CPU::STA, &CPU::ABY, 5 },{ "TXS", &CPU::TXS, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 5 },{ "???", &CPU::NOP, &CPU::IMP, 5 },{ "STA", &CPU::STA, &CPU::ABX, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },
			{ "LDY", &CPU::LDY, &CPU::IMM, 2 },{ "LDA", &CPU::LDA, &CPU::IZX, 6 },{ "LDX", &CPU::LDX, &CPU::IMM, 2 },{ "???", XXX, &CPU::IMP, 6 },{ "LDY", LDY, &CPU::ZP0, 3 },{ "LDA", LDA, &CPU::ZP0, 3 },{ "LDX", &CPU::LDX, &CPU::ZP0, 3 },{ "???", &CPU::XXX, &CPU::IMP, 3 },{ "TAY", &CPU::TAY, &CPU::IMP, 2 },{ "LDA", &CPU::LDA, &CPU::IMM, 2 },{ "TAX", &CPU::TAX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "LDY", &CPU::LDY, &CPU::ABS, 4 },{ "LDA", &CPU::LDA, &CPU::ABS, 4 },{ "LDX", &CPU::LDX, &CPU::ABS, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
			{ "BCS", &CPU::BCS, &CPU::REL, 2 },{ "LDA", &CPU::LDA, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 5 },{ "LDY", LDY, &CPU::ZPX, 4 },{ "LDA", LDA, &CPU::ZPX, 4 },{ "LDX", &CPU::LDX, &CPU::ZPY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },{ "CLV", &CPU::CLV, &CPU::IMP, 2 },{ "LDA", &CPU::LDA, &CPU::ABY, 4 },{ "TSX", &CPU::TSX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 4 },{ "LDY", &CPU::LDY, &CPU::ABX, 4 },{ "LDA", &CPU::LDA, &CPU::ABX, 4 },{ "LDX", &CPU::LDX, &CPU::ABY, 4 },{ "???", &CPU::XXX, &CPU::IMP, 4 },
			{ "CPY", &CPU::CPY, &CPU::IMM, 2 },{ "CMP", &CPU::CMP, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "CPY", CPY, &CPU::ZP0, 3 },{ "CMP", CMP, &CPU::ZP0, 3 },{ "DEC", &CPU::DEC, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "INY", &CPU::INY, &CPU::IMP, 2 },{ "CMP", &CPU::CMP, &CPU::IMM, 2 },{ "DEX", &CPU::DEX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 2 },{ "CPY", &CPU::CPY, &CPU::ABS, 4 },{ "CMP", &CPU::CMP, &CPU::ABS, 4 },{ "DEC", &CPU::DEC, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BNE", &CPU::BNE, &CPU::REL, 2 },{ "CMP", &CPU::CMP, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "CMP", CMP, &CPU::ZPX, 4 },{ "DEC", &CPU::DEC, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "CLD", &CPU::CLD, &CPU::IMP, 2 },{ "CMP", &CPU::CMP, &CPU::ABY, 4 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "CMP", &CPU::CMP, &CPU::ABX, 4 },{ "DEC", &CPU::DEC, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
			{ "CPX", &CPU::CPX, &CPU::IMM, 2 },{ "SBC", &CPU::SBC, &CPU::IZX, 6 },{ "???", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "CPX", CPX, &CPU::ZP0, 3 },{ "SBC", SBC, &CPU::ZP0, 3 },{ "INC", &CPU::INC, &CPU::ZP0, 5 },{ "???", &CPU::XXX, &CPU::IMP, 5 },{ "INX", &CPU::INX, &CPU::IMP, 2 },{ "SBC", &CPU::SBC, &CPU::IMM, 2 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", SBC, &CPU::IMP, 2 },{ "CPX", &CPU::CPX, &CPU::ABS, 4 },{ "SBC", &CPU::SBC, &CPU::ABS, 4 },{ "INC", &CPU::INC, &CPU::ABS, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },
			{ "BEQ", &CPU::BEQ, &CPU::REL, 2 },{ "SBC", &CPU::SBC, &CPU::IZY, 5 },{ "???", &CPU::XXX, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 8 },{ "???", NOP, &CPU::IMP, 4 },{ "SBC", SBC, &CPU::ZPX, 4 },{ "INC", &CPU::INC, &CPU::ZPX, 6 },{ "???", &CPU::XXX, &CPU::IMP, 6 },{ "SED", &CPU::SED, &CPU::IMP, 2 },{ "SBC", &CPU::SBC, &CPU::ABY, 4 },{ "NOP", &CPU::NOP, &CPU::IMP, 2 },{ "???", XXX, &CPU::IMP, 7 },{ "???", &CPU::NOP, &CPU::IMP, 4 },{ "SBC", &CPU::SBC, &CPU::ABX, 4 },{ "INC", &CPU::INC, &CPU::ABX, 7 },{ "???", &CPU::XXX, &CPU::IMP, 7 },
		};
	}




	void CPU::write(uint16_t a, uint8_t d)
	{
		bus->Write(a, d);
	}

	uint16_t CPU::read(uint16_t a, bool rd)
	{
		return bus->Read(a, rd);
	}

	void CPU::set_flag(FLAGS f, bool s)
	{

	}
	uint8_t CPU::get_flag(FLAGS f)
	{
		return 0x00;
	}

	void CPU::CPUClock()
	{
		if (cycles == 0)
		{
			opcode = read(pgrm_counter);
			pgrm_counter++;

			cycles = lookup[opcode].cycles;
			
			uint8_t addrOut = (this->*lookup[opcode].addrmode)();
			uint8_t operOut = (this->*lookup[opcode].operation)();

			cycles += (addrOut & operOut);
		}
		cycles--;
	}

	// Addressing Modes
	uint8_t CPU::IMP()
	{
		fetched = accumulator;
		return 0;
	}

	uint8_t CPU::IMM()
	{
		addr_abs = pgrm_counter++;
		return 0;
	}

	uint8_t CPU::ZP0()
	{
		addr_abs = read(pgrm_counter);
		pgrm_counter++;
		addr_abs &= 0x00FF;
		return 0;
	}
}