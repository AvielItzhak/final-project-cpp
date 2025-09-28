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
    1. can i use members function in constructor body? (like calculate_solutions and calculate_solutions_size)
    4. is it a problem to delete a pointer that wasn't created, inside the constructor? (like solutions pointer in the constructor)
*/