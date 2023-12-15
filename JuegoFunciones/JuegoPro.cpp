#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;
string characterName;
int selectataque = 0;

void IntNombre() {
    cout << " Habia una vez en las fiestas de Malaga un chaval con un gran corazon\n";
    cout << " Lo que pasa es que te metiste en callejon oscuro, ves dos sombras abalanzandose sobre ti, rapido!\n";
    cout << " Qual es tu nombre?\n";
    cin >> characterName;
}

    void Ataques() {
    cout << " Con que arma le vas a atacar\n";
    cout << " 1 espadazo\n";
    cout << " 2 hechizo de hielo\n";
    cout << " 3 hechizo de fuego\n";
    cout << " 4 punetazo\n";
    cout << " 5 Uppercut\n";
    cin >> selectataque;
}

int main()
{
    using namespace std;

    PlaySound(TEXT("LosChunguitosDameVeneno.wav"), NULL, SND_ASYNC);

    //STATS PERSONAJE
    int characterHP = 850;
    int characterDamage;
    string characterName;

    int espadazo = 90;
    int magiaFuego = 100;
    int magiaHielo = 100;
    int puñetazo = 55;
    int Uppercut = 80;

    //STATS BOSS1
    int bossHP1 = 450;
    int bossDamage;
    string bossName = "EL CIGALA";

    //STATS BOSS2
    int bossHP2 = 450;
    int bossDamage2;
    string bossName2 = "EL FARI";

    //enter your name
    IntNombre();

    int selectboss = 0;

    srand(time(NULL));

    while (characterHP > 0 && (bossHP1 > 0 || bossHP2 > 0)) {

        bossDamage = rand() % 100;
        bossDamage2 = rand() % 100;


        selectboss = 0;

        if (characterHP > 0) {
            Ataques();   
        }

        while (selectboss <= 0 || selectboss > 2) {
            if (characterHP > 0) {
                cout << " ¿A que enemigo quieres atacar?\n";

                if (bossHP1 > 0) {
                    cout << " 1 para atacar a " << bossName << "\n";
                }
                if (bossHP2 > 0) {
                    cout << " 2 para atacar a " << bossName2 << "\n";
                }

                cin >> selectboss;
                if (selectboss <= 0 || selectboss > 2) {
                    cout << " El enemigo que has puesto esta en el bar, revise su vista y vuelva  a elegir\n";
                }
            }
        }


        //Ataca el enemigo 1
        if (bossHP1 > 0) {
            characterHP = characterHP - bossDamage;

            if (characterHP <= 0) {
                cout << bossName << " te han dejado sangrando en medio de la nada. Game Over\n";
            }
            else {
                cout << bossName << " te ha pegado un palazo de " << bossDamage <<
                    " y te quedan " << characterHP << " de vida\n";
            }
        }

        //ataca el enemigo 2
        if (bossHP2 > 0 && characterHP > 0) {
            characterHP = characterHP - bossDamage2;

            if (characterHP <= 0) {
                cout << bossName2 << " te ha pegado un latigazo fino. Game Over\n";
            }
            else {
                cout << bossName2 << " te ha pegado un golpe de " << bossDamage2 <<
                    " y te quedan " << characterHP << " de vida\n";
            }
        }

        if (selectboss == 1) {
            //ATACAS AL ENEMIGO 1
            characterDamage = selectataque;
            if (selectataque == 1) {
                characterDamage = espadazo;
            }
            if (selectataque == 2) {
                characterDamage = magiaFuego;
            }
            if (selectataque == 3) {
                characterDamage = magiaHielo;
            }
            if (selectataque == 4) {
                characterDamage = puñetazo;
            }
            if (selectataque == 5) {
                characterDamage = Uppercut;
            }
            bossHP1 = bossHP1 - characterDamage;
            if (bossHP1 < 0) {
                bossHP1 = 0;
            }
            cout << characterName << " le ha pegado un Mamporrazo de " << characterDamage <<
                " y a " << bossName << " le quedan " << bossHP1 << " de vida\n";

            if (bossHP1 <= 0) {
                cout << "Te has cargado a " << bossName << " , ha ido al bar a por una cervecita \n";
            }
        }

        //ATACAS AL ENEMIGO 2
        if (selectboss == 2) {
            characterDamage = selectataque;
            if (selectataque == 1) {
                characterDamage = espadazo;
            }
            if (selectataque == 2) {
                characterDamage = magiaFuego;
            }
            if (selectataque == 3) {
                characterDamage = magiaHielo;
            }
            if (selectataque == 4) {
                characterDamage = puñetazo;
            }
            if (selectataque == 5) {
                characterDamage = Uppercut;
            }

            bossHP2 = bossHP2 - characterDamage;
            if (bossHP2 < 0) {
                bossHP2 = 0;
            }
            cout << characterName << " le ha pegado un Mamporrazo de " << characterDamage <<
                " y a " << bossName2 << " le quedan " << bossHP2 << " de vida\n";

            if (bossHP2 <= 0) {
                cout << " Has derrotado a " << bossName2 << " , le ha llamado su mujer y se ha ido a casa corriendo\n";
            }
        }
    }
}