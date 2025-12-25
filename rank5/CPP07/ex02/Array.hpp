#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
template <typename T>
class Array{
	public:
		Array();
		Array(const Array &);
		Array &operator=(const Array &);
		~Array();
		
		Array &operator[](const Array &);
		size_t size()const;
	private:
		T* data;
		size_t length;
};

#endif