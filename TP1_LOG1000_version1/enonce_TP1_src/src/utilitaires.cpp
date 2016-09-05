#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "utilitaires.h"

using namespace std;



void lisFichier(vector<string>& v,const string& fNom){
  ifstream fichier;
  fichier.open(fNom.c_str());
  if (fichier.fail()) {
    cout << "Fichier " << fNom << " pas trouve!\n" << endl;
    return;
  }

  // Lecture des donnees
  string ligne;
  getline(fichier, ligne);
  while (!fichier.eof()){
    v.push_back(ligne);
    getline(fichier,ligne);
  }
  fichier.close();
}

string ligneArbitraire(const vector<string>& lignes){
  int num=rand() % lignes.size();
  return lignes[num];
}

void generezLignes(vector<string>& lignes_generees,const vector<string>& noms,const vector<string>& prenoms,const vector<string>& cours,const vector<string>& sites,int nr){
  srand(time(0));
  if(nr>=0)
  {
  for(int i=0;i<nr;i++){
      
    string nom=ligneArbitraire(noms);
    string prenom=ligneArbitraire(prenoms);
    string uncours=ligneArbitraire(cours);
    string site=ligneArbitraire(sites);

    stringstream ligne;
    ligne << nom.c_str() << "," << prenom.c_str() << "," << uncours.c_str() << "," << site.c_str();
    lignes_generees.push_back(ligne.str());
  }
  }
}

void ecrivezLignes(const vector<string>& lignes_generees,const string& fNom){
  ofstream fichier;
  fichier.open(fNom.c_str());

  fichier << "nom,prenom,cours prefere,site prefere" << endl;
  
  for(vector<string>::const_iterator it=lignes_generees.begin();it!=lignes_generees.end();it++){
    fichier << it->c_str() << endl;
  }

  fichier.close();
}


/*Contrôler si le pair d'arguments a apparu déjà plus tôt dans le programme
*Params:
* first = un string
* second = aussi un string
*Returns:
* true si <first,second> a été rencontrée avant pendant le programme
*/
/*
bool estDuplicat(const string& first,const string& second){
 static set<string> dejavu;
 //[compléter ici]
 set<string>::iterator it=dejavu.find(pair);
 if(it!=dejavu.end()){
	return true;
	//duplication
	}
 else
	{
	dejavu.insert(pair);
	return false;
	}
}
*/
