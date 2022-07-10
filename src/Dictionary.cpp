//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#include "Dictionary.hpp"

bool Dictionary::rech(const char word[]) const {
    NodeBidir* node = _list->search(word);
    return node != nullptr;
}
bool Dictionary::ins(const char word[]) {
    if (_list->isEmpty()) {
        _list->add(word);
        _size++;
        return true;
    }
    NodeBidir* current = _list->head();
    bool end = current == _list->end();
    while (isAfter(word, current->getData()) && !end) {
        current = current->getNext();
        end = current == _list->end();
    }
    if(isAfter(word, current->getData())) {
        _list->addAfter(current, word);
    } else {
        _list->addAfter(current->getPrevious(), word);
    }
    _size++;
    return true;
}
bool Dictionary::del(const char word[]) {
    NodeBidir* node = _list->search(word);
    if (node == nullptr) {
        return false;
    }
    _list->remove(node);
    _size--;
    return true;
}
bool Dictionary::isAfter(const char word[], const char word2[]) {
    for (int i = 0; word[i] != 0; ++i) {
        if (word2[i] == 0) {
            return true;
        }
        if (word[i] > word2[i]) {
            return false;
        }
    }
    return true;
}
