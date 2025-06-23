#!/bin/sh

sum() {
    s=0
    err=0
    for arg in "$@"; do
        res=$(expr "$s" + "$arg" 2>/dev/null)
        status=$?
        if [ $status -ne 0 ]; then
            err=1
        else
            s=$res
        fi
    done

    if [ $err -ne 0 ]; then
        echo 0
    else
        echo $s
    fi
}

read -r line1
read -r line2

set -- $line1
r1=$(sum "$@")
set -- $line2
r2=$(sum "$@")

if [ "$r1" -eq "$r2" ]; then
    echo Equal
else
    echo Not equal
fi
