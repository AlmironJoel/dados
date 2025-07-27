#include <iostream>
//archivos
#include "funcionDados.h"
#include "funcionPlayer.h"
#include "player.h"
#include "rlutil.h"
//metodos
#include <cstdlib>  //para rand() y srand()
#include <ctime>    //para time()
#include <stdlib.h> //para system()

using namespace std;
void showItem(const char* text,int posX,int posY,bool seleted);

void showItem(const char* text,int posX,int posY,bool seleted){
    if(seleted){
        rlutil::setBackgroundColor(rlutil::BLUE);
    }else{
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
    rlutil::locate(posX,posY);
    cout << text <<endl;
}

int main()
{
//Menu Principal
int opcion = 1 ;
int yMenu=0;
do{
showItem("INICIAR JUEGO",50,18,yMenu==0);
showItem(" TOP PUNTAJE ",50,19,yMenu==1);
showItem("  CREDITOS   ",50,20,yMenu==2);
showItem("    SALIR    ",50,21,yMenu==3);
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(48,18+yMenu);
cout << (char)175<<endl;

int keyMenu=rlutil::getkey();

    switch(keyMenu){
    case 14://UP
            rlutil::locate(48,18+yMenu);
            cout <<"  "<<endl;
            if(yMenu<=0){
                yMenu=0;
            }else{
                yMenu--;
            }

        break;
    case 15://Down
            rlutil::locate(48,18+yMenu);
            cout <<"  "<<endl;
            if(yMenu>=3){
                yMenu=3;
            }else{
                yMenu++;
            }
        break;
    case 1 ://Enter

            switch(yMenu){
            case 0:
                cout<<"Entra al Juego"<< endl;


                break;
            case 1:
                cout<<"Entra a Estadisticas"<< endl;
            break;
            case 2:
                cout<<"Grupo 5"<< endl;
                cout<<"Integrantes y roles del Trabajo:"<< endl;
                cout<<"Joel Brian Almiron"<< endl;
                cout<<"Legajo : 32378"<<endl;

                cout<<"Joel Team Lider"<< endl;
                cout<<"Joel Diseno UX/UI "<< endl;
                cout<<"Joel control de calidad (el que rompe y arregla el codigo)"<< endl;
                cout<<"Joel Debug"<< endl;

            break;
            case 3:
                cout<<"Salida"<< endl;
                opcion=0;
                break;
            }//Switch Enter.

        break;
    }

}while(opcion!=0);//DO WHILE
//enter 1
//up 14
//down 15

//***********************
    srand(time(0));
    jugador Player[2];
    int ban;
    int ronda=1,turno=0;
    int totalPoliedro;
    pedirNombres(Player);
    rlutil::hidecursor();
    ban=primerTurno(Player);
    int VcontenedorIndices[12]={0};

//Inicio de juego
    while(ronda<=3){
    turno++;
    rlutil::locate(50,1);
    cout<<"Ronda "<<ronda<<" /3"<<endl;
    if(ban== 0){
            rlutil::locate(12,4);
            cout<<"Turno del jugador: "<<Player[ban].nombre<<endl;
        }else{
            rlutil::locate(70,4);
            cout<<"Turno del jugador: "<<Player[ban].nombre<<endl;
        }


//tirada de dados Objetivos
    totalPoliedro=pedirPoliedros(Player,ban);


//tirada de dados
    ponerEnCero(Player, ban,VcontenedorIndices);  // Limpiar datos del turno anterior

    for(int i=0;i<Player[ban].dadosStock;i++){
    Player[ban].vNumTirada[i]=tirarDado((i+1)*10,1*2);
    rlutil::locate(1,14+i);
    }
    rlutil::msleep(1000);

//Menu
    int op=-1,y=0;
    int sumaDeDados=0;
    bool salir=false;

    rlutil::hidecursor();
    rlutil::locate(18,14);

    cout << "Usa las Flechas para seleccionar dados y ENTER para confirmar. (ESC para terminar):" << endl;
    if(ban==1){
                    rlutil::locate(75, 16);
                }else{
                    rlutil::locate(2, 16);
                }
    cout<<"Dado objetivo del jugador "<<Player[ban].nombre<<" : "<<totalPoliedro<<" Puntos"<<endl;
        int dadosPorRonda=0;

        while(!salir){
        //mostrar todos los dados
        for(int n=0;n<12;n++){
            //ubicacion
                if(ban==1){
                    rlutil::locate(100, 18 + n);
                }else{
                    rlutil::locate(4, 18 + n);
                }
            //resaltar opcion
        if(Player[ban].vNumTirada[n]>0&&Player[ban].vNumTirada[n]<7){
                if(n==y){
                    rlutil::setBackgroundColor(rlutil::BLUE);
                }else{
                    rlutil::setBackgroundColor(rlutil::BLACK);
                }
            cout << Player[ban].vNumTirada[n] << "   ";
                }
         }
              rlutil::setBackgroundColor(rlutil::BLACK); // Restablecer color

    // Mostrar flecha de seleccion
        if(ban==1){
            rlutil::locate(97, 18 + y);
        }else{
            rlutil::locate(1, 18 + y);
            }
            cout << (char)175;
    int key = rlutil::getkey();

    switch (key) {
        case 14: // UP
            if(ban==1){
            rlutil::locate(97, 18 + y);
                }else{
            rlutil::locate(1, 18 + y);
            }

            cout << " "<<endl;
                y--;
            if (y< 0){
                y=0;
            }
            break;
        case 15: // DOWN
            if(ban==1){
            rlutil::locate(97, 18 + y);
                }else{
            rlutil::locate(1, 18 + y);
            }
            cout << " "<<endl;
                y++;
                if (y > 11){
                    y=11;
                }

            break;
        case 1: // ENTER
            if (Player[ban].vNumTirada[y] > 0) {
                VcontenedorIndices[y]=y;//guarda el indice del numero seleccionado
                Player[ban].puntosPoliedro[y] = Player[ban].vNumTirada[y];
                sumaDeDados += Player[ban].vNumTirada[y];
                rlutil::locate(50, 16 + 5);
                cout << "Suma parcial: " << sumaDeDados << "   ";
                Player[ban].vNumTirada[y] =0; // Marcar como ya seleccionado
            }
            break;
        case 0: // ESC
                 //cuenta dados usados
                 int dadosUsados=0;
                    for(int x=0;x<12;x++){
                        if(Player[ban].puntosPoliedro[x] != 0){
                            dadosUsados++;
                        }
                    }

            if(totalPoliedro==sumaDeDados&& dadosUsados > 0){
                // Calcular puntos
                Player[ban].puntos += totalPoliedro * dadosUsados;
                dadosPorRonda=dadosUsados;

                // Transferir dados (jugador actual -> oponente)
                transferirDados(Player, ban, (ban + 1) % 2, dadosUsados);

                // Verificar victoria automatica
                if(Player[ban].dadosStock == 0) {
                    Player[ban].puntos += 10000;
                    cout << "VICTORIA AUTOMATICA! " << Player[ban].nombre << " gana!";
                    ronda = 4; // Forzar fin del juego
                        }
                    salir = true; // Salir del bucle de seleccion de dados

            }else{
        // El oponente envia 1 dado (si tiene menos de 1)
            if(Player[(ban + 1) % 2].dadosStock > 1) {
                transferirDados(Player, (ban + 1) % 2, ban, 1);
                rlutil::locate(35,25);
                rlutil::setBackgroundColor(rlutil::RED);
                cout << "Penalizacion: " << Player[(ban + 1) % 2].nombre << " envia 1 dado"<<endl;
                rlutil::setBackgroundColor(rlutil::BLACK);
                }
                salir = true;
            }
            break;
    }//sale Switch

// Validar entrada
            if (op >= 0 && op < 12 && Player[ban].vNumTirada[op] > 0) {
                Player[ban].puntosPoliedro[op] = Player[ban].vNumTirada[op];
                sumaDeDados += Player[ban].vNumTirada[op];
// Mostrar seleccion actualizada
                rlutil::locate(10, 16 + 5);
                cout << "Suma parcial: " << sumaDeDados << "   ";
            }

        }//Sale del segundo While

        for(int i=0;i<12;i++){
            if(Player[ban].puntosPoliedro[i]!=0){
            cout<<"numeros SELECCIONADOS: "<<Player[ban].puntosPoliedro[i]<<endl;
            }
        }
            rlutil::locate(35,26);
            cout<<"Total puntos de la Ronda "<<ronda<<" : "<<sumaDeDados*dadosPorRonda<<"."<<endl;
            dadosPorRonda=0;
            rlutil::locate(35,27);
            cout<<"suma total= "<<Player[ban].puntos<<endl;

        rlutil::anykey();
        if(turno==2){
            ronda++;
            turno=0;
        }

        ban=(ban+1)%2;

    }//sale While primero
    rlutil::locate(50,40);
    cout<<"FIN DE LA PARTIDA!!! " << Player[ban].puntos<<endl;

    if(Player[0].puntos>Player[1].puntos){
    cout<<"Ganador! jugador: "<<Player[0].nombre<<endl;
    }else{
    cout<<"Ganador! jugador: "<<Player[1].nombre<<endl;
    }
    rlutil::anykey();
    //*****************

    return 0;
}




