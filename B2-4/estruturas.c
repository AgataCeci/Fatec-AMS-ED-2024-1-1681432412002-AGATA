#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
  char nome[50];
  int idade;
  char tipoAtend[20]; 
  char prioridade[10]; 
  time_t inicio;
  time_t fim;
} Paciente;

typedef struct Node{
  Paciente paciente;
  struct Node *prox;
} Node;

typedef struct{
  Node *inicio;
  Node *fim;
} Fila;
