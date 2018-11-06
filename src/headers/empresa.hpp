#ifndef HPP_EMPRESA
#define HPP_EMPRESA

#include <common.hpp>
#include <resourceManager.hpp>
#include <pessoa.hpp>

namespace grupoBatata{
	class Temprego;

	class Tempresa{
	public:
		enum Esetor : int{
			financas,
			marketing,
			tecnologia,
			normatividade,
			design,
			outro
		};
		enum Ecargo : int{
			auxiliar,
			tecnico,
			profissional,
			diretor_setor,
			diretor_operacoes,
			diretor_exec,
			count
		};
		static const map<Esetor, set<Tpessoa::Equalificacao_tipo>> requisitos_setor;

		//construtores / destrutores
		Tempresa(const string&);
		//getters
		const string &nome = the_nome;
		const map<Tpessoa, Temprego> &getEmpregos() const;
		Temprego &getEmprego(const Tpessoa&);
		//setters
		void setNome(const string&);
		void setEmprego(const Tpessoa&, const Temprego&);
		//outros
		void addEmpregado(const Tpessoa&, const Temprego&);
		void delEmpregado(const Tpessoa&);
		//manager
		static TresourceManager<string, Tempresa> manager;
	private:
		string the_nome;
		map<Tpessoa, Temprego> empregados;
	};
};

#endif//HPP_EMPRESA
