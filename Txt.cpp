#include "Txt.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>

l1::Txt::Txt() {
	data = nullptr;
}
l1::Txt::Txt(const char* fileName)
{
	std::ifstream file(fileName);
	std::string line;

	if (file.is_open()) {
		size_t count = 0;
		while (std::getline(file, line)) {
			count++;
		}
		length = count;

		data = new std::string[count];

		file.clear();
		file.seekg(0, std::ios::beg);
		for (int i = 0; i < count; i++) {
			std::getline(file, line);
			data[i] = line;
		}
		file.close();
	}
}
l1::Txt::~Txt() {
	delete[] data;
}
size_t l1::Txt::size()
{
	return length;
}
l1::Txt::Txt(Txt& obj) {
	data = new std::string[obj.length];//obj.data;
	length = obj.length;
	for (int i = 0; i < length; i++) {
		data[i] = obj.data[i];
	}
}
l1::Txt& l1::Txt::operator=(Txt& obj)
{
	if (this != &obj) {
		data = obj.data;
		length = obj.length;
	}
	return *this;
}
l1::Txt& l1::Txt::operator=(Txt&& obj)
{
	if (this != &obj) {
		delete[] data;
		data = obj.data;
		length = obj.length;
		obj.data = nullptr;
		obj.length = 0;
	}
	return *this;
}
l1::Txt::Txt(Txt&& obj) noexcept
{
	data = obj.data;
	obj.data = nullptr;
	length = obj.length;
}






