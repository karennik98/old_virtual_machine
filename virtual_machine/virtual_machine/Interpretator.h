#pragma once

#include "Declaration.h"
#include "Register.h"
#include "CPU.h"
#include "ALU.h"

#include <string>
#include <fstream>
#include <memory>
#include <unordered_map>

using namespace decl;

namespace virtual_machine {

	class CPU;
	class ALU;

	class Interpretator : public CPU {
	public:
		Interpretator() : m_pos(0), m_source(""), DEFAULT_WHITESPACES(" \t"), m_dummy(std::make_unique<ALU>()) {}

		void parse();

		char& current();
		void next_pos();
		void pos_reset();
		bool get_source();

		void open(std::string file_path);
		void fill_data();

		bool is_command(const char* name);
		bool is_jump_command(const char* command);

		Extantion get_extantion(std::string ex_name);
		void set_label(std::string label, size_t val);
		size_t get_label_value(std::string label);

		void call_operation(const char* command, std::string label, Register reg1, Register reg2, int64_t val, Extantion ex = Extantion::DW);

	private:
		std::string DEFAULT_WHITESPACES;
		std::ifstream m_stream;
		std::string m_source;
		size_t m_pos;
		std::vector<std::string> m_data;
		std::unordered_map<std::string, size_t> m_labels;
		std::unique_ptr<ALU> m_dummy;
	};
}