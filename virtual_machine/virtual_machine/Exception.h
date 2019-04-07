#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception
{
	friend class wrong_func;
	friend class wrong_file_path;
public:
	const char* what() const throw() = 0;
	Exception(std::string file, std::string func, unsigned line) : m_file(file), m_func(func), m_line(line)
	{
	}
	//virtual void info() = 0; //TO DO
private:
	std::string m_file;
	unsigned m_line;
	std::string m_func;
};

class wrong_func :public Exception {
public:
	wrong_func(std::string file, std::string func, unsigned line) : Exception(file, func, line)
	{
	}
	const char* what() const throw() override
	{
		return ("Wrong function call : File: " + m_file = "\nFunction: " + m_func + "\nLine: " + std::to_string(m_line)).c_str();
	}
};

class wrong_file_path :public Exception {
public:
	wrong_file_path(std::string file, std::string func, unsigned line) : Exception(file, func, line)
	{
	}
	const char* what() const throw() override
	{
		return ("Wrong function path : File: " + m_file = "\nFunction: " + m_func + "\nLine: " + std::to_string(m_line)).c_str();
	}
};

#endif