#ifndef KAREN_HPP
# define KAREN_HPP
#include <iostream>

#define DEB "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it"
#define INFO "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
#define ERROR "This is unacceptable,I want to speak to the manager now."



class Karen;
typedef void (Karen::*ArrayFunctions) (void);

class Karen
{
    public:
            void  complain(std::string level);
            void  initArray();
            void  init_level();
    private:
            ArrayFunctions arr[4];
            std::string levelArr[4];
            void debug (void);
            void info(void);
            void warnig(void);
            void error(void);
};

#endif