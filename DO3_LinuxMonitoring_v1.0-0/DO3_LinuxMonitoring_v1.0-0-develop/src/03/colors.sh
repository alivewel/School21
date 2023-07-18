#!/bin/bash

WHITE="\033[97m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
PURPLE="\033[35m"
BLACK="\033[30m"
WHITE_BACK="\033[107m"
RED_BACK="\033[41m"
GREEN_BACK="\033[42m"
BLUE_BACK="\033[44m"
PURPLE_BACK="\033[45m"
BLACK_BACK="\033[40m"
ENDCOLOR="\033[0m"

if [ $1 -eq 1 ]
then
COLUMN1_BACK=${WHITE_BACK}
elif [ $1 -eq 2 ]
then
COLUMN1_BACK=${RED_BACK}
elif [ $1 -eq 3 ]
then
COLUMN1_BACK=${GREEN_BACK}
elif [ $1 -eq 4 ]
then
COLUMN1_BACK=${BLUE_BACK}
elif [ $1 -eq 5 ]
then
COLUMN1_BACK=${PURPLE_BACK}
elif [ $1 -eq 6 ]
then
COLUMN1_BACK=${BLACK_BACK}
fi

if [ $2 -eq 1 ]
then
COLUMN1_FONT=${WHITE}
elif [ $2 -eq 2 ]
then
COLUMN1_FONT=${RED}
elif [ $2 -eq 3 ]
then
COLUMN1_FONT=${GREEN}
elif [ $2 -eq 4 ]
then
COLUMN1_FONT=${BLUE}
elif [ $2 -eq 5 ]
then
COLUMN1_FONT=${PURPLE}
elif [ $2 -eq 6 ]
then
COLUMN1_FONT=${BLACK}
fi

if [ $3 -eq 1 ]
then
COLUMN2_BACK=${WHITE_BACK}
elif [ $3 -eq 2 ]
then
COLUMN2_BACK=${RED_BACK}
elif [ $3 -eq 3 ]
then
COLUMN2_BACK=${GREEN_BACK}
elif [ $3 -eq 4 ]
then
COLUMN2_BACK=${BLUE_BACK}
elif [ $3 -eq 5 ]
then
COLUMN2_BACK=${PURPLE_BACK}
elif [ $3 -eq 6 ]
then
COLUMN2_BACK=${BLACK_BACK}
fi

if [ $4 -eq 1 ]
then
COLUMN2_FONT=${WHITE}
elif [ $4 -eq 2 ]
then
COLUMN2_FONT=${RED}
elif [ $4 -eq 3 ]
then
COLUMN2_FONT=${GREEN}
elif [ $4 -eq 4 ]
then
COLUMN2_FONT=${BLUE}
elif [ $4 -eq 5 ]
then
COLUMN2_FONT=${PURPLE}
elif [ $4 -eq 6 ]
then
COLUMN2_FONT=${BLACK}
fi

. ./info.sh
