#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int studentClass;
    char studentName[40];
    char studentSurname[40];
    char studentDepartment[40];

}Data;

typedef struct node{
    int data;
    Data studentData;
    struct node* fLink;
    struct node* bLink;

}node;

typedef struct{
    int count;
    node* head;
    node* pos;
    node* rear;

}list;



void showMenu(){

    printf("\n\n1)Liste Olustur.\n2)Linked List'i Yok Et.\n3)Ogrenci Ekle.\n4)Ogrenci Sil.\n5)Ogrenci Ara.\n6)Listeyi Goruntule.\n7)Cikis Yap.\n");

}

list* createList(){

    list* liste=(list*)malloc(sizeof(list));
    if(liste!=NULL){
        liste->head=NULL;
        liste->pos=NULL;
        liste->rear=NULL;
        liste->count=0;
    }
    return liste;
}

void destroyList(list* list){

    if(list){
        while(list->count!=0){
            list->pos=list->head;
            list->head=list->head->fLink;
            list->count--;
            free(list->pos);
        }
        free(list);
        printf("\nListe Yok edildi!!");
    }
    else
        printf("\nListe Bulunamadi!!");
    printf("\n------------------------------------------------------");
}

void searchNode(list* n,node** headPtr,int sData){

    n->pos= *headPtr;
    int r=-1,counter=0;

    if(n->count==0)
        printf("\nListe Bos!");

    else{//Liste bos degilse arama yapar.
        while(n->pos->data != sData){
            n->pos=n->pos->fLink;
            counter++;
            if(counter == (n->count) ){ //Dongunun listenin sonuna geldiginde sonlanmasýný saglýyor ve sonlandýysa "0" donduruyor.
                r=0;
                break;
            }
        }
        if(r==0)
            printf("\nOgrenci Bulunamadi!");
        else
            printf("\nOgrenci Adi: %s\nOgrenci Soyadi: %s\nOgrenci Bolumu: %s\nOgrenci Sinifi: %d",n->pos->studentData.studentName
                                                                                              ,n->pos->studentData.studentSurname
                                                                                              ,n->pos->studentData.studentDepartment
                                                                                              ,n->pos->studentData.studentClass);
    }
    printf("\n------------------------------------------------------");
}

void deleteNode(list* list,node** headPtr,int nodeData){

    list->pos= *headPtr;

    if(list->count==1){//Listenin son elemani silinmek istenirse listenin yok edilmesini saglar.
        printf("\nOgrenci silindi.");
        destroyList(list);
    }
    else if(list->count==0){//Listede eleman yok iken eleman silme durumu.
        printf("\nListe Bos!");
        printf("\n------------------------------------------------------");
    }

    else{//Elemanlarin silinmesi.

        while(list->pos->data!=nodeData){
            list->pos=list->pos->fLink;
        }
        if(list->pos->bLink==NULL){//ilk dugum
            *headPtr=list->pos->fLink;
            list->pos->fLink->bLink=NULL;
            free(list->pos);
            (list->count)--;
        }

        else if(list->pos->fLink==NULL){//son dugum
                list->pos->bLink->fLink=NULL;
                free(list->pos);
                (list->count)--;
        }

        else{
            list->pos->fLink->bLink=list->pos->bLink;
            list->pos->bLink->fLink=list->pos->fLink;
            free(list->pos);
            (list->count)--;
        }
        printf("\nOgrenci silindi.");
        printf("\n------------------------------------------------------");
    }

}

void traverseList(list* n,node** headPtr){

    n->pos= *headPtr;

    if(n->pos == NULL)
        printf("\nListe bos veya bulunamadi!!");
    else{
        int i=1;
        while(n->pos != NULL){
            printf("\n%d- %d %s %s %s %d",i++,n->pos->data
                                             ,n->pos->studentData.studentName
                                             ,n->pos->studentData.studentSurname
                                             ,n->pos->studentData.studentDepartment
                                             ,n->pos->studentData.studentClass);
            n->pos=n->pos->fLink;
        }
    }
    printf("\n------------------------------------------------------");
}

void addNodeBeginning(list* x,node** headPtr,int value){

    node* newNode=malloc(sizeof(node));
    (x->count)++;
    newNode->data=value;
    newNode->fLink=NULL;
    newNode->bLink=NULL;

    x->pos= *headPtr;

    if(x->pos == NULL){
        *headPtr=newNode;
    }

    else{
        newNode->fLink=x->pos;
        x->pos->bLink = newNode;
        *headPtr=newNode;

    }

}
void addNode(list* x,node** headPtr,int studentNumber, char* studentname,char* studentsurname,char* studentdepartment,int studentclass){

    node* newNode=malloc(sizeof(node));
    (x->count)++;//listeye eleman ekledikten sonra listede bulunan counteri artirir.

    //Bilgiler dolduruluyor.
    newNode->data=studentNumber;
    newNode->studentData.studentClass=studentclass;
    strcpy(newNode->studentData.studentName,studentname);
    strcpy(newNode->studentData.studentSurname,studentsurname);
    strcpy(newNode->studentData.studentDepartment,studentdepartment);

    newNode->fLink=NULL;
    newNode->bLink=NULL;

    if(*headPtr == NULL){
        *headPtr=newNode;
    }

    else{
        x->pos= *headPtr;

        while(x->pos->fLink != NULL)
            x->pos = x->pos->fLink;

        x->pos->fLink=newNode;
        newNode->bLink=x->pos;
    }
    printf("\nOgrenci kaydedildi.");
    printf("\n------------------------------------------------------");

}

int main()
{
    int secim,data,sinif;
    char isim[40];
    char soyisim[40];
    char bolum[40];

    list* liste=createList();

    printf("\n-----Ogrenci Bilgi Isleme Sistemine Hosgeldiniz!!-----");

    while(1){
        showMenu();
        printf("\nSeciminizi giriniz: ");
        scanf("%d",&secim);

        switch (secim) {
        case 1:
            printf("\nListe Olusturuldu.");
            printf("\n------------------------------------------------------");
            break;
        case 2:
            destroyList(liste);
            break;
        case 3:
            printf("\nOgrenci No'sunu Giriniz: ");
            scanf("%d",&data);
            printf("Ogrenci Adini Giriniz: ");
            scanf(" %[^\n]s",isim);//Bosluklu scan almak icin bu sekilde kullanildi.
            printf("Ogrenci Soyadini Giriniz: ");
            scanf("%s",soyisim);
            printf("Ogrenci Bolumunu Giriniz: ");
            scanf(" %[^\n]s",bolum);
            printf("Ogrenci Sinifini Giriniz: ");
            scanf("%d",&sinif);
            addNode(liste,&(liste->head),data,isim,soyisim,bolum,sinif);
            break;
        case 4:
            printf("\nSilmek istediginiz ogrencinin numarasini giriniz: ");
            scanf("%d",&data);
            deleteNode(liste,&(liste->head),data);
            break;
        case 5:
            printf("\nAramak istediginiz ogreninin numarasini giriniz: ");
            scanf("%d",&data);
            searchNode(liste,&(liste->head),data);
            break;
        case 6:
            traverseList(liste,&(liste->head));
            break;
        case 7:
            printf("\nCikis Yapiliyor...\n");
            exit(0);
        default:
            printf("\nGecerli Bir secim Yapiniz.");
        }
    }

    return 0;
}
