#include "pch.h"
#include "ALU.h"
#include "Interpretator.h"


using namespace decl;

namespace virtual_machine {

	//~~~~~~~~~~~~~~~~~~~Class ALU defination~~~~~~~~~~~~~~~~~//

	void ALU::ADD(Register reg1, Register reg2, Extantion ex) {
		if (reg2.get_value() > 0 && (reg1.get_value() > INT64_MAX - reg2.get_value())) {
			CPU::m_statusRegister.CF = 1;
		}
		if (reg2.get_value() < 0 && (reg1.get_value() < INT64_MIN - reg2.get_value())) {
			CPU::m_statusRegister.OF = 1;
		}
		if ((reg1 + reg2).get_value() == 0) {
			CPU::m_statusRegister.ZF = 0;
		}
		if ((reg1 + reg2).get_value() < 0) {
			CPU::m_statusRegister.SF = 1;
		}
		if ((reg1 + reg2).get_value() > 0) {
			CPU::m_statusRegister.SF = 0;
		}
		reg1 = reg1 + reg2;
	}

	void ALU::SUB(Register reg1, Register reg2, Extantion ex) {
		if (reg2.get_value() > 0 && (reg1.get_value() > INT64_MIN + reg2.get_value())) {
			CPU::m_statusRegister.CF = 1;
		}
		if (reg2.get_value() < 0 && (reg1.get_value() < INT64_MAX + reg2.get_value())) {
			CPU::m_statusRegister.OF = 1;
		}
		if ((reg1 - reg2).get_value() == 0) {
			CPU::m_statusRegister.ZF = 0;
		}
		if ((reg1 - reg2).get_value() < 0) {
			CPU::m_statusRegister.SF = 1;
		}
		if ((reg1 - reg2).get_value() > 0) {
			CPU::m_statusRegister.SF = 0;
		}
		reg1 = reg1 - reg2;
	}

	void ALU::MUL(Register reg1, Register reg2, Extantion ex) {
		if (reg1.get_value() > INT64_MAX / reg2.get_value() && (reg1.get_value() < INT64_MIN / reg2.get_value())) { //TODO
			m_statusRegister.CF = 1;
			m_statusRegister.OF = 1;
		}
		reg1 = reg1 * reg2;
	}

	void ALU::PRINT(Register reg) {
		std::cout << reg.get_value() << std::endl;
	}
	

	//~~~~~~~~~~~JUMP commands~~~~~~~~~~~~//
	void ALU::JUMP(std::string label) {
		CPU::set_IP(get_label_value(label));
	}

	void ALU::JZ(std::string label) {
		if (CPU::m_statusRegister.ZF) {
			CPU::set_IP(get_label_value(label));
		}
	}
	void ALU::JNZ(std::string label) {
		if (!CPU::m_statusRegister.ZF) {
			CPU::set_IP(get_label_value(label));
		}
	}
	void ALU::JO(std::string label) {
		if (CPU::m_statusRegister.OF) {
			CPU::set_IP(get_label_value(label));
		}
	}
	void ALU::JNO(std::string label) {
		if (!CPU::m_statusRegister.OF) {
			CPU::set_IP(get_label_value(label));
		}
	}
	void ALU::JS(std::string label) {
		if (CPU::m_statusRegister.SF) {
			CPU::set_IP(get_label_value(label));
		}
	}
	void ALU::JNS(std::string label) {
		if (!CPU::m_statusRegister.SF) {
			CPU::set_IP(get_label_value(label));
		}
	}

}