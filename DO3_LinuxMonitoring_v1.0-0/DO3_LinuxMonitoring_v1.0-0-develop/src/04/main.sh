#!/bin/bash

. ./config

if [ $(echo $column1_background | grep -E '^([1-6]$)') ] &&
   [ $(echo $column1_font_color | grep -E '^([1-6]$)') ] &&
   [ $(echo $column2_background | grep -E '^([1-6]$)') ] &&
   [ $(echo $column2_font_color | grep -E '^([1-6]$)') ]
    then
    if [ $column1_background -ne $column1_font_color ] && [ $column2_background -ne $column2_font_color ]
    then
        . ./colors.sh
        . ./info.sh
        . ./info_colors.sh
    else
        #echo "Цвета в конфигурационном файле не заданы, используются цвета по умолчанию"
        . ./default_colors
        . ./colors.sh
        . ./info.sh
        . ./info_colors.sh
    fi
fi
