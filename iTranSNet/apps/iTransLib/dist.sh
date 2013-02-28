#!/bin/sh
cat $1|awk '{if ($3=="cpu") printf("%s\n",$5);}'
echo ""
cat $1|awk '{if ($3=="radio") printf("%s\n",$5);}'
echo ""
cat $1|awk '{if ($3=="leds") printf("%s\n",$5);}'
echo ""
cat $1|awk '{if ($3=="Total") printf("%s\n",$5);}'
