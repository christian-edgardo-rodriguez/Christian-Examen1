#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int**newArray();
void deletePunteros(int** arreglo, int size);
void imprimirMatriz(int** array, int size);

int main(int argc, char const *argv[]){
	int size=7;
	int** arreglo=newArray();
	imprimirMatriz(arreglo, size);
	deletePunteros(arreglo, size);
	return 0;
}
int**newArray(){
	int size=7;
	int**arreglo= new int*[size];
	for (int i = 0; i < size; ++i){
		arreglo[i]=new int[7];
	}//fin new
	return arreglo;
}
void deletePunteros(int** arreglo, int size){
	for (int i = 0; i < size; ++i){
		delete[] arreglo[i];
	}
	delete[] arreglo;//fin delete
}
void imprimirMatriz(int** array, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			cout << setw(6) << array[i][j];	
		}
		cout<<endl;
	}
}