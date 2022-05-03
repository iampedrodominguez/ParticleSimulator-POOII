make:
	g++ -c main.cpp Collision_System.cpp Particles.cpp Particle.cpp
	g++ main.o Collision_System.o Particle.o Particles.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app