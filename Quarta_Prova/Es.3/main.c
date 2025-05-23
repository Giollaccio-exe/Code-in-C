#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 * Gioco dell’impiccato:
 *
 * - Si definisce un dizionario di parole, rappresentato come un array di stringhe,
 *   ad esempio: char * dizionario[] = {"sole", "mare", "neve"};
 *
 * - Il programma sceglie casualmente una parola dal dizionario.
 *
 * - Viene mostrata all’utente una "parola nascosta" costituita da tanti trattini
 *   quanti sono i caratteri della parola scelta (esempio: "____" per una parola di 4 lettere).
 *
 * - Il gioco procede con un ciclo in cui l’utente deve indovinare le lettere della parola:
 *
 *   1) L’utente inserisce una lettera da provare.
 *
 *   2) Il programma verifica se la lettera inserita è presente nella parola segreta:
 *      - Se la lettera è presente:
 *          • La parola nascosta viene aggiornata mostrando la lettera nelle posizioni corrette,
 *            mentre le lettere non ancora indovinate rimangono nascoste con i trattini.
 *          • Viene mostrata la parola aggiornata con le lettere scoperte.
 *          • Se tutte le lettere della parola sono state indovinate, il programma mostra
 *            un messaggio di congratulazioni e termina il gioco.
 *
 *      - Se la lettera non è presente nella parola:
 *          • Viene mostrato un messaggio che informa l’utente dell’errore.
 *          • Viene incrementato un contatore degli errori commessi.
 *          • Se il numero di errori raggiunge 6, il programma mostra un messaggio di sconfitta
 *            e termina il gioco.
 *
 * - Il ciclo continua finché l’utente indovina tutte le lettere della parola o commette 6 errori.
 *
 * Interazione tipica:
 *
 *   • Il programma mostra la parola nascosta (esempio: "_ _ _ _") e chiede all’utente di inserire una lettera.
 *   • L’utente inserisce una lettera.
 *   • Il programma aggiorna la visualizzazione in base alla correttezza della lettera.
 *   • Se la lettera è errata, mostra un messaggio di errore e invita a riprovare.
 *   • Se la lettera è corretta, mostra la parola aggiornata e invita a inserire un’altra lettera.
 *   • Se l’utente indovina tutta la parola, il programma mostra un messaggio di vittoria.
 *   • Se l’utente commette 6 errori, mostra un messaggio di sconfitta.
 *
 * Questo approccio permette di simulare il gioco classico dell’impiccato in modo semplice e chiaro,
 * utilizzando strutture dati base (array di stringhe) e cicli di controllo.
 */


 #define MAX_ERRORI 6

int main(){

    srand(time(NULL));

    char dizionario[][10] = {"sole", "mare", "neve"};
    //controllo quante parole ci sono
    int numParole = sizeof(dizionario) / sizeof(dizionario[0]);
    //Ne estraggo una casuale
    int indiceParola = rand() % numParole;

    char *parolaSegreta = dizionario[indiceParola];
    int lunghezza = strlen(parolaSegreta);

    int lettereIndovinate[lunghezza];
    for(int i = 0; i < lunghezza; i++){
        lettereIndovinate[i] = 0;
    }

    int errori = 0; 
    int lettereRimanenti = lunghezza;
    
    puts("Indovina la parola segreta");
    for(int i = 0; i < lunghezza; i++){
        printf("_ ");
    }
    printf("\n");

    while (errori < MAX_ERRORI && lettereRimanenti > 0)
    {
       printf("Dimmi una lettera: ");
       char input;
       scanf("%c", &input);
       
       int presente = 0;

       for(int i = 0; i < lunghezza; i++){
            if(parolaSegreta[i] == input && lettereIndovinate[i] == 0){
                lettereIndovinate[i] = 1;
                presente = 1;
                lettereRimanenti--;
                errori = 0;
            }
       }

       if(presente){

        printf("Bravo, la parola segreta: ");
        for(int i = 0; i < lunghezza; i++){
            if(lettereIndovinate[i])
            {
                printf("%c ", parolaSegreta[i]);
            }
            else{
                printf("_ ");
            }
         }
        printf("\n");
       }
       else{
        errori++;
        printf("La lettera %c non e' presente nella parola, riprova.\n", input);
        printf("Errori: %d su %d\n", errori, MAX_ERRORI);
       }
       
    }

    if(lettereRimanenti == 0){
        printf("Bravo hai indovinato, la parola era: ");
        for(int i = 0; i < lunghezza; i++){
            printf("%c", parolaSegreta[i]);
        }
        printf("\n");
    }else{
        printf("Hai perso! Hai superato il numero massimo di errori.\n");
        printf("La parola era: %s\n", parolaSegreta);
    }
    

    return 0;
}