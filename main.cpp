/*
Solve a consensus problem using ADMM. 
 */

#include <iostream>
#include <armadillo>
#include "agent.h"
#include "admm_solver.h"

using namespace std;
using namespace arma;



int main(int argc, char *argv[]) {

	arma_rng::set_seed(42);

	Agent agent(4);
	agent.printx();
	return 0;

}

