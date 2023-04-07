#include "Txt.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>

l1::Txt::Txt() {
	data = nullptr;
	size_ = 0;
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
		size_ = count;

		data = new std::string[count];

		file.clear();
		file.seekg(0, std::ios::beg);
		for (int i = 0; i < count; i++) {
			std::getline(file, line);
			data[i] = std::move(line);
		}
		file.close();
	}
}

l1::Txt::~Txt() {
	delete[] data;
}

size_t l1::Txt::size() const
{
	return size_;
}

l1::Txt::Txt(const Txt& obj) {
	data = new std::string[obj.size_];
	size_ = obj.size_;
	std::copy(obj.data, obj.data + size_, this->data);
}

l1::Txt& l1::Txt::operator=(Txt& obj)
{
	if (this != &obj) {
		size_ = obj.size_;
		data = new std::string[size_];
		std::copy(obj.data, obj.data + size_, data);
	}
	return *this;
}

l1::Txt& l1::Txt::operator=(Txt&& obj)
{
	delete[] data;
	data = std::move(obj.data);
	size_ = obj.size_;
	obj.data = nullptr;
	obj.size_ = 0;
	
	return *this;
}

l1::Txt::Txt(Txt&& obj)
{
	data = obj.data;
	obj.data = nullptr;
	size_ = obj.size_;
	obj.size_ = 0;
}