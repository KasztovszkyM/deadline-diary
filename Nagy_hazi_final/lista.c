#include "lista.h"

int komp(int x, int y){
    if(x>y)
        return 1;
    if(x==y)
        return 0;

    return -1;
}


//megvizsgalja idorendileg helyes-e
int kesobbe(Event* it, Event* uj){
    if(komp(uj->date.honap, it->date.honap)==1)
        return 1;
    if(komp(uj->date.honap, it->date.honap)==-1)
        return 0;

    if(komp(uj->date.nap, it->date.nap==-1))
        return 1;
    if(komp(uj->date.nap, it->date.nap==1))
        return 0;

    if(komp(uj->ido.ora, it->ido.ora)==-1)
        return 1;
    if(komp(uj->ido.ora, it->ido.ora)==1)
        return 0;

    if(komp(uj->ido.perc, it->ido.perc)==-1)
        return 1;

    return 0;
}




//megkeresi, hogy mi ele kell beszurni
Event* hova(Event* uj, Event* elso){
    Event* it = elso;

    while((it != NULL) && (kesobbe(it , uj) != 1)){ //kesobbe ret 1, ha it<uj, 0, ha it = uj vagy it>uj
        it = it->next;
    }
    return it;
}



//megfelelo helyre hozzafuz
Event* hozzaad(Event* elso, Event event){

    Event* eleje;
    //uj ptr
    Event* uj = (Event* )malloc(sizeof(Event)); //free majd fvben
    //uj adat
    strcpy(uj->nev, event.nev);
    strcpy(uj->hely, event.hely);
    strcpy(uj->note, event.note);

    uj->date.honap = event.date.honap;
    uj->date.nap = event.date.nap;

    uj->ido.ora = event.ido.ora;
    uj->ido.perc = event.ido.perc;

    //beillesztes:
    //ha ures
    if(elso == NULL){
        uj->next = NULL;
        eleje = uj;

    }
    //ha van mar elem
    else{
        Event* it = elso;
        Event* iw = NULL; //kell a vegere illesztes miatt
        while((it != hova(uj, elso)) && (it != NULL)){
            iw = it;
            it = it->next;
        }


        //esetszetvalasztas:eleje, vege, egyeb
        //elejere jol ir
        if(it == elso){
            uj->next = it;
            eleje = uj;
        }
        //vegere is tud mar
        else if(iw->next == NULL){
            uj->next = NULL;
            iw->next = uj;
            eleje = elso;
        }
        //kozepre jol ir
        else{
        iw->next = uj;
        uj->next = it;
        eleje = elso;
        }
    }
    return eleje;
}


//egy elemet kiir
void egykiir(Event* elem){
    printf("N�v: %s\n", elem->nev);
    printf("Hely: %s\n", elem->hely);
    printf("Megjegyz�s: %s\n", elem->note);

    printf("D�tum: %d/%d\n", elem->date.honap, elem->date.nap);
    printf("Id�pont: %d:%d\n", elem->ido.ora, elem->ido.perc);
    printf("\n");
}



//kiir konzolra
void kiir(Event* elso){
    printf("Esem�nyek: \n"
           "----------\n");
    if(elso == NULL)
        printf("Nincsenek esem�nyek\n");
    Event* it = elso;
    while(it != NULL){
        egykiir(it);
        it = it->next;
    }
}





//free
void freelista(Event* elso){
    Event* it = elso;
    Event* iw = NULL;

    while(it != NULL){
        iw = it;
        it = it->next;
        free(iw);
    }
}



//elemet keres
Event* keres(Event* elso, char* mit){
    Event* it = elso;

    while(it != NULL){
        if(strcmp(mit, it->nev) == 0)
            return it;
        it = it->next;
    }
    return NULL;
}




//elem torlese - valamiert nem torli a spacet tartalmazo elemet !!pedig meatalalja elvileg!!
Event* torol(Event* elso, char* mit){
    Event* eleje, *hol;

    hol = keres(elso, mit);

    if(hol == NULL)
        eleje = elso;

    else if(hol == elso){
        eleje = elso->next;
        free(hol);
    }

    else{
    //megprobalom megoldani hol-al,
    //de egyelore kell az elozo next-je->iw
    Event* it = elso;
    Event* iw = NULL;
    while(strcmp(mit, it->nev) != 0){
            iw = it;
            it = it->next;
    }
    iw->next = it->next;
    free(it);
    eleje = elso;
    }

    return eleje;
}



//elem modositasa
void modosit(Event* elso, char* mit){
    Event* pt = keres(elso, mit);
    if(pt == NULL){
        printf("Nincs ilyen esem�ny\n");
        return;
    }

    int l;


    printf("Mit szeretn�l m�dos�tani?\n");
    printf("-------------------------\n"
            "[1] N�v \n"
            "[2] Hely\n"
            "[3] Megjegyz�s\n"
            "[4] D�tum\n"
            "[5] Id�pont\n"
            "-------------------------\n");
    do{
    scanf("%d", &l );
    getchar();

    switch(l){
    case 1:
        printf("�j n�v:\n");
        scanf("%[^\n]s", pt->nev);
        break;

    case 2:
        printf("�j hely:\n");
        scanf("%[^\n]s", pt->hely);
        break;
    case 3:
        printf("�j megjegyz�s:\n");
        scanf("%[^\n]s", pt->note);
        break;
    case 4:
        printf("�j d�tum:\n");
        scanf("%d/%d", &pt->date.honap, &pt->date.nap);
        break;
    case 5:
        printf("�j id�pont:\n");
        scanf("%d/%d", &pt->ido.ora, &pt->ido.perc);
        break;
    default:
        printf("Nincs ilyen lehet�s�g\n");
        getchar();
    }
    }while(l>5 && l<1);
    return;
}
