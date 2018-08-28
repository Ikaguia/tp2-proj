#ifndef HPP_PESSOA
#define HPP_PESSOA

#include <common.hpp>

namespace grupoBatata{
	class Tpessoa{
	public:
		enum qualificacao{
			administrador,
			contador,
			economista,
			comunicador_social,
			mercadologos,
			eng_computacao,
			eng_sistemas,
			eng_informacao,
			advogado,
			design_grafico,
			design_multimidia,
			eng_social,
			count
		}

		Tpessoa();

		const string &getNome()const;
		const bool &getSexo()const;
		const data &getNascimento()const;
		const uint &getIdade()const;
		const string &getCPF()const;
		const bool &getEQualificado(const qualificacao&)const;

		void setEQualificado(const qualificacao&, const bool&);
	private:
		string nome;
		bool sexo;
		data nascimento;
		string cpf;
		bitset<qualificacao::count> qualificacoes;
	};
};

#endif//HPP_PESSOA
