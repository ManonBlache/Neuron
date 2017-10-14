#include "Neuron.h"
#include <cmath>

//Constructeur et constructeur de copie
	Neuron::Neuron()
	:membrane_pot_(10),
	 num_spikes_(0),
	 tau_(20),
	 tau_ref_(2),
	 membrane_resistance_(20),
	 threshold_(20),
	 life_time_(0),
	 h_(0.1),
	 ref_(0),
	 Iext_(200),
	 J_(0.2), 
	 D_(3),
	 buffer_(D_/h_, 0)
	 {}

	Neuron::Neuron(double const& birth) 
	:membrane_pot_(10),
	 num_spikes_(0),
	 tau_(20),
	 tau_ref_(2),
	 membrane_resistance_(20),
	 threshold_(20),
	 life_time_(birth),
	 h_(0.1),
	 ref_(0),
	 Iext_(200),
	 J_(0.2),
	 buffer_(D_/h_, 0)
	{} 
	
	Neuron::Neuron(Neuron const &autre)
	:membrane_pot_(autre.membrane_pot_), num_spikes_(autre.num_spikes_), tau_(10), tau_ref_(2)
	{} 
	
	Neuron::~Neuron (){};
	
//Getters and setters
	///double Neuron::getThreshold() const {return threshold_;}
	///double Neuron::getMembraneRes () const { return membrane_resistance_; }
	double Neuron::getMembranePot () const { return membrane_pot_; }
    unsigned int Neuron::getSpikes () const { return num_spikes_; }
    double Neuron::getLifeTime() const {return life_time_*0.1;}
    double Neuron::getH() const {return h_;}
    int Neuron::getD() const {return D_;}
     int Neuron::getJ() const {return J_;}
    ///double Neuron::getTau() const {return tau_;}
    ///void Neuron::setMembranePot (double const& r) {membrane_pot_=r;}
    ///void Neuron::setSpikes (unsigned int const& i) { num_spikes_= num_spikes_+i; }
    void Neuron::setLifeTime(int time) {life_time_=life_time_+time;}
    void Neuron::setH(double h) {h_=h;}
    void Neuron::setIext(double I) {Iext_=I;}

//Method that updates the neuron state from time t+T, where T=n*h
bool Neuron::Update ()
{
	spike_ =false;

	if (ref_>0){
		membrane_pot_=0;
		ref_ -=1;
	} else {
		
	membrane_pot_+= getBuffer((life_time_+1)%buffer_.size()) + ((exp(-h_/tau_)*membrane_pot_) + ( Iext_*membrane_resistance_*(1-exp(-h_/tau_)) ) );
		clearBuffer((life_time_+1)%buffer_.size());
	}
	
	if (membrane_pot_>=threshold_) {
		ref_= tau_ref_/h_;
		num_spikes_+=1;
		spike_=true;
		}
		
		life_time_+=1;
	return spike_;
}

/*void Neuron::Interact(Neuron &autre) {
	
	"this" is the neuron who send his spike potential to an other neuron
	connected to him 
	
	if (spike_) {
		autre.ImplementBuffer(J_,(life_time_+D_)%autre.buffer_.size());
		}
	
	
}*/

void Neuron::ImplementBuffer(double j, int d) {
	buffer_[(life_time_+d)%buffer_.size()]+=j;
	}

double Neuron::getBuffer(size_t position) {
	return buffer_[position];
}

void Neuron::clearBuffer(size_t position){
	buffer_[position]=0;
	}
