/*
Solve a consensus problem using ADMM. 
 */

#include <iostream>
#include <armadillo>
#include "agent.h"
#include "admm_solver.h"

using namespace std;
using namespace arma;

const int N_agents = 4;
const int steps = 7; // time steps in ADMM algorithm
const int n_states = 5; // dimension of state space for each agent

void test_admm_solver(){
	int arry[4] = {1,2,4,5};
	ADMM_solver solv(N_agents, n_states, arry);
	solv.ADMM_algorithm();	
}

void test_armadillo(){
	mat P = 2 * eye<mat>(n_states, n_states);
	mat q = randu<vec>(n_states);
	double r = 0;
	P.print("P:");
	q.print("q:");
	vec res = P * q;
	res.print("Matrix multiplication:");
}


int main(int argc, char *argv[]) {
	// test_admm_solver();
	// test_armadillo();

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

