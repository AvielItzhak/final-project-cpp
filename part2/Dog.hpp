/**
 * @file Dog.hpp
 * @author Aviel Itzhak
 * @brief 
 *        This file contains the declaration of the Dog class, which is derived from the Animal class.
 *        It includes a unique boolean field "is_large" and implements the check_health function to determine if a dog is healthy based on its specific health criteria:
 *              Temperature between 38 and 39.2 degrees Celsius,
 *              Breath rate between 10 and 35 breaths per minute,
 *              if dog is large Heart rate between 60 and 100 beats per minute,
 *              if dog is not large Heart rate between 100 and 140 beats per minute.
 * 
 * @attention In addition, the class includes a virtual print method to display the dog's information.
 * 
 */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
    bool is_large; // Unique boolean field to determine if the dog is large

public:
    Dog(const std::string& name, double temp, double breath, double heart, bool is_large);
    ~Dog() override; // Just to make sure

    bool check_health() const override; 
    void print_animal_info() const override;
};

#endif // DOG_HPP