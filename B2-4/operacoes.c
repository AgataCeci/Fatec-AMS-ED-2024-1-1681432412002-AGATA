#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Paciente cadPac() {
  Paciente paciente;

  printf("Digite o nome do paciente: \n");
  scanf("%s", paciente.nome);
  printf("Digite a idade do paciente: \n");
  scanf("%d", &paciente.idade);
  printf("Digite o tipo de atendimento do paciente: \n");
  scanf("%s", paciente.tipoAtend);
  printf("Digite a prioridade do paciente: \n");
  scanf("%s", paciente.prioridade);
  printf("---------------------------------");

  paciente.inicio = time(NULL);
  paciente.fim = 0;

  return paciente;
}

Paciente atender(Fila *fila) {
  Node *node = (Node *)malloc(sizeof(Node));
  Node *ant = fila->inicio;
  fila->inicio = fila->inicio->prox;
  return ant->paciente;
}

Fila iniciarFila() {
  Fila fila;

  fila.inicio = NULL;
  fila.fim = NULL;

  return fila;
}

void enfileirar(Fila *fila, Paciente *paciente) {
  Node *nn = (Node *)malloc(sizeof(Node));
  nn->paciente = *paciente;

  if (fila->inicio == NULL)
    fila->inicio = nn;

  else if (fila->fim != NULL)
    fila->fim->prox = nn;

  fila->fim = nn;
}

void mostrarFila(Fila *fila) {

  Node *nn = fila->inicio;

  while (nn != NULL) {
    printf("Fila: %s\n", nn->paciente.prioridade);
    printf("Nome: %s\n", nn->paciente.nome);
    printf("Idade: %d\n", nn->paciente.idade);
    printf("Tipo atendimento: %s\n", nn->paciente.tipoAtend);
    printf("---------------------------------\n");

    nn = nn->prox;
  }
}

Paciente *paciente_teste(char *nome, int idade, char *tipoAtend) {
  Paciente *np = (Paciente *)malloc(sizeof(Paciente));
  strcpy(np->nome, nome);
  np->idade = idade;
  strcpy(np->tipoAtend, tipoAtend);
  return np;
}

void menu() {
  int opcao;
  Fila fila = iniciarFila();
  Fila prio = iniciarFila();
  Fila urgente = iniciarFila();
  Fila histo = iniciarFila();

  enfileirar(&urgente, paciente_teste("Josias", 1, "quadril"));
  enfileirar(&fila, paciente_teste("Tikomo Nakama", 35, "mões"));
  enfileirar(&prio, paciente_teste("Choso", 68, "hemorragia"));
  enfileirar(&fila, paciente_teste("Sukuna", 35, "desmembrado"));

  int pref_counter = 1;

  while (opcao != 0) {
    printf("\n");
    printf("Escolha a ação que deseja realizar:\n");
    printf("\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Atender paciente\n");
    printf("3 - Mostrar filas\n");
    printf("0 - Finalizar operação\n");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
    case 1: {
      Paciente pc = cadPac();

      if (strcmp(pc.prioridade, "normal") == 0) {
        enfileirar(&fila, &pc);
      } else if (strcmp(pc.prioridade, "prioritário") == 0) {
        enfileirar(&prio, &pc);
      } else if (strcmp(pc.prioridade, "URGENTE") == 0) {
        enfileirar(&urgente, &pc);
      }

      break;
    }
    case 2: {
      Paciente pc;

      if (urgente.inicio != NULL) {
        pc = atender(&urgente);
      } else if (prio.inicio != NULL && pref_counter % 4 != 0) {
        pc = atender(&prio);
        pref_counter++;
      } else {
        pc = atender(&fila);
        pref_counter++;
      }

      printf("Paciente %s atendido\n", pc.nome);
      enfileirar(&histo, &pc);

      break;
    }
    case 3: {
      Fila filas[] = {fila, prio, urgente, histo};
      int i;
      printf("Qual fila você quer ver?\n1 - Normal\n2 - Prioritário\n3 - "
             "Urgente\n4 - Histórico\n> ");
      scanf("%d", &i);
      printf("---------------------------------\n");
      mostrarFila(&filas[i - 1]);

      break;
    }
    }
  }
}
