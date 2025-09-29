/**
 * @file Vet.cpp
 * @author Aviel Itzhak
 * @brief Implementation of the Vet singleton class that manages a collection of Animal pointers.
 * 
 * @attention The Vet class uses smart pointers (std::unique_ptr) to manage the memory of the Animal objects.
 * 
 * @attention This project doesn't include main function, so in order to test the Vet class,
 *            its upon the user to create a main function that utilizes the Vet class,
 *            and to make sure that the different animal objects are created on the heap (using new!).
 */

#include "Vet.hpp"
#include "Dog.hpp" // for dynamic_cast to Dog
#include <iostream>


Vet::Vet() 
    : animals() // Initialize the vector of unique_ptrs
{
    std::cout << this << ": This is Vet constructor." << std::endl;
}

Vet::~Vet() // The unique pointer will automatically clean up the Animal objects
{
    std::cout << this << ": This Vet destructor,\n\tDestroying all animals in the collection" << std::endl;
}


Vet& Vet::get_instance() // Utilizing singleton pattern
{ 
    static Vet instance; 
    return instance;
}


void Vet::add_animal(Animal* && animal) 
{
    animals.push_back(std::unique_ptr<Animal>(animal)); // Transfer ownership to unique pointer and add to vector
    std::cout << "Added animal named " << animal->get_name() << " to vet's collection." << std::endl;
}


void Vet::show_sick() const 
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

    if (is_all_healthy_flag) { std::cout << "No sick dogs found." << std::endl; } // If all dogs are healthy
}

