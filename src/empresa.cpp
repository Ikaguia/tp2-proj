#include <empresa.hpp>
#include <pessoa.hpp>
#include <emprego.hpp>

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
	TresourceManager<string, Tempresa> Tempresa::manager;

	//construtores / destrutores
	Tempresa::Tempresa(const string &v):nome{v}{}
	//getters
	const map<Tpessoa, Temprego> &Tempresa::getEmpregos() const{ return empregados; }
	Temprego &Tempresa::getEmprego(const Tpessoa &v){
		if(not empregados.count(v)){
			string error = string("Erro: get emprego para pessoa '") + v.nome + string("' na empresa '") + nome + string("' que não é empregada la.");
			throw invalid_argument(error);
		}
		return empregados.at(v);
	}
	//setters
	void Tempresa::setNome(const string &v){ the_nome = v; }
	void Tempresa::setEmprego(const Tpessoa &v1, const Temprego &v2){
		if(not empregados.count(v1)){
			string error = string("Erro: set emprego para pessoa '") + v1.nome + string("' na empresa '") + nome + string("' que não é empregada la.");
			throw invalid_argument(error);
		}
		empregados[v1] = v2;
	}
	//outros
	void Tempresa::addEmpregado(const Tpessoa &v1, const Temprego &v2){
		if(empregados.count(v1)){
			string error = string("Erro: add emprego para pessoa '") + v1.nome + string("' na empresa '") + nome + string("' que já é empregada la.");
			throw invalid_argument(error);
		}
		empregados[v1] = v2;
	}
	void Tempresa::delEmpregado(const Tpessoa &v){
		if(not empregados.count(v)){
			string error = string("Erro: del emprego para pessoa '") + v.nome + string("' na empresa '") + nome + string("' que não é empregada la.");
			throw invalid_argument(error);
		}
		empregados.erase(v);
	}
};
