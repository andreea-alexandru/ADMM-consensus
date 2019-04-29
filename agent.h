/*
Solve a consensus problem using ADMM. 
 *
 */
#ifndef __AGENT_H
#define __AGENT_H

#include <iostream>
#include <armadillo>
// #include "admm_solver.h"


struct cost {
	arma::mat P;
	arma::vec q;
	double r;
};

class Agent{

private:
	/* Local primal iterate x, vector in R^n*/
	arma::vec x;
	/* Local primal iterate z - consensus value, vector in R^n */
	arma::vec z;
	/* Local dual iterate u, vector in R^n */
	arma::vec u;
	/* For a local objective function f_i(x) = x'Px + q'x + r, the costs are P in R^(nxn), q in R^n, r in R */
	cost costs;
	/* Dimension of local variable x */
	unsigned n;

	/* Compute local value of the primal iterate x at the current iteration */
	void updateValueOfx();

	/* Compute local value of the dual iterate u at the current iteration */
	void updateValueOfu();

	/* Compute local value of the dual iterate z at the current iteration */
	void updateValueOfz();

	/* Get value of x */
	arma::vec getValueOfx();

	/* Get value of u */
	arma::vec getValueOfu();	

	/* Return costs P, q, r */
	cost getValueOfCosts();		

	friend class ADMM_solver;


public:
	/* ADMM parameter */
	double rho;

	/* Empty constructor */
	Agent();

	/* Constructor that gets the dimension of the variables */
	Agent(const unsigned _n);

	/* Constructor that gets the local cost function, which we assume it is a quadratic function 1/2 x'Px + q'x + r 
	and the ADMM parameter rho. It also initializes the initial values of x and u */
	Agent(const arma::mat _P, const arma::vec _q, const double _r, const double _rho);

	/* Virtual destructor */
	virtual ~Agent();

	/* Get local value of z */
	arma::vec getValueOfz();

	/* Set local value of z */
	void setValueOfz(const arma::vec _z);

	/* Return dimension of x, n */
	unsigned getValueOfn();

	/* Return ADMM parameter rho */
	double getValueOfrho();		

	/* Print current iterate x */
	void printx();

	/* Print current iterate u */
	void printu();

	/* Print current iterate z */
	void printz();		


};


#include "agent.cpp"

#endif