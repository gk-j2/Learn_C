#!/bin/sh
cat /etc/passwd | grep -v '#'| awk '(NR%2)' | tr ':' ' ' | awk '{print $1}' | rev | sort -r | sed  '2,4p'  | paste -s -d"," - | sed 's/,/, /g' | sed 's/$/./'  
