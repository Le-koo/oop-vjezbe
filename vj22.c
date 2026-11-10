#include <stdio.h>
#include <stdlib.h>

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

typedef struct{
	float x, y;
} Tocka;

typedef struct {
	Tocka *vrhovi;
	int n;
}Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {

	if (n < 3 || niz_x == NULL || niz_y == NULL) return NULL;

	Poligon *p = (Poligon*)malloc(sizeof(Poligon));

	p->n = n;
	p->vrhovi = (Tocka*)malloc(n * sizeof(Tocka));

	for (int i = 0; i < n; i++) {
		p->vrhovi[i].x = niz_x[i];
		p->vrhovi[i].y = niz_y[i];
	}

	return p;

}

Tocka** pozitivni(Poligon *p, int *np) {

	int brojac = 0;

	for (int i = 0; i < p->n; i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			brojac++;
		}
	}

	*np = brojac;

	Tocka** rezultat = (Tocka**)malloc(brojac * sizeof(Tocka*));

	int j = 0;
	for (int i = 0; i < p->n;i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			rezultat[j] = &p->vrhovi[i];
			j++;
		}
	}

	return rezultat;
}

int main() {
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

    int nth = 0;
    int *filt = filtriraj(niz, n, 5, &nth);

    if (filt != NULL) {
        printf("Filtrirani: ");
        for (int i = 0; i < nth; i++) {
            printf("%d ", filt[i]);
        }
        printf("\n");
        free(filt);
    }

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

	float x_koord[] = {-1.5, 2.0, 3.5, -4.0};
	float y_koord[] = { 3.0, 4.5, -2.0, 1.0 };

	Poligon *p = novi_poligon(x_koord, y_koord, 4);

	if (p != NULL) {
		int np = 0;
		Tocka** poz = pozitivni(p, &np);
		printf("Pozitivni vrhovi: ");
		for (int i = 0; i < np; i++) {

			printf("%f, %f", poz[i]->x, poz[i]->y);
		}
		printf("\n");

		free(poz);
		free(p->vrhovi);
		free(p);
	}
	

    return 0;
}
