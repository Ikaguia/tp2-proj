#include <pessoa.hpp>
#include <empresa.hpp>

namespace grupoBatata{
	TresourceManager<string, Tpessoa> Tpessoa::manager;

	//construtores / destrutores
	Tpessoa::Tpessoa(const string &v):the_nome(v){}
	//getters
	const Tpessoa::Equalificacao_nivel& Tpessoa::getQualificacao(const Equalificacao_tipo &tipo) const{
		return the_qualificacoes.at(tipo);
	}
	//setters
	void Tpessoa::setNome(const string &v){ the_nome = v; }
	void Tpessoa::setSexo(const bool &v){ the_sexo = v; }
	void Tpessoa::setNascimento(const data &v){ the_nascimento = v; }
	void Tpessoa::setCPF(const string &v){ the_cpf = v; }
	void Tpessoa::setEmpregos(const set<string> &v){ the_empregos = v; }
	void Tpessoa::setQualificacao(const Equalificacao_tipo &tipo, const Equalificacao_nivel &nivel){
		the_qualificacoes[tipo] = nivel;
	}
	//outros
	uint Tpessoa::getIdade() const{ return nascimento.idade(); }
	void Tpessoa::addEmprego(const string &v){
		if(empregos.count(v)){
			string error = "Erro: adicionando emprego '" + v + "' a pessoa '" + nome + "' que ja tem esse emprego.";
			throw invalid_argument(error);
		}
		the_empregos.insert(v);
	}
	void Tpessoa::delEmprego(const string &v){
		if(not empregos.count(v)){
			string error = "Erro: removendo emprego '" + v + "' de pessoa '" + nome + "' que não tem esse emprego.";
			throw invalid_argument(error);
		}
		the_empregos.erase(v);
	}
	//operators
	bool Tpessoa::operator<(const Tpessoa &v) const{
		if(cpf != v.cpf) return cpf < v.cpf;
		if(nome != v.nome) return nome < v.nome;
		if(sexo != v.sexo) return sexo < v.sexo;
		if(nascimento != v.nascimento) return nascimento < v.nascimento;
		{
			auto it1 = empregos.begin();
			auto it2 = v.empregos.begin();
			while(1){
				if(it1 == empregos.end() and it2 == v.empregos.end()) break;
				if(it1 == empregos.end()) return true;
				if(it2 == v.empregos.end()) return false;
				if(*it1 != *it2) return *it1 < *it2;
				it1++;
				it2++;
			}
		}
		{
			auto it1 = the_qualificacoes.begin();
			auto it2 = v.the_qualificacoes.begin();
			while(1){
				if(it1 == the_qualificacoes.end() and it2 == v.the_qualificacoes.end()) break;
				if(it1 == the_qualificacoes.end()) return true;
				if(it2 == v.the_qualificacoes.end()) return false;
				if(*it1 != *it2) return *it1 < *it2;
				it1++;
				it2++;
			}
		}
		return false;
	}
};
