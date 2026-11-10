#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mystrlen(char* str) {
	int len = 0;

	while (str[len] != '\0') {
		len++;
	}

	return len;
}

char* mystrcpy(char* str1, char* str2) {

	int brojac = 0;

	while (str1[brojac] != '\0') {
		str1[brojac] = str2[brojac];
		brojac++;
	}

	str1[brojac] = '\0';

	return str1;
}

// int* mystrcmp(char* str1, char* str2) {
// 	int i = 0;

// 	while (str1[i] != '\0' && str2[i] != '\0') {
// 		if (str1[i] != str2[i]) {
// 			return str1[i] - str2[i];
// 		}
// 		i++;
// 	}
// 	return str1[i] - str2[i];
// }

char* mystrcat(char* str1, char* str2) {
	int brojac = mystrlen(str1);
	int i = 0;
	while (str2[i] != '\0') {
		str1[brojac] = str2[i];
		i++;
		brojac++;
	}
	str1[brojac] = '\0';

	return str1;
}

char* mystrstr(char* str1, char* str2) {

	int len1 = mystrlen(str1);
	int len2 = mystrlen(str2);
	int brojac = 1;
	int j = 0;
	for (int i = 0; i < len1; i++) {

		for ( j = 0; j <= len2;j++) {
			if (str1[i+j] != str2[j]) {
				break;
			}

		}
		
		if (j == len2) {
			return &str1[i];
		}

	}

	return NULL;

}

char* reverse(char* str1, char* str2) {

	int len = mystrlen(str1);

	for (int i = 0; i < len; i++) {
		str2[i] = str1[len - 1 - i];
	}

	str2[len] = '\0';

	return str2;

}

char* izbaci_samoglasnike(char* str){
	char* samoglasnici = "aeiouAeiou";
	int duljinaNovog = strlen(str);
	for(int i = 0; i < strlen(str);i++){
		for(int j = 0; j<strlen(samoglasnici); j++){
			if(str[i]==samoglasnici[j]){
				duljinaNovog--;
				printf("%c == %c\n", str[i], samoglasnici[j]);
				break;
			}
		}
	}

	char* novi = malloc(sizeof(char)*(duljinaNovog+1));
	int tocno=0;
	int brojac=0;
	for(int i = 0; i < strlen(str);i++){
		for(int j = 0; j<strlen(samoglasnici); j++){
			if(str[i]==samoglasnici[j]){
				tocno=1;
			}
		}
		if(tocno==0){
			novi[brojac]=str[i];
			brojac++;
		}
		else{
			tocno=0;
		}

	}

	novi[brojac]='\0';

	return novi;

}

int main(void) {

	// char str1[100] = "sdfdsfds";
	// char str2[100] = "evil sdfdsfds";

	// char str3[100] = "abcabbaan";
	// char str4[100] = "ba";

	// char str5[100] = "evil";

	char nadopuna[]= "Roso Sale Rafo Bane";
	

	/*printf("duzina stringa %d\n", mystrlen(str1));

	printf("String %s\n", mystrcpy(str1, str2));

	printf("poredak %d\n", mystrcmp(str1, str2));*/

	//printf("Novi string: %s\n", mystrcat(str1, str2));

	//printf("Reverse: %s\n", reverse(str2, str5));

	//printf("%s", mystrstr(str3,str4));


	char* rezultat = izbaci_samoglasnike(nadopuna);

	printf("Bez samoglasnika: %s", rezultat);

	free(rezultat);

	return 0;
}