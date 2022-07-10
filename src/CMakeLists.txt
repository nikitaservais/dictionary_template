add_library(
        core
        CapitalLetter.hpp
        CapitalLetter.cpp
        AbstractDictionary.hpp
        Trie.cpp
        Trie.hpp
        Tree.hpp
        Dictionary.cpp Dictionary.hpp ListCircBidir.cpp ListCircBidir.hpp NodeBidir.hpp)

target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")