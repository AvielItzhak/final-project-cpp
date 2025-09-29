#include <iostream>
#include <string>
#include <vector>
#include "Dog.hpp"
#include "Cow.hpp"
#include "Cat.hpp"
#include "Vet.hpp"

int main() {
    // Create a Cow object
    std::cout << "----Cows creation----\n" << std::endl;
    Cow myCow1("Bessie", 39.0, 30, 70, 35);
    Cow myCow2("MooMoo", 40.0, 30, 70, 35);
    // Print the cow's information
    myCow1.print_animal_info();
    myCow2.print_animal_info();

    // Create a Dog object
    std::cout << "\n----Dogs creation----\n" << std::endl;
    Dog myDog1("Rex", 38.5, 20, 80, true);
    Dog myDog2("Buddy", 37.0, 22, 75, false);
    // Print the dog's information
    myDog1.print_animal_info();
    myDog2.print_animal_info();

    // Create a Cat object
    std::cout << "\n----Cats creation----\n" << std::endl;
    Cat myCat1("Whiskers", 39.1, 25, 130);
    Cat myCat2("Tom", 38.0, 24, 120);
    // Print the cat's information
    myCat1.print_animal_info();
    myCat2.print_animal_info();
    
    // Get the singleton instance of Vet
    std::cout << "\n----Vet creation and adding animals----\n" << std::endl;
    Vet& vet = Vet::get_instance();
    // Add animals to the vet's collection
    vet.add_animal(&myCow1);
    vet.add_animal(&myDog1);
    vet.add_animal(&myCat1);
    vet.add_animal(&myCow2);
    vet.add_animal(&myDog2);
    vet.add_animal(&myCat2);

    // Show all sick animals
    std::cout << "-\n----Sick animals---\n" << std::endl;
    vet.show_sick_animals();
    // Show all sick dogs
    std::cout << "-\n----Sick dogs----\n" << std::endl;
    vet.show_sick_dogs();

    std::cout << "\n----End of program: Destruction----\n" << std::endl;

    return 0;
}