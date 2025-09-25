#include <iostream>

class T {
public:
    int x;

    static T& get_instance() {
        static T instance{};
        return instance;
    }

    //delete copy operations
    T(const T&) = delete;
    T& operator =(const T&) = delete;

    ~T() {
        std::cout << "T destroyed\n";
    }

private:
    T() :x{} {
        std::cout << "T created\n";
    }


};



int main() {
    std::cout << "main start\n";
    std::cout << "getting x from T:" << T::get_instance().x << "\n";
    std::cout << "setting x to 10.\n";
    T::get_instance().x = 10;
    std::cout << "getting x from T:" << T::get_instance().x << "\n";

    //T t1{}; //compilation error

    std::cout << "main end\n";
}