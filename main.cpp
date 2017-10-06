/**
 * C=250pF
 * Tau=10ms
 * Tauref=2ms
 * Erepos=-70mV
 * Vreset= -70mV
 * h=0.1ms

 * */
#include "Neuron.h"
#include <fstream>
#include "Neuron.cpp"

double insertCurrent ();  
double insertTimeBirth (); 
double insertTimeStep ();
double insertTimeDeath ();
bool makeAWish();  

int main () {
	
	///These 3 values are used by default if the user doesnt want to change it
	double t_stop (1000);
	double h (0.1);
	double I (200);
	
	Neuron FirstNeuron;
	
	if (makeAWish()) { ///The user decide to change or not the values
		I = insertCurrent();
		h = insertTimeStep ();
		t_stop = insertTimeDeath();
		FirstNeuron.setLifeTime(insertTimeBirth());
	} 
		
	
	//OUVERTURE FICHIER ICI
	string nom_fichier ("data.txt");
	ofstream sortie (nom_fichier.c_str());
	
	
	if (sortie.fail()) {
		cerr << "Erreur d'ouverture du fichier,"
			 << "impossible d'écrire dans le fichier " << nom_fichier << endl;
			 } 
		else {
				while (FirstNeuron.getLifeTime()<t_stop) {
					FirstNeuron.Update(h,I);
						//ECRITURE FICHIER ICI
						sortie << "At time = " << FirstNeuron.getLifeTime() << ", membrane potential = " 
						     << FirstNeuron.getMembranePot() << endl;
						     
				}
				sortie << "--> Number of Spikes: " << FirstNeuron.getSpikes() << endl;
				}
	
	//FERMETURE FICHIER ICI
	sortie.close ();
	
	
	return 0;
}

double insertCurrent () {
	/**This function allows the user to choose a specific value for the external current Iext
	 * **/
	double current;
	cout << "Specify an external current Iext: " << endl;
	cin >> current;
	return current;
}
double insertTimeBirth () {
	/**This function allows the user to choose a specific value for the start time
	 * **/
	double start;
	cout << "Specify a start time: " << endl;
	cin >> start;
	return start;
}
double insertTimeStep () {
	/**This function allows the user to choose a specific value for the time interval h
	 * **/
	double step;
	cout << "Specify a time interval: " << endl;
	cin >> step;
	return step;
}
double insertTimeDeath () {
	/**This function allows the user to choose a specific value for the stop time
	 * **/
	double stop;
	cout << "Specify a stop time: " << endl;
	cin >> stop;
	return stop;
}

bool makeAWish() {
	/** In this function, the user choose to change the values for Iext and h or not
	 * **/
	char choix ('O');
	cout << "Voulez-vous choisir des valeurs pour Iext, t_start, t_stop et h?  (O/N) ";
		cin >> choix;
		if (choix == 'O') { return true;} else {return false;}
}





