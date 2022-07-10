//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_TRIE_HPP
#define INFO_F202_PROJET_CPP_TRIE_HPP

#define ALPHABET 26 // const int ALPHABET = 26 ou static const int dans la class CapitalLetter

#include "AbstractDictionary.hpp"
#include "CapitalLetter.hpp"
#include "Tree.hpp"

class Trie : public AbstractDictionary, protected Tree<CapitalLetter, ALPHABET> {
    explicit Trie(const CapitalLetter& letter) : AbstractDictionary(), Tree<CapitalLetter, ALPHABET>(letter) {}
    explicit Trie(Tree<CapitalLetter, ALPHABET>&& t)
            : AbstractDictionary(), Tree<CapitalLetter, ALPHABET>(std::move(t)) {}
    static int convert(const char& c) { return int(c) - 65; }
    static char convert(int& i) { return char(65 + i); }
    static void printAllWords(std::string& prefix, const Tree<CapitalLetter, ALPHABET>& tree) const;
public:
    Trie() : AbstractDictionary(), Tree<CapitalLetter, ALPHABET>() {};
    Trie(const Trie&) = delete;
    Trie(Trie&& s) noexcept: AbstractDictionary(std::move(s)), Tree<CapitalLetter, ALPHABET>(std::move(s)) {};
    Trie& operator=(const Trie&) = delete;
    Trie& operator=(Trie&& t) noexcept {
        if (this != &t) {
            Tree<CapitalLetter, ALPHABET>::operator=(std::move(t));
            AbstractDictionary::operator=(std::move(t));
        }
        return *this;
    }
    ~Trie() noexcept = default;
    bool rech(const char[]) const override;
    bool ins(const char[]) override;
    bool del(const char[]) override;
    friend std::ostream& operator<<(std::ostream&, const Trie&);
};


#endif //INFO_F202_PROJET_CPP_TRIE_HPP
