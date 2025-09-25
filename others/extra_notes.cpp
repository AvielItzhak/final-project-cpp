// mistake in example in project specification:
//cout << eq.get_solutions[0] << endl;
// correct:
//cout << eq.get_solutions()[0] << endl;


//if you implement singleton pattern:
//
// Vet& vet = Vet::get_instance();
//if you don't:
// Vet vet{};
// (and make default constructor available publicly)



/* reminder need to check in Equation.cpp and Equation.hpp:
    1. check how to handle memory leaking due to exceptions
    5. can i use members function in constructor body? (like calculate_solutions and calculate_solutions_size)
    6. how make the addition and subtraction operators commutative with int?
    7. add bad alloc exception handling?
    8. need to implement deep copy constructor and copy assignment operator
*/