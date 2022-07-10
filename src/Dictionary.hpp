//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_DICTIONARY_HPP
#define INFO_F202_PROJET_CPP_DICTIONARY_HPP


#include "ListCircBidir.hpp"
#include "AbstractDictionary.hpp"

class Dictionary : public AbstractDictionary {
    ListCircBidir* _list;
    static bool isAfter(const char* word, const char* word2);
public:
    Dictionary() : _list(new ListCircBidir()) {};
    explicit Dictionary(const char word[]) : _list(new ListCircBidir(word)) {};
    Dictionary(const Dictionary&) = delete;
    Dictionary(Dictionary&& d) noexcept: _list() {
        _list = d._list;
        d._list = nullptr;
    };
    Dictionary& operator=(const Dictionary&) = delete;
    Dictionary& operator=(Dictionary&& d) noexcept {
        if (this != &d) {
            delete _list;
            _list = d._list;
            d._list = nullptr;
        }
        return *this;
    };
    ~Dictionary() {
        delete _list;
    };
    bool rech(const char[]) const override;
    bool ins(const char[]) override;
    bool del(const char[]) override;
};


#endif //INFO_F202_PROJET_CPP_DICTIONARY_HPP
