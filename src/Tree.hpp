//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_TREE_HPP
#define INFO_F202_PROJET_CPP_TREE_HPP

#include <stdexcept>
#include <iostream>

template<typename T, int N = 0>
class Tree {
    class Node;
    Node* _n;
    explicit Tree(Node* m) : _n() {
        if (!m) {
            throw std::invalid_argument("Empty");
        }
        _n = m;
    }
public:
    Tree() : _n(new Node()) {} // _n doit etre null pour etre vide
    explicit Tree(const T& t) : _n(new Node(t)) {}
    Tree(Tree<T, N>&& t) noexcept: _n(nullptr) {
        _n = t._n;
        t._n = nullptr;
    }
    Tree<T, N>& operator=(Tree<T, N>&& t) noexcept {
        if (this != &t) {
            delete _n;
            _n = t._n;
            t._n = nullptr;
        }
        return *this;
    }
    Tree(const Tree<T, N>&) = delete;
    Tree<T, N>& operator=(const Tree<T, N>&) = delete;
    virtual ~Tree() {
        if (_n != nullptr) {
            delete _n;
        }
    }
    bool empty() const { return _n->isEmpty(); } // check if _n is null
    T info() const {
        return _n->getInfo();
    }
    bool isSignificant() const { return _n->isSignificant(); }
    void setSignificant(bool significant) { _n->setSignificant(significant); }
    Tree<T, N>* son(const unsigned& i) const {
        return _n->get(i);
    }
    void del(const unsigned& i) {
        _n->del(i);
        // if _n is empty delete _n
    }
    void ins(const unsigned& i, Tree<T, N>& t) {
        _n->set(i, t);
    }
    template<typename Elem, int M>
    friend std::ostream& operator<<(std::ostream&, const Tree<Elem, M>&);
};

template<typename T, int N>
class Tree<T, N>::Node {
private:
    bool _significant = false;
    T _info;
    Tree<T, N>* _next[N];
public:
    Node() : _info(), _next() {}
    explicit Node(const T& t) : _info(t), _next() {}
    Node(const Node&) = delete;
    Node(Node&& n) noexcept: _info(0), _next(nullptr) {
        *this = std::move(n);
    }
    Node& operator=(const Node&) = delete;
    Node& operator=(Node&& n) noexcept {
        if (this != &n) {
            for (int i = 0; i < N; ++i) {
                delete _next[i];
            }
            for (int i = 0; i < N; ++i) {
                _next[i] = n._next[i];
                n._next[i] = nullptr;
            }
        }
        return *this;
    }
    ~Node() {
        for (int i = 0; i < N; ++i) {
            if (_next[i] != nullptr) {
                delete _next[i];
            }
        }
    }
    T getInfo() const { return _info; }
    Tree<T, N>* get(const unsigned& i) const {
        return _next[i];
    }
    void set(const unsigned& i, Tree<T, N>& t) {
        this->del(i);
        _next[i] = &t;
    }
    void del(const unsigned& i) {
        if (_next[i] != nullptr) {
            delete _next[i];
            _next[i] = nullptr;
        }
    }
    bool isSignificant() const {
        return _significant;
    }
    void setSignificant(bool significant) {
        _significant = significant;
    }
    bool isEmpty() {
        for (int i = 0; i < N; ++i) {
            if (_next[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const Tree<T, N>& t) {
    T info = t.info();
    os << "root: " << info << " [";
    for (unsigned i = 0; i < N; ++i) {
        Tree<T, N>* tmp = t.son(i);
        if (tmp) {
            os << *tmp;
        }
    }
    os << "]";
    return os;
}

#endif //INFO_F202_PROJET_CPP_TREE_HPP

