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

void generezLignes(vector<string>& lignes_generees,const vector<string>& noms,const vector<string>& prenoms,const vector<string>& mails,const vector<string>& telephones,int nr){
  srand(time(0));
  if(nr>=0)
  {
  for(int i=0;i<nr;i++){
     do{ 
    string nom=ligneArbitraire(noms);
    string prenom=ligneArbitraire(prenoms);
     } while(estDuplicat(nom,prenom));
    string mail=ligneArbitraire(mails);
    string telephone=ligneArbitraire(telephones);

    stringstream ligne;
    ligne << prenom.c_str() << "," << nom.c_str() << "," << mail.c_str() << "," << telephone.c_str();
    lignes_generees.push_back(ligne.str());
  }
  }
}

void ecrivezLignes(const vector<string>& lignes_generees,const string& fNom){
  ofstream fichier;
  fichier.open(fNom.c_str());

  fichier << "prenom,nom,adresse mail,numero de telephone" << endl;
  
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

bool estDuplicat(const string& first,const string& second){
 static set<string> dejavu;
 //[compléter ici]
 string pair = first+","+ second;
 set<string>::iterator it=dejavu.find(pair);
 if(it!=dejavu.end()){
	return true; //duplication
	}
 else
	{
	dejavu.insert(pair);
	return false;
	}
}

