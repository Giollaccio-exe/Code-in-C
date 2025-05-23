#include <stdio.h>
#include <math.h>

/*
 * Questo programma definisce una struttura 'Punto' con i campi 'x' e 'y' di tipo double.
 * L'utente inserisce una sequenza di punti che rappresentano i vertici di un poligono nel piano cartesiano.
 * Il programma chiede all'utente quanti vertici ha il poligono, acquisisce le coordinate dei punti,
 * e calcola il perimetro del poligono sommando le distanze tra i punti consecutivi,
 * considerando anche il lato che chiude il poligono (dall'ultimo punto al primo).
 */


//Struttura
typedef struct{
    double x;
    double y;
} Punto;

//Funzione per calcolare la distanza
double distanza(Punto a, Punto b){

    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}


int main(){

    int numScelto;

    //Richiesta numero vertici
    printf("Inserisci il numero di vertici del poligono: ");
    scanf("%d", &numScelto);

    if(numScelto < 3){
        puts("I vertici devono essere almeno 3.\n");
        return 1;
    }


    Punto punto[numScelto];

    //Richiesta posizioni x y
    for(int i = 0; i < numScelto; i++){
        printf("Inserisci il punto numero %d (x y): ", i + 1);
        scanf("%lf %lf", &punto[i].x, &punto[i].y);
    }

    double perimetro = 0.0;

    //Calcolo del perimetro
    for(int i = 0; i < numScelto; i++){
        perimetro += distanza(punto[i], punto[(i + 1 % numScelto)]);
    }

    printf("Il perimetro e': %.2lf", perimetro);


    return 0;
}