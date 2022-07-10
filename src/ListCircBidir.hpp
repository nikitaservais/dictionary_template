//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_LISTCIRCBIDIR_HPP
#define INFO_F202_PROJET_CPP_LISTCIRCBIDIR_HPP

#include <utility>
#include "NodeBidir.hpp"

class ListCircBidir {
    NodeBidir* _head;
    int _count = 0;
    void destroy() {
        NodeBidir* end = _head->getPrevious();
        NodeBidir* current = _head;
        while (_head != nullptr && _head != end) {
            current = _head;
            _head = _head->getNext();
            delete current;
        }
        delete _head;
    }
public:
    ListCircBidir();
    explicit ListCircBidir(const char[]);
    ListCircBidir(const ListCircBidir&) = delete;
    ListCircBidir(ListCircBidir&& l) noexcept: _head(nullptr) {
        *_head = std::move(*l._head);
        l._head = nullptr;
    }
    ListCircBidir& operator=(const ListCircBidir&) = delete;
    ListCircBidir& operator=(ListCircBidir&& l) noexcept {
        if (this != &l) {
            destroy();
            *_head = std::move(*l._head);
            l._head = nullptr;
        }
        return *this;
    }
    ~ListCircBidir() {
       destroy();
    }
    bool isEmpty() const;
    void add(const char[]);
    void addAfter(NodeBidir*, const char[]);
    int size() const { return _count; }
    NodeBidir* head();
    NodeBidir* end();
    NodeBidir* search(const char[]) const;
    void remove(NodeBidir*);
};


#endif //INFO_F202_PROJET_CPP_LISTCIRCBIDIR_HPP
