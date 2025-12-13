#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void test_polymorphic_delete()
{
	std::cout << "\n=== polymorphic delete ===\n";
	const Animal *a = new Dog();
	const Animal *b = new Cat();
	delete a;
	delete b;
}

static void test_small_array()
{
    std::cout << "\n=== small array ===\n";
    Animal* arr[4];
    for (int i = 0; i < 2; ++i) arr[i] = new Dog();
    for (int i = 2; i < 4; ++i) arr[i] = new Cat();
    for (int i = 0; i < 4; ++i) { arr[i]->makeSound(); delete arr[i]; }
}

static void test_copy_ctor_and_assign()
{
	std::cout << "\n=== copy ctor and assignment (Dog) ===\n";
	Dog d1;
	Dog d2(d1);
	Dog d3;
	d3 = d1;

	std::cout << "\n=== copy ctor and assignment (Cat) ===\n";
	Cat c1;
	Cat c2(c1);
	Cat c3;
	c3 = c1;
}

int main()
{
	test_polymorphic_delete();
	test_small_array();
	test_copy_ctor_and_assign();

	std::cout << "\n=== leak check ===\n";
	system("leaks DeepCopy");
	return 0;
}
