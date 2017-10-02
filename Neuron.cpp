#include "Neuron.h"
#include <cmath>

//Constructeur et constructeur de copie
	Neuron::Neuron()
	:membrane_pot_(-70), tau_(10), tau_ref_(2), life_time_(0)
	{}

	Neuron::Neuron(double const& mem_pot, unsigned int const& spikes) 
	:membrane_pot_(mem_pot), num_spikes_(spikes), tau_(10), tau_ref_(2)
	{} 
	
	Neuron::Neuron(Neuron const &autre)
	:membrane_pot_(autre.membrane_pot_), num_spikes_(autre.num_spikes_), tau_(10), tau_ref_(2)
	{} 
	
	Neuron::~Neuron (){};
	
//Getters et setters
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
	void Neuron::Update (double const& h, double const& Iext, double const& tstop)
	{
		if (life_time_<tstop){
		setMembranePot( getMembranePot()+ (exp(-h/getTau())*getMembranePot()) + (Iext*(getMembraneRes()/getTau())*(1-exp(-h/getTau()))) );
		
		setLifeTime(h);
		
		if (getMembranePot()>getThreshold()) {
			setSpikes(1);
			
			spikes_times_.push_back(life_time_);
			setMembranePot(-70);
			setLifeTime(tau_ref_); ///Pendant 2ms apres le spike, pas d'interaction et pas de potentiel
			
			}
		
		}
	}
