#include "pch.h"
#include "Interpretator.h"
#include "Exception.h"
#include "ALU.h"
#include "Register.h"
#include "Declaration.h"

#include <unordered_map>


namespace virtual_machine {

	std::string key_extantion[]{ "B","W","DW","QW" };

	void Interpretator::next_pos() {
		++m_pos;
	}

	void Interpretator::pos_reset() {
		m_pos = 0;
	}

	char& Interpretator::current() {
		return m_source[m_pos];
	}

	void Interpretator::open(std::string file_path) {
		m_stream.open(file_path);
		if (false == m_stream.is_open()) {
			throw wrong_file_path("Parser.cpp", "open(std::string())", 29);
		}
	}

	void Interpretator::fill_data() {
		size_t idx = 0;
		while (!m_stream.eof()) {
			std::getline(m_stream, m_data[idx++]);
		}
	}

	Extantion Interpretator::get_extantion(std::string ex_name) {
		if (ex_name == "B") { return Extantion::B; }
		else if (ex_name == "W") { return Extantion::W; }
		else if (ex_name == "DW") { return Extantion::DW; }
		else { return Extantion::QW; }
	}

	void Interpretator::call_operation(const char* command, std::string label, Register reg1, Register reg2, int64_t val, Extantion ex) {
		switch (hash_function(command))
		{
		case ADD:
			if (val == INT64_MAX) {
				m_dummy->ADD(reg1, reg2, ex);
			}
			else {
				m_dummy->ADD(reg1, val, ex);
			}
			break;
		case JUMP:
			m_dummy->JUMP(label);
		default:
			break;
		}
	}

	bool Interpretator::is_command(const char* name) {
		switch (hash_function(name))
		{
		case ADD:
		case MUL:
		case JUMP:
		case ASSIGN:
		case MOV:
		case SWAP:
		case AND:
		case OR:
		case XOR:
		case NOT:
		case NAND:
		case NOR:
		case SUB:
		case DIV:
			return true;
		default:
			return false;
		}
	}

	bool Interpretator::get_source() {
		size_t ip = get_IP();
		if (get_IP() != m_data.size()) {
			m_source = m_data[get_IP()];
			set_IP(++ip);
			return true;
		}
		return false;
	}

	bool is_label(std::string str) {
		return (str.substr(0, 4) == "Label");
	}

	void Interpretator::set_label(std::string label, size_t val) {
		m_labels[label] = val;
	}

	size_t Interpretator::get_label_value(std::string label) {
		return m_labels.find(label)->second;
	}

	bool Interpretator::is_jump_command(const char* command) {
		switch (hash_function(command))
		{
		case JUMP:
		case JZ:
		case JNZ:
		case JO:
		case JNO:
		case JS:
		case JNS:
			return true;
		default:
			return false;
		}
	}


	void Interpretator::parse() {
		//function temporary objects
		std::string unknown_word;
		std::string command_name;
		std::string label;
		Extantion ex = Extantion::DW;
		Register reg1, reg2;
		int64_t val;
		while (get_source()) {
			unknown_word = "";
			command_name = "";
			while (m_pos <= m_source.size()) {
				while (m_pos <= m_source.size() && DEFAULT_WHITESPACES.find(current()) == std::string::npos) {
					unknown_word += current();
					next_pos();
				}
				if (is_command(unknown_word.c_str())) {
					command_name = unknown_word;
					if (is_jump_command(command_name.c_str())) {
						unknown_word.clear();
						while (m_pos <= m_source.size() && DEFAULT_WHITESPACES.find(current()) == std::string::npos) {
							unknown_word += current();
							next_pos();
						}
						label = unknown_word;
					}
				}
				else if (is_label(unknown_word)) {
					set_label(unknown_word, get_IP());
				}
				else if (key_extantion->find(unknown_word) != std::string::npos) {
					ex = get_extantion(unknown_word);
				}
				else if (unknown_word[0] == 'R') {
					unknown_word.erase(unknown_word.begin(), unknown_word.begin() + 1);
					size_t idx = std::stoi(unknown_word);
					if (!reg1.is_busy()) {
						reg1 = get_register(idx);
						reg1.set_flag(true);
					}
					else {
						reg2 = get_register(idx);
					}
				}
				else {
					size_t idx = 0;
					while (isdigit(unknown_word[idx]) && idx <= unknown_word.size()) {
						++idx;
					}
					if (idx == unknown_word.size()) {
						val = std::stoi(unknown_word);
					}
				}
				unknown_word.clear();
				next_pos();
			}
			pos_reset();
			call_operation(command_name.c_str(), label, reg1, reg2, val, ex);
		}
	}

}