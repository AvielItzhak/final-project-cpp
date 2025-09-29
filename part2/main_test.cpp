#include <iostream>
#include <string>
#include <vector>
#include "Dog.hpp"
#include "Cow.hpp"
#include "Cat.hpp"
#include "Vet.hpp"

int main() {
    bool flag = false; // change to false to test the heap implementation with Vet singleton
 if (flag) { 
    std::cout << "program start" << std::endl;
    Vet& vet = Vet::get_instance();
    //healthy dog
    vet.add_animal(new Dog("dog1", 38.5, 20, 80, true));
    //not healthy dog (temp too high)
    vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));
    //not healthy dog (heart rate too slow for a small breed)
    vet.add_animal(new Dog("dog3", 38.5, 20, 80, false));
    //healthy cat
    vet.add_animal(new Cat("cat1", 38.7, 30, 130));
    //not healthy cat (breath is too high)
    vet.add_animal(new Cat("cat2", 38.7, 42, 130));
    //healthy cow
    vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32));
    //not healthy cow (milk production too low)
    vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20));
    vet.show_sick(); //should print: dog2 dog3 cat2 cow2
    vet.show_sick_dogs(); //should print: dog2 dog3

    std::cout << "\n----End of program: Destruction----\n" << std::endl;
 }
 if (!flag) {
      // קבלת מופע הסינגלטון של ה-Vet
    std::cout << "\n----Vet initialization----\n" << std::endl;
    Vet& vet = Vet::get_instance();

    // ---- יצירת חיות והדפסת מידע (נוצרות על הערימה) ----

    std::cout << "----Cows creation & printing----\n" << std::endl;
    // יצירה זמנית של מצביעים גולמיים לצורך הדפסת המידע לפני הוספה ל-Vet
    Cow* cow1 = new Cow("Bessie", 39.0, 30, 70, 35); // מצב בריאותי תקין בהנחה
    Cow* cow2 = new Cow("MooMoo", 40.0, 30, 70, 35); // מצב בריאותי חולה בהנחה
    cow1->print_animal_info();
    cow2->print_animal_info();

    std::cout << "\n----Dogs creation & printing----\n" << std::endl;
    Dog* dog1 = new Dog("Rex", 38.5, 20, 80, true); // מצב בריאותי תקין בהנחה
    Dog* dog2 = new Dog("Buddy", 37.0, 22, 75, false); // מצב בריאותי חולה בהנחה
    dog1->print_animal_info();
    dog2->print_animal_info();

    std::cout << "\n----Cats creation & printing----\n" << std::endl;
    Cat* cat1 = new Cat("Whiskers", 39.1, 25, 130); // מצב בריאותי תקין בהנחה
    Cat* cat2 = new Cat("Tom", 38.0, 24, 120); // מצב בריאותי תקין בהנחה
    cat1->print_animal_info();
    cat2->print_animal_info();


    std::cout << "\n----Adding animals to Vet collection----\n" << std::endl;
    // העברת בעלות על אובייקטי הערימה (HEAP) ל-Vet באמצעות הפונקציה add_animal
    vet.add_animal(cow1);
    vet.add_animal(cow2);
    vet.add_animal(dog1);
    vet.add_animal(dog2);
    vet.add_animal(cat1);
    vet.add_animal(cat2);


    // הצגת כל החיות החולות
    std::cout << "-\n----Sick animals---\n" << std::endl;
    vet.show_sick();
    
    // הצגת כל הכלבים החולים (בודק dynamic_cast)
    std::cout << "-\n----Sick dogs----\n" << std::endl;
    vet.show_sick_dogs();

    std::cout << "\n----End of program: Destruction----\n" << std::endl;

    // הדסטרוקטור של Vet ייקרא כאשר התוכנית תסתיים, וימחק את כל החיות באמצעות unique_ptr.
 }
    return 0;
}