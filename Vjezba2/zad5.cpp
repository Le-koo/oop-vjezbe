#include <iostream>

inline double add(double a, double b){
    return a+b;
}

inline double subtract(double a, double b){
    return a-b;
}

inline double mulitply(double a, double b){
    return a*b;
}

inline double divide(double a, double b){
    if(a==0||b==0){
        std::cout<<"Ne mozete dijeliti s 0\n";
        return 0;
    }
    else{
        return a/b;
    }
}

int main(){

    double (*operacije[4])(double, double)={add,subtract,mulitply,divide};

    double x,y;
    int izbor;

    std::cout<<"Unesite prvi broj: ";
    std::cin>>x;
    std::cout<<std::endl;

    std::cout<<"Unesite drugi broj: ";
    std::cin>>y;
    std::cout<<std::endl;

    std::cout<<"Unesite broj operacije: ";
    std::cin>>izbor;
    std::cout<<std::endl;

    if(izbor>=0 && izbor<=3){
        if(!(izbor==3 && y==0)){
           std::cout<<"Rezultat: " << operacije[izbor](x,y); 
        }
    }
    else{
        std::cout<< "Krivi odabir operacije";
    }





}