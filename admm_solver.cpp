#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


// Constructor, receives N, steps, and list of agents as input
ADMM_solver::ADMM_solver(unsigned _N, unsigned _steps, int _agents []){
	N = _N;
	steps = _steps;
	for(int i = 0; i< N; i++){
		agents[i] = _agents[i];
	}
}


void ADMM_solver::ADMM_algorithm(){
/*
At each timestep:
Yells at agents to compute updates to their local variables;
Aggregates agent contributions to the global variable update.
*/
	for(int t = 0; t< steps; t++){
		std::cout << "This is step " << t << "!\n";
		// for(int ag = 0; ag <N; ag ++){
			// agents[i].update
		// }

	}
}
