STD = -std=c++2a
OPT = -O2
WARN = -Wall -Wextra
GCC = g++ $(OPT) $(STD) $(WARN)
PROGRAM = main

RANDOM = random/uniform
DATA = data/csv_file
FILES = $(RANDOM) $(DATA)

INCLUDE = $(addsuffix .h,$(FILES)) $(addsuffix .h,$(ARGPARSER))
MAIN = main.cpp
SRC = $(addsuffix .cpp,$(FILES)) $(MAIN) $(addsuffix .cpp,$(ARGPARSER))

all: random


random: $(INCLUDE) $(SRC)
	$(GCC) -o $(PROGRAM) $(SRC)


clean:
	rm *.o *.s
