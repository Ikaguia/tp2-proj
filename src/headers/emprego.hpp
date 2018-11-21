#ifndef HPP_EMPREGADO
#define HPP_EMPREGADO

#include <common.hpp>
#include <pessoa.hpp>
#include <empresa.hpp>
#include <resourceManager.hpp>


namespace grupoBatata{

	class Temprego{
	public:
		//construtores / destrutores
		Temprego();
		Temprego(Tempresa::Esetor, Tempresa::Ecargo);
		//getters
		const data &entrada = the_entrada;
		const uint &salario = the_salario;
		const Tempresa::Esetor &setor = the_setor;
		const Tempresa::Ecargo &cargo = the_cargo;
		//setters
		void setEntrada(const data&);
		void setSalario(const uint&);
		void setSetor(const Tempresa::Esetor&);
		void setCargo(const Tempresa::Ecargo&);
		//operators
		Temprego& operator=(const Temprego&);
	protected:
		data the_entrada;
		uint the_salario;
		Tempresa::Esetor the_setor;
		Tempresa::Ecargo the_cargo;
	};
};

#endif//HPP_EMPREGADO
