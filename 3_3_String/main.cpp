//add to lower string where needed


#include <iostream>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
using std::to_string,std::string, std::boolalpha, std::swap, std::vector, std::queue, std::set, std::map, std::pair;
using std::list, std::stack, std::istringstream,std::cout, std::endl, std::exception;

static int countVowels(string str);
static string reverseString(string str);
static string reverseWords(const string& sentence);
static bool isRotation(const string& str1, const string& str2);
static string removeDuplicates(const string& str);
static char getMaxOccurringChar(const string& str);
static string capitalize(string sentence);
static bool isAnagram(const string& first, const string& second);
static bool isAnagram2(const string& first, const string& second);

static bool isPalindrome(const string& word);
int main()
{

    cout << "Count Vowels: \t\t" << countVowels("Hello World") << endl;
    cout << "Reverse String: \t" << reverseString("Hello  World") << endl;
    cout << "Reverse Words: \t\t" << reverseWords("Hello World") << endl;
    cout << "Is Rotation: \t\t" << boolalpha << isRotation("WorldHello ", "Hello World") << endl;
    cout << "Remove Duplicates: \t" << removeDuplicates("Hello World") << endl;
    cout << "Get Max Occurring Char:\t" << getMaxOccurringChar("hello world") << endl;
    cout << "Capitalize: \t\t" << capitalize("hello world") << endl;
    cout << "Is Anagram: \t\t" << boolalpha << isAnagram("hello world", "worllo ldhe") << endl;
    cout << "Is Anagram2: \t\t" << boolalpha << isAnagram2("hello world", "worllo ldhe") << endl;
    cout << "Is Palindrome: \t\t" << isPalindrome("hello olleh") << endl;

    return EXIT_SUCCESS;
}


static bool contains(const string& str, const char& ch)
{
    //return std::find(str.begin(),str.end(), ch ) != str.end();
    return str.find_first_of(ch) != string::npos  ; // (size_t)-1
}

static bool contains(const string& str, const string& str2)
{   // str.find(str2, 0)
    return str.find(str2) != string::npos  ; //!= (size_t)-1 // not right! >= 0 fot size_t
}

static string trim(string& str)
{
    size_t space = str.find_first_not_of(" \t");
    if( string::npos != space ) str = str.substr( space );
    return str;
}

static stack<string> splitToWords(const string& s1)
{
    istringstream iss(s1);
    stack<string> result{};
    for(string s;iss>>s;) result.push(s);
    return result;
}


static string toString(const char& cha)
{
    string str(1, cha);
    return str;
}

static int countVowels(string str)
{
    if (str.empty()) return 0;
    int count{};
    string vowels = "aeiou";
    /*to lower case*/
    for (char & i : str) i = static_cast<char>(tolower(i));
    for (auto& ch : str)
        if (contains(vowels, ch)) count++;
    return count;
}

static string reverseString(string str)
{
    int n = (int)str.length();
    for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
    return str;
}


static string reverseWords(const string& sentence)
{
    if (sentence.empty()) return "";

    auto words = splitToWords(sentence);
    string str{};
    while(!words.empty())
    {
        str += trim(words.top()) + " ";
        words.pop();
    }
    return str;
}


static bool isRotation(const string& str1, const string& str2)
{
    if (str1.empty() || str2.empty()) return (bool)false;
    else if (str1.size() != str2.size()) return false;
    string newString = str1 + str1;
    if (contains(newString, str2)) return true;
    return false;
}

static string removeDuplicates(const string& str)
{
    if (str.empty()) return "";
    string output{};
    set<char> seen{};
    for (auto ch : str)
    {
        if (!seen.contains(ch))
        {
            seen.insert(ch);
            output += ch;
        }
    }
    return output;
}




static char getMaxOccurringChar(const string& str)
{
    if (str.empty()) throw exception();
    const int ASCII_SIZE = 256;
    int array[ASCII_SIZE] {};
    for (auto ch : str) array[ch]++;
    char result{};
    int max{};
    for (int i{}; i < ASCII_SIZE; ++i)
        if (array[i] > max)
        {
            max = array[i];
            result = (char)i;
        }
    return result;
}


static string capitalize(string sentence)
{
    if (sentence.empty() || trim(sentence).empty()) return "";
    stack<string> words = splitToWords(sentence);
    string str{};
    while(!words.empty()){
        string word = words.top();
        words.pop();
        string firstChar = toString(static_cast<char>(toupper(word.front())));
        word.replace(0, 1,  firstChar);
        str.append(word + " ");
    }
    return str;
}


static bool isAnagram(const string& first, const string& second)
{// O(nlogn)
    // ABCD - CBD
    //1 ['A', 'B', 'C', 'D'] - ['C', 'B', 'D','A']A =SORT=> ['A', 'B', 'C', 'D'] - ['A', 'B', 'C', 'D']
    if (first.empty() || second.empty()) return (bool)false;
    else if (second.size() != second.size()) return false;
    string array1 = first;
    string array2 = second;    // O(n)
    std::sort(array1.begin(), array1.end());     // O(nlogn)
    std::sort(array2.begin(), array2.end());
    return (int)array1.compare(array2) == 0;
}


static bool isAnagram2(const string& first, const string& second)
{// O(n)
    // ABCD - CBD
    //1 ['A', 'B', 'C', 'D'] - ['C', 'B', 'D','A']A =SORT=> ['A', 'B', 'C', 'D'] - ['A', 'B', 'C', 'D']
    // not works without replaceAll(" ", "") !!
    if (first.empty() || second.empty()) return false;
    if (first.size() != second.size()) return false;
    const int ENGLISH_ALPHABET = 256;//26 * 2; // 256
    int array[ENGLISH_ALPHABET] {};

    //first = first.replace(" ", "").ToLower();
    for (auto ch: first)
    {
        //if(contains(trim(toString(ch)), " " ))  continue;
        array[ch]++;
    }
    //second = second.replace(" ", "").ToLower();
    for (auto ch: second)
    { // O(n)
        //if(contains(trim(toString(ch)), " " ))  continue;
        int index = static_cast<int>((int)ch);
        if (array[index] == 0) return false;
        array[index]--;
    }
    return true;
}




static bool isPalindrome(const string& word)
{
    string reversed = reverseString(word);
    return (int)word.compare(reversed) == 0;
}


static bool isPalindrome2(const string& word)
{
    int left = 0;
    int right =  (int)word.size() - 1;
    while (left < right) if (word[left++] != word[right--]) return false;
    return true;
}
