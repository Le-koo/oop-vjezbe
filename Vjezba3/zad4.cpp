#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain){

    std::size_t prva_at = email.find('@');
    std::size_t zadnja_at = email.rfind('@');

    if(prva_at == std::string::npos || prva_at != zadnja_at) {
        return false;
    }

    if (prva_at == 0 || prva_at == email.length() - 1){
        return false;
    }

    user = email.substr(0, prva_at);
    domain = email.substr(prva_at + 1);

    if (domain.find('.') == std::string::npos){
        return false;
    }

    return true;
}

int main(){

    std::string unos_email, user, domain;

    std::cout << "Unesite e-mail adresu: ";
    if (std::getline(std::cin, unos_email)){
        if (split_email(unos_email, user, domain)) {
            std::cout << "-> korisnik: " << user << ", domena: " << domain << std::endl;
        } else {
            std::cout << "-> neispravna adresa" << std::endl;
        }
    }

    return 0;
}