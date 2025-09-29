/**
 * @file Vet.cpp
 * @author Aviel Itzhak
 * @brief Implementation of the Vet singleton class that manages a collection of Animal pointers.
 * 
 * @attention The Vet class uses smart pointers (std::unique_ptr) to manage the memory of the Animal objects.
 */

#include "Vet.hpp"
#include "Dog.hpp" // for dynamic_cast to Dog
#include <iostream>



Vet& Vet::get_instance() // utilizing singleton pattern
{ 
    static Vet instance; 
    return instance;
}

Vet::~Vet() 
{
    std::cout << this << ": This Vet destructor,\n\tDestroying all animals in the collection" << std::endl;
    // The unique_ptr will automatically clean up the Animal objects
}



void Vet::add_animal(Animal* && animal) 
{
    animals.push_back(std::unique_ptr<Animal>(animal)); // Transfer ownership to unique_ptr and add to vector
    std::cout << "Added animal named to vet's collection." << std::endl;
}


void Vet::show_sick_animals() const 
{
    std::cout << "Sick Animals in the Vet's Collection:" << std::endl;
    bool is_all_healthy_flag = true; // Flag to check if all animals are healthy

    for (const auto& animal_ptr : animals) // Iterate through all animals and print only the sick ones 
    {
        if (!animal_ptr->check_health()) 
        {
            std::cout << animal_ptr->get_name() << " ";
            is_all_healthy_flag = false; // At least one sick animal found
        }
    }
    std::cout << std::endl;

    if (is_all_healthy_flag) { std::cout << "No sick animals found." << std::endl; } // If all animals are healthy
}


void Vet::show_sick_dogs() const 
{
    std::cout << "Sick Dogs in the Vet's Collection:" << std::endl;
    bool is_all_healthy_flag = true; // Flag to check if all Dogs are healthy

    for (const auto& animal_ptr : animals) // Iterate through all animals and print only the sick Dogs
    {
        Dog* dog_ptr = dynamic_cast<Dog*>(animal_ptr.get()); // Creating temp Dog pointer with dynamic_cast to check if the Animal is a Dog
        if (dog_ptr && !dog_ptr->check_health()) 
        {
            std::cout << dog_ptr->get_name() << " ";
            is_all_healthy_flag = false; // At least one sick dog found
        }
    }
    std::cout << std::endl;

    if (is_all_healthy_flag) { std::cout << "No sick dogs found." << std::endl; }
}

