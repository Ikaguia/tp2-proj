#include <common.hpp>
#include <empresa.hpp>
#include <emprego.hpp>
#include <pessoa.hpp>
#include <data.hpp>
#include <Classes.h> // para acessar o codigo do outro grupo

string out;

int error(const string &c, const string &e){ return cerr << "Falha ao executar comando '" << c << "': " << e << endl, 1; }

Empresa outro;
Setor &get_setor(grupoBatata::Tempresa::Esetor setor){
    if(setor == grupoBatata::Tempresa::Esetor::financas)
        return outro.financas;
    if(setor == grupoBatata::Tempresa::Esetor::marketing)
        return outro.marketing;
    if(setor == grupoBatata::Tempresa::Esetor::tecnologia)
        return outro.tecnologia;
    if(setor == grupoBatata::Tempresa::Esetor::normatividade)
        return outro.normatividade;
    return outro.design;
}

void envia_empregado(Setor &s, grupoBatata::Tempresa::Ecargo cargo, shared_ptr<grupoBatata::Tpessoa> pessoa){
    static int id = 0;
    string nasc = "", now = "";
    stringstream inp;
	inp << pessoa->nascimento.dia ___ pessoa->nascimento.mes ___ pessoa->nascimento.ano;
    getline(inp, nasc);
    inp << grupoBatata::data::hoje().dia ___ grupoBatata::data::hoje().mes ___ grupoBatata::data::hoje().ano;
    getline(inp, now);
    
    if(cargo == grupoBatata::Tempresa::Ecargo::auxiliar){
        s.Auxiliares.emplace_back(pessoa->nome, to_string(pessoa->getIdade()), nasc,
                                  pessoa->cpf, to_string(id++), now, s.getTitulo(),
                                  s.getprofissao1(), s.getprofissao2(),
                                  s.getprofissao3());
    }
    else if(cargo == grupoBatata::Tempresa::Ecargo::tecnico){
        s.Tecnicos.emplace_back(pessoa->nome, to_string(pessoa->getIdade()), nasc,
                                pessoa->cpf, to_string(id++), now, s.getTitulo(),
                                s.getprofissao1(), s.getprofissao2(),
                                s.getprofissao3());
    }
    else if(cargo == grupoBatata::Tempresa::Ecargo::profissional){
        s.Profissionais.emplace_back(pessoa->nome, to_string(pessoa->getIdade()), nasc,
                                     pessoa->cpf, to_string(id++), now, s.getTitulo(),
                                     s.getprofissao1(), s.getprofissao2(),
                                     s.getprofissao3(), "Profissional"s, "Profissional"s, 6500.f);
    }
    else{
        s.Diretor.emplace_back(pessoa->nome, to_string(pessoa->getIdade()), nasc,
                               pessoa->cpf, to_string(id++), now, s.getTitulo(),
                               s.getprofissao1(), s.getprofissao2(),
                               s.getprofissao3(), "Diretor"s, "Diretor"s, 13000.0f);
    }
}

int rodaComando(const string &line){
	if(line.empty()) return 1;

	stringstream in(line);
	cout << "'" << line << "'" << endl;

	string command;
	in >> command;
	if(command == "sair") return 0;
	else if(command == "carregaArquivo"){
		string nome;
		in >> nome;
		ifstream file(string(DATA_PATH) + "/" + nome + ".data");
		if(not file.is_open()) return error(command, "falha ao abrir arquivo '"s + nome + "'"s);
		string the_line;
		while(getline(file, the_line)) rodaComando(the_line);
		cout << "Arquivo '" << nome << "' carregado com sucesso." << endl;
	}
	else if(command == "salvaArquivo"){
		string nome;
		in >> nome;
		ofstream file(string(DATA_PATH) + "/" + nome + ".data");
		if(not file.is_open()) return error(command, "falha ao abrir arquivo '"s + nome + "'"s);
		file << out;
	}
	else if(command == "mostraPessoa"){
		string nome;

		in >> nome;
		if(not grupoBatata::Tpessoa::manager.exists(nome)) return error(command, "pessoa '"s + nome + "' não existe."s);
		auto pessoa = grupoBatata::Tpessoa::manager.get(nome);
		cout << pessoa->nome << " ";
		cout << "sexo " << pessoa->sexo << " ";
		cout << "nascimento " << pessoa->nascimento.dia ___ pessoa->nascimento.mes ___ pessoa->nascimento.ano << " ";
		cout << "cpf " << pessoa->cpf << " ";
		for(const auto &emprego : pessoa->empregos) cout << "emprego " << emprego << " ";
		for(const auto &q : pessoa->qualificacoes) cout << "qualificacao " << q.ff ___ q.ss << " ";
		cout << endl;
	}
	else{
		out += line + "\n";
		if(command == "criaPessoa"){
			string nome, str1, str2, str3, erro = "";
			bool b;
			grupoBatata::data d;

			in >> nome;
			if(grupoBatata::Tpessoa::manager.exists(nome))
				erro = "pessoa '"s + nome + "' já existe."s;
			if(not erro.empty()) return error(command, erro);

			auto pessoa = grupoBatata::Tpessoa::manager.get(nome);
			while(in >> str1){
				if(str1 == "sexo"){
					in >> b;
					pessoa->setSexo(b);
				}
				else if(str1 == "nascimento"){
					in >> d.dia >> d.mes >> d.ano;
					pessoa->setNascimento(d);
				}
				else if(str1 == "cpf" or str1 == "CPF"){
					in >> str2;
					pessoa->setCPF(str2);
				}
				else if(str1 == "qualificação" or str1 == "qualificacao"){
					in >> str2 >> str3;
					auto qual_tipo = grupoBatata::Tpessoa::nome_qual_tipo.find(str2);
					auto qual_nivel = grupoBatata::Tpessoa::nome_qual_nivel.find(str3);

					if(qual_tipo == grupoBatata::Tpessoa::nome_qual_tipo.end())
						erro = "tipo de qualificação '"s + str2 + "' inválido."s;
					else if(qual_nivel == grupoBatata::Tpessoa::nome_qual_nivel.end())
						erro = "nivel de qualificação '"s + str3 + "' inválido."s;
					if(not erro.empty()) return error(command, erro);

					pessoa->setQualificacao(
						grupoBatata::Tpessoa::Equalificacao_tipo(qual_tipo->ss),
						grupoBatata::Tpessoa::Equalificacao_nivel(qual_nivel->ss)
					);
				}
				else return error(command, "atributo inválido '"s + str1 + "'"s);
			}
			cout << "Pessoa '" << nome << "' criada com sucesso." << endl;
		}
		else if(command == "criaEmpresa"){
			string nome;
			in >> nome;
			if(grupoBatata::Tempresa::manager.exists(nome)) return error(command, "empresa '"s + nome + "' já existe."s);
			grupoBatata::Tempresa::manager.get(nome);
			cout << "Empresa '" << nome << "' criada com sucesso." << endl;
		}
		else if(command == "criaEmprego"){
			string nomeEmpresa, nomePessoa, strSetor, strCargo, strQual;
			in >> nomeEmpresa >> nomePessoa >> strSetor >> strCargo >> strQual;

			string erro = "";
			if(not grupoBatata::Tempresa::manager.exists(nomeEmpresa)) erro = "empresa '"s + nomeEmpresa + "' não existe."s;
			else if(not grupoBatata::Tpessoa::manager.exists(nomePessoa)) erro = "pessoa '"s + nomePessoa + "' não existe."s;
			else if(not grupoBatata::Tpessoa::nome_qual_tipo.count(strQual)) erro = "qualificação '"s + strQual + "' não existe."s;
			else if(not grupoBatata::Tempresa::nome_setor.count(strSetor)) erro = "setor '"s + strSetor + "' não existe."s;
			else if(not grupoBatata::Tempresa::nome_cargo.count(strCargo)) erro = "cargo '"s + strCargo + "' não existe."s;
			else{
				auto empresa = grupoBatata::Tempresa::manager.get(nomeEmpresa);
				auto setor = grupoBatata::Tempresa::nome_setor.at(strSetor);
				auto cargo = grupoBatata::Tempresa::nome_cargo.at(strCargo);
				auto pessoa = grupoBatata::Tpessoa::manager.get(nomePessoa);
				auto qualificacao = grupoBatata::Tpessoa::nome_qual_tipo.at(strQual);

				if(empresa->getEmpregos().count(*pessoa))
					erro = "pessoa '"s + nomePessoa + "' já trabalha na empresa '"s + nomeEmpresa + "'."s;
				else if(not grupoBatata::Tempresa::requisitos_setor.at(setor).count(qualificacao))
					erro = "setor '"s + strSetor + "' não tem cargo para qualificação '"s + strQual + "'.";
				else if(pessoa->getQualificacao(qualificacao) < grupoBatata::Tempresa::qualificacao_minima(setor, cargo))
					erro = "pessoa '"s + nomePessoa + "' não tem qualificação para '"s + strSetor + ","s + strCargo + "'.";
				else{
					grupoBatata::Temprego emprego(setor, cargo);
					cout << "Emprego '"s + nomeEmpresa + ","s + nomePessoa + "' criado com sucesso.\n"s;
				}
			}
			if(not erro.empty()) return error(command, erro);

		}
		else if(command == "transfere"){
			string nomeEmpresa, nomePessoa, strSetor, strCargo;
			in >> nomeEmpresa >> nomePessoa >> strSetor >> strCargo;

			string erro = "";
			if(not grupoBatata::Tempresa::manager.exists(nomeEmpresa)) erro = "empresa '"s + nomeEmpresa + "' não existe."s;
			else if(not grupoBatata::Tpessoa::manager.exists(nomePessoa)) erro = "pessoa '"s + nomePessoa + "' não existe."s;
			else if(not grupoBatata::Tempresa::nome_setor.count(strSetor)) erro = "setor '"s + strSetor + "' não existe."s;
			else if(not grupoBatata::Tempresa::nome_cargo.count(strCargo)) erro = "cargo '"s + strCargo + "' não existe."s;
			else{
				auto empresa = grupoBatata::Tempresa::manager.get(nomeEmpresa);
				auto setor = grupoBatata::Tempresa::nome_setor.at(strSetor);
				auto cargo = grupoBatata::Tempresa::nome_cargo.at(strCargo);
				auto pessoa = grupoBatata::Tpessoa::manager.get(nomePessoa);

				if(not empresa->getEmpregos().count(*pessoa))
					erro = "pessoa '"s + nomePessoa + "' não trabalha na empresa '"s + nomeEmpresa + "'."s;
				else{
                    auto S = get_setor(setor);
                    auto pessoa = grupoBatata::Tpessoa::manager.get(nomePessoa);
                    envia_empregado(S, cargo, pessoa);
                    pessoa->delEmprego(nomeEmpresa);
                    cout << nomePessoa << " transferida com sucesso."s << endl;
				}
			}
			if(not erro.empty()) return error(command, erro);

		}
		else return error(command, "comando inválido");
	}
	return 1;
}

int main() {
	//fast input/output with cin/cout
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//read commands from standard input
	string line;
	while(getline(cin, line) and rodaComando(line));
}
