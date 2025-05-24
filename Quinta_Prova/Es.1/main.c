#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 ============================================================================
 Nome: Zeppa Enigmistica
 Descrizione:
 Questo programma verifica se due parole formano una "zeppa".

 DEFINIZIONE DI ZEPPA:
 Una zeppa è una coppia di parole tali che una si ottiene dall’altra
 inserendo una sola lettera in una qualunque posizione.

 Esempio:
    s1 = "ORO"
    s2 = "ORCO"
    → Inserendo la lettera 'C' nella posizione 2 di "ORO" si ottiene "ORCO"
    → Quindi, "ORO" e "ORCO" formano una zeppa.

 FUNZIONAMENTO DEL PROGRAMMA:
 1. Chiede ripetutamente all’utente di inserire due parole (`s1` e `s2`)
 2. Controlla se `s2` si ottiene da `s1` inserendo una sola lettera
 3. Se sì:
      - Stampa che le parole formano una zeppa
      - Mostra quale lettera è stata inserita e in quale posizione
 4. Se no:
      - Stampa che le parole NON formano una zeppa
 5. Il ciclo continua finché l’utente non digita "fine" per uscire

 CONSIGLI DI IMPLEMENTAZIONE:
 - Le parole devono essere di lunghezza valida:
     `strlen(s2) == strlen(s1) + 1`
 - Si scorrono le due stringhe confrontando i caratteri:
     → Alla prima differenza, si registra la lettera extra in `s2`
     → Si controlla che il resto delle stringhe corrisponda
 - Se si trova più di una differenza, non è una zeppa
 - Gestire inserimenti:
     - All'inizio: es. "RMA" → "ARMA"
     - In mezzo:  es. "ROA" → "ROBA"
     - Alla fine: es. "CAN" → "CANE"

 USO:
 Può essere usato per giochi enigmistici, esercitazioni di programmazione
 con stringhe, o semplici verifiche linguistiche.
 ============================================================================
*/

int main(){

    char s1[21] ;
    char s2[21];
    int differente = 0;
    char lettera;
    int posizione;

    while (1)
    {
        printf("Inserisci la prima parola (digita 'fine' per uscire): ");
        fgets(s1, 21, stdin);
        s1[strcspn(s1, "\n")] = '\0';

        if(strcmp(s1, "fine") == 0){
            break;
        }

        printf("Inserisci la seconda parola: ");
        fgets(s2, 21, stdin);
        s2[strcspn(s2, "\n")] = '\0';

        if(strcmp(s2, "fine") == 0){
            break;
        }

        int len1 = strlen(s1);
        int len2 = strlen(s2);

        if(len2 != len1 + 1){
            puts("Le parole NON formano una zeppa.");
            continue;
        }

        differente = 0;
        int i = 0;
        int j = 0;

        while (i < len1 && j < len2)
        {
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                if(differente == 1){
                    break;
                }

                differente = 1;
                lettera = s2[j];
                j++;
            }
        }

        if(differente == 0 && j == len2 - 1){
            lettera = s2[j];
            posizione = j;
            differente = 1;
        }

        if(differente == 1 && i == len1 && j == len2){
            printf("Le parole formano una zeppa!\nLettera inserita: %c \nPosizione: %d\n", lettera, posizione);
        }
        else{
            puts("Le parole NON formano una zeppa.");
        }
    }
    

    return 0;
}