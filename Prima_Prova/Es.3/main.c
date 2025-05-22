#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Si vuole realizzare un programma che realizza una semplice rubrica telefonica. La rubrica può contenere
fino a 100 contatti per ognuno dei quali vengono memorizzati nome, cognome e numero di telefono. A tal
fine si definisca una struttura contatto che permetta di memorizzare nome (max 20 caratteri), cognome
(max 20 caratteri) e numero di telefono (stringa di 10 caratteri) e si scriva un programma che:
•   utilizza un array di dimensione 100 di tipo contatto per rappresentare la rubrica; le posizioni della
    rubrica che sono vuote, memorizzano un contatto che consiste di tre stringhe vuote;
•   permette all’utente di eseguire le seguenti operazioni (tramite un opportuno menu):
    o   inserisci contatto: il programma chiede all’utente di inserire nome, cognome e numero
        telefonico del contatto, e lo salva in rubrica;
    o   cerca contatto: il programma chiede all’utente di inserire un nome e cognome e cerca il
        contatto corrispondente in rubrica; se lo trova mostra il numero di telefono;
    o   cancella contatto: il programma chiede all’utente di inserire un nome e cognome e cerca il
        contatto corrispondente in rubrica; se lo trova lo rimuove;
    o esci: il programma termina.
*/

#define MAX_CARATTERI 20
#define MAX_NUMERO 11

void pulisciTerminale(){
    #ifdef _WIN32
        system("cls");
    #else   
        system("clear");
    #endif
}


typedef struct{

    char nome[MAX_CARATTERI];
    char cognome[MAX_CARATTERI];
    char numero[MAX_NUMERO];

} Contatto;

int stampaMenu(){
    int scelta;
    puts("----------------");
    puts("Menu");
    puts("1) Inserisci contatto");
    puts("2) Cerca contatto");
    puts("3) Elimina contatto");
    puts("4) Visualizza rubrica");
    puts("5) Esci...");
    puts("----------------");
    printf("Fai la tua scelta: ");
    scanf(" %d", &scelta);
    getchar();
    return scelta;
}

void rimuoviNewline(char *str){
    str[strcspn(str, "\n")] = 0;
}

void inserisciContatto(Contatto rubrica[100]){
    pulisciTerminale();
    for(int i = 0; i < 100; i++){

        if(rubrica[i].nome[0] == '\0'){
            printf("Nome: ");
            fgets(rubrica[i].nome, MAX_CARATTERI, stdin);
            rimuoviNewline(rubrica[i].nome);

            printf("Cognome: ");
            fgets(rubrica[i].cognome, MAX_CARATTERI, stdin);
            rimuoviNewline(rubrica[i].cognome);

            printf("Numero di telefono: ");
            fgets(rubrica[i].numero, MAX_NUMERO, stdin);
            rimuoviNewline(rubrica[i].numero);
            printf("Contatto aggiunto.\n");
            return;
        }

    }
    printf("Rubrica piena!\n");
}

void cercaContatto(Contatto rubrica[100]){

    char nome[MAX_CARATTERI], cognome[MAX_CARATTERI];
    pulisciTerminale(); 
    printf("Nome da cercare: ");
    fgets(nome, MAX_CARATTERI, stdin);
    rimuoviNewline(nome);

    printf("Cognome da cercare: ");
    fgets(cognome, MAX_CARATTERI, stdin);
    rimuoviNewline(cognome);

    for(int i = 0; i < 100; i++){
        if(strcmp(rubrica[i].nome, nome) == 0 && strcmp(rubrica[i].cognome, cognome) == 0){
            printf("Numero trovato: %s\n", rubrica[i].numero);
            return;
        }
    }
    printf("Contatto non trovato!\n");
}

void eliminaContatto(Contatto rubrica[100]){
    char nome[MAX_CARATTERI], cognome[MAX_CARATTERI];
    pulisciTerminale();
    printf("Nome da eliminare: ");
    fgets(nome, MAX_CARATTERI, stdin);
    rimuoviNewline(nome);

    printf("Cognome da eliminare: ");
    fgets(cognome, MAX_CARATTERI, stdin);
    rimuoviNewline(cognome);

    for(int i = 0; i < 100; i++){
        if(strcmp(rubrica[i].nome, nome) == 0 && strcmp(rubrica[i].cognome, cognome) == 0){
            rubrica[i].nome[0] = '\0';
            rubrica[i].cognome[0] = '\0';
            rubrica[i].numero[0] = '\0';
            printf("Contatto eliminato!\n");
            return;
        }
    }
    printf("Contatto non trovato.\n");
}

void visualizzaRubrica(Contatto rubrica[100]){
    int vuota = 1;
    pulisciTerminale();
    puts("Contatti nella rubrica: ");
    for(int i = 0; i < 100; i++){
        if(rubrica[i].nome[0] != '\0'){
            printf("Nome: %s\nCognome: %s\nNumero: %s\n", rubrica[i].nome, rubrica[i].cognome, rubrica[i].numero);
            puts("----------------");
            vuota = 0;
        }
    }

    if(vuota){
        printf("Rubrica vuota!\n");
    }
    
}

int main(){

    Contatto rubrica[100] = {0};
    int scelta;

    do
    {
        scelta = stampaMenu();

        switch (scelta)
        {
        case 1:
            inserisciContatto(rubrica);
            break;
        case 2:
            cercaContatto(rubrica);
            break;
        case 3: 
            eliminaContatto(rubrica);
            break;
        case 4:
            visualizzaRubrica(rubrica);
            break;
        case 5:
            puts("Chiusura programma...");
            break;
        
        default:
            puts("Scelta non valida.\n");
            break;
        }
       

    } while (scelta != 5);
    
    return 0;
}