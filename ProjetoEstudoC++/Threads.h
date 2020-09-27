#pragma once
#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

void fazerContagemPrimaria(int maximo);
void fazerContagemSecundaria(int minimo, int maximo);
void executar(int minimo, int maximo);

void fazerContagemPrimaria(int maximo) {
	for (int i = 0; i < maximo; i++) {
		cout << "primeiro: " << i << "\n";
	}
}

void fazerContagemSecundaria(int minimo, int maximo) {
	for (int i = minimo; i < maximo; i++) {
		cout << "segundo: " << i << "\n";
	}
}

void executar(int minimo, int maximo) {
	// Primeiro sem as Threads
	time_t dataInicioSemThread = time(NULL);
	fazerContagemPrimaria(maximo);
	fazerContagemSecundaria(minimo, maximo);
	time_t dataFinalSemThread = time(NULL);

	// Agora com as Threads
	time_t dataInicioComThread = time(NULL);

	thread first(fazerContagemPrimaria, maximo);
	thread second(fazerContagemSecundaria, minimo, maximo);

	first.join();
	second.join();

	time_t dataFinalComThread = time(NULL);

	cout << "Diferenca de Tempo SEM THREADS: " << dataFinalSemThread << " - " << dataInicioSemThread << "\n";
	cout << "Diferenca de Tempo COM THREADS: " << dataFinalComThread << " - " << dataInicioComThread << "\n";
}