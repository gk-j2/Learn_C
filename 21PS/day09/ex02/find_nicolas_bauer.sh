#!/bin/sh
cat $1 | grep -i "nicolas\tbauer" | rev | awk '{print $2}' | rev 
