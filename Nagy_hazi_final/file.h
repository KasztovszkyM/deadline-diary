#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#include "ujevent.h" //structok miatt

//FUGGVENYEK:
void fileir(Event* elso); //file
void eventir(FILE* fp, Event* iter); //file
int hanysor(FILE* fp); //file
Event* fileolvas(void);//file


#endif // FILE_H_INCLUDED
