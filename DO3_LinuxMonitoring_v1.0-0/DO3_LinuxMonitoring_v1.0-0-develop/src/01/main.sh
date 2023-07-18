#!/bin/bash

REGEX=$(echo $1|grep -E '^-?[[:digit:]]+$')
if [[ $REGEX != "" ]];
    then echo "Ошибка: Число не подходит. Введите строку." >&2; exit 1
else
    echo $1
fi
