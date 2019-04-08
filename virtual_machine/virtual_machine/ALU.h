#pragma once
#include "Declaration.h"
#include "Register.h"
#include "CPU.h"
#include "Interpretator.h"

using namespace decl;

namespace virtual_machine {
	class Interpretator;

	class ALU : public Interpretator, public CPU {
	public:
		ALU() = default;
		void ADD(Register reg1, Register reg2, Extantion ex = Extantion::DW);
		void SUB(Register reg1, Register reg2, Extantion ex = Extantion::DW);
		void JUMP(std::string label);
		void JZ(std::string label);
		void JNZ(std::string label);
		void JO(std::string label);
		void JNO(std::string label);
		void JS(std::string label);
		void JNS(std::string label);
		void PRINT(Register reg);
		void MUL(Register reg1, Register reg2, Extantion ex = Extantion::DW);
		void CMP();
		void DIV();
		void MOV();
		void ASSIGN();
		void SWAP();
		void AND();
		void OR();
		void XOR();
		void NOT();
		void NAND();
		void NOR();
	};
}