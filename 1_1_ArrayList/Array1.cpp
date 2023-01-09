#include "Array1.h"

void Array1::resize(){
    int* newArray = new int[arrayLength * 2];
    for (size_t i{}; i < arrayLength; ++i)
        newArray[i] = itemArray[i];
    //delete itemArray;
    itemArray = newArray;
    arrayLength *= 2;
}

bool Array1::needToReSize() const{ return arrayLength == count; }

bool Array1::needToReSize(int index) const { return index >= count; }

bool Array1::contains(int item) const { return indexOf(item) != -1; }

int Array1::indexOf(int &item) const {
    for (int i{}; i < count; ++i) if (itemArray[i] == item) return i;
    return -1;
}

int Array1::lastIndexOf(int item) { return itemArray[indexOf(item)]; }

int Array1::get(int index) { return itemArray[index]; }

int Array1::add(int item) {
    if (needToReSize()) resize();
    itemArray[count] = item;
    count++;
    return item;
}

int Array1::set(int index, int item) {
    if (needToReSize(index)) throw exception();
    itemArray[index] = item;
    return item;
}

int Array1::remove(int index) {
    int item = itemArray[index];
    if (needToReSize(index)) throw exception();
    for (int i = index; i < count; i++) itemArray[i] = itemArray[i + 1];
    count--;
    return item;
}

int Array1::removeItem(int item) { return remove(indexOf(item)); }

void Array1::print() const {
    for (int i = 0; i < count; ++i) cout << itemArray[i] << ", ";
    cout << "\n";
}
