/**
 * @file Animal.hpp
 * @author Aviel Itzhak
 * @brief 
 *        This file contains the declaration of the Animal class, which serves as a base class for Dog, Cat, and Cow classes.
 *        It defines the common interface and attributes for all animal types: 
 *               Name, Temperature (temp), Breath Rate (breath), and Heart Rate (heart).
 * 
 *        In addition, it includes a pure virtual boolean function "check_health" that,
 *        based on given measurements and unique characteristics checks if the animal is healthy.
 *
 * @attention In addition, the class includes a virtual print method to display the animal's information.
 *            And a Name getter method helper for the Vet class.
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>


class Animal {
protected:
    std::string m_name;
    double m_temp; // Temperature in Celsius
    double m_breath; // Respiratory rate in breaths per minute
    double m_heart; // Heart rate in beats per minute

public:
    Animal(const std::string& name, double temp, double breath, double heart); 
    virtual ~Animal(); 

    // In the assumption that we don't want to allow copying of Animal objects
    Animal(const Animal&) = delete; // Delete copy constructor
    Animal& operator=(const Animal&) = delete; // Delete assignment operator

    virtual bool check_health() const = 0; // Pure virtual function to check health
    virtual void print_animal_info() const = 0; // additional abstract method to print animal information
    const std::string& get_name() const; // Helper get method for name
};

#endif // ANIMAL_HPP