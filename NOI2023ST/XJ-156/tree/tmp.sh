#!/bin/bash

id=$1;

echo $id;

cp tree${id}.in tree.in
cp tree${id}.ans tree.ans

time ./tree.run
./judge.run

diff -b tree.ans tree.out
