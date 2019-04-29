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

	int n = 4;
	// Agent agent(n);
	// agent.printx();

	double rho = 0.3;
	mat P(n,n);
	P.fill(2.0);
	vec q(n);
	q.fill(-1.0);
	double r = 0.6;

	Agent agent2(P, q, r, rho);
	agent2.printx();
	agent2.printu();
	agent2.printz();	

	vec z(n);
	z.fill(1.0);

	agent2.setValueOfz(z);
	agent2.printx();
	agent2.printu();
	agent2.printz();

	return 0;

}

