#ifndef UJEVENT_H
#define UJEVENT_H

#include <stdio.h>
#include <stdlib.h>


//STRUKTURAK:
typedef struct Date{
    int honap, nap;
}Date;

typedef struct Ido{
    int ora, perc;
}Ido;

typedef struct Event{
    char nev[50];
    char hely[50];
    char note[50];
    Ido ido;
    Date date;
    struct Event* next;
    //struct Event* prev
}Event;


//FUGGVENYEK:
Event beolvas(void); //ujevent

#endif // UJEVENT_H_INCLUDED
