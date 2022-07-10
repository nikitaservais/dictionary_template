//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#include <stack>
#include "Trie.hpp"

bool Trie::rech(const char w[]) const {
    if (this->empty()) {
        return false;
    }
    const Tree<CapitalLetter, ALPHABET>* current = static_cast<const Tree<CapitalLetter, ALPHABET>*>(this);
    for (int i = 0; w[i] != 0; ++i) {
        current = current->son(convert(w[i]));
        if (current == nullptr) {
            return false;
        }
    }
    return current->isSignificant();
}

bool Trie::ins(const char w[]) {
    Tree<CapitalLetter, ALPHABET>* current = this;
    for (unsigned i = 0; w[i] != 0; ++i) {
        if (current->son(convert(w[i])) == nullptr) {
            Tree<CapitalLetter, ALPHABET>* tree= new Tree<CapitalLetter, ALPHABET>((CapitalLetter(w[i])));
            current->ins(convert(w[i]), *tree);
        }
        current = current->son(convert(w[i]));
    }
    current->setSignificant(true);
    _size++;
    return true;
}

bool Trie::del(const char w[]) {
    if (this->empty()) {
        return false;
    }
    Tree<CapitalLetter, ALPHABET>* current = this;
    int lastLetter = 0;
    for (int i = 0; w[i] != 0; ++i) {
        lastLetter = convert(w[i]);
        current = current->son(convert(w[i]));
        if (current == nullptr) {
            return false;
        }
    }
    if (current->isSignificant()) {
        current->setSignificant(false);
        if (current->empty()) {
            current->del(lastLetter);
        }
        _size--;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Trie& s) {
    std::string t;
    s.printAllWords(t, static_cast<const Tree<CapitalLetter, ALPHABET>&>(s));
    return os;
}

void Trie::printAllWords(std::string& prefix, const Tree<CapitalLetter, ALPHABET>& tree) const {
    if (tree.isSignificant()) {
        std::cout << prefix << "  ";
    }
    for (int i = 0; i < ALPHABET; ++i) {
        char next = convert(i);
        Tree<CapitalLetter, ALPHABET>* pTree = tree.son(i);
        if (pTree != nullptr) {
            prefix.push_back(next);
            printAllWords(prefix, *pTree);
            prefix.pop_back();
        }
    }
}
