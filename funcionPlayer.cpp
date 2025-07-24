#include <iostream>
#include "funcionPlayer.h"
#include "player.h"
using namespace std;

void pedirNombres (jugador Player[2]){
            for(int i=0;i<2;i++){
                rlutil::hidecursor();
                rlutil::locate(40,13+i);
            cout<<"introduce el nombre del Jugador: "<<i+1<<" ";
            cin.getline(Player[i].nombre,50);
            }
        rlutil::cls();
    }

int primerTurno(jugador Player[2]){
    //Dado de inicio.
        int ban;
        rlutil::locate(40,3);
        cout<<"Dados de Inicio !!!"<<endl;
        for(int i=0;i<2;i++){
        rlutil::hidecursor();
            Player[i].dadoInicial=tirarDado(40+(i*10),5);
        }
        if(Player[0].dadoInicial>Player[1].dadoInicial){
            ban=0;
            rlutil::locate(40,10);
            cout<<"Comienza el jugardor: "<<Player[ban].nombre<<" !!!"<<endl;
        }else{
            ban=1;
            rlutil::locate(40,10);
            cout<<"Comienza el jugardor: "<<Player[ban].nombre<<" !!!"<<endl;
              }
              rlutil::anykey();
              rlutil::cls();
              return ban;
    }

int pedirPoliedros(jugador Player[2],int ban){
        int total=0;
        //ingresa valores
        for(int j=0;j<2;j++){
            if(ban==1){
                Player[ban].vDadosObjetivos[j]=tirarPoliedro(80+j*10,6);
            }else{
                Player[ban].vDadosObjetivos[j]=tirarPoliedro((j+2)*10,6);
            }
          total=total+Player[ban].vDadosObjetivos[j];
        }
       cout<<endl;
        //muestra valores de cada poliedro
        for(int j=0;j<2;j++){
            if(ban==1){
                rlutil::locate(80,10+j);
            }else{
                rlutil::locate(2,10+j);
            }
            cout<<"Poliedro "<<j+1<<" del jugador "<<Player[ban].nombre<<": "<<Player[ban].vDadosObjetivos[j]<<endl;
        }
           if(ban==0){
                rlutil::locate(2,12);
                } else{
                    rlutil::locate(80,12);
                    }
           cout <<"Dando un total de : "<<total<<" PUNTOS a alcanzar"<<endl;
        system("pause");
        rlutil::cls();

        return total;
    }

void ponerEnCero(jugador Player[2],int ban,int VcontenedorIndices[12]){
        for(int i=0;i<12;i++){
            Player[ban].puntosPoliedro[i] = 0;
            Player[ban].vNumTirada[i] = 0;  // Tambien limpiamos los valores de tirada
            VcontenedorIndices[i] = 0;// Y los indices seleccionados
        }
    }

void transferirDados(jugador Player[2],int origenIndex,int destinoIndex,int cantidad){
        if(Player[origenIndex].dadosStock>=cantidad&&cantidad>0){
            //sacamos la cantidad a uno y se lo asignamos al otro jugador
            Player[origenIndex].dadosStock-=cantidad;
            Player[destinoIndex].dadosStock+=cantidad;

            rlutil::locate(25, 30);
       cout << "TRANSFERENCIA: " << cantidad << " dado(s) de "
       << Player[origenIndex].nombre << " a " << Player[destinoIndex].nombre<<endl;
        }else {
        cout << "No se transfirio nada mi rey..." <<endl;
        }
    }

