#!/bin/sh
cat Template${2}.txt|sed "s/TEMP/${1}/g" >${1}.java
