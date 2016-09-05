#include <vector>
#include "utilitaires.h"

using namespace std;


int main(int argc, char* argv[]){

  vector<string> noms;
  lisFichier(noms,argv[1]);

  vector<string> prenoms;
  lisFichier(prenoms,argv[2]);

  vector<string> mails;
  lisFichier(mails,argv[3]);

  vector<string> telephones;
  lisFichier(telephones,argv[4]);

  vector<string> lignes_generees;
  generezLignes(lignes_generees,noms,prenoms,mails,telephones,15);
  ecrivezLignes(lignes_generees,argv[5]);
}
