#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testBasicAnimals()
{
	std::cout << "=== Basic Animal tests ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testWrongAnimals()
{
	std::cout << "\n=== WrongAnimal tests ===" << std::endl;
	const WrongAnimal *w = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	delete w;
}

void testCopyAndAssignment()
{
	std::cout << "\n=== Copy and assignment tests ===" << std::endl;
	Dog d1;
	Dog d2(d1);
	Dog d3;
	d3 = d1;

	Cat c1;
	Cat c2(c1);
	Cat c3;
	c3 = c1;
}

void testPolymorphicArray()
{
	std::cout << "\n=== Polymorphic array ===" << std::endl;
	Animal *zoo[4];
	for (int k = 0; k < 4; ++k)
	{
		if (k % 2 == 0)
			zoo[k] = new Dog();
		else
			zoo[k] = new Cat();
	}
	for (int k = 0; k < 4; ++k)
	{
		zoo[k]->makeSound();
		delete zoo[k];
	}
}
int main()
{
	testBasicAnimals();
	testWrongAnimals();
	testCopyAndAssignment();
	testPolymorphicArray();
	return 0;
}