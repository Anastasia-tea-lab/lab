#!/bin/bash

archive() {
    tar -cf "$1.tar" "$1"
}

folder=$1
max=$2

for file in $folder/*
do
    size=$(wc -c < "$file")
    if ((size > max))
    then
        archive "$file"
    fi
done