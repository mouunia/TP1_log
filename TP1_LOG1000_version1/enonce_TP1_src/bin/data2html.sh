#!/bin/bash

if [ "$#" -ne "3" ] ; then
  echo "Usage: $0 data input output"
  exit
fi

DATA=$1
INPUT=$2
OUTPUT=$3


#1. D'abord on copie la partie de $INPUT avant la ligne de coupage
LIGNE_COUPAGE=`grep -n -e "===COUPEZ ICI===" $INPUT | cut -f 1 -d :`
head -n $((LIGNE_COUPAGE - 1)) $INPUT > $OUTPUT

#2. On transforme maintenant les titres des champs en HTML
NOMS=`head -n 1 $DATA | perl -pe "s/,/<\/th><th>/g"`
echo "<tr><th>${NOMS}</th></tr>" >> $OUTPUT

#3. Maintenant les donnees sont transformees en HTML
grep -P -v -e "^nom,prenom" $DATA | perl -pe "s/,/<\/td><td>/g" | perl -pe "s/(http:\/\/.*$)/<a href=\"\1\">\1<\/a>/" | perl -pe "s/^(.*)$/<tr><td>\1<\/td><\/tr>/" >> $OUTPUT

#4. On finit avec la partie de $INPUT apres la ligne de coupage
TAILLE_INPUT=`wc -l $INPUT | perl -pe "s/^ *(\d+) +.*$/\1/"`
NR_LIGNES_APRES_COUPAGE=$(( ${TAILLE_INPUT} - ${LIGNE_COUPAGE} ))
tail -n ${NR_LIGNES_APRES_COUPAGE} $INPUT >> $OUTPUT
