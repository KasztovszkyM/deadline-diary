#include "ujevent.h"

#include "file.h"
#include "lista.h" //hozzaad miatt

/*kell: filebol nyitaskor beolvas teljes listat (jo esetben nem kell rendezes, csak adatfelvetel)
        fileba beir bezaraskor(es/vagy menteskor), szinten csak vegig megy a listan*/


//KIIRAS:
void eventir(FILE* fp, Event* iter){

            fprintf(fp, "%s\n", iter->nev);
            fprintf(fp, "%s\n", iter->hely);
            fprintf(fp, "%s\n", iter->note);

            fprintf(fp, "%d\n", iter->date.honap);
            fprintf(fp, "%d\n", iter->date.nap);

            fprintf(fp, "%d\n", iter->ido.ora);
            fprintf(fp, "%d\n", iter->ido.perc);

            fprintf(fp, "\n");

            return ;
            }



void fileir(Event* elso){

    FILE* fp;
    fp = fopen("naplo.txt", "w");
    if(fp == NULL){
        perror("nem sikerult megnyitni\n");
        return;
        }

    Event* iter = elso;
    while(iter != NULL){
        eventir(fp, iter); //egy elem adatait beirja

        iter = iter->next;
    }
    fclose(fp);

    return;
}
/////////////////////////////////////////////////////////////////////////////


//BOLVASAS:

//fileban sorok szamat megszamolja -> megtudjuk hany adatot kell beolvasni
int hanysor(FILE* fp) {
    int sorok = 0;
    for(int c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n')
            sorok++;
    }
    if(sorok == 0){// ha nincs is adat akkor 0 sor, nem ad hozza egyet
        printf("sorok: 0");
        return 0;
        }

    sorok ++; //1. sor nem volt beszamlalva
    fseek(fp,0,SEEK_SET); //a file pointert visszallitja az elejere
    return sorok;
}



//filebol letrehoz listat
Event* fileolvas(void){

        Event uj;
        Event* elso = NULL;

        FILE* fp;
        fp = fopen("naplo.txt", "r");
        if(fp == NULL){
            perror("nem sikerult megnyitni");
            return NULL; //elv nem kell kezelni, mert ures lista = null
        }

        int n = hanysor(fp);

        printf("sorok: %d\n", n);


        for(int i = 0; i < (n/8); ++i){

            //getcharok az ujsorok miatt
            fscanf(fp, "%[^\n]s", uj.nev);
            fgetc(fp);

            fscanf(fp, "%[^\n]s", uj.hely);
            fgetc(fp);

            fscanf(fp, "%[^\n]s", uj.note);
            fgetc(fp);

            fscanf(fp, "%d", &uj.date.honap);
            fgetc(fp);

            fscanf(fp, "%d", &uj.date.nap);
            fgetc(fp);

            fscanf(fp, "%d", &uj.ido.ora);
            fgetc(fp);

            fscanf(fp, "%d", &uj.ido.perc);
            fgetc(fp);

            fgetc(fp);

            elso = hozzaad(elso, uj);

        }

    fclose(fp);
    return elso;
}
