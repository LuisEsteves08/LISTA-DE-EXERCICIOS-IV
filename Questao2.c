#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        printf("\n");
    }

    printf("\n--- Lista de Alunos ---\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n\n", alunos[i].nota);
    }

    return 0;
}

