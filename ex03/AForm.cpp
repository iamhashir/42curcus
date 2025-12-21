#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ================== CONSTRUCTORS ==================
AForm::AForm():_name("etc"),_isSigned(false),_gradeToSign(100),_gradeToExecute(150){}
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):_name(name),_isSigned(false),_gradeToSign(gradeToSign),_gradeToExecute(gradeToExecute){
    if(gradeToSign < 1 || gradeToExecute <1)
        throw AForm::GradeTooHighException();
    
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    
}
AForm::AForm(const AForm &other):_name(other._name),_isSigned(other._isSigned),_gradeToSign(other._gradeToSign),_gradeToExecute(other._gradeToExecute)
{}

// ================== ASSIGNMENT ==================

AForm &AForm::operator=(const AForm &other){
    if(this!=&other)
        _isSigned = other._isSigned;
    return *this;
}
// ================== DESTRUCTOR ==================
AForm::~AForm(){}


// ================== GETTERS =====================
const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

// ================== CORE LOGIC ==================
void AForm::beSigned(const Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw AForm::NotSignedException();

    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();

    this->executeAction();
}
// ================== EXCEPTIONS ==================

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high";
}


const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low";
}
const char *AForm::NotSignedException::what() const throw()
{
    return "AForm not signed";
}
// ================== STREAM OPERATOR ==================

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm " << AForm.getName()
       << ", signed: " << (AForm.isSigned() ? "yes" : "no")
       << ", grade to sign: " << AForm.getGradeToSign()
       << ", grade to execute: " << AForm.getGradeToExecute();
    return os;
}
