#include "pch.h"
#include "virtual_machine.h"

#include <iostream>


int main()
{
	virtual_machine::CPU cpu;
	cpu.execute("Assembly.txt");
}
