#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include "shellsort.cpp"
#include "countingsort.cpp"
using namespace std;
using namespace std::chrono;

vector<int> readData(const string& filename){
    ifstream file(filename);
    vector<int> data;
    int val;
    while(file >> val) data.push_back(val);
    return data;
}

long long medirTiempoShell(vector<int>& data, int rep){
    long long total = 0;
    for(int i = 0; i < rep; i++){
        vector<int> tmp = data;
        auto start = high_resolution_clock::now();
        shellSort(tmp.data(), tmp.size());
        auto end = high_resolution_clock::now();
        total += duration_cast<nanoseconds>(end - start).count();
    }
    return total / rep;
}

long long medirTiempoCounting(vector<int>& data, int rep){
    long long total = 0;
    for(int i = 0; i < rep; i++){
        vector<int> tmp = data;
        auto start = high_resolution_clock::now();
        countingSort(tmp);
        auto end = high_resolution_clock::now();
        total += duration_cast<nanoseconds>(end - start).count();
    }
    return total / rep;
}

int main(){
    system("mkdir results");
    int opcion, repeticiones;
    string archivo;

    cout<<"Elige la cantidad de datos a usar:\n";
    cout<<"1. 10\n2. 100\n3. 1000\n4. 10000\n5. 100000\nOpcion: ";
    cin>>opcion;

    switch(opcion){
        case 1: archivo="C:/Users/ASUS/Desktop/Proyecto PA B/Shell-Sort-and-Counting-Sort/data/datos10.txt"; repeticiones=100000; break;
        case 2: archivo="C:/Users/ASUS/Desktop/Proyecto PA B/Shell-Sort-and-Counting-Sort/data/datos100.txt"; repeticiones=1000; break;
        case 3: archivo="C:/Users/ASUS/Desktop/Proyecto PA B/Shell-Sort-and-Counting-Sort/data/datos1000.txt"; repeticiones=1000; break;
        case 4: archivo="C:/Users/ASUS/Desktop/Proyecto PA B/Shell-Sort-and-Counting-Sort/data/datos10000.txt"; repeticiones=100; break;
        case 5: archivo="C:/Users/ASUS/Desktop/Proyecto PA B/Shell-Sort-and-Counting-Sort/data/datos100000.txt"; repeticiones=50; break;
        default: cout<<"Opcion invalida\n"; return 0;
    }
    
    vector<int> data = readData(archivo);
    if(data.empty()){
        cout<<"Error: no se pudieron leer los datos del archivo "<<archivo<<endl;
        return 1;
    }

    long long tShell = medirTiempoShell(data, repeticiones);
    long long tCounting = medirTiempoCounting(data, repeticiones);
 
    return 0;
}