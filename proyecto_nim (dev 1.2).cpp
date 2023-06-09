/*
PROYECTO NIM (DEVELOPER 1.2)
Notas de versi�n:
- Funci�n resetear para reiniciar el tablero
- Punteo de los jugadores
*/
#include <iostream>
using namespace std;


bool game_finished(int monton1, int monton2, int monton3){
	
	// revisa si el juego termino 
	if(monton1 == 0 && monton2 == 0 && monton3 == 0){
		
		return true;
	}else{
		return false;
	}
}
	void imprimir_creditos(){
		
		// Funcion para imprimir los creditos del juego
		cout << "Juego creado por; " << endl;
		cout << "Rubio Morales, Eduardo Rubio		202308051" << endl;
		cout << "Sontay Mendez, Felix Magdiel 		202308066" << endl;
		cout << "Dominguez Avila, Manuel Jose		202308053" << endl;
	}
		
		void reiniciar(int* monton1, int* monton2, int* monton3){
			*monton1 = 3;
			*monton2 = 5;
			*monton3 = 7;
			
		}
			void imprimir_tablero(int monton1, int monton2, int monton3, string jugador1, string jugador2, int punteo1, int punteo2){
				/* Funcion para imprimir el tablero del juego, recibe la informacion de los montones
				para poder imprimir la cantidad de elementos sobrantes en el tablero y recibe los 
				nombres de los jugadores para poder imprimirlos en pantalla*/
				int i;
				
				system("CLS");
				
				cout << "Player #1: " << jugador1 << "----- punteo: " << punteo1 << endl;
				cout << "Player #2: " << jugador2 << "----- punteo: " << punteo2 << endl;
				
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
					
					// motor del juego
					
					int monton1 = 3, monton2 = 5, monton3 = 7, punteo_jugador_uno = 0, punteo_jugador_dos = 0;
					string jugador1, jugador2;
					bool juego_terminado = false, player_one_turn;
					
					cout<< "Ingrese el nombre del PRIMER jugador" << endl;
					cin>> jugador1;	
					cout<< "Ingrese el nombre del SEGUNDO jugador" << endl;
					cin>> jugador2;
					
					
					while(true){
						
						imprimir_tablero(monton1, monton2, monton3, jugador1, jugador2, punteo_jugador_uno, punteo_jugador_dos);
						player_one_turn = true;
						
						while(player_one_turn){
							int linea_selecta, cantidad_retirar;
							
							cout << "***** Jugador " << jugador1 << " *****" << endl;
							cout << "elija una linea para retirar elementos" << endl;
							cin >> linea_selecta;
							
							cout << "elija una cantidad de elementos a retirar" << endl;
							cin >> cantidad_retirar;
							if(linea_selecta == 1 && cantidad_retirar <= monton1){
								monton1 = monton1 - cantidad_retirar;
								player_one_turn = false;
							}else if(linea_selecta == 2 && cantidad_retirar <= monton2){
								monton2 = monton2 - cantidad_retirar;
								player_one_turn = false;
							}else if(linea_selecta == 3 && cantidad_retirar <= monton3){
								monton3 = monton3 - cantidad_retirar;
								player_one_turn = false;
							}else{
								cout << "Movimiento invalido" << endl;
							}
							
							juego_terminado = game_finished(monton1, monton2, monton3);
							
							if(juego_terminado){
								punteo_jugador_dos++;
								reiniciar(&monton1, &monton2, &monton3);
							}
						}
						
						// imprime el tablero y limpia la pantalla despu�s de cada turno de jugador
						imprimir_tablero(monton1, monton2, monton3, jugador1, jugador2, punteo_jugador_uno, punteo_jugador_dos);
						
						while(!player_one_turn && !juego_terminado){
							int linea_selecta, cantidad_retirar;
							cout << "***** Jugador " << jugador2 << " *****" << endl;
							cout << "elija una linea para retirar elementos" << endl;
							cin >> linea_selecta;
							
							cout << "elija una cantidad de elementos a retirar" << endl;
							cin >> cantidad_retirar;
							if(linea_selecta == 1 && cantidad_retirar <= monton1){
								monton1 = monton1 - cantidad_retirar;
								player_one_turn = true;
							}else if(linea_selecta == 2 && cantidad_retirar <= monton2){
								monton2 = monton2 - cantidad_retirar;
								player_one_turn = true;
							}else if(linea_selecta == 3 && cantidad_retirar <= monton3){
								monton3 = monton3 - cantidad_retirar;
								player_one_turn = true;
							}else{
								cout << "Movimiento invalido" << endl;
							}
							
							juego_terminado = game_finished(monton1, monton2, monton3);
							if(juego_terminado){
								punteo_jugador_uno++;
								reiniciar(&monton1, &monton2, &monton3);
							}
						}
						
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
							cout<< "Elija una opci�n del men�" << endl;
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
						
