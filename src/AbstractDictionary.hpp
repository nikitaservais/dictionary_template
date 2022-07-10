//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#ifndef INFO_F202_PROJET_CPP_ABSTRACTDICTIONARY_HPP
#define INFO_F202_PROJET_CPP_ABSTRACTDICTIONARY_HPP


class AbstractDictionary {
protected:
    int _size = 0;
public:
    AbstractDictionary() noexcept = default;
    AbstractDictionary(const AbstractDictionary&) = delete;
    AbstractDictionary(AbstractDictionary&&) noexcept = default;
    AbstractDictionary& operator=(const AbstractDictionary&) = delete;
    AbstractDictionary& operator=(AbstractDictionary&&) noexcept = default;
    virtual ~AbstractDictionary() noexcept = default;
    virtual bool rech(const char[]) const = 0;
    virtual bool ins(const char[]) = 0;
    virtual bool del(const char[]) = 0;
    virtual int size() const noexcept { return _size; };
};


#endif //INFO_F202_PROJET_CPP_ABSTRACTDICTIONARY_HPP
