#include <iostream>
#include "funcionPlayer.h"
#include "player.h"
#include <cstring>  // strcpy
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

void showItem(const char* text,int posX,int posY,bool seleted){
    if(seleted){
        rlutil::setBackgroundColor(rlutil::BLUE);
    }else{
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
    rlutil::locate(posX,posY);
    cout << text <<endl;
}

void game(point top[5]){
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

    int bpoin = 0;

    if (Player[0].puntos > Player[1].puntos) {
        cout << "Ganador! jugador: " << Player[0].nombre << endl;

        for (int i = 0; i < 5; i++) {
            if (bpoin == 0 && Player[0].puntos > top[i].score) {
                // Mover hacia abajo los puntajes más bajos
                for (int j = 4; j > i; j--) {
                    top[j] = top[j - 1]; // Copia toda la estructura
                }
            strcpy(top[i].name, Player[0].nombre);
            top[i].score = Player[0].puntos;
            bpoin = 1;
        }
    }

} else if (Player[1].puntos > Player[0].puntos) {
    cout << "Ganador! jugador: " << Player[1].nombre << endl;

    for (int i = 0; i < 5; i++) {
        if (bpoin == 0 && Player[1].puntos > top[i].score) {
            for (int j = 4; j > i; j--) {
                top[j] = top[j - 1];
            }
            strcpy(top[i].name, Player[1].nombre);
            top[i].score = Player[1].puntos;
            bpoin = 1;
        }
    }

        } else {
            cout << "EMPATE!" << endl;
        }
    rlutil::anykey();
    rlutil::cls();
    //*****************
}

