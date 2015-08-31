#!/bin/bash

g++ -c src/Base/Agents/Agent.cc -o Agent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/NetworkAgent.cc -o NetworkAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/MemoryAgent.cc -o MemoryAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/DiskAgent.cc -o DiskAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/IdentificationAgent.cc -o IdentificationAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/ExtendedAgent.cc -o ExtendedAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/Agents/FileSystemAgent.cc -o FileSystemAgent.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi

g++ -c src/Base/DataTypes/ExtendedInformation.cc -o ExtendedInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/FileInformation.cc -o FileInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/MountInformation.cc -o MountInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/MountType.cc -o MountType.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/OptionalField.cc -o OptionalField.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/DiskInformation.cc -o DiskInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/IdentificationInformation.cc -o IdentificationInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
g++ -c src/Base/DataTypes/MemoryInformation.cc -o MemoryInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi

g++ src/main.cc -o main Agent.o NetworkAgent.o MemoryAgent.o DiskAgent.o IdentificationAgent.o ExtendedAgent.o FileSystemAgent.o ExtendedInformation.o FileInformation.o MountInformation.o MountType.o OptionalField.o DiskInformation.o IdentificationInformation.o MemoryInformation.o -std=c++11 -Wall -Werror -Wextra -pedantic -ansi
