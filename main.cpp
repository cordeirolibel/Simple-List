#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;

struct Node
{
    Node* ant, *prox;
    int dado;
};

void imprimeMenu(bool tudo=true)
{
    system("cls");
    cout << "  _      _     _     __  __             _             _       _                  " << endl;
    cout << " | |    (_)   | |   |  \\/  |           (_)           | |     | |                " << endl;
    cout << " | |     _ ___| |_  | \\  / | __ _ _ __  _ _ __  _   _| | __ _| |_ ___  _ __     " << endl;
    cout << " | |    | / __| __| | |\\/| |/ _` | '_ \\| | '_ \\| | | | |/ _` | __/ _ \\| '__| " << endl;
    cout << " | |____| \\__ \\ |_  | |  | | (_| | | | | | |_) | |_| | | (_| | || (_) | |      " << endl;
    cout << " |______|_|___/\\__| |_|  |_|\\__,_|_| |_|_| .__/ \\__,_|_|\\__,_|\\__\\___/|_|  " << endl;
    cout << "                                         | |                                     " << endl;
    cout << "                                         |_|                                     " << endl;
    cout << "=============================================================================    " << endl;
    if(tudo)
    {
        cout << " Selecione uma opção:" << endl;
        cout << "  1. Exibir lista" << endl;
        cout << "  2. Inclusão no início da lista " << endl;
        cout << "  3. Inclusão no fim da lista" << endl;
        cout << "  4. Remoção do início da lista" << endl;
        cout << "  5. Remoção do fim da lista " << endl;
        cout << "  0. Sair " << endl;
        cout << ">>";
    }
}

int receberDado(const char* msg)
{
    int dado;
    imprimeMenu(false);
    cout << msg;
    cout << endl << " Dado: ";
    cin >> dado;

    /// Tratamento de entrada
    while(!cin.good())
    {
        cin.clear();
        cin.ignore();
        imprimeMenu(false);
        cout << msg;
        cout << endl << " Entrada inválida!" << endl << " Dado: ";
        cin >> dado;
    }
    return dado;
}

void exibirLista(Node *topo)
{
    imprimeMenu(false);
    cout << " Exibir lista:" << endl;

    if (topo == NULL)
    {
        cout << "  A lista não possui itens!" << endl;
    }
    else
    {
        Node* node = topo;
        int i = 0;
        cout << "Topo: " << topo << "  Endereço do topo: " << &topo << endl;
        do
        {
            cout << "No " << (++i);
            cout << ": Endereço: " << node;
            cout <<" Valor: " << node->dado;
            cout <<" Endereço do próximo: " << node->prox << endl;

            node = node->prox;
        }
        while(node != NULL);
    }
    system("pause");
}

void inclusaoInicio(Node** topo, Node** fim, int dado)
{
    Node *node = new Node();
    node->dado = dado;
    node->prox = *topo;
    node->ant = NULL;

    /// Primeiro item
    if(*fim == NULL)
        *fim = node;
    else
        (*topo)->ant = node;

    *topo = node;
}

void inclusaoFim(Node** topo, Node** fim, int dado)
{
    Node *node = new Node();
    node->dado = dado;
    node->prox = NULL;
    node->ant = *fim;

    /// Primeiro item
    if(*topo == NULL)
        *topo = node;
    else
        (*fim)->prox = node;

    *fim = node;

    system("pause");
}

void removerInicio(Node** topo, Node** fim)
{
    /// Nenhum item
    if(*fim == NULL)
    {
        imprimeMenu(false);
        cout << " A lista não possui itens, nenhum item foi removido!"  << endl;
        system("pause");
        return;
    }

    /// Múltiplos itens
    if(((*topo)->prox) != NULL)
    {
        ((*topo)->prox)->ant = NULL;
        Node *aux = ((*topo)->prox);
        delete *topo;
        *topo = aux;
    }
    /// Um item
    else
    {
        delete *topo;
        *topo = *fim = NULL;
    }

    imprimeMenu(false);
    cout << "Removido do início da lista!"  << endl;
    system("pause");
}

void removerFim(Node** topo, Node** fim)
{
    /// Nenhum item
    if(*fim == NULL)
    {
        imprimeMenu(false);
        cout << " A lista não possui itens, nenhum item foi removido!" << endl;
        system("pause");
        return;
    }

    /// Múltiplos itens
    if(((*fim)->ant) != NULL)
    {
        ((*fim)->ant)->prox = NULL;
        Node *aux = ((*fim)->ant);
        delete *fim;
        *fim = aux;
    }
    /// Um item
    else
    {
        delete *fim;
        *topo = *fim = NULL;
    }

    imprimeMenu(false);
    cout << "Removido do fim da lista!"  << endl;
    system("pause");
}

int main()
{
    Node* topo = NULL;
    Node* fim = NULL;

    setlocale(LC_ALL, "Portuguese");

    char ent;
    while(1)
    {
        imprimeMenu();

        cin >> ent;
        switch(ent)
        {
        case '0':
            return 0;
        /// Exibir lista
        case '1':
            exibirLista(topo);
            break;
        /// Inclusão no início da lista
        case '2':
            inclusaoInicio(&topo,&fim, receberDado(" Inclusão no início da lista:"));
            break;
        /// Inclusão no fim da lista
        case '3':
            inclusaoFim(&topo,&fim, receberDado(" Inclusão no fim da lista:"));
            break;
        /// Remoção do início da lista
        case '4':
            removerInicio(&topo,&fim);
            break;
        /// Remoção do fim da lista
        case '5':
            removerFim(&topo,&fim);
            break;
        /// Entrada inválida
        default:
            break;
        }
    }
}
