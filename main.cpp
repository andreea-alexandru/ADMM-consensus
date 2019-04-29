#include <iostream>
#include <armadillo>
#include "admm_solver.h"

using namespace std;
using namespace arma;

const int N_agents = 4;
const int steps = 7;
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

int main(){
	// test_admm_solver();
	test_armadillo();
	return 0;
}