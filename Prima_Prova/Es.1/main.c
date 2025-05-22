#include <stdio.h>

/*
Scrivere un programma che fa inserire all’utente una sequenza di interi,
la cui lunghezza può essere chiesta all’utente prima dell’inserimento, 
e dice all’utente se gli elementi della sequenza sono tutti distinti.
*/

int main(){

    int nElementi = 0;

    printf("Inserisci il numero di elementi: ");
    scanf("%d", &nElementi);

    int arr[nElementi];
    int distinti = 0;

    for(int i = 0; i < nElementi; i++){

        printf("Elemento n.%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < nElementi; i++){
        for(int j = i + 1; j < nElementi; j++){

            if(arr[i] == arr[j]){
                distinti = 1;
            }
        }
    }

    if(distinti){
        printf("Gli elementi sono tutti uguali o vi sono doppioni.\n");
    }else{
        printf("Gli elementi sono tutti distinti.\n");
    }



    return 0;
}