// fix the amount of Destruction
// fix trim
// fix toLowerCaseSting
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <memory>
#include <cctype>
using std::string, std::to_string, std::cout,  std::vector, std::map;
using std::pair, std::list, std::shared_ptr, std::make_shared, std::exception;

class Trie {   //for example only

private:
    struct Node
    {
        typedef std::shared_ptr<struct Node> p_Node;
        char value;
        bool isEndOfWord;
        map<char, p_Node> words;  //map <pair<char, Node>>
        explicit Node(char data) : words{}, value{data}, isEndOfWord{false} { }
        ~Node(){ cout << "del:" << value << "; "; }
        //used Word instead Child !
        [[nodiscard]] bool isEmpty() const { return words.empty(); }
        p_Node getWord(const char& ch)  {  return words.find(ch)->second; }
        bool hasWord(char& ch) const { return words.find(ch) != words.end(); }
        void addWord(char ch)
        {
            auto newNode = make_shared<struct Node>(ch);
            words.insert({ch, newNode});
        }
        void removeWord(const char& ch)  { words.erase(ch); }
        [[nodiscard]] vector<p_Node> getWords() const
        {
            vector<p_Node> wordsVector{};
            for(const auto & word : words)  wordsVector.push_back(word.second);
            return wordsVector;
        }
        [[nodiscard]] bool hasWords() const { return !isEmpty(); }
    };

    typedef std::shared_ptr<struct Node> p_Node;

    [[nodiscard]] static bool isNull(const p_Node& node) { return node == nullptr; }
    [[nodiscard]] static bool isNull(const string& word) { return word.length() == 0; }

    [[maybe_unused]] static string& toLowerCaseSting(const string& str)
    {
        string lowerCaseString{};
        for (int i = 0; i < str.length(); i++) lowerCaseString += tolower(str[i]);
        return lowerCaseString;
    }
    static string& trim(string& str){
        size_t space = str.find_first_not_of(" \t");
        if( string::npos != space )
        {
            str = str.substr( space );
        }
        return str;
    }
    bool contains(string& word, int index, const p_Node& node) const
    {
        if (index == word.length()) return node->isEndOfWord;
        char ch = word[index];
        if (!node->hasWord(ch)) return false;
        else return contains(word, index + 1, node->getWord(ch));
    }
    void remove(const string& word, const int& index, const p_Node& node)
    {   //לחזור
        if (index == word.length())
        {
            node->isEndOfWord = false;
            return;
        }
        auto ch = word[index];
        auto next = node->getWord(ch);
        if (isNull(next)) return;
        remove(word, index + 1, next);
        if (!next->hasWords() && !next->isEndOfWord) node->removeWord(ch); //!!!
    }

    void traversePreOrder(const p_Node& node, string& str)
    {
        str += node->value;
        for (const auto& chNode : node->getWords()) traversePreOrder(chNode, str);
        str += " ";
    }
    void traversePostOrder(const p_Node& node)
    {
        cout << " ";
        for (const auto& chNode : node->getWords()) traversePostOrder(chNode);
        cout << node->value;
    }
    void findWords(const string& word, /*ref*/ list<string>& wordList, const p_Node& node)
    {
        if (node->isEndOfWord) wordList.push_back(word);
        for(const auto& chNode : node->getWords()) findWords(word + to_string(chNode->value), wordList, chNode);
    }
    [[nodiscard]] p_Node findWordEnd(const string& word) const
    {
        auto current = root;
        for (auto ch : word)
        {
            auto next = current->getWord(ch);
            if (isNull(next)) return nullptr;
            current = next;
        }
        return current;
    }
public:
    explicit Trie() : root{make_shared<struct Node>('\0')} { }
    ~Trie() = default;
    p_Node root;
    void insert(const string& word) const
    {
        string lowerCaseString = word;//toLowerCaseSting(word);
        if (isNull(word)) throw exception();
        auto current = root ;
        for(char& ch : lowerCaseString)
        {
            if (!current->hasWord(ch))  current->addWord(ch);
            current = current->getWord(ch);
        }
        current->isEndOfWord = true;
    }
    bool contains(const string& word)   //recursion
    {
        string lowerCaseString = word;//toLowerCaseSting(word);
        if (isNull(word)) return false;
        return contains(lowerCaseString, 0, root);
    }
    void remove(const string& word) { remove(word, 0, root); }
    string traversePreOrder() { string str{}; traversePreOrder(root, str);str = trim(str) ;str += "\n"; return str  ; }

    [[maybe_unused]] void traversePostOrder() { traversePostOrder(root); }

    [[maybe_unused]] list<string>& findWords(const string& word) //לחזור
    {
        list<string> wordList{};    //java ArrayList<>
        auto startNode = findWordEnd(word);    //startPoint
        findWords(word, wordList, startNode);
        return wordList;
    }
    string print() { return traversePreOrder();  }
};