#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::abs;

int**newArray();
void deletePunteros(int** arreglo, int size);
void imprimirMatriz(int** array, int size);
void llenarMatriz(int** array, int size);
bool validacionPieza(int** array, int x, int y, int pieza);
bool validacionMove(int** array, int x, int y, int piezaX,int piezaY);
void movimiento(int** array,int size, int xPos, int yPos, int pieza);

int main(int argc, char const *argv[]){
	int size=7, bandera=1, xPieza, yPieza, xPos, yPos;
	int** arreglo=newArray();
	bool win=false;
	llenarMatriz(arreglo, size);
	do{
		if (bandera==1){
			cout<<"------JUGADOR 1---------"<<endl;
			cout<<"Ingrese x de la pieza que quiere mover (de 0 a 6): ";
			cin>>xPieza;
			cout<<"Ingrese y de la pieza que quiere mover (de 0 a 6): ";
			cin>>yPieza;
			if(xPieza>=0&&xPieza<=6&&yPieza>=0&&yPieza<=6){
				bool piezaJug1= validacionPieza(arreglo, xPieza, yPieza, 1);
				if(piezaJug1==false){
					cout<<"Ingrese x en el tablero (de 0 a 6): ";
					cin>>xPos;
					cout<<"Ingrese y en el tablero (de 0 a 6): ";
					cin>>yPos;
					if(xPos>=0&&xPos<=6&&yPos>=0&&yPos<=6){
						bool movJug1= validacionMove(arreglo, xPos, yPos, xPieza, yPieza);
						if (movJug1==false){
							movimiento(arreglo, size, xPos, yPos, 1);
						}
					}else{
						cout<<"Esta posicion no existe"<<endl;
						bandera=2;
					}
				}
				bandera=2;
			}else{
				cout<<"Esta posicion no existe"<<endl;
				bandera=2;
			}
			bandera=2;
		}else if(bandera==2){
			cout<<"------JUGADOR 2---------"<<endl;
			cout<<"Ingrese x de la pieza que quiere mover (de 0 a 6): ";
			cin>>xPieza;
			cout<<"Ingrese y de la pieza que quiere mover (de 0 a 6): ";
			cin>>yPieza;
			if(xPieza>=0&&xPieza<=6&&yPieza>=0&&yPieza<=6){
				bool piezaJug2= validacionPieza(arreglo, xPieza, yPieza, 5);
				if(piezaJug2==false){
					cout<<"Ingrese x en el tablero (de 0 a 6): ";
					cin>>xPos;
					cout<<"Ingrese y en el tablero (de 0 a 6): ";
					cin>>yPos;
					if(xPieza>=0&&xPieza<=6&&yPieza>=0&&yPieza<=6){
						bool movJug2= validacionMove(arreglo, xPos, yPos, xPieza, yPieza);
						if (movJug2==false){
							movimiento(arreglo, size, xPos, yPos, 5);
						}			
					}else{
						cout<<"Esta posicion no existe"<<endl;
						bandera=1;
					}
				}
				bandera=1;
			}else{
				cout<<"Esta posicion no existe"<<endl;
				bandera=1;
			}
			bandera=1;
		}
	}while(win==false);
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
void llenarMatriz(int** array, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			array[i][j]=0;
			if ((i==0&&j==3)||(i==6&&j==3)){
				array[i][j]=1;
			}else if ((i==3&&j==0)||(i==3&&j==6)){
				array[i][j]=5;
			}
		}	
	}
}
bool validacionPieza(int** array, int x, int y, int pieza){
	if (array[x][y]!=pieza){
		cout<<"No hay una pieza suya en esa posicion. "<<endl;
		return true;
	}
	return false;
}
bool validacionMove(int** array, int xPos, int yPos, int xPieza, int yPieza){
	if ((xPos!=xPieza+1&&xPos!=xPieza-1&&xPos!=xPieza+2&&xPos!=xPieza-2&&xPos!=xPieza)
		||(yPos!=yPieza+1&&yPos!=yPieza-1&&yPos!=yPieza+2&&yPos!=yPieza-2&&yPos!=yPieza)){
		cout<<"El movimiento es invalido"<<endl;
		return true;
	}
	if (array[xPos][yPos]!=0){
		cout<<"El movimiento es invalido"<<endl;
		return true;
	}
	return false;
}
void movimiento(int** array,int size, int xPos, int yPos, int pieza){
	array[xPos][yPos]=pieza;
	imprimirMatriz(array, size);
}