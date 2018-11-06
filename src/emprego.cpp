#include <emprego.hpp>


namespace grupoBatata{
	void Temprego::setEntrada(const data &new_entrada){ the_entrada = new_entrada; }
	void Temprego::setSalario(const uint &new_salario){ the_salario = new_salario; }
	void Temprego::setSetor(const Tempresa::Esetor &new_setor){ the_setor = new_setor; }
	void Temprego::setCargo(const Tempresa::Ecargo &new_cargo){ the_cargo = new_cargo; }
	//operators
	Temprego& Temprego::operator=(const Temprego &v){
		the_entrada = v.entrada;
		the_salario = v.salario;
		the_setor = v.setor;
		the_cargo = v.cargo;
		return *this;
	}
};
