/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                                                        */
/*                         Ágata Cesquim                                  */
/*     Objetivo: Analisar eficiência de algorítimos e passar para         */
/*               notação Big O                                            */
/*                                                                        */
/*                                                                        */
/*                                                        Data:01/10/2024 */
/*------------------------------------------------------------------------*/ 


#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; 
    }
    return -1; 
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element not present\n")
                   : printf("Element found at index %d\n", result);
    return 0;
}