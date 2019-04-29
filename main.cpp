/*
Solve a consensus problem using ADMM. 
 */

#include <iostream>
#include <armadillo>
#include "agent.h"
#include "admm_solver.h"

using namespace std;
using namespace arma;

const int N_agents = 10;
const int steps = 15; // time steps in ADMM algorithm
const int states = 5; // dimension of state space for each agent


void test_armadillo(){
	mat P = 2 * eye<mat>(states, states);
	mat q = randu<vec>(states);
	double r = 0;
	P.print("P:");
	q.print("q:");
	vec res = P * q;
	res.print("Matrix multiplication:");
}


void test_agent(){
	// Agent agent(n);
	// agent.printx();

	double rho = 0.3;
	mat P(states,states);
	P.fill(2.0);
	vec q(states);
	q.fill(-1.0);
	double r = 0.6;

	Agent agent2(P, q, r, rho);
	agent2.printx();
	agent2.printu();
	agent2.printz();	

	vec z(states);
	z.fill(1.0);

	agent2.setValueOfz(z);
	agent2.printx();
	agent2.printu();
	agent2.printz();
}

void initialize_cost(mat& P, vec& q, double& r){
	mat M = randu<mat>(states, states);
	P = M * M.t();
	q = randu<vec>(states);
	r = 0;
}

void initialize_agents(std::vector<Agent>& agents){
	double rho = 1;	
	for (int i=0;i<N_agents;i++){

		mat P;
		vec q(states);
		double r;

		arma_rng::set_seed(i);

		initialize_cost(P, q, r);

		Agent agent (P, q, r, rho);
		vec z = randu<vec>(states);
		agent.setValueOfz(z);

		agents.push_back(agent);
	}
}

int main(int argc, char *argv[]) {
	// test_armadillo();
	// test_agent();

	std::vector<Agent> agents;
	initialize_agents(agents);

	ADMM_solver solv (N_agents, steps, states, agents);
	solv.ADMM_algorithm();

	return 0;
}

