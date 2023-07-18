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

if [ $column1_background -eq 1 ]
then
COLUMN1_BACK=${WHITE_BACK}
COLUMN1_BACK_INFO="white"
elif [ $column1_background -eq 2 ]
then
COLUMN1_BACK=${RED_BACK}
COLUMN1_BACK_INFO="red"
elif [ $column1_background -eq 3 ]
then
COLUMN1_BACK=${GREEN_BACK}
COLUMN1_BACK_INFO="green"
elif [ $column1_background -eq 4 ]
then
COLUMN1_BACK=${BLUE_BACK}
COLUMN1_BACK_INFO="blue"
elif [ $column1_background -eq 5 ]
then
COLUMN1_BACK=${PURPLE_BACK}
COLUMN1_BACK_INFO="purple"
elif [ $column1_background -eq 6 ]
then
COLUMN1_BACK=${BLACK_BACK}
COLUMN1_BACK_INFO="black"
fi

if [ $column1_font_color -eq 1 ]
then
COLUMN1_FONT=${WHITE}
COLUMN1_FONT_INFO="white"
elif [ $column1_font_color -eq 2 ]
then
COLUMN1_FONT=${RED}
COLUMN1_FONT_INFO="red"
elif [ $column1_font_color -eq 3 ]
then
COLUMN1_FONT=${GREEN}
COLUMN1_FONT_INFO="green"
elif [ $column1_font_color -eq 4 ]
then
COLUMN1_FONT=${BLUE}
COLUMN1_FONT_INFO="blue"
elif [ $column1_font_color -eq 5 ]
then
COLUMN1_FONT=${PURPLE}
COLUMN1_FONT_INFO="purple"
elif [ $column1_font_color -eq 6 ]
then
COLUMN1_FONT=${BLACK}
COLUMN1_FONT_INFO="black"
fi

if [ $column2_background -eq 1 ]
then
COLUMN2_BACK=${WHITE_BACK}
COLUMN2_BACK_INFO="white"
elif [ $column2_background -eq 2 ]
then
COLUMN2_BACK=${RED_BACK}
COLUMN2_BACK_INFO="red"
elif [ $column2_background -eq 3 ]
then
COLUMN2_BACK=${GREEN_BACK}
COLUMN2_BACK_INFO="green"
elif [ $column2_background -eq 4 ]
then
COLUMN2_BACK=${BLUE_BACK}
COLUMN2_BACK_INFO="blue"
elif [ $column2_background -eq 5 ]
then
COLUMN2_BACK=${PURPLE_BACK}
COLUMN2_BACK_INFO="purple"
elif [ $column2_background -eq 6 ]
then
COLUMN2_BACK=${BLACK_BACK}
COLUMN2_BACK_INFO="black"
fi

if [ $column2_font_color -eq 1 ]
then
COLUMN2_FONT=${WHITE}
COLUMN2_FONT_INFO="white"
elif [ $column2_font_color -eq 2 ]
then
COLUMN2_FONT=${RED}
COLUMN2_FONT_INFO="red"
elif [ $column2_font_color -eq 3 ]
then
COLUMN2_FONT=${GREEN}
COLUMN2_FONT_INFO="green"
elif [ $column2_font_color -eq 4 ]
then
COLUMN2_FONT=${BLUE}
COLUMN2_FONT_INFO="blue"
elif [ $column2_font_color -eq 5 ]
then
COLUMN2_FONT=${PURPLE}
COLUMN2_FONT_INFO="purple"
elif [ $column2_font_color -eq 6 ]
then
COLUMN2_FONT=${BLACK}
COLUMN2_FONT_INFO="black"
fi
