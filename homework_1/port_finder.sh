#!/bin/bash

if [ "$#" -ne 2 ]; then
  echo "Upotreba: $0 <IP_adresa> <port>"
  exit 1
fi

ip_address="$1"
port="$2"

if ! command -v nc &> /dev/null; then
  echo "Netcat (nc) nije instaliran. Molimo instalirajte ga prije korištenja ovog alata."
  exit 1
fi

nc -z -v -w 5 "$ip_address" "$port"

if [ $? -eq 0 ]; then
  echo "Port $port je otvoren na IP adresi $ip_address."
else
  echo "Port $port nije otvoren na IP adresi $ip_address."
fi
