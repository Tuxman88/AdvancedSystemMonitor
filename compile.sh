#!/bin/bash

g++ -c src/Base/Agents/Agent.cc -o Agent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/NetworkAgent.cc -o NetworkAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ src/main.cc -o main CommandManager.o Agent.o NetworkAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
