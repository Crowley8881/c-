#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#define MAX_PASSAGES 100
const std::string FILENAME = "viajar.txt";

struct Passagem
{
    int id;
    std::string origem;
    std::string destino;
    std::string cidadeOrigem;
    std::string cidadeDestino;
    std::string data;
    std::string horarioPartida;
    std::string horarioChegada;
    float precoPassagem;
};

void pesquisarPassagem(const std::vector<Passagem> &passagens, int idBuscado)
{
    bool passagemEncontrada = false;
    for (const auto &passagem : passagens)
    {
        if (passagem.id == idBuscado)
        {
            passagemEncontrada = true;
            std::cout << "\nID: " << passagem.id << std::endl;
            std::cout << "Origem: " << passagem.origem << std::endl;
            std::cout << "Destino: " << passagem.destino << std::endl;
            std::cout << "Cidade de Origem: " << passagem.cidadeOrigem << std::endl;
            std::cout << "Cidade de Destino: " << passagem.cidadeDestino << std::endl;
            std::cout << "Data da Partida: " << passagem.data << std::endl;
            std::cout << "Horário de Partida: " << passagem.horarioPartida << std::endl;
            std::cout << "Horário de Chegada: " << passagem.horarioChegada << std::endl;
            std::cout << "Preço da Passagem: " << passagem.precoPassagem << std::endl;
            break;
        }
    }

    if (!passagemEncontrada)
    {
        std::cout << "Passagem não encontrada.\n";
    }
}

void cadastrarPassagem(std::vector<Passagem> &passagens)
{
    if (passagens.size() >= MAX_PASSAGES)
    {
        std::cout << "Limite de passagens atingido.\n";
        return;
    }

    Passagem novaPassagem;
    novaPassagem.id = passagens.size() + 1;

    std::cout << "Digite a sigla do estado de origem (ex: SP): ";
    std::cin >> novaPassagem.origem;

    std::cout << "Digite a sigla do estado de destino (ex: RJ): ";
    std::cin >> novaPassagem.destino;

    std::cout << "Digite a cidade de origem: ";
    std::cin >> novaPassagem.cidadeOrigem;

    std::cout << "Digite a cidade de destino: ";
    std::cin >> novaPassagem.cidadeDestino;

    std::cout << "Digite a data da partida (dd/mm/aaaa): ";
    std::cin >> novaPassagem.data;

    std::cout << "Digite o horário de partida (hh:mm): ";
    std::cin >> novaPassagem.horarioPartida;

    std::cout << "Digite o horário de chegada (hh:mm): ";
    std::cin >> novaPassagem.horarioChegada;

    std::cout << "Digite o preço da passagem: ";
    std::cin >> novaPassagem.precoPassagem;

    passagens.push_back(novaPassagem);
    std::cout << "Passagem cadastrada com sucesso.\n";
}

void exibirPassagens(const std::vector<Passagem> &passagens)
{
    for (const auto &passagem : passagens)
    {
        std::cout << "\nID: " << passagem.id << std::endl;
        std::cout << "Origem: " << passagem.origem << std::endl;
        std::cout << "Destino: " << passagem.destino << std::endl;
        std::cout << "Cidade de Origem: " << passagem.cidadeOrigem << std::endl;
        std::cout << "Cidade de Destino: " << passagem.cidadeDestino << std::endl;
        std::cout << "Data da Partida: " << passagem.data << std::endl;
        std::cout << "Horário de Partida: " << passagem.horarioPartida << std::endl;
        std::cout << "Horário de Chegada: " << passagem.horarioChegada << std::endl;
        std::cout << "Preço da Passagem: " << passagem.precoPassagem << std::endl;
    }
}

void editarPassagem(std::vector<Passagem> &passagens)
{
    int idEditar;
    std::cout << "Digite o ID da passagem que deseja editar: ";
    std::cin >> idEditar;
    bool passagemEncontrada = false;
    for (auto &passagem : passagens)
    {
        if (passagem.id == idEditar)
        {
            passagemEncontrada = true;
            std::cout << "Digite o novo destino da passagem (sigla do estado): ";
            std::cin >> passagem.destino;

            std::cout << "Digite a nova cidade de destino: ";
            std::cin >> passagem.cidadeDestino;

            std::cout << "Digite a nova data da partida (dd/mm/aaaa): ";
            std::cin >> passagem.data;

            std::cout << "Digite o novo horário de partida (hh:mm): ";
            std::cin >> passagem.horarioPartida;

            std::cout << "Digite o novo horário de chegada (hh:mm): ";
            std::cin >> passagem.horarioChegada;

            std::cout << "Digite o novo preço da passagem: ";
            std::cin >> passagem.precoPassagem;

            std::cout << "Passagem editada com sucesso.\n";
            break;
        }
    }

    if (!passagemEncontrada)
    {
        std::cout << "Passagem não encontrada.\n";
    }
}

void excluirPassagem(std::vector<Passagem> &passagens)
{
    int idExcluir;
    std::cout << "Digite o ID da passagem que deseja excluir: ";
    std::cin >> idExcluir;
    bool passagemEncontrada = false;
    for (auto it = passagens.begin(); it != passagens.end(); ++it)
    {
        if (it->id == idExcluir)
        {
            passagemEncontrada = true;
            passagens.erase(it);
            break;
        }
    }

    if (passagemEncontrada)
    {
        std::cout << "Passagem excluida com sucesso.\n";
    }
    else
    {
        std::cout << "Passagem não encontrada.\n";
    }
}
// Adicione mensagens de debug ao longo do código
void salvarPassagens(const std::vector<Passagem> &passagens)
{
    const std::string FILENAME = "viajar.txt";
    std::ofstream file(FILENAME);

    if (!file.is_open())
    {
        std::cout << "Erro ao abrir o arquivo.\n";
        return;
    }

    // Adicione mensagens de debug
    std::cout << "Salvando passagens no arquivo...\n";

    for (const auto &passagem : passagens)
    {
        //for (const auto &passagem : passagens)
    {
        file << "ID: " << passagem.id << "\n";
        file << "Origem: " << passagem.origem << "\n";
        file << "Destino: " << passagem.destino << "\n";
        file << "Cidade de Origem: " << passagem.cidadeOrigem << "\n";
        file << "Cidade de Destino: " << passagem.cidadeDestino << "\n";
        file << "Data da Partida: " << passagem.data << "\n";
        file << "Horário de Partida: " << passagem.horarioPartida << "\n";
        file << "Horário de Chegada: " << passagem.horarioChegada << "\n";
        file << "Preço da Passagem: " << passagem.precoPassagem << "\n\n";
    } 
    }

    // Adicione mensagens de debug
    std::cout << "Passagens salvas com sucesso.\n";

    // file.close(); // Remova esta linha
}
    
   

void carregarDados(std::vector<Passagem> &passagens)
{
    std::ifstream file(FILENAME);
    if (!file.is_open())
    {
        std::cout << "Erro ao abrir o arquivo.\n";
        return;
    }

    std::string linha;
    while (std::getline(file, linha))
    {
        std::stringstream ss(linha);
        Passagem passagem;
        std::getline(ss, linha, ';');
        passagem.id = std::stoi(linha);
        std::getline(ss, passagem.origem, ';');
        std::getline(ss, passagem.destino, ';');
        std::getline(ss, passagem.cidadeOrigem, ';');
        std::getline(ss, passagem.cidadeDestino, ';');
        std::getline(ss, passagem.data, ';');
        std::getline(ss, passagem.horarioPartida, ';');
        std::getline(ss, passagem.horarioChegada, ';');
        std::getline(ss, linha, ';');
        passagem.precoPassagem = std::stof(linha);
        passagens.push_back(passagem);
    }

    file.close();
    std::cout << "Dados carregados com sucesso.\n";
}

void listarPassagens(const std::vector<Passagem> &passagens)
{
    if (passagens.empty())
    {
        std::cout << "Nenhuma passagem cadastrada.\n";
        return;
    }

    std::cout << "ID;Origem;Destino;Cidade Origem;Cidade Destino;Data;Horário Partida;Horário Chegada;Preço da Passagem\n";
    for (const auto &passagem : passagens)
    {
        std::cout << passagem.id << ";" << passagem.origem << ";" << passagem.destino << ";" << passagem.cidadeOrigem << ";" << passagem.cidadeDestino << ";" << passagem.data << ";" << passagem.horarioPartida << ";" << passagem.horarioChegada << ";" << passagem.precoPassagem << "\n";
    }
}

void pesquisarPassagens(const std::vector<Passagem> &passagens)
{
    std::string origem, destino;
    std::cout << "Digite a origem da passagem: ";
    std::cin >> origem;
    std::cout << "Digite o destino da passagem: ";
    std::cin >> destino;

    bool passagemEncontrada = false;
    for (const auto &passagem : passagens)
    {
        if (passagem.origem == origem && passagem.destino == destino)
        {
            passagemEncontrada = true;
            std::cout << "ID: " << passagem.id << "\n";
            std::cout << "Origem: " << passagem.origem << "\n";
            std::cout << "Destino: " << passagem.destino << "\n";
            std::cout << "Cidade Origem: " << passagem.cidadeOrigem << "\n";
            std::cout << "Cidade Destino: " << passagem.cidadeDestino << "\n";
            std::cout << "Data: " << passagem.data << "\n";
            std::cout << "Horário Partida: " << passagem.horarioPartida << "\n";
            std::cout << "Horário Chegada: " << passagem.horarioChegada << "\n";
            std::cout << "Preço da Passagem: " << passagem.precoPassagem << "\n";
        }
    }

    if (!passagemEncontrada)
    {
        std::cout << "Nenhuma passagem encontrada com essa origem e destino.\n";
    }
}

void interface()
{
    int opcao;
    std::vector<Passagem> passagens;

    while (true)
    {
        std::cout << "\n1. Cadastrar Passagem\n";
        std::cout << "2. Editar Passagem\n";
        std::cout << "3. Excluir Passagem\n";
        std::cout << "4. Salvar Passagens\n";
        std::cout << "5. Carregar Dados\n";
        std::cout << "6. Listar Passagens\n";
        std::cout << "7. Pesquisar Passagens\n";
        std::cout << "8. Sair\n";
        std::cout << "Digite a opção desejada: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarPassagem(passagens);
            break;
        case 2:
            editarPassagem(passagens);
            break;
        case 3:
            excluirPassagem(passagens);
            break;
        case 4:
            salvarPassagens(passagens);
            break;
        case 5:
            carregarDados(passagens);
            break;
        case 6:
            listarPassagens(passagens);
            break;
        case 7:
            pesquisarPassagens(passagens);
            break;
        case 8:
            return;
        default:
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

int main()
{
    interface();
    return 0;
}