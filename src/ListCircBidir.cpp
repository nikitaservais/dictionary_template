//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#include "ListCircBidir.hpp"

ListCircBidir::ListCircBidir() : _head(new NodeBidir()) {
    _head->setNext(_head);
    _head->setPrevious(_head);
    _count = 0;
}
ListCircBidir::ListCircBidir(const char word[]) : _head(new NodeBidir(word)) {
    _head->setNext(_head);
    _head->setPrevious(_head);
    _count = 0;
}
bool ListCircBidir::isEmpty() const {
    return _head->getNext() == _head;
}
void ListCircBidir::add(const char word[]) {
    NodeBidir* temp = new NodeBidir(word);
    temp->setNext(_head->getNext());
    temp->setPrevious(_head);
    _head->getNext()->setPrevious(temp);
    _head->setNext(temp);
    _count++;
}
void ListCircBidir::addAfter(NodeBidir* base, const char word[]) {
    NodeBidir* temp = new NodeBidir(word);
    temp->setNext(base->getNext());
    temp->setPrevious(base);
    base->getNext()->setPrevious(temp);
    base->setNext(temp);
    _count++;
}
NodeBidir* ListCircBidir::head() {
    return _head->getNext();
}
NodeBidir* ListCircBidir::end() {
    return _head->getPrevious();
}
NodeBidir* ListCircBidir::search(const char word[]) const {
    NodeBidir* current = _head->getNext();
    while (current != _head && current->getData() != word) {
        current = current->getNext();
    }
    if (current == _head) {
        return nullptr;
    }
    return current;
}
void ListCircBidir::remove(NodeBidir* base) {
    base->getPrevious()->setNext(base->getNext());
    base->getNext()->setPrevious(base->getPrevious());
    _count--;
}
