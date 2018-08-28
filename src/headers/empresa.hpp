#ifndef HPP_EMPREGADO
#define HPP_EMPREGADO

#include <common.hpp>

namespace grupoBatata{
	class empregado;

	class Tempresa{
	public:
		enum Esetor{
			financas,
			marketing,
			tecnologia,
			normatividade,
			design,
			outro,
			count,
		};
		enum Ecargo{
			auxiliar,
			tecnico,
			profissional,
			diretor_setor,
			diretor_operacoes,
			diretor_exec,
			count,
		}
		static const array<bitset<Tpessoa::Equalificacao::count>, Esetor::count> qualsPorSetor;

		Tempresa();

		void addEmpregado(const Tempregado &empregado);
		void addEmpregado(const string &empregado);
		void removeEmpregado(const uint &id);
		string runCommand(const vector<string> &args);

		Tempregado &getEmpregado(const uint &id);

	private:
		map<uint, Tempregado> empregados;
	};
};

#endif//HPP_EMPREGADO
