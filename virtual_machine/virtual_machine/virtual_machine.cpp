#include "pch.h"
#include <iostream>
#include "Interpretator.h"
#include "CPU.h"
#include "Exception.h"

int main()
{
	virtual_machine::CPU cpu;
	cpu.execute("Assembly.txt");
}
