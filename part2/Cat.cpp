/**
 * @file Cat.cpp
 * @author Aviel Itzhak
 * @brief This file contains the implementation of the Cat class, which is derived from the Animal class.
 * 
 * @attention This class also implements additional overridden print method to display the cat's information.
 */

#include "Cat.hpp"
#include <iostream>


Cat::Cat(const std::string& name, double temp, double breath, double heart)
    : Animal(name, temp, breath, heart) 
    {
        std::cout << this << ": This is Cat named " << name << " constructor." << std::endl;
    }

Cat::~Cat()
{
    std::cout << this << ": This is Cat named " << m_name << " destructor." << std::endl;
}

bool Cat::check_health() const 
{
    // Creating boolean variables to hold the status of each health criterion
    bool temp_check = (m_temp >= 38.0 && m_temp <= 39.2);
    bool breath_check = (m_breath >= 16 && m_breath <= 40);
    bool heart_check = (m_heart >= 120 && m_heart <= 140);

    return temp_check && breath_check && heart_check; // Return true only if all criteria are met
}

void Cat::print_animal_info() const 
{
    std::cout << "Cat Information:\n"
              << "\tName: " << m_name << std::endl
              << "\tTemperature: " << m_temp << " °C" << std::endl
              << "\tBreath Rate: " << m_breath << " breaths/min" << std::endl
              << "\tHeart Rate: " << m_heart << " beats/min" << std::endl
              << "\tHealth Status: " << (check_health() ? "Healthy" : "Sick") << std::endl;
}