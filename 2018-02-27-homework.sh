#!/bin/bash

### 1
questao01(){
  LISTA=$(cut --delimiter=':' -f1 /etc/passwd | sort)
}

### 2
questao02(){
  if grep -qsw "$1" /etc/passwd
  then
    echo "Usuário existe no sistema"
  else
    echo "Usuário não existe no sistema"
  fi
}

### 3
questao03(){
  ps -ax | sed 1d | grep -w $PROCESS | sed -n "s/ *//p" | cut -d' ' -f 1
  #pgrep -l $PROCESS  ## Forma alternativa
}

### 4
questao04(){
  while true
  do
    echo "(1) - Exibir status da utilização das partições do sistema;"
    echo "(2) - Exibir relação de usuários logados;"
    echo "(3) - Exibir data e hora;"
    echo "(4) - Sair."
    echo "Informe sua opção:"
    read NUM
    echo
    case "$NUM" in
      1) df -h ;;
      2) who ;;
      3) date ;;
      4) break ;;
      *) echo "Opção Inválida!" ;;
    esac
    echo
  done
}

# ## Questão 01;
# echo "QUESTÃO 01!"
# questao01
# echo $LISTA
# echo

# ## Questão 02;
# echo "QUESTÃO 02!"
# echo "Informe o usuário"
# read NOME
# questao02 $NOME
# echo

# ## Questão 03;
# echo "QUESTÃO 03!"
# echo "Informe o Processo"
# read PROCESS
# questao03 $PROCESS
# echo

# ## Questão 04;
# echo "QUESTÃO 04!"
# questao04
# echo

while true
do
  echo "(1) - Questão 01"
  echo "(2) - Questão 02"
  echo "(3) - Questão 03"
  echo "(4) - Questão 04"
  echo "(5) - Sair"
  echo "Informe a opção: "
  read OPTION
  echo
  case "$OPTION" in
    1) questao01; echo $LISTA ;;
    2) echo "Informe o usuário"; read NOME; questao02 $NOME ;;
    3) echo "Informe o Processo"; read PROCESS; questao03 $PROCESS ;;
    4) questao04 ;;
    5) break ;;
    *) echo "Opção Inválida!"
  esac
  echo
done
