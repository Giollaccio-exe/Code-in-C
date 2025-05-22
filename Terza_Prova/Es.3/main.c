#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 * Il programma implementa il gioco "Indovina che numero ho pensato".
 * Viene generato casualmente un numero intero compreso tra 1 e 1000.
 * L'utente deve cercare di indovinare il numero inserendo dei tentativi.
 *
 * Ad ogni tentativo:
 * - Se l'utente inserisce 0, il programma termina e rivela il numero da indovinare.
 * - Se l'utente indovina il numero, il programma si congratula e mostra il numero di tentativi effettuati.
 * - Se il numero inserito è maggiore del numero da indovinare, il programma indica che il numero corretto è più basso.
 * - Se il numero inserito è minore del numero da indovinare, il programma indica che il numero corretto è più alto.
 *
 * Il gioco continua finché l'utente non indovina o non inserisce 0 per interrompere.
 */


int main(){

    int numUtente, count = 1;
    srand(time(NULL));
    int numeroCPU = rand() % 1000 + 1;

    puts("--- Indovina Il Numero ---");
    puts("Ho scelto un numero casuale compreso tra 1 e 1000\nVediamo in quanti tentativi riesci ad indovinarlo!");

    do
    {
        printf("Tentativo numero: %d: ", count);
        scanf("%d", &numUtente);

        if(numUtente < numeroCPU){
            printf("Numero troppo basso, riprova!\n");
            count++;
        }
        else if(numUtente > numeroCPU){
            printf("Numero troppo alto, riprova!\n");
            count++;
        }
        else if(numUtente == numeroCPU){
            printf("Complimenti, hai vinto in %d tentativi!", count);
        }
        else{
            printf("Valore inserito non valido!");
        }


    } while (numUtente != numeroCPU);
    
    


    return 0;
}