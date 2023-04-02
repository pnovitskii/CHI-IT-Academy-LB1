#include "Txt.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>

l1::Txt::Txt() {
	data = NULL;
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
			data[i] = line;
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
	if (obj.size_ <= 0) {
		throw std::invalid_argument("Invalid size_ for Txt object");
	}
	data = new std::string[obj.size_];
	size_ = obj.size_;
	std::copy(obj.data, obj.data + size_, this->data);
	/*for (int i = 0; i < size_; i++) {
		data[i] = obj.data[i];
	}*/
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