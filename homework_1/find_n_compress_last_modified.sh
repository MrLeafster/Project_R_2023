#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Upotreba: $0 <broj_minuta>"
  exit 1
fi

minutes="$1"

find "/home/$USER" -type f -mmin "-$minutes" -print > files.txt

if [ -s files.txt ]; then
  tar czf backup.tgz -T files.txt
  echo "Pronađene datoteke su komprimirane u backup.tgz."
  rm files.txt
else
  echo "Nema datoteka promijenjenih u zadnjih $minutes minuta u direktoriju $directory."
fi
