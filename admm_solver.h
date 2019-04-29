#ifndef __ADMM_SOLVER_H
#define __ADMM_SOLVER_H

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class ADMM_solver {
private:
	unsigned N; // number of agents
	unsigned steps; // number of steps for ADMM
	int agents []; // list of agents
public:
	ADMM_solver(unsigned _N, unsigned _steps, int _agents []); // constructor
	void ADMM_algorithm(); // algorithm
};

#include "admm_solver.cpp"

#endif