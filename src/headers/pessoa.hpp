#ifndef HPP_PESSOA
#define HPP_PESSOA

#include <common.hpp>
#include <data.hpp>
#include <resourceManager.hpp>

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
			nenhum,
			auxiliar,
			tecnico,
			profissional
		};
		static const map<string, Equalificacao_tipo> nome_qual_tipo;
		static const map<string, Equalificacao_nivel> nome_qual_nivel;

		//construtores / destrutores
		// Tpessoa()=default;
		Tpessoa(const string&);
		//getters
		const string &nome = the_nome;
		const bool &sexo = the_sexo;
		const data &nascimento = the_nascimento;
		const string &cpf = the_cpf;
		const set<string> &empregos = the_empregos;
		const map<Equalificacao_tipo, Equalificacao_nivel> &qualificacoes = the_qualificacoes;
		const Equalificacao_nivel &getQualificacao(const Equalificacao_tipo&) const;
		//setters
		void setNome(const string&);
		void setSexo(const bool&);
		void setNascimento(const data&);
		void setCPF(const string&);
		void setEmpregos(const set<string>&);
		void setQualificacao(const Equalificacao_tipo&, const Equalificacao_nivel&);
		//outros
		uint getIdade() const;
		void addEmprego(const string&);
		void delEmprego(const string&);
		//operators
		bool operator<(const Tpessoa&) const;
		//manager
		static TresourceManager<string, Tpessoa> manager;
	protected:
		string the_nome = "?nome?";
		bool the_sexo;
		data the_nascimento;
		string the_cpf = "?cpf?";
		set<string> the_empregos;
		map<Equalificacao_tipo, Equalificacao_nivel> the_qualificacoes;
	};
};

#endif//HPP_PESSOA
