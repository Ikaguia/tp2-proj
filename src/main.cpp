#include <common.hpp>
#include <empresa.hpp>
#include <emprego.hpp>
#include <pessoa.hpp>
#include <data.hpp>

string out;

int rodaComando(const string &line){
	stringstream in(line);
	string command;
	in >> command;
	if(command == "sair") return 0;
	else if(command == "carregaArquivo"){
		string nome;
		in >> nome;
		ifstream file(string(DATA_PATH) + "/" + nome + ".data");
		if(not file.is_open()){
			cerr << "Falha ao executar comando 'carregaArquivo': falha ao abrir arquivo '" << nome << "'." << endl;
			return 1;
		}
		string the_line;
		while(getline(file, the_line)) rodaComando(the_line);
		cout << "Arquivo '" << nome << "' carregado com sucesso." << endl;
	}
	else if(command == "salvaArquivo"){
		string nome;
		in >> nome;
		ofstream file(string(DATA_PATH) + "/" + nome + ".data");
		if(not file.is_open()){
			cerr << "Falha ao executar comando 'salvaArquivo': falha ao abrir arquivo '" << nome << "'." << endl;
			return 1;
		}
		file << out;
	}
	else if(command == "mostraPessoa"){
		string nome;

		in >> nome;
		if(not grupoBatata::Tpessoa::manager.exists(nome)){
			cerr << "Falha ao executar comando 'mostraPessoa': pessoa '" << nome << "' não existe." << endl;
			return 1;
		}
		auto pessoa = grupoBatata::Tpessoa::manager.get(nome);
		cout << pessoa->nome << " ";
		cout << "sexo " << pessoa->sexo << " ";
		cout << "nascimento " << pessoa->nascimento.dia ___ pessoa->nascimento.mes ___ pessoa->nascimento.ano << " ";
		cout << "cpf " << pessoa->cpf << " ";
		for(const auto &emprego : pessoa->empregos) cout << "emprego " << emprego << " ";
		for(const auto &q : pessoa->qualificacoes) cout << "qualificacao " << q.ff ___ q.ss << " ";
		cout << endl;
	}
	else{
		out += line + "\n";
		if(command == "criaPessoa"){
			string nome, str1, str2, str3;
			bool b;
			int i1, i2;
			grupoBatata::data d;

			in >> nome;
			if(grupoBatata::Tpessoa::manager.exists(nome)){
				cerr << "Falha ao executar comando 'criaPessoa': pessoa '" << nome << "' já existe." << endl;
				return 1;
			}
			auto pessoa = grupoBatata::Tpessoa::manager.get(nome);
			while(in >> str1){
				if(str1 == "sexo"){
					in >> b;
					pessoa->setSexo(b);
				}
				else if(str1 == "nascimento"){
					in >> d.dia >> d.mes >> d.ano;
					pessoa->setNascimento(d);
				}
				else if(str1 == "cpf" or str1 == "CPF"){
					in >> str2;
					pessoa->setCPF(str2);
				}
				else if(str1 == "qualificação" or str1 == "qualificacao"){
					in >> i1 >> i2;
					pessoa->setQualificacao(
						grupoBatata::Tpessoa::Equalificacao_tipo(i1),
						grupoBatata::Tpessoa::Equalificacao_nivel(i2)
					);
				}
			}
			cout << "Pessoa '" << nome << "' criada com sucesso." << endl;
		}
		else if(command == "criaEmpresa"){
			string nome;
			in >> nome;
			if(grupoBatata::Tempresa::manager.exists(nome)){
				cerr << "Falha ao executar comando 'criaEmpresa': empresa '" << nome << "' já existe." << endl;
				return 1;
			}
			grupoBatata::Tempresa::manager.get(nome);
			cout << "Empresa '" << nome << "' criada com sucesso." << endl;
		}
		else if(command == "criaEmprego"){
			string nomeEmpresa, nomePessoa;
			in >> nomeEmpresa >> nomePessoa;

			if(not grupoBatata::Tempresa::manager.exists(nomeEmpresa)){
				cerr << "Falha ao executar comando 'criaEmprego': empresa '" << nomeEmpresa << "' não existe." << endl;
				return 1;
			}
			if(not grupoBatata::Tpessoa::manager.exists(nomePessoa)){
				cerr << "Falha ao executar comando 'criaEmprego': pessoa '" << nomePessoa << "' não existe." << endl;
				return 1;
			}
			auto empresa = grupoBatata::Tempresa::manager.get(nomeEmpresa);
			auto pessoa = grupoBatata::Tpessoa::manager.get(nomePessoa);
			if(empresa->getEmpregos().count(*pessoa)){
				cerr << "Falha ao executar comando 'criaEmprego': pessoa '" << nomePessoa
					<< "' já trabalha na empresa '" << nomeEmpresa << "'." << endl;
				return 1;
			}
			cout << "Emprego '" << nomeEmpresa << "," << nomePessoa << "' criado com sucesso." << endl;
		}
		else cout << "Comando invalido" << endl;
	}
	return 1;
}

int main() {
	//fast input/output with cin/cout
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//read commands from standard input
	string line;
	while(getline(cin, line) and rodaComando(line));
}
