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

printf("HATÁRIDöNAPLÓ\n\n");
    do{
        printf( "-------------------------\n"
                "[1] Esemény létrehozása \n"
                "[2] Esemény módosítása\n"
                "[3] Esemény törlése\n"
                "[4] Események listázása\n"
                "[5] Esemény keresése\n"
                "[9] Kilépés\n"
                "-------------------------\n"
                );


        scanf("%d", &sel);

        switch(sel){
            case 1: //uj esemeny
                system("cls"); //consol torlese
                printf("Új esemény létrehozása\n");

                event = beolvas();
                elso = hozzaad(elso, event);
                break;

            case 2: //modositas
                system("cls");
                printf("Esemény módosítása\n\n");
                kiir(elso);

                getchar();
                printf("Melyik eseményt szeretnéd módosítani?\n");
                scanf("%[^\n]s", keresett);
                modosit(elso, keresett);
                break;

            case 3: // torles
                system("cls");
                printf("Esemény törlése\n\n");
                kiir(elso);

                getchar();
                printf("Melyik elemet szeretnéd törölni?\n"); //a menu valsztasbol hatramaradt entert kiveszi
                scanf("%[^\n]s", keresett);
                elso = torol(elso, keresett);
                kiir(elso);
                break;

            case 4: //listazas
                system("cls");
                printf("Események listázása\n\n");
                kiir(elso);

                break;

            case 5: //kereses
                system("cls");
                printf("Esemény keresése\n");

                getchar();
                printf("A keresett esemény neve: \n");
                scanf("%[^\n]s", keresett);
                if(keres(elso, keresett) == NULL)
                    printf("Nincs ilyen esemény\n");
                else
                    egykiir(keres(elso, keresett));
                break;

            case 9:
                system("cls");

                printf("Kilépés...\n\n");
                break;

            default:
                printf("Kérlek megfelelö számot válassz!\n");
                break;
            }

    }while(sel!=9 && getchar() != 1);

if(elso != NULL)
    kiir(elso);

fileir(elso);

freelista(elso);
return 0;
}
