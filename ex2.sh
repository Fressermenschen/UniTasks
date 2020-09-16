#!/bin/bash
printf '0\n' > ex2.txt
while(true)
do
OUT=$(tail -n 1 < ex2.txt)
((OUT++)) //critical region
echo "$OUT" >> ex2.txt
done

//race condition manifested starting from the fist appended digit
