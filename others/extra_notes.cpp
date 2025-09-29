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

/* need to do:
    1. should i delete copy constructor and assignment operator in Animal class?
    2. should i make the destructor in Animal class pure virtual or default?
    3. should i make its field private or protected?
    4. should i make the types of specific animal destructors virtual or default?
*/


