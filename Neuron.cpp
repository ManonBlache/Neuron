#include "Neuron.h"
#include <cmath>

//Constructeur et constructeur de copie
	Neuron::Neuron()
	:membrane_pot_(10), num_spikes_(0), tau_(20), tau_ref_(2),membrane_resistance_(20), threshold_(20), life_time_(0)
	{}

	Neuron::Neuron(double const& birth) 
	:membrane_pot_(10),  num_spikes_(0), tau_(20), tau_ref_(2),membrane_resistance_(20), threshold_(20), life_time_(birth)
	{} 
	
	Neuron::Neuron(Neuron const &autre)
	:membrane_pot_(autre.membrane_pot_), num_spikes_(autre.num_spikes_), tau_(10), tau_ref_(2)
	{} 
	
	Neuron::~Neuron (){};
	
//Getters and setters
	double Neuron::getThreshold() const {return threshold_;}
	double Neuron::getMembraneRes () const { return membrane_resistance_; }
	double Neuron::getMembranePot () const { return membrane_pot_; }
    unsigned int Neuron::getSpikes () const { return num_spikes_; }
    double Neuron::getLifeTime() const {return life_time_;}
    double Neuron::getTau() const {return tau_;}
    void Neuron::setMembranePot (double const& r) {membrane_pot_=r;}
    void Neuron::setSpikes (unsigned int const& i) { num_spikes_= num_spikes_+i; }
    void Neuron::setLifeTime(double time) {life_time_=life_time_+time;}

//Method that updates the neuron state from time t+T, where T=n*h
	void Neuron::Update (double const& h, double const& Iext)
	{
		setLifeTime(h);
		
		if (ref>0){
			setMembranePot(10);
			ref -=1;
		} else {
		
		membrane_pot_= membrane_pot_+ ((exp(-h/tau_)*membrane_pot_) + ( Iext*(membrane_resistance_/tau_)*(1-exp(-h/tau_)) ) );
		
		if (getMembranePot()>=getThreshold()) {
			ref = tau_ref_/h;
			setSpikes(1);
			spikes_times_.push_back(life_time_);
			}
	}
	}
