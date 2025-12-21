#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat():_name("defaultCon"),_grade(149){}
 
Bureaucrat::Bureaucrat(const std::string &name,int grade):_name(name),_grade(grade){
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name),_grade(other._grade){}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat&other){
    if(this!=&other)
        _grade = other._grade;
    
    return *this;
}
Bureaucrat::~Bureaucrat(){}
void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign "
        << form.getName()
        << " because " << e.what() << std::endl;
    }
}


void Bureaucrat::executeForm(AForm const & form) const
{
    try{
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << this->_name << " couldn't execute "
                  << form.getName() << " because "
                  << e.what() << std::endl;
    }
}
const char *Bureaucrat::GradeTooHighException::what()const throw(){
    return "Grade too High (1-150)";
}
const char *Bureaucrat::GradeTooLowException::what()const throw(){
    return "Grade too Low (1-150)";
}
const std::string &Bureaucrat::getName()const{return this->_name;}
int Bureaucrat::getGrade()const{return this->_grade;}

void Bureaucrat::incGrade(){
    if(_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--; 
}
void Bureaucrat::decGrade(){
    if(_grade >=150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}
std::ostream &operator<<(std::ostream &out,const Bureaucrat &b){
    out << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << ".";
    return out;
}
