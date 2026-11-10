#include <stdio.h>
#include <stdlib.h>

int* spoji(int* niz1, int n1, int* niz2, int n2){

    int *novi = malloc(sizeof(int)*(n1+n2));

    for(int i = 0; i < n1; i++){
        novi[i]=niz1[i];
    }

    for(int i = 0; i < n2; i++){
        novi[n1+i]=niz2[i];
    }

    return novi;

}

int* neparni(int* niz, int n1){
    int duljinaNovi = 0;
    for(int i = 0; i<n1; i++){
        if(niz[i]%2!=0){
            duljinaNovi++;
        }
    }

    int* novi = malloc(sizeof(int)*duljinaNovi);

    int brojac=0;
    for(int i = 0; i<n1; i++){
        if(niz[i]%2!=0){
            novi[brojac]=niz[i];
            brojac++;
        }
    }

    return novi;
}

int main(void){

    int niz1[]= {1,2,3,4,5};
    int niz2[]= {6,7,8,9,10};

    int n1 = sizeof(niz1)/sizeof(niz1[0]);
    int n2 = sizeof(niz2)/sizeof(niz2[0]);


    int* rezultat = spoji(niz1,n1,niz2,n2);

    for(int i = 0; i<(n1+n2); i++){
        printf("%d ", rezultat[i]);
    }

    printf("\n\n");

    rezultat = neparni(niz1,n1);

    for(int i = 0; i<3; i++){
        printf("%d ", rezultat[i]);
    }


    return 0;
}