# bearden_pa6
2750 Programming Assignment 6

This is a program that creates child processes running concurrently that run a given command (with arguments) from stdin.

It is compiled by "make all" or "make runsim". It is run by ./runsim # - where # is the maximum number of concurrent processes you want to run.

Runsim is packaged with a second program called testsim that can be compiled by "make testsim" or "make all"; as well as a file of sample data called testing.data.

If all 3 programs are in the same directory then you execute by ./runsim # < testing.data