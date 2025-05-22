#include <stdio.h>
#include <string.h>

/*
// 1. Definire una funzione 'muoviSinistra' che riceve come parametri:
//    - una matrice di interi che rappresenta la griglia di gioco;
//    - il numero di righe (m);
//    - il numero di colonne (n).


// 2. Per ogni riga della matrice:
//    a. Creare un array temporaneo per memorizzare temporaneamente i valori diversi da zero,
//       eliminando quindi tutti gli zeri presenti nella riga (simulando il movimento delle tessere verso sinistra).

//    b. Riempire l'array temporaneo scorrendo da sinistra a destra:
//       - Se si incontra una cella con valore > 0, la si aggiunge alla prima posizione libera dell’array temporaneo.


// 3. Dopo aver rimosso gli zeri, eseguire la fusione delle tessere:
//    - Scorrere l’array temporaneo da sinistra verso destra.
//    - Se due celle consecutive hanno lo stesso valore, sommare i loro valori (raddoppiandoli)
//      e impostare la cella successiva a zero (in quanto è stata fusa con la precedente).


// 4. Dopo la fusione, rimuovere nuovamente gli zeri che si sono creati a causa della fusione,
//    ripetendo lo stesso procedimento del punto 2a.


// 5. Aggiornare la riga corrispondente della matrice originale con i valori dell’array temporaneo
//    e riempire eventuali celle rimanenti con zeri (a destra), per mantenere la dimensione costante.


// 6. Nel main:
//    - Definire una matrice con dimensioni arbitrarie e inizializzarla con alcuni valori di esempio
//      che simulano una configurazione del gioco 2048 (inclusi zeri).
//    - Chiamare la funzione 'muoviSinistra' passando la matrice e le sue dimensioni.
//    - Stampare la matrice aggiornata per verificare che lo spostamento e le fusioni siano state eseguite correttamente.

*/

void muoviSinistra(int griglia[5][5]){

    for(int i = 0; i < 5; i++){
        int temp[5] = {0};
        int indice = 0;

        for(int j = 0; j < 5; j++){
            if(griglia[i][j] != 0){
                temp[indice++] = griglia[i][j];
            }
        }

        for(int j = 0; j < 4; j++){
            if(temp[j] != 0 && temp[j] == temp[j + 1]){
                temp[j] *= 2;
                temp[j + 1] = 0;
            }
        }

        int nuovaRiga[5] = {0};
        indice = 0;
        for(int j = 0; j < 5; j++){
            if(temp[j] != 0){
                nuovaRiga[indice++] = temp[j];
            }
        }

        for(int j = 0; j < 5; j++){
            griglia[i][j] = nuovaRiga[j];
        }
    }

}


int main(){

    int griglia[5][5] = {
        {2, 0, 2, 4, 0},
        {0, 4, 4, 0, 2},
        {2, 2, 2, 2, 2},
        {0, 0, 0, 2, 2},
        {4, 0, 0, 0, 4}
    };

    puts("Griglia originale:");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%4d", griglia[i][j]);
        }
        printf("\n");
    }

    muoviSinistra(griglia);
    
    puts("\nGriglia dopo il movimento a sinistra:");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%4d", griglia[i][j]);
        }
        printf("\n");
    }

    return 0;
}