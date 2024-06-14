/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                                                        */
/*                         Ágata Cesquim                                  */
/*     Objetivo: Inserir na Lista Ligada                                  */
/*                                                                        */
/*                                                        Data:28/05/2024 */
/*------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* novoNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void inserirNaOrdem(Node** head, int data) {
    Node* newNode = novoNode(data);
  
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main(void) {
  
  Node* head = novoNode(10);
  head->next = novoNode(25);
  head->next->next = novoNode(40);
  head->next->next->next = novoNode(80);

  inserirNaOrdem(&head, 30);

  printList(head);
}

//temp de processamento 285ms
