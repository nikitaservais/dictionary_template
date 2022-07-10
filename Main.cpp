//
// matricule: 000463055
// nom: Servais
// prenom: Nikita
//

#include <Tree.hpp>
#include <Trie.hpp>
#include <Dictionary.hpp>
#include "CapitalLetter.hpp"


void dictionaryTest();
void treeTest() {
    std::cout << "## Start test Tree<T,N> class : " << std::endl;
    // Special methods
    std::cout << "# Constructor from Typename T : ";
    Tree<CapitalLetter, 2> tree(CapitalLetter('B'));
    std::cout << tree << std::endl;
    std::cout << "# Move constructor : ";
    Tree<CapitalLetter, 2> treeMovedConstructor(CapitalLetter('A'));
    Tree<CapitalLetter, 2> treeMoveConstructor(std::move(treeMovedConstructor));
    std::cout << treeMoveConstructor << std::endl;
    std::cout << "# Move operator : ";
    Tree<CapitalLetter, 2> treeMovedOperator(CapitalLetter('A'));
    Tree<CapitalLetter, 2> treeMoveOperator(CapitalLetter('B'));
    treeMoveConstructor = std::move(treeMovedOperator);
    std::cout << treeMoveOperator << std::endl;
    // Methods
    std::cout << "# Insertion : ";
    Tree<CapitalLetter, 2>* insertedTree = new Tree<CapitalLetter, 2>(CapitalLetter('C'));
    tree.ins(1, *insertedTree);
    std::cout << tree << std::endl;
    std::cout << "# Deletion : ";
    tree.del(1);
    std::cout << tree << std::endl;
    std::cout << "# Empty : ";
    std::cout << tree.empty() << std::endl;
    std::cout << "# Returns root info : ";
    std::cout << tree.info() << std::endl;
    // Different Typename
    std::cout << "# Test a different typename, with std::string : ";
    Tree<std::string, 10> tree1("rules");
    std::cout << tree1 << std::endl;
    std::cout << "# Insertion : ";
    Tree<std::string, 10>* tree2 = new Tree<std::string, 10>("arbre");
    tree1.ins(9, *tree2);
    std::cout << tree1 << std::endl;
//    delete insertedTree;
//    delete tree2;
}


void trieTest() {
    std::cout << "## Start test Trie class : " << std::endl;
    // Special methods
    std::cout << "# Move constructor : ";
    Trie trieMovedConstructor;
    trieMovedConstructor.ins("A");
    Trie trieMoveConstructor(std::move(trieMovedConstructor));
    std::cout << trieMoveConstructor << std::endl;
    std::cout << "# Move operator : ";
    Trie trieMovedOperator;
    trieMovedOperator.ins("A");
    Trie trieMoveOperator;
    trieMoveOperator.ins("B");
    trieMoveConstructor = std::move(trieMovedOperator);
    std::cout << trieMoveOperator << std::endl;
    // Methods
    std::cout << "# Insertion A, ABC, BDC, AAA, TEST : ";
    Trie trie;
    const char words[5][5] = {"A", "ABC", "BDC", "AAA", "TEST"};
    for (int i = 0; i < 5; ++i) {
        trie.ins(words[i]);
    }
    std::cout << trie << std::endl;
    std::cout << "# Research A ";
    std::cout << trie.rech("A") << std::endl;
    std::cout << "# Research AZ ";
    std::cout << trie.rech("AZ") << std::endl;
    std::cout << "# Delete ABC ";
    trie.del("ABC");
    std::cout << trie << std::endl;
    std::cout << "## Start test Trie as a dictionary : " << std::endl;
    // Special methods
    std::cout << "# Move operator : ";
    AbstractDictionary* dicMovedOperator = new Trie();
    dicMovedOperator->ins("A");
    AbstractDictionary* dicMoveOperator = new Trie();
    dicMoveOperator->ins("B");
    *dicMoveOperator = std::move(*dicMovedOperator);
    std::cout << dicMoveOperator->rech("A") << std::endl;
    AbstractDictionary* dictionary = new Trie();
    // Methods
    std::cout << "# Insertion AB : ";
    std::cout << dictionary->ins("AB") << std::endl;
    std::cout << "# Insertion ABC : ";
    std::cout << dictionary->ins("ABC") << std::endl;
    std::cout << "# Insertion ABCD : ";
    std::cout << dictionary->ins("ABCD") << std::endl;
    std::cout << "# Research AB : ";
    std::cout << dictionary->rech("AB") << std::endl;
    std::cout << "# Research ABC : ";
    std::cout << dictionary->rech("ABC") << std::endl;
    std::cout << "# Research ABCD : ";
    std::cout << dictionary->rech("ABCD") << std::endl;
    std::cout << "# Research A : "; // check if rech return 0
    std::cout << dictionary->rech("A") << std::endl;
    std::cout << "# Delete ABC : ";
    std::cout << dictionary->del("ABC") << std::endl;
    std::cout << "# Research ABC : ";
    std::cout << dictionary->rech("ABC") << std::endl;
    delete dicMoveOperator;
    delete dicMovedOperator;
    delete dictionary;
}

void dictionaryTest() {
    std::cout << "## Start test Dictionary class : " << std::endl;
    Dictionary dictionary = Dictionary();
    // Insertion
    std::cout << "# Insertion AB : ";
    std::cout << dictionary.ins("AB") << std::endl;
    std::cout << "# Insertion ABC : ";
    std::cout << dictionary.ins("ABC") << std::endl;
    std::cout << "# Insertion ABCD : ";
    std::cout << dictionary.ins("ABCD") << std::endl;
    // Research
    std::cout << "# Research AB : ";
    std::cout << dictionary.rech("AB") << std::endl;
    std::cout << "# Research ABC : ";
    std::cout << dictionary.rech("ABC") << std::endl;
    std::cout << "# Research ABCD : ";
    std::cout << dictionary.rech("ABCD") << std::endl;
    std::cout << "# Research A : "; // check if rech return 0
    std::cout << dictionary.rech("A") << std::endl;
    // Delete
    std::cout << "# Delete ABC : ";
    std::cout << dictionary.del("ABC") << std::endl;
    std::cout << "# Research ABC : ";
    std::cout << dictionary.rech("ABC") << std::endl;
    Dictionary dic = std::move(dictionary);
}

int main() {
    treeTest();
    trieTest();
    dictionaryTest();
    return 0;
}
