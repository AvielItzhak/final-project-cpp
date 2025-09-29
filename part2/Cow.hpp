/**
 * @file Cow.hpp
 * @author Aviel Itzhak
 * @brief 
 *        This file contains the declaration of the Cow class, which is derived from the Animal class.
 *        It include a unique field "milk" and implements the check_health function to determine if a cow is healthy based on its specific health criteria:
 *            Temperature between 38.5 and 39.5 degrees Celsius,
 *            Breath rate between 26 and 50 breaths per minute,
 *            Heart rate between 48 and 84 beats per minute,
 *            Milk production 30 or higher liters per day.
 *
 * @attention In addition, the class includes a virtual print method to display the cow's information.
 */

#ifndef COW_HPP
#define COW_HPP

#include "Animal.hpp"

class Cow : public Animal {
private:
    double milk; // Unique field to determine the amount of milk produced by the cow

public:
    Cow(const std::string& name, double temp, double breath, double heart, double milk);
    virtual ~Cow();

    bool check_health() const override; // Override the check_health function
    void print_animal_info() const override; // Override the print method to display cow's information
};

#endif // COW_HPP