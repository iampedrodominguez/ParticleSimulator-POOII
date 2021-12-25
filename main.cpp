//#include "LibraryHeader.h"
#include "Collision_System.h"

int main()
{
    int number_particles = 0;


    //INTERFACE PARA EL USUARIO
    while (number_particles == 0 || number_particles > 250)
    {
        cout << "How many particles do you wish to see? (Max 250): "; cin >> number_particles;
        if (number_particles > 250)
            cout << "-Error- Try again";
    }

    //RENDERIZADO DE PANTALLA
    sf::RenderWindow window(sf::VideoMode(width, height), "Simulacion de particulas");
    Collision_System start(&window, number_particles);

    return 0;
}