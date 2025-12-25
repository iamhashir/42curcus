#include "Array.hpp"

template <class A> class abc{

	public:
		A num1;
		A num2;
		abc(A n1,A n2):num1(n1),num2(n2){}	
		void getValues(){std::cout<<"num1: "<<num1<<" num2: "<<num2;}	
	private:

};

int main(){
	abc<int> a(1,2);
	a.getValues();
	abc<int> b(1.1,1);
	b.getValues();
}