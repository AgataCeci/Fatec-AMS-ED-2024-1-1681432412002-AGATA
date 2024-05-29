#include <stdio.h>

int main(void) {

  int seqNum[5] = {10,25,40,80};
  int valor = 30;
  int numElementos = 4;

  int meio = numElementos/2;

  for(int i=numElementos; i > meio; i--){
    seqNum[i] = seqNum[i-1];
  }

  seqNum[meio] = valor;

  for (int i=0; i<5; i++){
    printf("%d\n", seqNum[i]);
  }

 return 0;
  
}

//Tempo de execução: 270ms
