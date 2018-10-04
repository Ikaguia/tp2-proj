#include <pessoa.hpp>

namespace grupoBatata{
	uint Tpessoa::getIdade() const{ return nascimento.idade(); }
	const Tpessoa::Equalificacao_nivel& Tpessoa::getQualificacao(const Equalificacao_tipo &tipo) const{
		return qualificacoes.at(tipo);
	}

	void Tpessoa::setQualificacao(const Equalificacao_tipo &tipo, const Equalificacao_nivel &nivel){
		qualificacoes[tipo] = nivel;
	}
};
