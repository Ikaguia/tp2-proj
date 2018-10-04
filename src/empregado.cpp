#include <empregado.hpp>


namespace grupoBatata{
	Tempregado::Tempregado(const string &in_string){
		stringstream in(in_string);
		in >> the_entrada.dia >> the_entrada.mes >> the_entrada.ano;
		in >> the_id >> the_salario;
		in >> the_setor;
		in >> the_cargo;
	}

	Tempregado& Tempregado::operator=(const Tempregado &other){
		the_entrada = other.the_entrada;
		the_id = other.the_id;
		the_salario = other.the_salario;
		the_setor = other.the_setor;
		the_cargo = other.the_cargo;
		return *this;
	}

	void Tempregado::setEntrada(const data &new_entrada){ the_entrada = new_entrada; }
	void Tempregado::setID(const uint &new_id){ the_id = new_id; }
	void Tempregado::setSalario(const uint &new_salario){ the_salario = new_salario; }
	void Tempregado::setSetor(const Tempresa::Esetor &new_setor){ the_setor = new_setor; }
	void Tempregado::setCargo(const Tempresa::Ecargo &new_cargo){ the_cargo = new_cargo; }
};
