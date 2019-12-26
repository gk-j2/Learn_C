#!/bin/sh
touch -A -000001-a bomb.txt
stat -s bomb.txt | cut -c111- | rev | cut -c104- | rev
