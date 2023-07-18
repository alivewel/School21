#!/bin/bash

if [ $(echo $1 | grep -E '^([1-6]$)') ] &&
   [ $(echo $2 | grep -E '^([1-6]$)') ] &&
   [ $(echo $3 | grep -E '^([1-6]$)') ] &&
   [ $(echo $4 | grep -E '^([1-6]$)') ]
    then
    if [ $1 -ne $2 ] && [ $3 -ne $4 ]
    then
        . ./colors.sh $1 $2 $3 $4
    else
        read -p "Цвета фона и текста совпадают. Запустить скрипт снова? y/n " answer
        if [ $answer = 'y' ]
        then
            read -p "Введите новые цвета " color1 color2 color3 color4
            sh main.sh $color1 $color2 $color3 $color4
        else
            echo
        fi
    fi
fi
