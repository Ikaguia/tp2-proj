#include <empresa.hpp>
#include <empregado.hpp>

namespace grupoBatata{
	const map<Tempresa::Esetor, set<Tpessoa::Equalificacao_tipo>> Tempresa::requisitos_setor = {
		{Tempresa::Esetor::financas, {
			Tpessoa::Equalificacao_tipo::administrador,
			Tpessoa::Equalificacao_tipo::contador,
			Tpessoa::Equalificacao_tipo::economista,
		}},
		{Tempresa::Esetor::marketing, {
			Tpessoa::Equalificacao_tipo::comunicador_social,
			Tpessoa::Equalificacao_tipo::mercadologos,
			Tpessoa::Equalificacao_tipo::administrador,
		}},
		{Tempresa::Esetor::tecnologia, {
			Tpessoa::Equalificacao_tipo::eng_computacao,
			Tpessoa::Equalificacao_tipo::eng_sistemas,
			Tpessoa::Equalificacao_tipo::eng_informacao,
		}},
		{Tempresa::Esetor::normatividade, {
			Tpessoa::Equalificacao_tipo::advogado,
			Tpessoa::Equalificacao_tipo::comunicador_social,
			Tpessoa::Equalificacao_tipo::contador,
		}},
		{Tempresa::Esetor::design, {
			Tpessoa::Equalificacao_tipo::design_grafico,
			Tpessoa::Equalificacao_tipo::design_multimidia,
			Tpessoa::Equalificacao_tipo::eng_social,
		}},
		{Tempresa::Esetor::outro, {
			Tpessoa::Equalificacao_tipo::administrador,
			Tpessoa::Equalificacao_tipo::contador,
			Tpessoa::Equalificacao_tipo::economista,
			Tpessoa::Equalificacao_tipo::comunicador_social,
			Tpessoa::Equalificacao_tipo::mercadologos,
			Tpessoa::Equalificacao_tipo::eng_computacao,
			Tpessoa::Equalificacao_tipo::eng_sistemas,
			Tpessoa::Equalificacao_tipo::eng_informacao,
			Tpessoa::Equalificacao_tipo::advogado,
			Tpessoa::Equalificacao_tipo::design_grafico,
			Tpessoa::Equalificacao_tipo::design_multimidia,
			Tpessoa::Equalificacao_tipo::eng_social
		}}
	};

	void Tempresa::addEmpregado(const Tempregado &empregado){ empregados[empregado.id] = empregado; }
	void Tempresa::addEmpregado(const string &empregado){
		Tempregado tmp(empregado);
		if(empregados.count(tmp.id)){
			string err = "Conflicting id numbers '" + to_string(tmp.id) + " with employees '" +
				empregados[tmp.id].nome << "' '" + tmp.nome + "'";
			throw invalid_argument(err);
		}
		empregados[tmp.id] = tmp;
	}
	void Tempresa::removeEmpregado(const uint &id){ empregados.erase(id); }
	Tempregado& Tempresa::getEmpregado(const uint &id){ return empregados[id]; }
	string Tempresa::runCommand(const vector<string> &args){
		uint commandID = stoi(args[0]);
		switch(commandID){
			case 0:
				return "batata";
			default:
				return "Comando não implementado";
		}
		return "";
	}

	void Tempresa::load_file(const string &filename){
		ifstream input(filename);
		string line;
		while(getline(input, line)){
			if(line.empty()) continue;
			try{
				addEmpregado(line);
			}
			catch(const exception &e){
				cerr << "Error while reading from input file:" << endl << e.what() << endl << line << endl << endl;
			}
		}
	}

};
