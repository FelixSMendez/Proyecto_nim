/*
PROYECTO NIM (DEVELOPER 1.0)
Notas de versión:
- Creditos actualizados
- Funcion imprimir_tablero
*/

#include <iostream>

using namespace std;

int jugabilidad(){
	
	return 0;
}
	
	
	void imprimir_creditos(){
		
		cout << "Juego creado por; " << endl;
		cout << "Rubio Morales, Eduardo Rubio		202308051" << endl;
		cout << "Sontay Mendez, Felix Magdiel 		202308066" << endl;
		cout << "Dominguez Avila, Manuel Jose		202308053" << endl;
	}
		
	void imprimir_tablero(int monton1, int monton2, int monton3, string jugador1, string jugador2){
		int i;
		
		system("CLS");
		
		cout << "Player #1: " << jugador1 << endl;
		cout << "Player #2: " << jugador2 << endl;
		
		for(i = 1; i <= monton1; i++){
			cout << " o ";
		}
		
		cout << endl;
		
		for(i = 1; i <= monton2; i++){
			cout << " o ";
		}
		cout << endl;
		
		for(i = 1; i <= monton3; i++){
			cout << " o ";
		}
		cout << endl;
	}
	void jugar(){
		int monton1 = 3, monton2 = 5, monton3 = 7;
		string jugador1, jugador2;
		bool juego_terminado = false;
		int temp;
		
		cout<< "Ingrese el nombre del PRIMER jugador" << endl;
		cin>> jugador1;	
		cout<< "Ingrese el nombre del SEGUNDO jugador" << endl;
		cin>> jugador2;
		
		
		while(!juego_terminado){
			
			imprimir_tablero(monton1, monton2, monton3, jugador1, jugador2);
			cin >> temp;
			
		}
		
		
		
	}
		
		

		int main(){
			bool stay_on_menu = true;
			int seleccion_usuario = 0;
			string jugador1, jugador2;
			
			while(stay_on_menu){
				cout<< "Bienvenido" << endl;
				cout<< "1. Juego Nuevo" << endl;
				cout<< "2. creditos" << endl;
				cout<< "3. Salir" << endl;
				cout<< "Elija una opción del menú" << endl;
				cin>> seleccion_usuario;
				switch(seleccion_usuario){
				case 1:
					cout<< endl;
					jugar();
					cout<< endl;
					// system("CLS");
					break;
				case 2:
					cout<< endl;
					imprimir_creditos();
					cout<< endl;
					break;
				case 3:
					cout<< endl;
					cout<< "Adios" << endl;
					stay_on_menu = false;
					break;
				}
			}
			return 0;
		}
