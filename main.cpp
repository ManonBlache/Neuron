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

double insertCurrent () {
	double current;
	cout << "Specify an external current Iext: " << endl;
	cin >> current;
	return current;
}
double insertTimeStep () {
	double step;
	cout << "Specify a time interval: " << endl;
	cin >> step;
	return step;
}

bool makeAWish() {
	char choix ('O');
	cout << "Voulez-vous choisir des valeurs pour Iext et h?  (O/N) ";
		cin >> choix;
		if (choix == 'O') { return true;} else {return false;}
}

int main () {
	
		
	double t_stop (1000); //il faut permettre a l'utilisateur d'entrer lui meme les donnees de run
	double h (0.1);
	double I (200);
	if (makeAWish()) {
		I = insertCurrent();
		h = insertTimeStep ();
	}
	
	///OUVERTURE FICHIER ICI
	string nom_fichier ("data.txt");
	ofstream sortie (nom_fichier.c_str());
	
	
	if (sortie.fail()) {
		cerr << "Erreur d'ouverture du fichier,"
			 << "impossible d'écrire dans le fichier " << nom_fichier << endl;
			 } 
		else {
		
				Neuron FirstNeuron;
				while (FirstNeuron.getLifeTime()<t_stop) {
					FirstNeuron.Update(h,I);
						///ECRITURE FICHIER ICI
						
					sortie << "Membrane potential = " << FirstNeuron.getMembranePot() << " at Time =  " 
						   << /*setw(col2) <<*/ FirstNeuron.getLifeTime() << endl;
				}
				}
		
	
	
	///FERMETURE FICHIER ICI
	sortie.close ();
	
	
	
	
	return 0;
}







