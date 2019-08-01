#!/bin/bash

echo "Seu pc vai explodir"
#NUM=$($1 $2)
#LISTA=$NUM
#contador=0
#for numero in $LISTA
#do
#  contador=$((contador+1))
#  echo "$contador: $numero"
#  sleep 0.2
#done
#echo "BUM!"

case "$1" in
  -h | --help) echo "Mensagem" ;;
  -V | --version) echo "1.0" ;;
  *) echo "Opção inválida: $1" ;;
esac

pedir_nome() {
  echo -n "Digite seu nome: "
  read NOME
}

pedir_nome
echo "Hi $NOME!"
