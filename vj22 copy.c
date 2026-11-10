#include <stdio.h>
#include <stdlib.h>

// --- 1. DIO: Funkcije za nizove brojeva iz 2. vježbe ---

int* podniz(int *niz, int start, int stop) {
    if (start > stop || niz == NULL) return NULL;
    
    int velicina = stop - start + 1;
    int *novi_niz = (int*) malloc(velicina * sizeof(int));

    for (int i = 0; i < velicina; i++) {
        novi_niz[i] = niz[start + i];
    }

    return novi_niz;
}

int* filtriraj(int *niz, int n, int th, int *nth) {
    if (niz == NULL || nth == NULL) return NULL;

    int brojac = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            brojac++;
        }
    }

    *nth = brojac;

    int *filtrirani = (int*) malloc(brojac * sizeof(int));

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            filtrirani[j] = niz[i];
            j++;
        }
    }

    return filtrirani;
}

int** podijeli(int *niz, int n) {
    if (niz == NULL || n <= 0) return NULL;

    int n1 = n / 2;
    int n2 = n - n1;

    int **rezultat = (int**) malloc(2 * sizeof(int*));

    rezultat[0] = (int*) malloc(n1 * sizeof(int));
    rezultat[1] = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        rezultat[0][i] = niz[i];
    }

    for (int i = 0; i < n2; i++) {
        rezultat[1][i] = niz[n1 + i];
    }

    return rezultat;
}


// --- 2. DIO: Strukture i rad s poligonima ---

typedef struct {
    float x, y;
} Tocka;

typedef struct {
    Tocka *vrhovi;
    int n;
} Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {
    if (n < 3 || niz_x == NULL || niz_y == NULL) return NULL;

    Poligon *p = (Poligon*) malloc(sizeof(Poligon));
    if (p == NULL) return NULL;

    p->n = n;
    p->vrhovi = (Tocka*) malloc(n * sizeof(Tocka));
    if (p->vrhovi == NULL) {
        free(p);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        p->vrhovi[i].x = niz_x[i];
        p->vrhovi[i].y = niz_y[i];
    }

    return p;
}

Tocka** pozitivni(Poligon *p, int *np) {
    if (p == NULL || np == NULL) return NULL;

    int brojac = 0;

    for (int i = 0; i < p->n; i++) {
        if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
            brojac++;
        }
    }

    *np = brojac;
    if (brojac == 0) return NULL;

    Tocka** rezultat = (Tocka**) malloc(brojac * sizeof(Tocka*));
    if (rezultat == NULL) return NULL;

    int j = 0;
    for (int i = 0; i < p->n; i++) {
        if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
            rezultat[j] = &p->vrhovi[i];
            j++;
        }
    }

    return rezultat;
}

Tocka* tocke_u_kvadrantu(Poligon* p, int kvadrant, int* np) {
    if (p == NULL || np == NULL || kvadrant < 1 || kvadrant > 4) return NULL;

    int brojac = 0;

    for (int i = 0; i < p->n; i++) {
        float x = p->vrhovi[i].x;
        float y = p->vrhovi[i].y;

        if (kvadrant == 1 && x > 0 && y > 0) brojac++;
        else if (kvadrant == 2 && x < 0 && y > 0) brojac++;
        else if (kvadrant == 3 && x < 0 && y < 0) brojac++;
        else if (kvadrant == 4 && x > 0 && y < 0) brojac++;
    }

    *np = brojac;
    if (brojac == 0) return NULL;

    Tocka* rezultat = (Tocka*) malloc(brojac * sizeof(Tocka));
    if (rezultat == NULL) return NULL;

    int j = 0;
    for (int i = 0; i < p->n; i++) {
        float x = p->vrhovi[i].x;
        float y = p->vrhovi[i].y;

        int uvjet = 0;
        if (kvadrant == 1 && x > 0 && y > 0) uvjet = 1;
        else if (kvadrant == 2 && x < 0 && y > 0) uvjet = 1;
        else if (kvadrant == 3 && x < 0 && y < 0) uvjet = 1;
        else if (kvadrant == 4 && x > 0 && y < 0) uvjet = 1;

        if (uvjet) {
            rezultat[j] = p->vrhovi[i];
            j++;
        }
    }

    return rezultat;
}


// --- 3. DIO: Main funkcija za testiranje ---

int main(void) {
    // Test 1: Podniz
    int niz[] = {1, 5, 2, 8, 3, 9, 4};
    int n = 7;

    int *sub = podniz(niz, 2, 5);
    if (sub != NULL) {
        printf("Podniz: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", sub[i]);
        }
        printf("\n");
        free(sub);
    }

    // Test 2: Filtriraj
    int nth = 0;
    int *filt = filtriraj(niz, n, 5, &nth);
    if (filt != NULL) {
        printf("Filtrirani (<5): ");
        for (int i = 0; i < nth; i++) {
            printf("%d ", filt[i]);
        }
        printf("\n");
        free(filt);
    }

    // Test 3: Podijeli niz
    int **dijelovi = podijeli(niz, n);
    if (dijelovi != NULL) {
        printf("Prvi dio: ");
        for (int i = 0; i < n / 2; i++) {
            printf("%d ", dijelovi[0][i]);
        }
        printf("\nDrugi dio: ");
        for (int i = 0; i < n - n / 2; i++) {
            printf("%d ", dijelovi[1][i]);
        }
        printf("\n");
        
        free(dijelovi[0]);
        free(dijelovi[1]);
        free(dijelovi);
    }

    // Test 4: Poligon i točke
    float x_koord[] = {-1.5, 2.0, 3.5, -4.0};
    float y_koord[] = { 3.0, 4.5, -2.0,  1.0};

    Poligon *p = novi_poligon(x_koord, y_koord, 4);

    if (p != NULL) {
        // Test pozitivnih (vraća pokazivače na originalne točke)
        int np = 0;
        Tocka** poz = pozitivni(p, &np);
        printf("Pozitivni vrhovi (pokazivaci): ");
        for (int i = 0; i < np; i++) {
            printf("(%.1f, %.1f) ", poz[i]->x, poz[i]->y);
        }
        printf("\n");
        free(poz);

        // Test točaka u kvadrantu (vraća novi alocirani niz točaka)
        int np_kvadrant = 0;
        int trazeni_kvadrant = 1;
        Tocka* t_kvadrant = tocke_u_kvadrantu(p, trazeni_kvadrant, &np_kvadrant);
        if (t_kvadrant != NULL) {
            printf("Tocke u %d. kvadrantu: ", trazeni_kvadrant);
            for (int i = 0; i < np_kvadrant; i++) {
                printf("(%.1f, %.1f) ", t_kvadrant[i].x, t_kvadrant[i].y);
            }
            printf("\n");
            free(t_kvadrant);
        }

        // Čišćenje memorije poligona
        free(p->vrhovi);
        free(p);
    }

    return 0;
}