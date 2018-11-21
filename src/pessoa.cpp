#include <pessoa.hpp>
#include <empresa.hpp>

namespace grupoBatata{
	const map<string, Tpessoa::Equalificacao_tipo> Tpessoa::nome_qual_tipo = {
		{"administrador",		Tpessoa::Equalificacao_tipo::administrador},
		{"contador",			Tpessoa::Equalificacao_tipo::contador},
		{"economista",			Tpessoa::Equalificacao_tipo::economista},
		{"comunicador_social",	Tpessoa::Equalificacao_tipo::comunicador_social},
		{"mercadologos",		Tpessoa::Equalificacao_tipo::mercadologos},
		{"eng_computacao",		Tpessoa::Equalificacao_tipo::eng_computacao},
		{"eng_sistemas",		Tpessoa::Equalificacao_tipo::eng_sistemas},
		{"eng_informacao",		Tpessoa::Equalificacao_tipo::eng_informacao},
		{"advogado",			Tpessoa::Equalificacao_tipo::advogado},
		{"design_grafico",		Tpessoa::Equalificacao_tipo::design_grafico},
		{"design_multimidia",	Tpessoa::Equalificacao_tipo::design_multimidia},
		{"eng_social",			Tpessoa::Equalificacao_tipo::eng_social},
	};
	const map<string, Tpessoa::Equalificacao_nivel> Tpessoa::nome_qual_nivel = {
		{"auxiliar",	Tpessoa::Equalificacao_nivel::auxiliar},
		{"tecnico",		Tpessoa::Equalificacao_nivel::tecnico},
		{"profissional",Tpessoa::Equalificacao_nivel::profissional},
	};


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
