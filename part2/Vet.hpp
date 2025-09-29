/**
 * @file Vet.hpp
 * @author Aviel Itzhak
 * @brief 
 *        This file contains the declaration of the Vet class, which manages a collection of Animal pointers inside a vector.
 *        The Vet class will be a singleton based on a static method get_instance() that returns a reference to the single Vet instance.
 *        This singleton provides functionality to add, and to show the sick animals and Dogs in particular in its collection.
 * 
 *        Additionally, its responsible for destroying the Animal objects in its collection first upon its own destruction.
 *
 * @attention The member vector will utilize smart pointers (std::unique_ptr) to manage the memory of the Animal objects.
 */

#ifndef VET_HPP
#define VET_HPP

#include <vector> // for std::vector
#include <memory> // for std::unique_ptr
#include "Animal.hpp"

class Vet {
private:
    std::vector<std::unique_ptr<Animal>> animals; // Vector of unique pointers to Animal objects
    
    Vet();
    ~Vet();

    // Ensuring that the singleton cannot be copied or moved
    Vet(Vet&&) = delete; // Delete move constructor
    Vet& operator=(Vet&&) = delete; // Delete move assignment operator
    Vet(const Vet&) = delete; // Delete copy constructor
    Vet& operator=(const Vet&) = delete; // Delete copy assignment operator

public:
    static Vet& get_instance(); // Static method to get the single instance of Vet

    void add_animal(Animal* && animal); // Receive an rvalue to a pointer to specific animal and add it to the vector
    void show_sick() const; // Print all the sick animals in the vector
    void show_sick_dogs() const; // Print all the sick dogs in the vector

};

#endif // VET_HPP