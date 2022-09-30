#pragma once
#include <iostream>
using std::string, std::to_string, std::cout;
template<typename T>
class Array2
{
private:
    T* itemArray;
    int arrayLength{};
    int count{}; //count
    void resize();
    [[nodiscard]] bool needToReSize() const;

    [[maybe_unused]] bool needToReSize(int& index) const;
public:
    explicit Array2(int length);
    Array2();
    ~Array2(){ delete[](itemArray); };

    [[maybe_unused]] bool contains(T item) const;
    int indexOf(T& item) const;
    [[maybe_unused]] int lastIndexOf(T& item) const;

    [[maybe_unused]] T get(int& index) const;
    [[nodiscard]] int size() const;

    [[maybe_unused]] T add(T item);
    [[maybe_unused]] int set(int& index, const T& item);
    T remove(int index);
    [[maybe_unused]] T removeItem(T& item) const;
    void print() const;
};


template<typename  T>
inline void Array2<T>::resize()
{
    int* newArray = new int[arrayLength * 2];
    for (int i = 0; i < arrayLength; ++i)
        newArray[i] = itemArray[i];
    //delete itemArray;
    itemArray = newArray;
    arrayLength *= 2;
}
//private
template<typename  T> bool Array2<T>::needToReSize() const { return arrayLength == count; }
template<typename T> [[maybe_unused]] bool Array2<T>::needToReSize(int& index) const { return index >= count; }
//public
template<typename T> inline Array2<T>::Array2(int length) : count{}, arrayLength{length}, itemArray {new T[arrayLength]} { }
template<typename T> inline Array2<T>::Array2() { Array2(5); }
template<typename T> [[maybe_unused]] bool Array2<T>::contains(T item) const { return indexOf(item) != -1; }
template<typename T> int Array2<T>::indexOf(T& item) const { for (int i = 0; i < count; ++i) if (itemArray[i] == item) return i; return -1; }
template<typename T>
[[maybe_unused]] int Array2<T>::lastIndexOf(T& item) const { return itemArray[indexOf(item)]; }
template<typename T> [[maybe_unused]] T Array2<T>::get(int& index) const { return itemArray[index]; }
template<typename T> int Array2<T>::size() const { return count; }
template<typename T> [[maybe_unused]] T Array2<T>::add(T item)
{
    if (needToReSize()) resize();
    itemArray[count] = item;
    count++;
    return item;
}
template<typename T>
[[maybe_unused]] int Array2<T>::set(int& index, const T& item)
{
    if (needToReSize(index)) throw std::exception();
    itemArray[index] = item;
    return item;
}
template<typename T> T Array2<T>::remove(int index)
{
    int item = itemArray[index];
    if (needToReSize(index)) throw std::exception();
    for (int i = index; i < count; i++)
        itemArray[i] = itemArray[i + 1];
    count--;
    return item;
}
template<typename T>
[[maybe_unused]] T Array2<T>::removeItem(T& item) const { return remove(indexOf(item)); }
template<typename T> void Array2<T>::print() const
{
    for (int i{}; i < count; ++i)
        cout << itemArray[i] << ", ";
    cout << "\n";
}
