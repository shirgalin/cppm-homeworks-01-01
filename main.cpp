#include <iostream>
#include <fstream>

using namespace std;

void fileout(int* array1, int size1, int* array2, int size2);

void change(int* arr1, int size1, int* arr2, int size2) {
    int* array1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        array1[i] = arr1[i + 1];
    }
    array1[size1 - 1] = arr1[0];
    int* array2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        array2[i + 1] = arr2[i];
    }
    array2[0] = arr2[size2 - 1];
    fileout(array1, size1, array2, size2);
}

void fileout(int* array1, int size1, int* array2, int size2) {
    ofstream fout("/Users/osmanshirgalin/CLionProjects/01/out.txt");
    fout << size2 << endl;
    for (int i = 0; i < size2; i++) {
        fout << array2[i] << " ";
    }
    fout << endl;
    fout << size1 << endl;
    for (int i = 0; i < size1; i++) {
        fout << array1[i] << " ";
    }
    fout << endl;
    fout.close();
    delete[] array1;
    delete[] array2;
}

int main() {
    ifstream fin("/Users/osmanshirgalin/CLionProjects/01/in.txt");
    int N = 0, M = 0;
    fin >> N;
    int* arr1 = new int[N];
    for (int i = 0; i < N; i++) {
        fin >> arr1[i];
    }
    fin >> M;
    int* arr2 = new int[M];
    for (int i = 0; i < M; i++) {
        fin >> arr2[i];
    }
    change(arr1, N, arr2, M);
    fin.close();
    delete[] arr1;
    delete[] arr2;
}
