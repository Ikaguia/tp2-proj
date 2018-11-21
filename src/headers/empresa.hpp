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
		static const map<string, Esetor> nome_setor;
		static const map<string, Ecargo> nome_cargo;

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
		static Tpessoa::Equalificacao_nivel qualificacao_minima(Esetor, Ecargo);
		//manager
		static TresourceManager<string, Tempresa> manager;
	private:
		string the_nome;
		map<Tpessoa, Temprego> empregados;
	};
};

#endif//HPP_EMPRESA
