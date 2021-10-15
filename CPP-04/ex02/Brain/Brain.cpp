#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor Called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain CopyCostructor Called" << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = obj.ideas[i];
    }

}

 std::string Brain::getBrainIdea()
 {
     return (this->ideas[0]);
 }

 void        Brain::setBrainIdea(const std::string &str)
 {
     this->ideas[0] = str;
 }

 Brain & Brain::operator=(const Brain & obj)
 {
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = obj.ideas[i];
    }
    return (*this);
 }