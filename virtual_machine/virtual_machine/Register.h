#pragma once
#include <iostream>

namespace virtual_machine {

	class Register { //TODO with extantions
	public:

		Register() = default;
		Register(const Register& reg) : m_value(reg.m_value), m_isBusy(reg.m_isBusy) {}
		Register(int64_t value, bool flag) : m_value(value), m_isBusy(flag) {}
		Register(int64_t value) : m_value(value), m_isBusy(false) {}

		int64_t get_value()const { return m_value; }
		bool is_busy()const { return m_isBusy; }
		void set_value(int64_t value) { m_value = value; }
		void set_flag(bool flag) { m_isBusy = flag; }

		Register& operator+(const Register& reg);
		Register& operator-(const Register& reg);
		Register& operator*(const Register& reg);
		Register& operator = (const Register& reg);

	private:
		int64_t m_value;
		bool m_isBusy;
	};

	class FlagsRegister {
	public:
		bool CF : 1;
		bool ZF : 1;
		bool SF : 1;
		bool OF : 1;
	};
}
