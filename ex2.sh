#!/bin/bash
lockfile -r 0 /tmp/the.lock || exit 1
printf '0\n' > ex2.txt
for i in {0..1000}
do
OUT=$(tail -n 1 < ex2.txt)
((OUT++)) //critical region
echo "$OUT" >> ex2.txt
done
rm -f /tmp/the.lock

//race condition manifested starting from the fist appended digit
//the race condition is prevented by locking the file< thus the the script will not run if it is already running
