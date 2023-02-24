#!/bin/bash

p="Queen Bishop Pawn Rook Knight"

for i in $p
do
    #rm $i.h $i.cpp
    #cp King.h $i.h
    #cp King.cpp $i.cpp
    #sed -i "s/King/$i/g" $i.h
    #sed -i "s/King/$i/g" $i.cpp
    #sed -i "s/KING/$(echo $i | tr "[:lower:]" "[:upper:]")/g" $i.h 
done
