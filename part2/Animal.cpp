/**
 * @file Animal.cpp
 * @author Aviel Itzhak
 * @brief This file contains the implementation of the Animal class, which serves as a base class for Dog, Cat, and Cow classes.
 */

#include "Animal.hpp"
#include <iostream>


Animal::Animal(const std::string& name, double temp, double breath, double heart)
    : m_name(name), m_temp(temp), m_breath(breath), m_heart(heart) 
    {
        std::cout << this << ": This is base Animal named " << name << " constructor." << std::endl;
    }

Animal::~Animal() 
{
    std::cout << this << ": This is base Animal named " << m_name << " destructor." << std::endl;
}

const std::string& Animal::get_name() const  { return m_name; } // Return the name of the animal
