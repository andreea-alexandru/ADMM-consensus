/*
Solve a consensus problem using ADMM. 
 */

// #ifndef __AGENT_CPP
// #define __AGENT_CPP

#include <iostream>
#include <armadillo>
// #include "agent.h"

using namespace std;
using namespace arma;


/* Empty constructor */
Agent::Agent(){}

/* Constructor that gets the dimension of the variables. It also initializes the initial values of x and u */
Agent::Agent(const unsigned _n) {
	n = _n;
	x = randu<vec>(n);
	u = randu<vec>(n);
}

/* Constructor that gets the local cost function, which we assume it is a quadratic function 1/2 x'Px + q'x + r. 
It also initializes the initial values of x and u */
Agent::Agent(const mat _P, const vec _q, const double _r)
{
	costs.P = _P; costs.q = _q; costs.r = _r;
	n = costs.P.n_rows;
	x = randu<vec>(n);
	u = randu<vec>(n);
}

/* Destructor */
Agent::~Agent() {}


/* Get local value of z */
vec Agent::getValueOfz(){
	return z;
}

/* Set local value of z */
void Agent::setValueOfz(const arma::vec _z){
	z = _z;
}

/* Get value of x */
vec Agent::getValueOfx(){
	return x;
}

/* Get value of u */
vec Agent::getValueOfu(){
	return u;
}	

/* Return dimension of x, n */
unsigned Agent::getValueOfn(){
	return n;
}

/* Return ADMM parameter rho */
double Agent::getValueOfrho(){
	return rho;
}

/* Return cost in the objective function */
cost Agent::getValueOfCosts(){
	return costs;
}

/* Compute local value of the primal iterate x at the current iteration */
void Agent::updateValueOfx(){
	vec x_ = Agent::getValueOfx();
	vec u_ = Agent::getValueOfu();
	vec z_ = Agent::getValueOfz();
	double rho_ = Agent::getValueOfrho();
	unsigned n_ = Agent::getValueOfn();
	cost costs = Agent::getValueOfCosts();

	mat P_ = costs.P; vec q_ = costs.q;

	x_ = inv( P_ + rho_ * eye<mat>(n_,n_) ) * (rho_ * (z_ - u_) - q_ );

	Agent::updateValueOfz();

}

/* Compute local value of the dual iterate u at the current iteration */
void Agent::updateValueOfu(){
	vec x_ = Agent::getValueOfx();
	vec u_ = Agent::getValueOfu();
	vec z_ = Agent::getValueOfz();

	u = u_ + x_ - z_;

	Agent::updateValueOfx();
}


/* Compute local value of the dual iterate z at the current iteration */
void Agent::updateValueOfz(){
	vec x_ = Agent::getValueOfx();
	vec u_ = Agent::getValueOfu();	
	vec z = x_ - u_;
}

/* Print current iterate x */
void Agent::printx()
{
	vec x_ = Agent::getValueOfx();
	x_.print("x:");	
}

/* Print current iterate u */
void Agent::printu()
{
	vec u_ = Agent::getValueOfu();
	u_.print("u:");	
}

/* Print current iterate z */
void Agent::printz()
{
	vec z_ = Agent::getValueOfz();
	z_.print("z:");	
}


// #endif