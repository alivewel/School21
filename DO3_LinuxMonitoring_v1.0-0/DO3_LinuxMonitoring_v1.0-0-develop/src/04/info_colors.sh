#!/bin/bash

echo
if [ $colors_default ]
then
echo "column1_background = default ($COLUMN1_BACK_INFO)"
echo "column1_font_color = default ($COLUMN1_FONT_INFO)"
echo "column2_background = default ($COLUMN2_BACK_INFO)"
echo "column2_font_color = default ($COLUMN2_FONT_INFO)"
else
echo "column1_background = $column1_background ($COLUMN1_BACK_INFO)"
echo "column1_font_color = $column1_font_color ($COLUMN1_FONT_INFO)"
echo "column2_background = $column2_background ($COLUMN2_BACK_INFO)"
echo "column2_font_color = $column2_font_color ($COLUMN2_FONT_INFO)"
fi
