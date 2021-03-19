#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_EQUIPAMENTOS 20

//ESTRUTURA DE DADOS
struct s_equipamento {
char nome[50];
int preco_aquisicao[20];
char fabricante[50];
int numero_serie;
char data_fabricacao[10];
char filiacao[75];
};




// VETOR COM NO MAXIMO 20 EQUIPAMENTOS
struct s_equipamento EQUIPAMENTOS[MAX_EQUIPAMENTOS];


// EDITAR EQUIPAMENTOS
int n_EQUIPAMENTOS = 0;
void editarEquipamento(struct s_equipamento equipamento, int i){
 EQUIPAMENTOS[i] = equipamento;
}

// CADASTRAR EQUIPAMENTOS
void cadastraEquipamento(struct s_equipamento equipamento) {
    EQUIPAMENTOS[n_EQUIPAMENTOS] = equipamento;
    n_EQUIPAMENTOS++;
}

// LENDO AS INFORMACOES DOS EQUIPAMENTOS
struct s_equipamento leDados() {
    struct s_equipamento auxiliar;
    printf("-----------------------------\n");
    printf("|  Cadastrando Equipamento  |\n");
    printf("-----------------------------\n");
    printf("\n\n");
    printf("Nome do produto: ");
    fflush(stdin);
    fgets(auxiliar.nome, 50, stdin);
    printf("\nPreco de aquisicao: ");
    fflush(stdin);
    fgets(auxiliar.preco_aquisicao, 15, stdin);
    printf("\nFabricante: ");
    fflush(stdin);
    fgets(auxiliar.fabricante, 15, stdin);
    printf("\nData de Fabricacao: ");
    fflush(stdin);
    scanf("%s", &auxiliar.data_fabricacao);
    printf("\nNumero de serie: ");
    fflush(stdin);
    scanf("%d", &auxiliar.numero_serie);
    system("cls");
    return auxiliar;

}
// FUNCAO DE RETORNO NA TELA

void imprimeEQUIPAMENTOS() {
    int i=0;

    for (i=0; i<n_EQUIPAMENTOS; i++) {
        printf("+++++++++++++++++++++++++\n");
        printf("Posicao: %d\n", i+1);
        printf("Nome do equipamento: %s", EQUIPAMENTOS[i].nome);
        printf("Preco de aquisicao: %s", EQUIPAMENTOS[i].preco_aquisicao);
        printf("Fabricante: %s", EQUIPAMENTOS[i].fabricante);
        printf("Data de Fabricacao: %s", EQUIPAMENTOS[i].data_fabricacao);
        printf("Numero de serie: %d", EQUIPAMENTOS[i].numero_serie);
        printf("\n+++++++++++++++++++++++++\n");
    }
}

// MENU DE OPCOES

int menu() {
    int opcao;

    printf("---------------------------------------\n"
           "| Sistema de Estoque de Equipamentos |\n"
           "---------------------------------------\n");
    printf("\n\n===== MENU DE OPCOES =====\n");
    printf("0 - SAIR \n");
    printf("1 - INSERIR \n");
    printf("2 - EXIBIR TODOS \n");
    printf("3 - EXCLUIR \n");
    printf("4 - EDITAR\n");
    printf("==== ============== ====\n");
    printf("\nO que deseja fazer? ");
    scanf("%d", &opcao);

    return opcao;
}

// Função para remover um equipamento do vetor
// Note que não há retorno, apenas remove.
void remover(int posicao) {
    int indice = posicao - 1;
    int i=0;

    if ((posicao < 1) || (posicao > n_EQUIPAMENTOS)) {
        printf("\nPosicao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao == n_EQUIPAMENTOS) {
        n_EQUIPAMENTOS--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_EQUIPAMENTOS; i++) {
        EQUIPAMENTOS[i] = EQUIPAMENTOS[i+1];
    }
    n_EQUIPAMENTOS--;
}

// Editando dados do equipamento
void edit() {
    int i=0;
    struct s_equipamento equipamentos;

    struct s_equipamento auxiliar;
    printf("Digite a posicao do equipamento que deseja editar: ");
    scanf("%d", &i);
    printf("Novo Nome do equipamento: ");
    fflush(stdin);
    fgets(equipamentos.nome, 50, stdin);

    printf("Novo Preco de aquisicao: ");
    fflush(stdin);
    fgets(equipamentos.preco_aquisicao, 20, stdin);

    printf("Novo Fabricante: ");
    fflush(stdin);
    fgets(equipamentos.fabricante, 50, stdin);

    printf("Nova Data de Fabricacao: ");
    fflush(stdin);
    fgets(equipamentos.data_fabricacao, 10, stdin);

    printf("Novo Numero de serie: ");
    scanf("%d", &equipamentos.numero_serie);

    editarEquipamento(equipamentos, --i);

}

// Função principal, aqui começa o programa.
int main()
{
    int opcao_selecionada;
    int rem = 0;
    struct s_equipamento novo_EQUIPAMENTOS;
    int r;

    do {
        opcao_selecionada = menu();
        switch(opcao_selecionada) {
            case 0: break;

            case 1: // código para inserir
                system("cls");
                if (n_EQUIPAMENTOS == MAX_EQUIPAMENTOS) {
                    printf("\nBANCO DE DADOS LOTADO!\n");
                    break;
                }
                novo_EQUIPAMENTOS = leDados();
                cadastraEquipamento(novo_EQUIPAMENTOS);
                break;
            case 2: // código para exibir
                system("cls");
                imprimeEQUIPAMENTOS();
                break;
            case 3: // código para excluir
                system("cls");
                printf("Digite a posicao que deseja excluir: ");
                scanf("%d", &r);
                remover(r);
            break;
            case 4:
                system("cls");
                edit();

            break;

            default:
                printf("----- OPCAO INVALIDA -----");
        }
    }
    while (opcao_selecionada != 0);
    return 0;
}
