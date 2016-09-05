#include <vector>
#include "utilitaires.h"

using namespace std;


int main(void){

  vector<string> noms;
  lisFichier(noms,"data/noms.txt");

  vector<string> prenoms;
  lisFichier(prenoms,"data/prenoms.txt");

  vector<string> mails;
  lisFichier(mails,"data/mails.txt");

  vector<string> telephones;
  lisFichier(telephones,"data/telephones.txt");

  vector<string> lignes_generees;
  generezLignes(lignes_generees,noms,prenoms,mails,telephones,15);
  ecrivezLignes(lignes_generees,"data.txt");
}
