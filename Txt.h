#pragma once
#include <string>
namespace l1{
	class Txt {
		std::string* data;
		size_t size_;
	public:
		Txt();
		~Txt();
		Txt(const char* fileName);
		Txt(const Txt& obj);
		Txt(Txt&& obj);
		Txt& operator=(Txt& obj);
		Txt& operator=(Txt&& obj);
		size_t size() const;
	};
}