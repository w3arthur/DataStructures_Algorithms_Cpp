//fix the issue with too much destructures

#include <iostream>


#include "Trie.cpp"
//#include "TrieC.c"    // fix c implementation
using  std::cout, std::endl;
int main() {

    cout << "TrieTree" << endl;   //retrieval
    {
        Trie trie{};
        trie.insert("cat");
        trie.insert("can");
        trie.insert("cant");
        trie.insert("cada");
        trie.remove("cada");
        cout << endl << trie.print() << endl;
        cout << trie.contains("cat") << endl;
        cout << trie.contains("caty") << endl;
        //trie.traversePostOrder();
        auto x = trie.root;
        cout << "";
    }


    // fix c implementation
//    printf("\n\n");
//    printf("Trie Tree C:\n");
//    struct node *root = NULL;
//    insert(&root, "KIT");
//    insert(&root, "KITTTE");
//    insert(&root, "CATTLE");
//    insert(&root, "KIR");
//    insert(&root, "KIAR");
//    print(root);


    return EXIT_SUCCESS;
}