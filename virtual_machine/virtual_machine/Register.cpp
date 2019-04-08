#include "pch.h"
#include "Register.h"

namespace virtual_machine {

	//~~~~~~~~~~~~~~~~~~~Class Register defination~~~~~~~~~~~~~~~~~//

	Register& Register::operator = (const Register& reg) {
		if (this == &reg) {
			return *this;
		}
		m_value = reg.m_value;
		m_isBusy = reg.m_isBusy;
		return *this;
	}
	Register& Register::operator + (const Register& reg) {
		m_value += reg.m_value;
		return *this;
	}
	Register& Register::operator - (const Register& reg) {
		m_value -= reg.m_value;
		return *this;
	}
	Register& Register::operator * (const Register& reg) {
		m_value *= reg.m_value;
		return *this;
	}
}