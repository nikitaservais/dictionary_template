//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#include <iostream>
#include "CapitalLetter.hpp"

CapitalLetter::CapitalLetter(const char& c) : _word() {
    if (65 <= c && c <= 90) {
        _word = c;
    } else {
        throw std::invalid_argument("not upper case letter");
    }
}

CapitalLetter& CapitalLetter::operator=(const char& c) {
    if (65 <= c && c <= 90) {
        _word = c;
    } else {
        throw std::invalid_argument("not upper case letter");
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const CapitalLetter& u) {
    os << u._word;
    return os;
}
