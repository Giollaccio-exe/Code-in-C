#include <stdio.h>

/*
 * Questo programma simula una parte del funzionamento del videogioco Tetris.
 * In particolare, implementa una funzione chiamata `controllaRighe` che analizza una matrice m x n
 * che rappresenta l'area di gioco del Tetris.
 *
 * Ogni cella della matrice può contenere:
 *   - 0 se la cella è vuota,
 *   - 1 se la cella è occupata da un blocco.
 *
 * L'obiettivo della funzione `controllaRighe` è:
 *   1. Verificare se ci sono righe "complete", ovvero righe in cui tutte le celle sono uguali a 1.
 *   2. Se una riga è completa, viene "rimossa": tutte le righe soprastanti vengono spostate verso il basso.
 *   3. Dopo aver spostato le righe verso il basso, il controllo riparte dalla riga eliminata,
 *      perché potrebbe esserci una nuova riga completa che si è formata in quella posizione.
 *
 * La funzione riceve come parametri:
 *   - una matrice intera (l'area di gioco),
 *   - il numero di righe (m),
 *   - il numero di colonne (n).
 *
 * È fornita anche una funzione `main` che serve per testare `controllaRighe`.
 * In `main`, si definisce una matrice di esempio direttamente nel codice (letterale array),
 * si stampa la matrice iniziale, si applica la funzione `controllaRighe`,
 * e si stampa la matrice risultante per verificare il corretto funzionamento della funzione.
 */

#define MAX_CELLE 10

void controllaRighe(int matrice[MAX_CELLE][MAX_CELLE]){

    //Ciclo for che parte dal basso
    for(int i = MAX_CELLE - 1; i >= 0; i--){

        //Ipotizzo che la cella sia completa
        int completa = 1;
        
        //Se la riga è 0 non è completa
        for(int j = 0; j < MAX_CELLE; j++){
            if(matrice[i][j] == 0){
                completa = 0;
                break;
            }
        }
        //Se la riga è completa
        if(completa){
            for(int k = i; k > 0; k--){
                for(int j = 0; j < MAX_CELLE; j++){
                    //Faccio scendere la riga superiore
                    matrice[k][j] = matrice[k - 1][j];
                }
            }
            //Mando a zero la prima riga
            for(int j = 0; j < MAX_CELLE; j++){
                matrice[0][j] = 0;
            }
            //Controlla la riga sotto
            i++;
        }
    }

};

int main(){

    // Esempio di campo di gioco Tetris 10x10
    int matrice[MAX_CELLE][MAX_CELLE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Riga completa
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Riga completa
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    //Stampo il campo di gioco prima
    puts("Campo di gioco prima: ");
    for(int i = 0; i < MAX_CELLE; i++){
        for(int j = 0; j < MAX_CELLE; j++){
            printf("%d", matrice[i][j]);
        }
        printf("\n");
    }
    //Richiamo la funzione
    controllaRighe(matrice);

    //Stampo il campo di gioco dopo la funzione
    puts("Campo da gioco dopo: ");
    for(int i = 0; i < MAX_CELLE; i++){
        for(int j = 0; j < MAX_CELLE; j++){
            printf("%d", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}