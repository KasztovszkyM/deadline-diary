#include "ujevent.h"

Event beolvas(void){
    Event UjEvent;

    getchar();
    printf("N�v:\n");
    scanf("%[^\n]s", UjEvent.nev);

    getchar();
    printf("Hely:\n");
    scanf("%[^\n]s", UjEvent.hely);

    getchar();
    printf("Megjegyz�s:\n");
    scanf("%[^\n]s", UjEvent.note);

    getchar();
    printf("D�tum(m/d):\n");
    scanf("%d/%d", &UjEvent.date.honap, &UjEvent.date.nap);


    printf("Id�pont(h:min):\n");
    scanf("%d:%d",&UjEvent.ido.ora, &UjEvent.ido.perc);

    return UjEvent;
}

