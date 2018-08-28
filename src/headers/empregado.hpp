#ifndef HPP_EMPREGADO
#define HPP_EMPREGADO

#include <common.hpp>
#include <pessoa.hpp>
#include <empresa.hpp>


namespace grupoBatata{
	class Tempregado : Tpessoa{
	public:
		Tempregado();

		const data &getEntrada()const;
		const uint &getID()const;
		const uint &getSalario()const;
		const Tempresa::Esetor &getSetor()const;
		const Tempresa::Ecargo &getCargo()const;

		void setEntrada(const data&);
		void setID(const uint&);
		void setSalario(const uint&);
		void setSetor(const Tempresa::Esetor&);
		void setCargo(const Tempresa::Ecargo&);
	private:
		data entrada;
		uint id,salario;
		Tempresa::Esetor setor;
		Tempresa::Ecargo cargo;
	};
};

#endif//HPP_EMPREGADO
