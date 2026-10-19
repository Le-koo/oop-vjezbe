#include <iostream>

inline bool ascending(int a,int b){
	return a<b;
}

inline bool descending(int a,int b){
	return a>b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int)){

	for(int i = 0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(!cmp(arr[j],arr[j+1])){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
template<typename broj>
void printarr(broj arr[],int n){
	for(int i=0;i<n;i++){
		std::cout << arr[i]<<" ";
	}
	std::cout<< std::endl;
}

//ne radi za double niz zato sto ascending i descending funkcije primaju int
template<typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)){
	for(int i = 0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(!cmp(arr[j],arr[j+1])){
				T temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


template<typename broj>
inline bool ascending(broj a,broj b){
	return a<b;
}
template<typename broj>
inline bool descending(broj a, broj b){
	return a>b;
}



int main(){

	int arr[]={3,5,1,6,56,-2};
	double arr2[]={3.2, 5.0, 1.5, 6.65, 56.0, -2.0};
	char arr3[]="asdhgjkert";

	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout<<"Pocetni niz: ";
	printarr(arr, n);

	std::cout<<"Ulazno: ";
	my_sort(arr,n, ascending);
	printarr(arr, n);

	std::cout<<"Silazno: ";
	my_sort(arr,n, descending);
	printarr(arr, n);

	std::cout<<std::endl;

	std::cout<<"Pocetni niz: ";
	printarr(arr2, n);

	std::cout<<"Ulazno: ";
	my_sort(arr2,n, ascending);
	printarr(arr2, n);

	std::cout<<"Silazno: ";
	my_sort(arr2,n, descending);
	printarr(arr2, n);

	std::cout<<std::endl;

	std::cout<<"Pocetni niz: ";
	printarr(arr3, n);

	std::cout<<"Ulazno: ";
	my_sort(arr3,n, ascending);
	printarr(arr3, n);

	std::cout<<"Silazno: ";
	my_sort(arr3,n, descending);
	printarr(arr3, n);
}