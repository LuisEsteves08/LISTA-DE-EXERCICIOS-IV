#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirAluno(struct Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Nota: %.2f\n", a.nota);
}

struct Aluno criarAluno() {
    struct Aluno novo;
    size_t len;

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    len = strlen(novo.nome);
    if (len > 0 && novo.nome[len - 1] == '\n') {
        novo.nome[len - 1] = '\0';
    }

    printf("Idade: ");
    while (scanf("%d", &novo.idade) != 1) {
        limpar_buffer();
        printf("Entrada invalida. Digite a idade: ");
    }
    limpar_buffer();

    printf("Nota: ");
    while (scanf("%f", &novo.nota) != 1) {
        limpar_buffer();
        printf("Entrada invalida. Digite a nota: ");
    }
    limpar_buffer();

    return novo;
}

void removerAluno(struct Aluno alunos[], int *qtd, int indice) {
    int i;
    for (i = indice; i < (*qtd) - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    (*qtd)--;
}

int main() {
    struct Aluno alunos[4];
    int qtd = 0;
    int opcao;
    int i;
    int indice;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Criar novo aluno\n");
        printf("2 - Exibir todos os alunos\n");
        printf("3 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Opcao invalida.\n");
            continue;
        }
        limpar_buffer();

        if (opcao == 1) {
            if (qtd == 4) {
                printf("Limite maximo de alunos atingido.\n");
            } else {
                alunos[qtd] = criarAluno();
                qtd++;
            }
        } 
        else if (opcao == 2) {
            if (qtd == 0) {
                printf("Nenhum aluno cadastrado.\n");
            } else {
                for (i = 0; i < qtd; i++) {
                    printf("\nAluno %d:\n", i);
                    exibirAluno(alunos[i]);
                }
            }
        } 
        else if (opcao == 3) {
            if (qtd == 0) {
                printf("Nao ha alunos para remover.\n");
            } else {
                printf("Informe o indice do aluno para remover (0 a %d): ", qtd - 1);
                if (scanf("%d", &indice) != 1) {
                    limpar_buffer();
                    printf("Indice invalido.\n");
                    continue;
                }
                limpar_buffer();

                if (indice < 0 || indice >= qtd) {
                    printf("Indice invalido.\n");
                } else {
                    removerAluno(alunos, &qtd, indice);
                    printf("Aluno removido.\n");
                }
            }
        }

    } while (opcao != 0);

    return 0;
}

