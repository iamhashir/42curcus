#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm {
    public:
    // Canonical
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        // Getters
        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor)const;
        
        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };            
    protected:
        virtual void executeAction() const = 0;
    private:
       
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
