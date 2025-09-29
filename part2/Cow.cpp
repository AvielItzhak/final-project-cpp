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
    : Animal(name, temp, breath, heart), m_milk(milk) 
    {
        std::cout << this << ": This is Cow named " << name << " constructor." << std::endl;
    }

Cow::~Cow() 
{
    std::cout << this << ": This is Cow named " << m_name << " destructor." << std::endl;
}


bool Cow::check_health() const 
{
    // Creating boolean variables to hold the status of each health criterion
    bool temp_check = (m_temp >= 38.5 && m_temp <= 39.5);
    bool breath_check = (m_breath >= 26 && m_breath <= 50);
    bool heart_check = (m_heart >= 48 && m_heart <= 84);

    bool milk_check = (m_milk >= 30); // Milk production check

    return temp_check && breath_check && heart_check && milk_check; // Return true only if all criteria are met
}


void Cow::print_animal_info() const 
{
    std::cout << "Cow Information:\n"
              << "\tName: " << m_name << std::endl
              << "\tTemperature: " << m_temp << " °C" << std::endl
              << "\tBreath Rate: " << m_breath << " breaths/min" << std::endl
              << "\tHeart Rate: " << m_heart << " beats/min" << std::endl
              << "\tMilk Production: " << m_milk << " liters/day" << std::endl
              << "\tHealth Status: " << (check_health() ? "Healthy" : "Sick") << std::endl;
}