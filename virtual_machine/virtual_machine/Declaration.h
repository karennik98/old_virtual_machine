#pragma once

namespace decl {
	constexpr const size_t  STRING_END_BYTE = 0;
	constexpr const size_t  STRING_HASH_KEY = 5381;

	constexpr size_t hash_function(const char* str, size_t hash = STRING_HASH_KEY)
	{
		return (str[0] == 0) ? hash : hash_function(str + 1, hash + static_cast<size_t>(*str));
	}

	enum Command {
		ADD    = hash_function("ADD"),
		JUMP   = hash_function("JUMP"),
		JZ     = hash_function("JZ"),
		JNZ    = hash_function("JNZ"),
		JO     = hash_function("JO"),
		JNO    = hash_function("JNO"),
		JS     = hash_function("JC"),
		JNS    = hash_function("JNC"),
		PRINT  = hash_function("PRINT"),
		CMP    = hash_function("CMP"),
		DIV    = hash_function("DIV"),
		MUL    = hash_function("MUL"),
		MOV    = hash_function("MOV"),
		ASSIGN = hash_function("ASSIGN"),
		SUB    = hash_function("SUB"),
		SWAP   = hash_function("SWAP"),
		AND    = hash_function("AND"),
		OR     = hash_function("OR"),
		XOR    = hash_function("XOR"),
		NOT    = hash_function("NOT"),
		NAND   = hash_function("NAND"),
		NOR    = hash_function("NOR"),
	};

	enum class Extantion {
		B  = 1,
		W  = 2,
		DW = 4,
		QW = 8,
	};

}