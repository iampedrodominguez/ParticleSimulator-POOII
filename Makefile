# required for SFML programs
LDLIBS := $(shell pkg-config sfml-all --libs)

all: main.cpp Collision_System.cpp Particle.cpp Particles.cpp
	g++ -c main.cpp
	g++ -c Collision_System.cpp
	g++ -c Particle.cpp
	g++ -c Particles.cpp
	g++ main.o Collision_System.o Particle.o Particles.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm main.o
	rm Collision_System.o
	rm Particle.o
	rm Particles.o