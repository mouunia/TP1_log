#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include <vector>
#include <string>

void lisFichier(std::vector<std::string>& v,const std::string& fNom);

std::string ligneArbitraire(const std::vector<std::string>& lignes);

void generezLignes(std::vector<std::string>& lignes_generees,const std::vector<std::string>& noms,const std::vector<std::string>& prenoms,const std::vector<std::string>& cours,const std::vector<std::string>& sites,int nr);

void ecrivezLignes(const std::vector<std::string>& lignes_generees,const std::string& fNom);

// bool estDuplicat(const string& first, const string& second);
#endif
