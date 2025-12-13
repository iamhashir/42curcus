#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &other);
	~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &other);

	void makeSound() const;
	std::string getType() const;
};

#endif
