#include <stdio.h>
#include <string.h>

/*
// 1. Definire la struttura 'medaglie' che rappresenta il medagliere di una nazione.
//    - 'paese' è una stringa di massimo 20 caratteri che memorizza il nome della nazione.
//    - 'ori', 'argenti' e 'bronzi' sono interi che memorizzano rispettivamente il numero di medaglie d'oro, d'argento e di bronzo.


// 2. Chiedere all’utente quanti paesi si desidera inserire nel medagliere.
//    - Utilizzare una variabile per memorizzare questo numero e usarlo per determinare la dimensione dell’array di strutture.


// 3. Creare un array di strutture 'medaglie' per memorizzare i dati di ciascun paese.


// 4. Utilizzare un ciclo per permettere all’utente di inserire i dati per ogni paese:
//    - Inserire il nome della nazione.
//    - Inserire il numero di medaglie d’oro, d’argento e di bronzo.


// 5. Inizializzare una variabile che tenga traccia del paese attualmente primo in classifica.


// 6. Utilizzare un ciclo per confrontare tutti i paesi e determinare quale ha il medagliere migliore:
//    - Confrontare prima il numero di medaglie d’oro.
//    - In caso di parità, confrontare le medaglie d’argento.
//    - Se c’è ancora parità, confrontare le medaglie di bronzo.


// 7. Alla fine del ciclo, visualizzare a schermo il nome del paese che risulta primo nel medagliere,
//    cioè quello con il maggior numero di ori, poi argenti, poi bronzi in caso di parità.

*/
#define MAX_CARATTERI 20

typedef struct{

    char paese[MAX_CARATTERI];
    int ori;
    int argenti;
    int bronzi;

} Medaglie;

// Rimozione della newline dai dati
void rimuoviNewline(char *str){
    str[strcspn(str, "\n")] = 0;
}

int main(){

    int nPaesi = 0;

    printf("Inserisci il numero di paesi da inserire: ");
    scanf("%d", &nPaesi);
    getchar();

    int primo = 0;

    Medaglie medagliere[nPaesi];

    for(int i = 0; i < nPaesi; i++){
        printf("Inserisci il nome del paese: ");
        fgets(medagliere[i].paese, MAX_CARATTERI, stdin);
        rimuoviNewline(medagliere[i].paese);

        printf("Inserisci il numero di ori: ");
        scanf("%d", &medagliere[i].ori);
        getchar();

        printf("Inserisci il numero di argenti: ");
        scanf("%d", &medagliere[i].argenti);
        getchar();

        printf("Inserisci il numero di bronzi: ");
        scanf("%d", &medagliere[i].bronzi);
        getchar();
    }

    for(int i = 1; i < nPaesi; i++){
            if(medagliere[i].ori == medagliere[primo].ori){

                if(medagliere[i].argenti == medagliere[primo].argenti){

                    if(medagliere[i].bronzi > medagliere[primo].bronzi){
                        primo = i;
                    }

                }
                else if(medagliere[i].argenti > medagliere[primo].argenti){
                    primo = i;
                }

            }
            else if(medagliere[i].ori > medagliere[primo].ori){
                primo = i;
            }
    }
    
    for(int i = 0; i < nPaesi; i++){
        printf("| Paese: %s | Ori: %d | Argenti: %d | Bronzi: %d |\n", medagliere[i].paese, medagliere[i].ori, medagliere[i].argenti, medagliere[i].bronzi);
    }
    
    printf("Paese vincitore: %s", medagliere[primo].paese);


    return 0;
}