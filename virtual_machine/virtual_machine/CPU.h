#pragma once

#include "Declaration.h"
#include "Interpretator.h"
#include "Register.h"

#include <vector>
#include <string>
#include <memory>

using namespace decl;

namespace virtual_machine {

	class Interpretator;
	class ALU;

	class CPU {
	public:
		CPU();
		void init_regs();
		void fetch();//TODO
		size_t get_IP();
		void   set_IP(size_t ip);
		//void decod();
		void execute(std::string file_name);
		Register& get_register(size_t idx);
	public:
		FlagsRegister m_statusRegister;//TODO
	private:
		size_t m_IP;
		size_t m_IR;
		std::vector<Register> m_genRegs;
		std::unique_ptr<Interpretator> m_parser;
	};
}

