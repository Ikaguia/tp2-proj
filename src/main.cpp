#include <common.hpp>
#include <empregado.hpp>

int main() {
	//fast input/output with cin/cout
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//structure to hold the employees
	grupoBatata::Tempresa empresa;

	//open input file
	string line;
	ifstream input(DATA_PATH + "/input");

	//read from input file untill eof, ignoring blank lines
	while(getline(input, line) and line != ""){
		empresa.addEmpregado(line);
		// try{
		// 	grupoBatata::Tempregado emp(line);
		// 	if(empregados.count(emp.getID())){
		// 		cerr << "Error whie reading from input file:" << endl;
		// 		cerr << "Conflicting id numbers '" << emp.getID() "' with employees '";
		// 		cerr << empregados[emp.getID()].getName() << "' '";
		// 		cerr << emp.getName() << "'" << endl << endl;
		// 	}
		// 	else empregados[emp.getID()] = emp;
		// }
		// catch(const exception &e){
		// 	cerr << "Error while reading from input file:" << endl << e.what() << endl << line << endl << endl;
		// }
	}

	//read commands from standard input
	while(getline(cin, line)){
		if(line == "exit") return 0;

		string arg,result;
		vector<string> args;

		stringstream in(line);
		while(in >> arg) args.push_back(arg);

		result = empresa.runCommand(args);
		if(result != "") cout << result << endl;
	}
}
