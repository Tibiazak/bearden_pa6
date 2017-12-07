# bearden_pa6
2750 Programming Assignment 6

This is a program that creates child processes running concurrently that run a given command (with arguments) from stdin.

It is compiled by "make all" or "make runsim". It is run by ./runsim # - where # is the maximum number of concurrent processes you want to run.

Runsim is packaged with a second program called testsim that can be compiled by "make testsim" or "make all"; as well as a file of sample data called testing.data.

If all 3 programs are in the same directory then you execute by ./runsim # < testing.data

Note: The command line arguments for the program to be executed are currently limited to 2, which can be changed by editing the constant MAX_ARG in runsim.c - it should be set to 1 more than the max number of command line arguments you want to use. (2 args, set constant to 3.)