/**
 * @file Dog.cpp
 * @author Aviel Itzhak
 * @brief This file contains the implementation of the Dog class, which is derived from the Animal class.
 * 
 * @attention This class also implements additional overridden print method to display the dog's information.
 */

#include "Dog.hpp"
#include <iostream>
#include <string>


Dog::Dog(const std::string& name, double temp, double breath, double heart, bool is_large)
    : Animal(name, temp, breath, heart), is_large(is_large) 
    {
        std::cout << this << ": This is Dog named " << name << " constructor." << std::endl;
    }

Dog::~Dog() 
{
    std::cout << this << ": This is Dog named " << m_name << " destructor." << std::endl;
}

bool Dog::check_health() const 
{
    // Creating boolean variables to hold the status of each health criterion
    bool temp_check = (m_temp >= 38.0 && m_temp <= 39.2);
    bool breath_check = (m_breath >= 10 && m_breath <= 35);
    bool heart_check;

    // Heart rate check based on size condition
    if (is_large) {  // Large dog
        heart_check = (m_heart >= 60 && m_heart <= 100);
    } else { // Small dog
        heart_check = (m_heart >= 100 && m_heart <= 140);
    }

    return temp_check && breath_check && heart_check; // Return true only if all criteria are met
}

void Dog::print_animal_info() const 
{
    std::cout << "Dog Information:\n"
              << "\tName: " << m_name << std::endl
              << "\tTemperature: " << m_temp << " °C" << std::endl
              << "\tBreath Rate: " << m_breath << " breaths/min" << std::endl
              << "\tHeart Rate: " << m_heart << " beats/min" << std::endl
              << "\tSize: " << (is_large ? "Large" : "Small") << std::endl
              << "\tHealth Status: " << (check_health() ? "Healthy" : "Sick") << std::endl;
}

