#!/usr/bin/env bash
./a.out_03_FLOW_b &
#echo $!
sleep 1.5
kill -USR1 $!
sleep 1.3
kill -USR1 $!
sleep 1.1
kill -USR1 $!
#echo ...
kill -USR1 $!
#sleep 1.7
#kill -USR1 $!
#kill -USR1 $!

