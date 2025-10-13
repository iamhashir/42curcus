#include <iostream>
#include <exception>

int main(){

	try{
		throw std::runtime_error("thrown");
		std::cout<<"this will never run after throw";
	}
	catch(std::exception &e){
	throw std::runtime_error("sdafa");
	}
}