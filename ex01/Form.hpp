#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class Form {
public:
    // Canonical
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:

    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
