#ifndef HPP_EMPRESA
#define HPP_EMPRESA

#include <common.hpp>
#include <pessoa.hpp>

namespace grupoBatata{
	class Tempregado;

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

		void addEmpregado(const Tempregado &empregado);
		void addEmpregado(const string &empregado);
		void removeEmpregado(const uint &id);
		string runCommand(const vector<string> &args);

		Tempregado &getEmpregado(const uint &id);
	private:
		map<uint, Tempregado> empregados;
	};
};

#endif//HPP_EMPRESA
