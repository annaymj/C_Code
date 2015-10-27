# Files
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))

# Options
CC      := icc
CFLAGS  := -O2
LDFLAGS := -L/lib
LDLIBS := -lm 

# Rules
all: shuffleSequence contigStatistic_SOAP contigStatistic_Velvet clean
shuffleSequence: shuffleSequence.o
	$(CC)  -o $@ $^

contigStatistic_SOAP: contigStatistic_SOAP.o
	$(CC) -o $@ $^

contigStatistic_Velvet: contigStatistic_Velvet.o
	$(CC)  -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) 

# Useful phony targets
.PHONY: clean
clean: 
	$(RM) *.o *.exe
