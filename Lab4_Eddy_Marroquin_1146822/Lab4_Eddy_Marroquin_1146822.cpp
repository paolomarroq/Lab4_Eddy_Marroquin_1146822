#include "pch.h"
#include <string>
#include "iostream"
#include "windows.h"
#include <stdlib.h>
#include <time.h>



using namespace std;
using namespace System;

void LlenarCarrera(string* pista, int n_T, int* posicion_T, int n_L, int* posicion_L)
{
    *posicion_T = *posicion_T + n_T;
    *posicion_L = *posicion_L + n_L;
    if (*posicion_T < 0)
    {
        *posicion_T = 0;
    }
    else if(*posicion_T > 69)
    {
        *posicion_T = 69;
    }
    if (*posicion_L < 0)
    {
        *posicion_L = 0;
    }
    else if (*posicion_L > 69)
    {
        *posicion_L = 69;
    }

    for (size_t i = 0; i < 70; i++)
    {
        if (i == *posicion_T)
        {
            pista[i] = "T";
        }
        else if (i == *posicion_L)
        {
            pista[i] = "H";
        }
        else
        {
            pista[i] = "-";
        }
        if (i == *posicion_L && *posicion_L == *posicion_T)
        {
            pista[i] = "!OUCH!";
        }
    }
}

void MoverPersonajes(string* pista, int Desp_T[], int* posicion_T, int Desp_L[], int* posicion_L)
{
    srand(time(NULL));
    int movimiento_T = rand() % 10;
    if (movimiento_T > 0 && movimiento_T <= 5)
    {
        movimiento_T = 1;
    }
    else if (movimiento_T >= 6 && movimiento_T <= 7)
    {
        movimiento_T = 2;
    }
    else
    {
        movimiento_T = 0;
    }

    srand(time(NULL));
    int movimiento_L = rand() % 10;
    if (movimiento_L >= 1 && movimiento_L <= 2)
    {
        movimiento_L = 0;
    }
    else if (movimiento_L >= 3 && movimiento_L <= 5)
    {
        movimiento_L = 1;
    }
    else if (movimiento_L >= 6 && movimiento_L <= 7)
    {
        movimiento_L = 2;
    }
    else if (movimiento_L >= 8 && movimiento_L <= 9)
    {
        movimiento_L = 3;
    }
    else
    {
        movimiento_L = 4;
    }
    LlenarCarrera(pista, Desp_T[movimiento_T], posicion_T, Desp_L[movimiento_L], posicion_L);
    Sleep(1000);
}

void MostrarPersonajes(string* pista)
{
    for (size_t i = 0; i < 70; i++)
    {
        cout << pista[i] << " ";
    }
    cout << "\n";
}

bool ValidarGanador(string* pista)
{
    if (pista[69] == "T" || pista[69] == "H")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Ganador(string* pista)
{
    if (pista[69] == "T" )
    {
        return 1;
    }
    else if (pista[69] == "H")
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void carrera()
{
    string pista[70];
    //Tortuga
    int movimiento_T[3] = {1, 3, -6};
    int posicion_T = 0;
    int* punt_pos_T = &posicion_T;

    //Liebre
    int movimiento_L[5] = {0, 1, 9, -2, -12};
    int posicion_L = 0;
    int* punt_pos_L = &posicion_L;
    bool ganador = false;

    cout << "Oprima ENTER para comenzar la carrera" << endl;
    Console::ReadKey();


    while (ganador != true)
    {
        MoverPersonajes(pista, movimiento_T, punt_pos_T, movimiento_L, punt_pos_L);
        ganador = ValidarGanador(pista);
        MostrarPersonajes(pista);
        
    }
    if (Ganador(pista) == 1)
    {
        cout << "¡LA TORTUGA GANA! ¡BRAVO!" << endl;
    }
    else
    {
        cout << " \"La liebre gana ni hablar\" " << endl;
    }
    Console::ReadKey();
}

int main()
{
    carrera();
    return 0;
}
