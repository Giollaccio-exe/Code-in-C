#include <stdio.h>
#include <string.h>

/*
Si vuole realizzare un programma che gestisca un sistema di prenotazione per un esame. 
Il sistema deve permettere l'iscrizione di un massimo di 100 studenti, memorizzando 
per ciascuno il nome, il cognome e il numero di matricola. 

A tale scopo, si definisce una struttura denominata "Prenotazione" che conterrà le seguenti informazioni:
    - Nome dello studente (max 20 caratteri)
    - Cognome dello studente (max 20 caratteri)
    - Numero di matricola (6 caratteri, con il settimo carattere per il terminatore '\0')

Il programma dovrà utilizzare un array di 100 elementi di tipo "Prenotazione" per rappresentare 
la lista degli studenti iscritti. Le posizioni vuote nell'array dovranno contenere prenotazioni 
che consistono di tre stringhe vuote (ad esempio, `nome = ""`, `cognome = ""`, `matricola = ""`).

Le operazioni che il programma dovrà gestire tramite un menu interattivo sono le seguenti:
    1. **Inserisci prenotazione**: Il programma chiede all'utente di inserire il nome, il cognome 
       e il numero di matricola, e salva questi dati nella lista. Se la lista è piena, avvisa l'utente.
    2. **Cancella prenotazione**: Il programma chiede di inserire un numero di matricola e cerca 
       la corrispondente prenotazione nella lista. Se trovata, la prenotazione viene eliminata.
    3. **Stampa prenotati**: Il programma visualizza l'elenco completo degli studenti prenotati, 
       mostrando per ognuno il nome, il cognome e il numero di matricola.
    4. **Esci**: Il programma termina.

L'interazione con l'utente avviene attraverso un menu di scelta, che permette di eseguire una 
delle operazioni sopra descritte. Il programma continua a funzionare fino a quando l'utente non 
sceglie di uscire.
*/

#define MAX_STUDENTI 100
#define MAX_CARATTERI 20
#define NUM_MATRICOLA 7 // 6 + 1 per il '\0'

// Struttura prenotazione
typedef struct{
    char nome[MAX_CARATTERI];
    char cognome[MAX_CARATTERI];
    char matricola[NUM_MATRICOLA];
} Prenotazione;

// Menu di scelta per l'utente
int menu(){
    int scelta;
    puts("-----------------");
    puts("Menu");
    puts("1) Inserisci prenotazione");
    puts("2) Cancella Prenotazione");
    puts("3) Stampa Prenotati");
    puts("4) Esci...");
    puts("-----------------");
    printf("Fai la tua scelta: ");
    scanf("%d", &scelta);
    getchar();

    return scelta;
}
// Rimozione della newline dai dati
void rimuoviNewline(char *str){
    str[strcspn(str, "\n")] = 0;
}

// Inserimento prenotazione 
void inserisciPrenotazione(Prenotazione lista[]){
    for(int i = 0; i < MAX_STUDENTI; i++){
        //Se ci sono posti vuoti
        if(lista[i].nome[0] == '\0'){
            printf("Nome: ");
            fgets(lista[i].nome, MAX_CARATTERI, stdin); // Si salva la stringa
            rimuoviNewline(lista[i].nome); // Richiama la funzione per eliminare il newline

            printf("Cognome: ");
            fgets(lista[i].cognome, MAX_CARATTERI, stdin);
            rimuoviNewline(lista[i].cognome);

            printf("Numero di matricola: ");
            fgets(lista[i].matricola, NUM_MATRICOLA, stdin);
            rimuoviNewline(lista[i].matricola);

            puts("Prenotazione aggiunta correttamente!");
            return;
        }
    }
    puts("Lista prenotazioni piena.");
}

// Cancellazione di una prenotazione tramite numero matricola
void cancellaPrenotazione(Prenotazione lista[]){

    char matricola[NUM_MATRICOLA];

    printf("Inserisci il numero di matricola da cancellare: ");
    fgets(matricola, NUM_MATRICOLA, stdin);
    rimuoviNewline(matricola);

    for(int i = 0; i < MAX_STUDENTI; i++){
        if(strcmp(lista[i].matricola, matricola) == 0){ // Se il numero di matricola inserito esiste
            lista[i].nome[0] = '\0'; // Viene cancellato completamente
            lista[i].cognome[0] = '\0';
            lista[i].matricola[0] = '\0';
            puts("Prenotazione cancellata.");
            return;
        }
    }
    puts("Nessuna prenotazione trovata con il numero di matricola.");
}

void stampaPrenotati(Prenotazione lista[]){
    int trovati = 0;

    printf("\n--- Lista Studenti Prenotati ---\n");
    for(int i = 0; i < MAX_STUDENTI; i++){
        if(lista[i].nome[0] != '\0'){
            printf("Nome: %s | Cognome: %s | Matricola: %s\n", lista[i].nome, lista[i].cognome, lista[i].matricola);
            trovati = 1;
            
        }else{
            break;
        }
    }
    if(!trovati){
        puts("Nessuna prenotazione presente.");
    }
}

int main(){

    Prenotazione lista[MAX_STUDENTI];
    int scelta;

    do{
        scelta = menu();

        switch (scelta)
        {
        case 1:
            inserisciPrenotazione(lista);
            break;
        case 2:
            cancellaPrenotazione(lista);
            break;
        case 3: 
            stampaPrenotati(lista);
            break;
        case 4: 
            puts("Chiusura del programma in corso...");
            break;
        default:
            puts("Valore non valido.");
            break;
        }

    }while(scelta != 4);
    

    return 0;
}