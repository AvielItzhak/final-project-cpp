/**
 * @file Equation.cpp
 * @author Aviel Itzhak
 * 
 * @brief This is the source file for the implementation of Equation class use for solving quadratic equations.
 */

#include "Equation.hpp"
#include <iomanip> // for std::setprecision
#include <cmath> // for sqrt
#include <utility> // for std::swap




// Constructor for the Equation class:
Equation::Equation(double a, double b, double c) : m_a(a), m_b(b), m_c(c), solutions_size(0)
{
    if (m_a == 0) // A cannot be zero for a quadratic equation
    {
        std::cerr << "Coefficient A must be non-zero." << std::endl;
        throw std::invalid_argument("Coefficient A must be non-zero."); // throw an exception
    }
    try // try block to catch any exceptions during memory allocation for solutions array
    {
        calculate_solutions_and_size_CTOR(); // Calculate and set the solutions array and solutions_size
        std::cout << this << ": this Quadratic Equation instance is created." << std::endl;
    }
    catch(const std::bad_alloc& e) // Catch bad_alloc exception
    {
        std::cerr << e.what() << '\n';
        delete[] solutions; // Free allocated memory to prevent memory leak
        solutions = nullptr;
        solutions_size = 0;
        throw; // Rethrow the exception
    }
    
}

// Destructor for the Equation class:
Equation::~Equation()
{
    delete[] solutions;
    std::cout << this << ": this Quadratic Equation instance is deleted." << std::endl;
    solutions = nullptr;
}


// Copy constructor and copy assignment operator for the Equation class:
Equation::Equation(const Equation& other) : m_a(other.m_a), m_b(other.m_b), m_c(other.m_c), solutions_size(other.solutions_size)
{
    if (other.solutions != nullptr && solutions_size > 0) // Only if other.solutions is not nullptr meaning there are solutions to copy
    {
        try // try block to catch any exceptions during memory allocation for solutions array
        {
            solutions = new double[solutions_size];
            for (std::size_t i = 0; i < solutions_size; ++i)
            {
                solutions[i] = other.solutions[i];
            }
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << e.what() << '\n';
            delete[] solutions; // free allocated memory to prevent memory leak
            solutions = nullptr;
            throw; // rethrow the exception
        }
    }
    else { solutions = nullptr; } // Setting solutions to nullptr if there are no solutions in other
}

Equation& Equation::operator=(const Equation& other)
{
    if (this != &other) // Check if not self-assignment and then using copy-and-swap idiom    
    {
        Equation temp(other); // Create a copy of the other object
        // Swap the members with the temporary object
        std::swap(m_a, temp.m_a);
        std::swap(m_b, temp.m_b);
        std::swap(m_c, temp.m_c);
        std::swap(solutions, temp.solutions); 
        std::swap(solutions_size, temp.solutions_size);
    }
    return *this; // Return the object
}


// Getter methods for Equation coefficients:
double Equation::get_a() const { return m_a; }
double Equation::get_b() const { return m_b; }
double Equation::get_c() const { return m_c; }


// Setter methods for Equation coefficients:
void Equation::set_a(double a)
{
    if (a == 0) // A cannot be zero for this quadratic equation
    {
        std::cerr << "Coefficient A must be non-zero." << std::endl;
        throw std::invalid_argument("Coefficient A must be non-zero."); // throw an exception
    }
    m_a = a; // Update coefficient A if not zero
    
    try // try block to catch any exceptions during memory allocation for solutions array
    {
        calculate_solutions_and_size(); // Update solutions array and solutions size
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        delete[] solutions; // free allocated memory to prevent memory leak
        solutions = nullptr;
        solutions_size = 0;
        throw; // rethrow the exception
    }
}

void Equation::set_b(double b)
{
    m_b = b;
    
    try // try block to catch any exceptions during memory allocation for solutions array
    {
        calculate_solutions_and_size(); // Update solutions array and solutions size
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        delete[] solutions; // free allocated memory to prevent memory leak
        solutions = nullptr;
        solutions_size = 0;
        throw; // rethrow the exception
    }
}

void Equation::set_c(double c)
{
    m_c = c;
    
    try // try block to catch any exceptions during memory allocation for solutions array
    {
        calculate_solutions_and_size(); // Update solutions array and solutions size
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        delete[] solutions; // free allocated memory to prevent memory leak
        solutions = nullptr;
        solutions_size = 0;
        throw; // rethrow the exception
    }
}


// Methods to get solutions information:
size_t Equation::get_solutions_size() const { return solutions_size; }
double* const Equation::get_solutions() const { return solutions; }


// Addition operator methods:
Equation Equation::operator+(const Equation& other) const // Two Equations addition
{
    if (m_a + other.m_a == 0) // A cannot be zero for this quadratic equation
    {
        std::cerr << "Coefficient A must be non-zero." << std::endl;
        throw std::invalid_argument("Coefficient A must be non-zero."); // throw an exception
    }

    return Equation(m_a + other.m_a, m_b + other.m_b, m_c + other.m_c);
}

Equation Equation::operator+(int value) const { return Equation(m_a, m_b, m_c + value); } // Add integer to C coefficient

Equation operator+(int value, const Equation& eq) { return eq + value; } // Complementary function to make addition commutative with int


// Subtraction operator methods:
Equation Equation::operator-(const Equation& other) const // Two Equations subtraction
{
    if (m_a - other.m_a == 0) // A cannot be zero for this quadratic equation
    {
        std::cerr << "Coefficient A must be non-zero." << std::endl;
        throw std::invalid_argument("Coefficient A must be non-zero."); // throw an exception
    }

    return Equation(m_a - other.m_a, m_b - other.m_b, m_c - other.m_c);
}

Equation Equation::operator-(int value) const { return Equation(m_a, m_b, m_c - value);} // Subtract integer from C coefficient

Equation operator-(int value, const Equation& eq) { return Equation(eq.m_a, eq.m_b, value - eq.m_c); } // Complementary function to make subtraction commutative with int


// Output stream operator function:
std::ostream& operator<<(std::ostream& os, const Equation& eq)
{
    os << std::fixed << std::setprecision(1); // Set precision to one decimal place

    if (eq.m_b > 0 && eq.m_c > 0) { os << eq.m_a << " * x^2 + " << eq.m_b << " * x + " << eq.m_c << " = 0"; } // A*x^2 + B*x + C = 0
    else if (eq.m_b < 0 && eq.m_c > 0) { os << eq.m_a << " * x^2 - " << -eq.m_b << " * x + " << eq.m_c << " = 0"; } // A*x^2 - B*x + C = 0
    else if (eq.m_b > 0 && eq.m_c < 0) { os << eq.m_a << " * x^2 + " << eq.m_b << " * x - " << -eq.m_c << " = 0"; } // A*x^2 + B*x - C = 0
    else if (eq.m_b < 0 && eq.m_c < 0) { os << eq.m_a << " * x^2 - " << -eq.m_b << " * x - " << -eq.m_c << " = 0"; } // A*x^2 - B*x - C = 0
    else if (eq.m_b == 0 && eq.m_c == 0) { os << eq.m_a << " * x^2 = 0"; } // A*x^2 = 0
    else if (eq.m_b == 0 && eq.m_c > 0) { os << eq.m_a << " * x^2 - " << eq.m_c << " = 0"; } // A*x^2 - C = 0
    else if (eq.m_b == 0 && eq.m_c < 0) { os << eq.m_a << " * x^2 + " << -eq.m_c << " = 0"; } // A*x^2 + C = 0
    else if (eq.m_b > 0 && eq.m_c == 0) { os << eq.m_a << " * x^2 + " << eq.m_b << " * x = 0"; } // A*x^2 + B*x = 0
    else if (eq.m_b < 0 && eq.m_c == 0) { os << eq.m_a << " * x^2 - " << -eq.m_b << " * x = 0"; } // A*x^2 - B*x = 0

    return os; // Return the output stream
}


// Private helper method to calculate solutions and solutions size:
void Equation::calculate_solutions_and_size_CTOR()
{
    double discriminant = m_b * m_b - 4 * m_a * m_c; // Calculate the discriminant of the quadratic equation

    if (discriminant > 0) { solutions_size = 2; } // Two real solutions
    else if (discriminant == 0) { solutions_size = 1; } // One real solution
    else { solutions_size = 0; } // No real solutions

    if (solutions_size == 2)
    {
        solutions = new double[2]; // Allocate memory for two solutions
        solutions[0] = (-m_b + sqrt(discriminant)) / (2 * m_a);
        solutions[1] = (-m_b - sqrt(discriminant)) / (2 * m_a);
    }
    else if (solutions_size == 1)
    {
        solutions = new double[1]; // Allocate memory for one solution
        solutions[0] = -m_b / (2 * m_a);
    }
}

void Equation::calculate_solutions_and_size()
{
    // free previously allocated memory for solutions
    delete[] solutions;
    solutions = nullptr;

    double discriminant = m_b * m_b - 4 * m_a * m_c; // Calculate the discriminant of the quadratic equation

    if (discriminant > 0) { solutions_size = 2; } // Two real solutions
    else if (discriminant == 0) { solutions_size = 1; } // One real solution
    else { solutions_size = 0; } // No real solutions

    if (solutions_size == 2)
    {
        solutions = new double[2]; // Allocate memory for two solutions
        solutions[0] = (-m_b + sqrt(discriminant)) / (2 * m_a);
        solutions[1] = (-m_b - sqrt(discriminant)) / (2 * m_a);
    }
    else if (solutions_size == 1)
    {
        solutions = new double[1]; // Allocate memory for one solution
        solutions[0] = -m_b / (2 * m_a);
    }
}

// Method to print the solutions:
void Equation::print_solutions() const
{
    std::cout << std::fixed << std::setprecision(3); // Set precision to three decimal places

    // Print solutions based on the number of solutions found
    if (solutions_size == 0) // No real solutions
    {
        std::cout << "No real solutions." << std::endl;
    }
    else if (solutions_size == 1) // One real solution
    {
        std::cout << "One solution: x = " << solutions[0] << std::endl;
    }
    else if (solutions_size == 2) // Two real solutions
    {
        std::cout << "Two solutions: x1 = " << solutions[0] << ", x2 = " << solutions[1] << std::endl;
    }
}


// Example usage and testing of the Equation class
int main() {

    Equation eq(10,20,30);
    std::cout << eq << std::endl;
    //should print: 10X^2 + 20X + 30 = 0
    std::cout << eq.get_solutions_size() << std::endl;
    //should print 0
    eq = -20 + eq;
    std::cout << eq << std::endl;
    //should print: 10X^2 + 20X + 10 = 0
    std::cout << eq.get_solutions_size() << std::endl;
    //should print 1
    std::cout << eq.get_solutions()[0] << std::endl;
    //should print -1
    std::cout << Equation(1,5,3) + Equation(2,6,4) << std::endl;
    //should print: 3X^2 + 11X + 7 = 0
    eq = Equation(1,3,-4);
    std::cout << eq << std::endl;
    //should print 1X^2 + 3X + -4 = 0
    std::cout << eq.get_solutions_size() << std::endl;
    //should print 2
    std::cout << "X1 = " << eq.get_solutions()[0] << std::endl;
    //should print: X1 = 1
    std::cout << "X2 = " << eq.get_solutions()[1] << std::endl;
    //should print: X2 = -4
}