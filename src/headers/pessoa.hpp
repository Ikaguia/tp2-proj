#ifndef HPP_PESSOA
#define HPP_PESSOA

#include <common.hpp>

namespace grupoBatata{
	class Tpessoa{
	public:
		Tpessoa();

		const string &getNome()const;
		const bool &getSexo()const;
		const data &getNascimento()const;
		const uint &getIdade()const;
		const string &getCPF()const;
	private:
		string nome;
		bool sexo;
		data nascimento;
		string cpf;
	};
};

#endif//HPP_PESSOA
