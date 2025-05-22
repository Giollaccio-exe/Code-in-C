#include <stdio.h>

/*
Nel gioco degli scacchi, l’alfiere si muove in diagonale, attraversando un numero qualsiasi di caselle 
in entrambe le direzioni diagonali (sia in alto a sinistra e in basso a destra, che in alto a destra e in basso a sinistra). 
Un pezzo che si trova su una di queste due diagonali passanti per l’alfiere è considerato "minacciato" dall’alfiere.

Il compito è scrivere una funzione chiamata **contaMinacciati**, la quale deve contare il numero di pezzi 
minacciati da un alfiere su una scacchiera. 
La funzione riceve in ingresso un array bidimensionale di caratteri di dimensione 8x8 che rappresenta la scacchiera, 
in cui ogni elemento rappresenta una casella della scacchiera. I pezzi sulla scacchiera sono rappresentati da caratteri 
specifici:
    - 'R' per il re
    - 'D' per la regina
    - 'T' per la torre
    - 'A' per l’alfiere
    - 'C' per il cavallo
    - 'P' per il pedone
    - Un carattere vuoto (' ') indica una casella vuota.

Per semplicità, si assume che tutti i pezzi siano dello stesso colore e che l'alfiere minacci solo i pezzi 
del suo stesso colore.

**Funzionalità richiesta:**
1. La funzione deve cercare l'alfiere sulla scacchiera.
2. Una volta trovato, deve esplorare le due diagonali che passano per l'alfiere, contando i pezzi che si trovano 
   su queste diagonali.
3. Ogni pezzo che si trova sulla stessa diagonale dell'alfiere è considerato minacciato, ma si fermano appena 
   viene trovato un altro pezzo, poiché l'alfiere non può saltare sopra altri pezzi.
4. La funzione restituirà il numero di pezzi minacciati dall'alfiere.

**Input:**
- Una matrice 8x8 rappresentante una scacchiera con i pezzi posizionati.

**Output:**
- Il numero di pezzi minacciati dall’alfiere trovato nella scacchiera.

Per testare la funzione, sarà sufficiente definire una matrice 8x8 tramite un array di caratteri e passarlo alla 
funzione **contaMinacciati**. Un programma di esempio dovrà essere incluso, in modo che l'utente possa verificare 
il comportamento della funzione con diverse configurazioni di pezzi sulla scacchiera.
*/


#define MAX_TABELLA 8 // Grandezza scacchiera

int contaMinacciati(char tabella[MAX_TABELLA][MAX_TABELLA]){

    int count = 0; // inizializzo il counter dei pezzi minacciati

    // Direzioni delle diagonali
    int dx[] = {-1, -1, 1, 1}; 
    int dy[] = {-1, 1, -1, 1};

    // Per evitare di contare lo stesso pezzo più volte
    int minacciati[MAX_TABELLA][MAX_TABELLA] = {0};

    // Ciclo per individuare l'alfiere
    for(int riga = 0; riga < MAX_TABELLA; riga++){
        for(int colonna = 0; colonna < MAX_TABELLA; colonna++){

            if(tabella[riga][colonna] == 'A'){ // Se si trova l'alfiere
                //Ciclo per esplorare le 4 direzioni diagonali
                for(int dir = 0; dir < 4; dir++){
                    int x = riga + dx[dir];
                    int y = colonna + dy[dir];

                    // Finché si è all'interno della tabella di gioco
                    while(x >= 0 && x < MAX_TABELLA && y >= 0 && y < MAX_TABELLA){
                        //Se troviamo un pezzo
                        if(tabella[x][y] != ' '){
                            if(!minacciati[x][y]){ // Se non è un pezzo segnato come minacciato
                                count++;  // Incrementa il counter dei minacciati
                                minacciati[x][y] = 1; // Segna il pezzo come già minacciato
                            }
                            break; // la diagonale viene bloccata da un pezzo
                        }
                        // Aggiornamento delle coordinate
                        x += dx[dir];
                        y += dy[dir];
                    }
                }
            }
        }
    }
    return count; // Restituisce il numero dei pezzi minacciati
}

int main(){

    // Definizione della scacchiera 8x8
    char tabella[MAX_TABELLA][MAX_TABELLA] = {
        {'T', ' ', ' ', ' ', ' ', ' ', ' ', 'T'},
        {' ', 'C', ' ', ' ', ' ', ' ', 'C', ' '},
        {' ', ' ', 'A', ' ', 'P', ' ', ' ', ' '},
        {' ', ' ', ' ', 'A', ' ', ' ', ' ', ' '},
        {' ', 'P', ' ', ' ', 'D', ' ', 'P', ' '},
        {' ', ' ', ' ', ' ', ' ', 'C', ' ', ' '},
        {'P', ' ', 'P', ' ', 'P', ' ', 'P', ' '},
        {'R', ' ', ' ', ' ', ' ', ' ', ' ', 'R'}
    };

    int minacciati = contaMinacciati(tabella); // Richiama la funzione e salva il valore di ritorno nella variabile
    printf("Pezzi minacciati dall'alfiere: %d\n", minacciati); // Stampa il risultato

    return 0;
}