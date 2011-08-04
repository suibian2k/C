#!/bin/bash

dir='/home/'`whoami`'/Trash/'`date +%x`;
file="$1"'_'`date +%X`

if [ ! -e $dir  ]; then
     mkdir -p -m 755 $dir 
fi
mv  $1 $file
mv  $file $dir
