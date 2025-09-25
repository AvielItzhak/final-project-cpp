/**
 * @brief This is a header file for part1 of the final project in, RT Embedded Systems, C++ course.
 *        The goal of this part is to implement a class that represents a Quadratic equation,
 *        and its solutions based on given coefficients.
 * 
 * @file Equation.hpp
 * @author Aviel Itzhak
 */


#include <cstddef> // for size_t
#include <iostream> 
#include <stdexcept> // for std::invalid_argument

/**
 * @brief This Class represents a quadratic equation.
 *                  A * x^2 + B * x + C = 0
 *        A, B, C are the coefficients of the equation (while A != 0), 
 *        solutions are pointers to the values of x that satisfy the equation,
 *        solutions_size is the number of solutions found (0, 1, or 2).
 *        The class provides methods to get and set the coefficients, retrieve the solutions,
 *        and overloads the output stream operator to print the equation in specific format:
 *                              "%.1F * x^2 + %.1F * x + %.1F = 0"
 */


class Equation
{
private:
    double m_a; // A, must be non-zero
    double m_b; // B
    double m_c; // C
    double* solutions; // Array of pointers to the solutions
    std::size_t solutions_size; // Number of solutions found (0, 1, or 2)
    void calculate_solutions_and_size(); // Calculate the solutions based on the coefficients and update the solutions array and solutions_size

public:
    Equation(double a, double b, double c);
    ~Equation();

    Equation(const Equation&) = delete; // Disable copy constructor
    Equation& operator=(const Equation&) = delete; // Disable copy assignment operator

    Equation operator+(const Equation& other) const; // Overload the addition operator to add two equations coefficients and return new equation
    Equation operator+(int value) const; // Overload the addition operator to add an integer value to C coefficient and return new equation
    Equation operator-(const Equation& other) const; // Overload the subtraction operator to subtract two equations coefficients and return new equation
    Equation operator-(int value) const; // Overload the subtraction operator to subtract an integer value from C coefficient and return new equation
    std::ostream& operator<<(std::ostream& os) const; // Overload the output stream operator to print the equation in specific format

    double get_a() const; // Return coefficient A
    double get_b() const; // Return coefficient B
    double get_c() const; // Return coefficient C

    void set_a(double a); // Set coefficient A, should be non-zero
    void set_b(double b); // Set coefficient B
    void set_c(double c); // Set coefficient C

    std::size_t get_solutions_size() const; // Return the number of solutions found
    double* const get_solutions() const; // Return the array of solutions

    void print_solutions() const; // Print solutions to standard output

};
