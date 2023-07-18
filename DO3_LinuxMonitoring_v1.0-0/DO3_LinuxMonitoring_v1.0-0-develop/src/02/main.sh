#!/bin/bash

. ./info.sh
read -p "Записать данные в файл? y/n " answer

if [ $answer = 'y' ]
then
. ./info.sh >> "$(date +"%d_%m_%Y_%H_%M_%S")".status
fi
