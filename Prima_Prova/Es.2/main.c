#include <stdio.h>

#define MAX_CELLE 9

// Funzione per verificare se una regione 3x3 del Sudoku è correttamente riempita
int verificaRegione(int arr[MAX_CELLE][MAX_CELLE], int regioneRiga, int regioneColonna) {

    // Array per tracciare i numeri da 1 a 9
    int verificate[MAX_CELLE] = {0};

    // Calcolo l'inizio della riga e della colonna della regione 3x3
    int inizioRiga = regioneRiga * 3;
    int inizioColonna = regioneColonna * 3;

    // Verifico i numeri nella regione 3x3
    for (int i = inizioRiga; i < inizioRiga + 3; i++) {
        for (int j = inizioColonna; j < inizioColonna + 3; j++) {
            int valore = arr[i][j];
            
            // Se il valore non è tra 1 e 9, oppure è già stato trovato, la regione è errata
            if (valore < 1 || valore > 9 || verificate[valore - 1] == 1) {
                return 0; // Regione non valida
            }
            
            // Segno che il numero è stato trovato
            verificate[valore - 1] = 1;
        }
    }

    // Se tutto è corretto, restituisco 1
    return 1; 
}

int main() {
    // Matrice che rappresenta una soluzione valida di un Sudoku
    int arr[MAX_CELLE][MAX_CELLE] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    // Test di una regione specifica (ad esempio la regione in alto a sinistra)
    int regioneRiga = 0;
    int regioneColonna = 0;

    int risultato = verificaRegione(arr, regioneRiga, regioneColonna);

    if (risultato) {
        printf("La regione [%d][%d] è riempita correttamente.\n", regioneRiga, regioneColonna);
    } else {
        printf("La regione [%d][%d] non è riempita correttamente.\n", regioneRiga, regioneColonna);
    }

    return 0;
}
