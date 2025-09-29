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


