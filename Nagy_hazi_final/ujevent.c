#include "ujevent.h"

Event beolvas(void){
    Event UjEvent;

    getchar();
    printf("Név:\n");
    scanf("%[^\n]s", UjEvent.nev);

    getchar();
    printf("Hely:\n");
    scanf("%[^\n]s", UjEvent.hely);

    getchar();
    printf("Megjegyzés:\n");
    scanf("%[^\n]s", UjEvent.note);

    getchar();
    printf("Dátum(m/d):\n");
    scanf("%d/%d", &UjEvent.date.honap, &UjEvent.date.nap);


    printf("Idöpont(h:min):\n");
    scanf("%d:%d",&UjEvent.ido.ora, &UjEvent.ido.perc);

    return UjEvent;
}

