
#include <iostream>
#include <stack>
#import "Stack.cpp"
#import "ListedStack.cpp"
using std::string, std::boolalpha, std::endl, std::cout;

static bool isBalanced(const string &input);
static string reverseString(const string &str);

int main()
{
    Stack stack{};
    stack.push(10);
    cout << stack.pop() << endl;
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    stack.push(110);
    stack.push(120);
    stack.push(130);
    stack.push(140);
    stack.push(150);
    stack.push(160);

    cout << stack.pop() << endl;
    cout << "Stack: "<< stack.print() << endl;


    cout << endl << "Stack wit Linked List" << endl;
    LinkedStack stack2{};

    stack2.push(10);
    stack2.push(20);
    stack2.push(30);
    stack2.push(40);
    stack2.push(50);
    cout << stack2.pop() << endl;
    cout << stack2.print();

    cout << endl;
    cout << reverseString("Apple") << endl;

    cout << boolalpha << isBalanced(")Apple(")<< endl;
    cout << boolalpha << isBalanced("[abc]") << endl;
    cout << boolalpha << isBalanced("[a>bc]") << endl;


    return EXIT_SUCCESS;
}

static const char leftBrackets[] = { '(', '<', '{', '[' };
static const char rightBrackets[] = {')', '>', '}', ']' };
static const int arrayLength =  4;

static int findIndex(const char charArray[],const char &value)
{
    for(int i{}; i< arrayLength; ++i)
    {
        if(charArray[i] == value) return i;
    }
    return -1;
}


static bool bracketMatch(char chLeft, char chRight) { return findIndex(leftBrackets, chLeft) == findIndex(rightBrackets, chRight); }

static bool isBalanced(const string &input)
{
    std::stack<char> stack{};
    for (auto ch : input)
    {
        if ( findIndex(leftBrackets, ch) != -1 ) stack.push(ch); // (
        else if (findIndex(rightBrackets, ch) != -1 )
        {
            if (stack.empty()) return false;    //Edge case
            char opposite = stack.top();
            stack.pop();
            if (!bracketMatch(ch, opposite)) return false;
        }
    }
    return stack.empty(); //boolean
}


static string reverseString(const string &str)
{
    string reversedString{};
    std::stack<char> stack{};
    for(auto ch : str) stack.push(ch);
    while(!stack.empty()){ reversedString += stack.top(); stack.pop(); }
    return  reversedString;
}