STD = -std=c++2a
OPT = -O3
WARN = -Wall -Wextra
GCC = g++ $(OPT) $(STD) $(WARN)
PROGRAM = main

RANDOM = $(addprefix random/, uniform normal exponential poisson gamma generator chi-square)
DATA = data/csv_file
FILES = $(RANDOM) $(DATA)

INCLUDE = $(addsuffix .h,$(FILES)) $(addsuffix .h,$(ARGPARSER)) random/random.h
MAIN = main.cpp
SRC = $(addsuffix .cpp,$(FILES)) $(MAIN) $(addsuffix .cpp,$(ARGPARSER))

all: random


random: $(INCLUDE) $(SRC)
	$(GCC) -o $(PROGRAM) $(SRC)


clean:
	rm *.o *.s
