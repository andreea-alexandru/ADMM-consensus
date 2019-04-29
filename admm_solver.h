#ifndef __ADMM_SOLVER_H
#define __ADMM_SOLVER_H

#include <iostream>
#include <armadillo>
#include "agent.h"

using namespace std;
using namespace arma;

class ADMM_solver {
private:
	unsigned N; // number of agents

	unsigned steps; // number of steps for ADMM

	unsigned states; // dimension of each agent's state

	std::vector<Agent> agents; // vector of agents

public:
	ADMM_solver(unsigned _N, unsigned _steps, unsigned _states, std::vector<Agent> _agents); // constructor

	ADMM_solver(); // empty constructor

	virtual ~ADMM_solver(); // destructor

	void ADMM_algorithm(); // algorithm
};

#include "admm_solver.cpp"

#endif