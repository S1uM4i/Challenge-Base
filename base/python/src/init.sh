#!/bin/sh

echo $GZCTF_FLAG > /home/ctf/flag
unset GZCTF_FLAG

socat TCP-LISTEN:70,reuseaddr,fork EXEC:/run.sh,stderr
