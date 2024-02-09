#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int manoDealer;
int manoJugador;
int as1u11;
int RandIndex;
int Valor;
string siONo;

bool ArrayDiamante[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
bool ArrayTrebol[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
bool ArrayCorazon[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
bool ArrayPica[] = { false, false, false, false, false, false, false, false, false, false, false, false, false };

int obtenerValorCarta(int RandValor) {
    if (RandValor >= 10) {
        return 10;
    }
    else {
        return RandValor + 1;
    }
}

void pedirCarta() {
    bool ganadoOPerdido = true;
    while (ganadoOPerdido)
    {
        RandIndex = rand() % 4;
        int RandValor = rand() % 13;
        Valor = obtenerValorCarta(RandValor);





        string nombrePalo = "";
        switch (RandIndex)
        {
        case 0:
            if (!ArrayDiamante[RandValor]) {
                ArrayDiamante[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Diamantes";
            }
            break;
        case 1:
            if (!ArrayTrebol[RandValor]) {
                ArrayTrebol[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Treboles";
            }
            break;
        case 2:
            if (!ArrayCorazon[RandValor]) {
                ArrayCorazon[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Corazones";
            }
            break;
        case 3:
            if (!ArrayPica[RandValor]) {
                ArrayPica[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Picas";
            }
            break;
        case 10:
            cout << "J" << nombrePalo;
        case 11:
            cout << "Q" << nombrePalo;
        case 12:
            cout << "K" << nombrePalo;
        default:
            break;
        }

        if (!ganadoOPerdido) {
            cout << "Te ha salido " << Valor << " " << nombrePalo << ".\n";
            manoJugador += Valor;
        }

        if (Valor == 1)
        {
            cout << " Quieres un 1 o un 11?";
            cin >> as1u11;
            manoJugador += (as1u11 == 1) ? 1 : 11;
        }
    }
}

void cartaCroupier() {
    bool ganadoOPerdido = true;
    while (ganadoOPerdido)
    {
        RandIndex = rand() % 4;
        int RandValor = rand() % 13;
        Valor = obtenerValorCarta(RandValor);

        string nombrePalo = "";
        switch (RandIndex)
        {
        case 0:
            if (!ArrayDiamante[RandValor]) {
                ArrayDiamante[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Diamantes";
            }
            break;
        case 1:
            if (!ArrayTrebol[RandValor]) {
                ArrayTrebol[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Treboles";
            }
            break;
        case 2:
            if (!ArrayCorazon[RandValor]) {
                ArrayCorazon[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Corazones";
            }
            break;
        case 3:
            if (!ArrayPica[RandValor]) {
                ArrayPica[RandValor] = true;
                ganadoOPerdido = false;
                nombrePalo = "Picas";
            }
            break;
        default:
            break;
        }

        if (!ganadoOPerdido) {
            cout << ", al croupier le ha salido " << Valor << " " << nombrePalo << ".\n";
            manoDealer += Valor;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    pedirCarta();

    cout << "Ahora es turno del croupier";
    cartaCroupier();

    // Decidir si quiere más cartas
    cout << "Quieres otra carta? ";
    cin >> siONo;
    while (siONo == "si") {
        pedirCarta();
        cout << "Tu puntuación actual es de " << manoJugador << endl;
        if (manoJugador > 21) {
            cout << "Te has pasado de 21. El croupier te coge todas tus fichas.\n";
            return 0;
        }
        cout << "Quieres otra carta? ";
        cin >> siONo;
    }
    if (manoJugador < 21) {
        cout << "Ahora le toca al croupier";
        cartaCroupier();
    }   if (manoDealer < manoJugador && manoDealer < 21) {
        cartaCroupier();
    }

    return determinarGanador();
}



int determinarGanador() {
    if (manoDealer == 21)
    {
        cout << " El dealer tiene blackjack. Dealer gana.\n";
        return manoDealer;
    }
    else if (manoJugador == 21)
    {
        cout << " El jugador tiene blackjack. Jugador gana.\n";
        return manoJugador;
    }
    else if (manoDealer > 21 && manoJugador <= 21)
    {
        cout << " El croupier se ha pasado de 21. Jugador Gana.\n";
        return manoJugador;
    }
    else if (manoJugador > 21 && manoDealer <= 21)
    {
        cout << " El jugador se ha pasado de 21. Croupier gana.\n";
        return manoDealer;
    }
    else if (manoDealer > manoJugador)
    {
        cout << " Croupier gana.\n";
        return manoDealer;
    }
    else if (manoJugador > manoDealer)
    {
        cout << " Jugador Gana.\n";
        return manoJugador;
    }
    else if (manoJugador = manoDealer)
    {   
        cout << "Empate. \n";
        return 0; // Tie
    }
}





