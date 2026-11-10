#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* izdvoji(char* str, int n){

    
    int zadnji = -1;
    for(int i = 0; i<n; i++){
        if(str[i]== ' '){
            zadnji = i;
        }
    }

    zadnji+=1;

    char* novi = malloc(sizeof(char)*(n-zadnji)+1);

    int brojac=0;
    for(int i = zadnji; i < n;i++){
        novi[brojac]=str[i];
        brojac++;
    }

    novi[brojac]='\0';

    return novi;

}

char** razdvoji(char* str){

    int sredina = -1;
    for(int i = 0; i<strlen(str); i++){
        if(str[i]==' '){
            sredina = i;
            break;
        }
    }

    char* str1 = malloc(sizeof(char)*sredina+1);
    char* str2 = malloc(sizeof(char)*(strlen(str)-sredina));

    int brojac = 0;
    for(int i = 0; i<sredina; i++){
        str1[i]=str[i];
    }
    str1[sredina] = '\0';

    for(int i = sredina+1; i<strlen(str); i++){
        str2[brojac]=str[i];
        brojac++;
    }
     str2[brojac] = '\0';

    char** niz = malloc(sizeof(char*) * 2);

    niz[0] = str1;
    niz[1] = str2;

    return niz;

}

int main(void){

    char str1[] = "Rafini nokti na nogama";
    char str2[] = "Rafo Sale";
    int duljina = sizeof(str1)/sizeof(str1[0]);
    char* rezultat = izdvoji(str1, duljina);

    if (rezultat != NULL) {
        printf("Zadnja rijec: %s\n", rezultat);
        free(rezultat);
    }

    char** rezultat2 = razdvoji(str2);
    printf("Prva ric: %s, Druga ric: %s", rezultat2[0], rezultat2[1]);

    return 0;
}