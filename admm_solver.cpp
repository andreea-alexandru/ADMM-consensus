#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


// Empty constructor
ADMM_solver::ADMM_solver(){}

// Constructor: receives N, steps, and vector of agents as input
ADMM_solver::ADMM_solver(unsigned _N, unsigned _steps, unsigned _states, std::vector<Agent> _agents){
	N = _N;
	steps = _steps;
	states = _states;
	for(int i = 0; i< N; i++){
		agents.push_back(_agents[i]);
	}
}

// Destructor
ADMM_solver::~ADMM_solver(){}

void ADMM_solver::ADMM_algorithm(){
/*
At each timestep:
Aggregates agent contributions to the global variable update;
Tells agents to compute one iteration of updates to their local variables.
*/
	for(int t = 0; t< steps; t++){

		std::cout << "Executing time step " << t << ".\n";

		vec z = zeros<vec>(states);
		for(int current = 0; current < N; current++){
			z += agents[current].getValueOfz();
		}
		z /= N;

		z.print("Global z:");

		for(int current = 0; current < N; current++){
			agents[current].setValueOfz(z);
		}
	}
}
