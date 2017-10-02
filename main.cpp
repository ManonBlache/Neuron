/**
 * C=250pF
 * Tau=10ms
 * Tauref=2ms
 * Erepos=-70mV
 * Vreset= -70mV
 * h=0.1ms
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */
#include "Neuron.h"
//#include "Neuron.cpp"

int main () {
	//ouverture fichier
	//ecriture apres update
	//ne pas oublier de fermer le fichier
	
	double t_stop (1000);
	double h (0.1);
	double I (200);
	
	Neuron FirstNeuron;
	FirstNeuron.Update(h,I,t_stop);
	
	
	
	
	
	
	
	return 0;
}







