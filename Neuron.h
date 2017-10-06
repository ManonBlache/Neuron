#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
using namespace std;

class Neuron
{
	private:
		double membrane_pot_;
		unsigned int num_spikes_;
		vector <double> spikes_times_;
		
		double tau_; ///Tau used in the membrane potential implementation formula
		double tau_ref_; ///refractory time of neuron
		double membrane_resistance_;
		double threshold_; 
		double life_time_;
		double ref;
		

	
	public:
	
	//Constructeur et constructeur de copie
	Neuron();
	Neuron(double const& birth); 
	Neuron(Neuron const &autre);
	~Neuron ();
	
	//Getters et setters
	double getThreshold() const;
	double getMembraneRes() const ;
	double getMembranePot() const;
    unsigned int getSpikes() const;
    double getLifeTime() const;
    double getTau() const;
    void setMembranePot (double const& r);
    void setSpikes (unsigned int const& i);
    void setLifeTime(double time);
	
	//Method that updates the neuron state from time t+T, where T=n*h
	void Update(double const& h, double const& Iext);
	
	
};




#endif
