#include <iostream>
using namespace std;

void print2DArr(int** arr, int rows, int cols)
{
    if (rows > 0 && cols > 0 && arr!=nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int** create2DArr(int& rows, int& cols)
{
    int** arr = nullptr;
    if (rows > 0 && cols > 0)
    {
        arr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
    }
    return arr;
}

int* createArr(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = INT32_MIN;
    }

    return arr;
}

void fill(int** arr, int& rows, int& cols, int min = -10, int max = 10)
{
    srand(time(0));
    if (rows > 0 && cols > 0 && arr!=nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = rand() % (max - min) + min;
            }
        }
    }
}

void deleteArray(int** arr, int& rows)
{
    if (arr != nullptr && rows > 0)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
}

void my_cin(int& rows, int& cols)
{
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;
}

int getMin(int* arr, int size, int& index)
{
    int min = arr[0];
    index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return min;
}

void setPtrArr(int**& ptrArr, int index, int** arrA, int** arrB, int** arrC) {
    if(ptrArr != nullptr)
    {
        ptrArr = nullptr;
    }
    // set new ptr and size
    if (index == 0)
    {
        ptrArr = arrA;
    }
    else if (index == 1)
    {
        ptrArr = arrB;
    }
    else if (index == 2)
    {
        ptrArr = arrC;
    }
}

bool isGeneralValue(int** arr, int rows, int cols, int value)
{
    if (rows > 0 && cols > 0 && arr != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] == value) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isUniqueValue(int countArrays, int indexCurrentArr,
                   int** arrA, int** arrB, int** arrC,
                   int* rowsArr, int* colsArr,
                   int value)
{
    int** ptrArr = nullptr;
    int elArr = 0;

    for (int i = 0; i < countArrays; ++i) {
        setPtrArr(ptrArr, i, arrA, arrB, arrC);
        // check that there is no element checking in the same array
        if(indexCurrentArr == i){continue;}

        for (int j = 0; j < rowsArr[elArr]; ++j) {
            for (int l = 0; l < colsArr[elArr]; ++l)
            {
                if (ptrArr[j][l] == value) {
                    return false;
                }
            }
        }
        elArr++;
    }

    return true;
}

bool isInTheArray(int* arr, int size, int value)
{
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value)
        {
            return true;
        }
    }

    return false;
}

void updateArr(int*& arr, int size, int& newSize)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != INT_MIN)
        {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    for (int i = 0; i < newSize; i++)
    {
        if (arr[i] != INT_MIN)
        {
            newArr[i] = arr[i];
        }
    }

    delete[] arr;
    arr = newArr;
}


int main()
{
    int rows1 = 0, cols1=0;
    my_cin(rows1, cols1);
    int** arrA = create2DArr(rows1, cols1);
    fill(arrA, rows1, cols1);
    print2DArr(arrA, rows1, cols1);

    int rows2 = 0, cols2 = 0;
    my_cin(rows2, cols2);
    int** arrB = create2DArr(rows2, cols2);
    fill(arrB, rows2, cols2);
    print2DArr(arrB, rows2, cols2);

    int rows3 = 0, cols3 = 0;
    my_cin(rows3, cols3);
    int** arrC = create2DArr(rows3, cols3);
    fill(arrC, rows3, cols3);
    print2DArr(arrC, rows3, cols3);


    int countElemA = rows1 * cols1;
    int countElemB = rows2 * cols2;
    int countElemC = rows3 * cols3;


    const int N = 3;
    int countsArrays[N] = { countElemA ,countElemB ,countElemC };
    int rowsArr[N] = {rows1, rows2, rows3};
    int colsArr[N] = {cols1, cols2, cols3};
    int index;
    int size = getMin(countsArrays, N, index);
    int sizeAllArr = countElemA + countElemB + countElemC;
    int sizeTwoArr = 0;


    // create new arrays
    int* generalValuesArr = createArr(size);
    int* generalNegativeValuesArr = createArr(size);
    int* uniqueValuesArr = createArr(sizeAllArr);

    if(countElemA > countElemC)
    {
        sizeTwoArr = rows1;
    }
    else
    {
        sizeTwoArr = rows3;
    }
    int* generalValuesTwoArr = createArr(size);


    // assign a pointer to the smallest array
    int** ptrArr = nullptr;
    setPtrArr(ptrArr, index, arrA, arrB, arrC);

    // task 1 and 4
    // Одновимірний масив, який містить загальні значення для A, B, C;
    // Одновимірний масив, який містить від'ємні значення для A, B, C без повторень.
    // init new arrays
    int k = 0;
    int m = 0;
    // for generalValuesArr
    for (int i = 0; i < rowsArr[index]; ++i)
    {
        for (int j = 0; j < colsArr[index]; ++j)
        {
            if (isGeneralValue(arrA, rows1, cols1, ptrArr[i][j]) &&
                isGeneralValue(arrB, rows2, cols2, ptrArr[i][j]) &&
                isGeneralValue(arrC, rows3, cols3, ptrArr[i][j]))
            {
                generalValuesArr[k] = ptrArr[i][j];
                k++;

                if(ptrArr[i][j] < 0 && !isInTheArray(generalNegativeValuesArr, m, ptrArr[i][j]))
                {
                    generalNegativeValuesArr[m] = ptrArr[i][j];
                    m++;
                }
            }
        }
    }

    // task 2
    // Одновимірний масив, який містить унікальні значення для A, B, C;
    // loop for each array
    int elArr = 0;
    k = 0;
    for (int i = 0; i < N; ++i) {
        setPtrArr(ptrArr, i, arrA, arrB, arrC);
        for (int j = 0; j < rowsArr[elArr]; ++j) {
            for (int l = 0; l < colsArr[elArr]; ++l)
            {
                if (!isInTheArray(uniqueValuesArr, k, ptrArr[j][l]))
                {
                    if (isUniqueValue(N, i, arrA, arrB, arrC, rowsArr, colsArr, ptrArr[j][l]))
                    {
                        uniqueValuesArr[k] = ptrArr[j][l];
                        k++;
                    }
                }
            }
        }
        elArr++;
    }

    // task 3
    // Одновимірний масив, який містить спільні значення для A і C;
    k = 0;
    // for generalValuesTwoArr
    for (int i = 0; i < rowsArr[index]; ++i)
    {
        for (int j = 0; j < colsArr[index]; ++j)
        {
            if (!isInTheArray(generalValuesTwoArr, k, ptrArr[i][j]))
            {
                if (isGeneralValue(arrA, rows1, cols1, ptrArr[i][j]) &&
                    isGeneralValue(arrC, rows3, cols3, ptrArr[i][j]))
                {
                    generalValuesTwoArr[k] = ptrArr[i][j];
                    k++;
                }
            }
        }
    }


    // update arrays, sizes arrays, and print
    int sizeGeneralArr = 0;
    updateArr(generalValuesArr, size, sizeGeneralArr);
    cout << "General values: ";
    printArr(generalValuesArr, sizeGeneralArr);

    int sizeUniqueArr = 0;
    updateArr(uniqueValuesArr, sizeAllArr, sizeUniqueArr);
    cout << "Unique values: ";
    printArr(uniqueValuesArr, sizeUniqueArr);

    int sizeGeneralTwoArr = 0;
    updateArr(generalValuesTwoArr, size, sizeGeneralTwoArr);
    cout << "General values arrays A and C: ";
    printArr(generalValuesTwoArr, sizeGeneralTwoArr);

    int sizeGeneralNegativeArr = 0;
    updateArr(generalNegativeValuesArr, size, sizeGeneralNegativeArr);
    cout << "General negative values without repetitions: ";
    printArr(generalNegativeValuesArr, sizeGeneralNegativeArr);

//    deleteArray(ptrArr, ptrSize);
    deleteArray(arrA, rows1);
    deleteArray(arrB, rows2);
    deleteArray(arrC, rows3);
    delete[] generalValuesArr;
    delete[] uniqueValuesArr;
    delete[] generalValuesTwoArr;
    delete[] generalNegativeValuesArr;

    return 0;
}