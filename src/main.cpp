#include <common.hpp>
#include <empregado.hpp>

int main() {
	//fast input/output with cin/cout
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//structure to hold the employees
	grupoBatata::Tempresa empresa;

	empresa.load_file(DATA_PATH + "input");

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
