#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

typedef struct {
    float x, y, z;
} Vrh;

typedef struct {
    Vrh normala;
    Vrh vrhovi[3];
    unsigned short boja;
} Trokut;

#pragma pack()

typedef struct {
    Trokut *trokuti;
    unsigned int broj_trokuta;
} Objekt3D;

Objekt3D ucitaj_binarni_stl(const char *ime_datoteke) {
    Objekt3D obj;
    obj.trokuti = NULL;
    obj.broj_trokuta = 0;

    FILE *f = fopen(ime_datoteke, "rb");
    if (!f) {
        printf("Greska: Nije moguce otvoriti datoteku %s za citanje!\n", ime_datoteke);
        return obj;
    }

    char zaglavlje[80];
    fread(zaglavlje, 1, 80, f);

    if (fread(&obj.broj_trokuta, sizeof(unsigned int), 1, f) != 1) {
        printf("Greska pri citanju broja trokuta!\n");
        fclose(f);
        return obj;
    }

    obj.trokuti = (Trokut *)malloc(obj.broj_trokuta * sizeof(Trokut));
    if (!obj.trokuti) {
        printf("Greska: Nema dovoljno memorije!\n");
        fclose(f);
        obj.broj_trokuta = 0;
        return obj;
    }

    for (unsigned int i = 0; i < obj.broj_trokuta; i++) {
        fread(&obj.trokuti[i], 50, 1, f);
    }

    fclose(f);
    return obj;
}

int zapisi_binarni_stl(const char *ime_datoteke, Objekt3D obj) {
    FILE *f = fopen(ime_datoteke, "wb");
    if (!f) {
        printf("Greska: Nije moguce stvoriti datoteku %s!\n", ime_datoteke);
        return 0;
    }

    char zaglavlje[80] = {0};
    fwrite(zaglavlje, 1, 80, f);

    fwrite(&obj.broj_trokuta, sizeof(unsigned int), 1, f);

    unsigned short dodatni_broj = 0;
    for (unsigned int i = 0; i < obj.broj_trokuta; i++) {
        fwrite(&obj.trokuti[i], 50, 1, f);
        fwrite(&dodatni_broj, sizeof(unsigned short), 1, f);
    }

    fclose(f);
    return 1;
}

int zapisi_tekstualni_stl(const char *ime_datoteke, Objekt3D obj) {
    FILE *f = fopen(ime_datoteke, "w");
    if (!f) {
        printf("Greska: Nije moguce stvoriti tekstualnu datoteku %s!\n", ime_datoteke);
        return 0;
    }

    fprintf(f, "solid Objekt3D\n");

    for (unsigned int i = 0; i < obj.broj_trokuta; i++) {
        fprintf(f, "  facet normal %e %e %e\n", obj.trokuti[i].normala.x, obj.trokuti[i].normala.y, obj.trokuti[i].normala.z);
        fprintf(f, "    outer loop\n");
        fprintf(f, "      vertex %e %e %e\n", obj.trokuti[i].vrhovi[0].x, obj.trokuti[i].vrhovi[0].y, obj.trokuti[i].vrhovi[0].z);
        fprintf(f, "      vertex %e %e %e\n", obj.trokuti[i].vrhovi[1].x, obj.trokuti[i].vrhovi[1].y, obj.trokuti[i].vrhovi[1].z);
        fprintf(f, "      vertex %e %e %e\n", obj.trokuti[i].vrhovi[2].x, obj.trokuti[i].vrhovi[2].y, obj.trokuti[i].vrhovi[2].z);
        fprintf(f, "    endloop\n");
        fprintf(f, "  endfacet\n");
    }

    fprintf(f, "endsolid Objekt3D\n");
    fclose(f);
    return 1;
}


void obrisi_objekt3d(Objekt3D *obj) {
    if (obj != NULL) {
        if (obj->trokuti != NULL) {
            free(obj->trokuti);
            obj->trokuti = NULL;
        }
        obj->broj_trokuta = 0;
    }
}


int main(void) {
    const char *ulazni_binarni = "primjerbin.stl";
    const char *izlazni_binarni = "izlaz_binarni.stl";
    const char *izlazni_tekstualni = "izlaz_tekstualni.stl";


    printf("Citanje binarne datoteke: %s ...\n", ulazni_binarni);
    Objekt3D moj_objekt = ucitaj_binarni_stl(ulazni_binarni);

    if (moj_objekt.broj_trokuta > 0) {
        printf("Uspjesno učitano trokuta: %u\n", moj_objekt.broj_trokuta);


        if (zapisi_binarni_stl(izlazni_binarni, moj_objekt)) {
            printf("Uspjesno spremljeno u binarnu datoteku: %s\n", izlazni_binarni);
        }

        if (zapisi_tekstualni_stl(izlazni_tekstualni, moj_objekt)) {
            printf("Uspjesno spremljeno u tekstualnu datoteku: %s\n", izlazni_tekstualni);
        }


        obrisi_objekt3d(&moj_objekt);
        printf("Objekt uspjesno izbrisan i memorija oslobodjena.\n");
    }
    else{
        printf("Nije moguce nastaviti testiranje jer objekt nema trokuta ili datoteka ne postoji.\n");
    }

    return 0;
}