#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T> class Array{
	public:
		Array():_arr(NULL),_length(0){}

		Array(unsigned int length):_arr(NULL),_length(length){
			if(_length > 0)
				_arr = new T[_length]();
		}
		
		Array(const Array &other):_arr(NULL),_length(other._length){

			if(_length > 0){
				_arr = new T[_length]();
			for(size_t i = 0; i < _length ; ++i)
				_arr[i]=other._arr[i];
			}
		
		}
		Array &operator=(const Array &other){
			
			if(this == &other)
				return *this;
			delete[] _arr;
			this->_length = other._length;
			this->_arr = NULL;
			
			if(_length > 0){
				this->_arr = new T[_length]();
				for(size_t i = 0; i < _length ; ++i)
					_arr[i]=other._arr[i];
			}
			return *this;
		}
		
		~Array(){
			delete[] _arr;
		}
		
		T &operator[](unsigned int index){
			if(index >=_length)throw std::exception();
			return _arr[index];
		}
		const T &operator[](unsigned int index)const{
			if(index >=_length)throw std::exception();
			return _arr[index];
		}
		size_t size()const{
			return _length;
		}
	private:
		T* _arr;
		size_t _length;
};
#endif