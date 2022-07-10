//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_NODEBIDIR_HPP
#define INFO_F202_PROJET_CPP_NODEBIDIR_HPP

class NodeBidir {
    const char* _data = nullptr;
    NodeBidir* _next = nullptr;
    NodeBidir* _previous = nullptr;
public:
    NodeBidir() noexcept = default;
    explicit NodeBidir(const char word[]) : _data(word) {};
    NodeBidir(const NodeBidir&) = delete;
    NodeBidir(NodeBidir&& t) noexcept {
        _data = t._data;
        t._data = nullptr;
        _next = t._next;
        t._next = nullptr;
        _previous = t._previous;
        t._previous = nullptr;
    };
    NodeBidir& operator=(const NodeBidir&) = delete;
    NodeBidir& operator=(NodeBidir&& n) noexcept {
        if (this != &n) {
            delete _data;
            delete _next;
            delete _previous;
            _data = n._data;
            _next = n._next;
            _previous = n._previous;
            n._data = nullptr;
            n._next = nullptr;
            n._previous = nullptr;
        }
        return *this;
    };
    ~NodeBidir() noexcept = default;
    const char* getData() { return _data; }
    NodeBidir* getNext() { return _next; }
    NodeBidir* getPrevious() { return _previous; }
    void setData(const char data[]) { _data = data; }
    void setNext(NodeBidir* data) { _next = data; }
    void setPrevious(NodeBidir* data) { _previous = data; }
};

#endif //INFO_F202_PROJET_CPP_NODEBIDIR_HPP
