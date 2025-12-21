#pragma once
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat{

    public:
        Bureaucrat();
        Bureaucrat(const std::string &,int);
        Bureaucrat(const Bureaucrat &);
        Bureaucrat &operator=(const Bureaucrat&);
        ~Bureaucrat();

        class GradeTooHighException: public std::exception{
            public: const char *what()const throw();
        };
        class GradeTooLowException: public std::exception{
            public: const char *what()const throw();
        };

        const std::string &getName()const;
        int getGrade()const;

        void incGrade();
        void decGrade();

    private:
        const std::string _name;
        int _grade;
};
std::ostream &operator<<(std::ostream &,const Bureaucrat &);