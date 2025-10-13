#include "iostream"
class Dog
{
protected:
	std::string name;

public:
	Dog(std::string n) : name(n) {};
	void bark()
	{
		std::cout << name << " Says woof!\n";
	}
};

class PoliceDog : public Dog
{
	public:
		PoliceDog(std::string n) : Dog(n) {};
		void sniff()
		{
			std::cout << name << " Dog is sniffing for crime\n";
		}
};
int main()
{
	PoliceDog rex("Rex");
	rex.bark();
	rex.sniff();
}