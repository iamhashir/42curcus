#include <iostream>

class Account{

	private:
		int balance;
	public:
		Account(){balance = 0;}
		void deposit(int amount){
			balance+=amount;
			std::cout<<"Deposited! "<< amount <<"\nnew balance is: "<<balance<<"\n";
		}
		void withdrawal(int amount){
			balance-=amount;
			std::cout<<"Withdrawed! "<< amount <<"\nnew balance is: "<<balance<<"\n";
		}

};

int main(){

	Account hashir;
	hashir.deposit(140);
	hashir.deposit(140);
	hashir.withdrawal(60);

}