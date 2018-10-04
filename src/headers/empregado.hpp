#ifndef HPP_EMPREGADO
#define HPP_EMPREGADO

#include <common.hpp>
#include <pessoa.hpp>
#include <empresa.hpp>


namespace grupoBatata{

	class Tempregado : Tpessoa{
	public:
		Tempregado()=default;
		Tempregado(const string&);
		Tempregado& operator=(const Tempregado&);

		const data &entrada = the_entrada;
		const uint &id = the_id;
		const uint &salario = the_salario;
		const Tempresa::Esetor &setor = the_setor;
		const Tempresa::Ecargo &cargo = the_cargo;

		void setEntrada(const data&);
		void setID(const uint&);
		void setSalario(const uint&);
		void setSetor(const Tempresa::Esetor&);
		void setCargo(const Tempresa::Ecargo&);
	private:
		data the_entrada;
		uint the_id, the_salario;
		Tempresa::Esetor the_setor;
		Tempresa::Ecargo the_cargo;
	};
};

#endif//HPP_EMPREGADO
