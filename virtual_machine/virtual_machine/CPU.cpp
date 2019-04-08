#include "pch.h"
#include "Exception.h"
#include "CPU.h"

#include <iostream>

namespace virtual_machine {

	//~~~~~~~~~~~~~~~~~~~Class CPU defination~~~~~~~~~~~~~~~~~//

	void CPU::init_regs() {
		m_genRegs.assign(31, Register(0));
	}

	void CPU::fetch() {

		m_IR = m_IP; //TODO
	}

	void CPU::set_IP(size_t ip) {
		m_IR = ip;
	}
	size_t CPU::get_IP() {
		return m_IP;
	}

	//void CPU::decod() {

	//}

	CPU::CPU() : m_parser(std::make_unique<Interpretator>()) {
		init_regs();
		m_IP = 0;
	}

	void CPU::execute(std::string file_name) {
		try {
			m_parser->open(file_name);
			m_parser->parse();
		}
		catch (Exception& except) {
			std::cout << except.what() << std::endl;
			system("pause");
		}
	}

	Register& CPU::get_register(size_t idx) {
		return m_genRegs[idx];
	}
}

