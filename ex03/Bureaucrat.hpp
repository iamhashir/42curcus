#pragma once
#include <string>
#include <exception>
#include <ostream>
class AForm;

class Bureaucrat{

    public:
        Bureaucrat();
        Bureaucrat(const std::string &,int);
        Bureaucrat(const Bureaucrat &);
        Bureaucrat &operator=(const Bureaucrat&);

        void signForm(AForm &form) const;
        void executeForm(AForm const & form) const;
        
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