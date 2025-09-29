/**
 * @file Cat.hpp
 * @author Aviel Itzhak
 * @brief 
 *        This file contains the declaration of the Cat class, which is derived from the Animal class.
 *        It implements the check_health function to determine if a cat is healthy based on its specific health criteria:
 *              Temperature between 38 and 39.2 degrees Celsius,
 *              Breath rate between 16 and 40 breaths per minute,
 *              Heart rate between 120 and 140 beats per minute.
 * 
 * @attention In addition, the class includes a virtual print method to display the cat's information.
 */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat(const std::string& name, double temp, double breath, double heart);
    ~Cat();

    bool check_health() const override; // Override the check_health function
    void print_animal_info() const override; // Override the print method to display cat's information
};

#endif // CAT_HPP