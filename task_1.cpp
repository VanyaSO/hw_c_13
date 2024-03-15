#include <iostream>
#include <cstring>
using namespace std;

void sortArr(char**& arr, int size)
{

    for (int i = 0; i < size; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j)
        {

            if(strcmp(arr[minIndex], arr[j]) > 0)
            {
                minIndex = j;
                arr[minIndex] = arr[j];
            }
        }
        char* temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

char* getSurname(int size)
{
    char* surname = new char[size];
    cin.getline(surname, size-1);

    int len = strlen(surname);
    char* newSurname = new char[len+1];
    int i = 0;
    while(surname[i] != '\0')
    {
        newSurname[i] = surname[i];
        i++;
    }

    delete[] surname;
    return newSurname;
}

void deleteArr(char** arr, int size)
{
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void addElToArr(char**& arr, int& size, char* surname)
{
    char** newArr = new char*[size+1];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    newArr[size] = surname;

    delete[] arr;
    size++;
    arr = newArr;
}


void initArr(char**& arr, int& sizeArr, int sizeSurname)
{
    cout << "Enter 5 surnames: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << i+1 << ") ";
        addElToArr(arr, sizeArr, getSurname(sizeSurname));
    }
}

void printArr(char** arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
}

int main() {
    int sizeArr = 0;
    int sizeSurname = 33;
    char** arrSurnames = new char*[sizeArr];

    initArr(arrSurnames, sizeArr, sizeSurname);
    sortArr(arrSurnames, sizeArr);
    printArr(arrSurnames, sizeArr);
    deleteArr(arrSurnames, sizeArr);


    return 0;
}