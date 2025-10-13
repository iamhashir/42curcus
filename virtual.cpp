#include <iostream>
class Parent{

	public:
	Parent(){std::cout<<"\ti am Parent defauulted";};
	std::string a = "\thashir";
 
		 void speak(){std::cout<<a<<"\tbase is called";};
};
class Child : public Parent{
	private:

	public:
	std::string a = "\thashir";
	Child(){std::cout<<"\ti am child defauulted";};
		void speak(){std::cout<<a<<"\ti am Parentualized";};
};
int main(){
	Parent obj = Child();
	obj.speak();
}

