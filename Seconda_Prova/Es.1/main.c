#include <stdio.h>

/*
Scrivere un programma che consenta all'utente di inserire una sequenza di numeri interi. 
La lunghezza della sequenza deve essere chiesta all'utente prima dell'inserimento. 
Il programma poi deve esaminare la sequenza e visualizzare gli indici di tutti gli elementi che hanno almeno un duplicato successivo. 

**Obiettivo:**
Per ogni elemento della sequenza, il programma deve verificare se esiste un altro elemento uguale a lui in una posizione successiva. 
Se tale elemento esiste, il programma deve visualizzare l'indice dell'elemento nella sequenza.

**Esempio:**
Consideriamo la seguente sequenza di numeri: 
1, 2, 3, 1, 2, 4, 5, 1, 5

Nel caso di questa sequenza, gli elementi che hanno un duplicato successivo sono:
- 1 alla posizione 0 (duplicato alla posizione 3 e 7)
- 2 alla posizione 1 (duplicato alla posizione 4)
- 1 alla posizione 3 (duplicato alla posizione 7)
- 5 alla posizione 6 (duplicato alla posizione 8)

Quindi, il programma dovrebbe stampare gli indici:
0, 1, 3, 6

**Passaggi principali del programma:**
1. Chiedere all'utente la lunghezza della sequenza.
2. Creare un array di interi per contenere la sequenza di numeri.
3. Chiedere all'utente di inserire i numeri uno per uno.
4. Per ogni numero nella sequenza, controllare se esiste un duplicato successivo in una posizione più avanti nella sequenza.
5. Se esiste, memorizzare l'indice di tale elemento e, alla fine, visualizzare tutti gli indici trovati.

**Nota:** 
- La sequenza può avere anche numeri ripetuti, e il programma deve riuscire a gestirli correttamente.
- La ricerca del duplicato deve essere effettuata solo sui numeri che si trovano nelle posizioni precedenti nella sequenza.

**Esempio di input e output:**
Input:
Lunghezza della sequenza: 9
Sequenza: 1, 2, 3, 1, 2, 4, 5, 1, 5

Output:
Indici degli elementi con duplicati successivi: 0, 1, 3, 6
*/


int main(){
    int nElementi;
    // Richiesta di quanti elementi
    printf("Indica il numero di elementi da inserire: ");
    scanf("%d", &nElementi); // salvataggio nella variabile

    // Creazione array con il numero di elementi
    int sequenza[nElementi];

    //Ciclo per far salvare i numeri all'interno degli elementi
    for(int i = 0; i < nElementi; i++){
        printf("Elemento numero %d: ", i + 1);
        scanf("%d", &sequenza[i]);
    }

    // Ciclo per stampare la posizione degli elementi che si ripetono
    for(int i = 0; i < nElementi; i++){
        for(int j = i + 1; j < nElementi; j++){
            if(sequenza[i] == sequenza[j]){
                printf("%d ", i);
                break;
            }
        }
    }
    printf("\n");


    return 0;
}