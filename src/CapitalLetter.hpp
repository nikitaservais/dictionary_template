//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_CAPITALLETTER_HPP
#define INFO_F202_PROJET_CPP_CAPITALLETTER_HPP

#include <ostream>

class CapitalLetter {
private:
    char _word;
public:
    CapitalLetter() noexcept = default;
    explicit CapitalLetter(const char&);
    CapitalLetter& operator=(const char&);
    CapitalLetter(const CapitalLetter&) noexcept = default;
    CapitalLetter(CapitalLetter&&) noexcept = default;
    CapitalLetter& operator=(const CapitalLetter&) noexcept = default;
    CapitalLetter& operator=(CapitalLetter&&) noexcept = default;
    ~CapitalLetter() noexcept = default;
    friend std::ostream& operator<<(std::ostream&, const CapitalLetter&);
};


#endif //INFO_F202_PROJET_CPP_CAPITALLETTER_HPP
