/**
 * @file Cow.cpp
 * @author Aviel Itzhak
 * @brief This file contains the implementation of the Cow class, which is derived from the Animal class.
 * 
 * @attention This class also implements additional overridden print method to display the cow's information. 
 */

#include "Cow.hpp"
#include <iostream>


Cow::Cow(const std::string& name, double temp, double breath, double heart, double milk)
    : Animal(name, temp, breath, heart), milk(milk) 
    {
        std::cout << this << ": This is Cow named " << name << " constructor." << std::endl;
    }

Cow::~Cow() 
{
    std::cout << this << ": This is Cow named " << name << " destructor." << std::endl;
}


bool Cow::check_health() const 
{
    // Creating boolean variables to hold the status of each health criterion
    bool temp_check = (temp >= 38.5 && temp <= 39.5);
    bool breath_check = (breath >= 26 && breath <= 50);
    bool heart_check = (heart >= 48 && heart <= 84);
    
    bool milk_check = (milk >= 30); // Milk production check

    return temp_check && breath_check && heart_check && milk_check; // Return true only if all criteria are met
}


void Cow::print_animal_info() const 
{
    std::cout << "Cow Information:\n"
              << "\tName: " << name << std::endl
              << "\tTemperature: " << temp << " °C" << std::endl
              << "\tBreath Rate: " << breath << " breaths/min" << std::endl
              << "\tHeart Rate: " << heart << " beats/min" << std::endl
              << "\tMilk Production: " << milk << " liters/day" << std::endl
              << "\tHealth Status: " << (check_health() ? "Healthy" : "Sick") << std::endl;
}