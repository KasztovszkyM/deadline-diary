#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

#include "ujevent.h"
#include "file.h"
#include "lista.h"

#include "debugmalloc.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int main()
{

#ifdef _WIN32
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
#endif


Event* elso = fileolvas(); //lista eleje
Event event; //uj esemeny beolvasasahoz
char keresett[50]; //modositashoz & torleshez kell

int sel;

printf("HAT�RID�NAPL�\n\n");
    do{
        printf( "-------------------------\n"
                "[1] Esem�ny l�trehoz�sa \n"
                "[2] Esem�ny m�dos�t�sa\n"
                "[3] Esem�ny t�rl�se\n"
                "[4] Esem�nyek list�z�sa\n"
                "[5] Esem�ny keres�se\n"
                "[9] Kil�p�s\n"
                "-------------------------\n"
                );


        scanf("%d", &sel);

        switch(sel){
            case 1: //uj esemeny
                system("cls"); //consol torlese
                printf("�j esem�ny l�trehoz�sa\n");

                event = beolvas();
                elso = hozzaad(elso, event);
                break;

            case 2: //modositas
                system("cls");
                printf("Esem�ny m�dos�t�sa\n\n");
                kiir(elso);

                getchar();
                printf("Melyik esem�nyt szeretn�d m�dos�tani?\n");
                scanf("%[^\n]s", keresett);
                modosit(elso, keresett);
                break;

            case 3: // torles
                system("cls");
                printf("Esem�ny t�rl�se\n\n");
                kiir(elso);

                getchar();
                printf("Melyik elemet szeretn�d t�r�lni?\n"); //a menu valsztasbol hatramaradt entert kiveszi
                scanf("%[^\n]s", keresett);
                elso = torol(elso, keresett);
                kiir(elso);
                break;

            case 4: //listazas
                system("cls");
                printf("Esem�nyek list�z�sa\n\n");
                kiir(elso);

                break;

            case 5: //kereses
                system("cls");
                printf("Esem�ny keres�se\n");

                getchar();
                printf("A keresett esem�ny neve: \n");
                scanf("%[^\n]s", keresett);
                if(keres(elso, keresett) == NULL)
                    printf("Nincs ilyen esem�ny\n");
                else
                    egykiir(keres(elso, keresett));
                break;

            case 9:
                system("cls");

                printf("Kil�p�s...\n\n");
                break;

            default:
                printf("K�rlek megfelel� sz�mot v�lassz!\n");
                break;
            }

    }while(sel!=9 && getchar() != 1);

if(elso != NULL)
    kiir(elso);

fileir(elso);

freelista(elso);
return 0;
}
