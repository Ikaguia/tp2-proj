#ifndef HPP_PESSOA
#define HPP_PESSOA

#include <common.hpp>
#include <data.hpp>

namespace grupoBatata{
	class Tpessoa{
	public:
		enum Equalificacao_tipo{
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
			eng_social
		};
		enum Equalificacao_nivel{
			auxiliar,
			tecnico,
			profissional
		};

		// Tpessoa()=default;

		const string &nome = the_nome;
		const bool &sexo = the_sexo;
		const data &nascimento = the_nascimento;
		const string &cpf = the_cpf;
		uint getIdade() const;
		const Equalificacao_nivel &getQualificacao(const Equalificacao_tipo&) const;

		void setQualificacao(const Equalificacao_tipo&, const Equalificacao_nivel&);
	private:
		string the_nome;
		bool the_sexo;
		data the_nascimento;
		string the_cpf;
		map<Equalificacao_tipo, Equalificacao_nivel> qualificacoes;
	};
};

#endif//HPP_PESSOA
