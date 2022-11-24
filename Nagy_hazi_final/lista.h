#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ujevent.h"





//FUGGVENYEK:
Event* hova(Event* uj, Event* elso); //lista
Event* hozzaad(Event* elso, Event event); //lista
void freelista(Event* elso); //lista
void kiir(Event* elso); //lista
void egykiir(Event* elem); //lista
Event* keres(Event* elso, char* mit); //lista
void modosit(Event* elso, char* mit); //lista
Event* torol(Event* elso, char* mit);


#endif // LISTA_H_INCLUDED
