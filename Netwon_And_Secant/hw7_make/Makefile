# Files
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))

# Options
CC      := icc
CFLAGS  := -O2
LDFLAGS := -L$$TACC_MKL_LIB -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread
LDLIBS := -L/lib 
# Rules
all: secant newton1 newton2 newton3
secant: hw7_secant.o
	$(CC)  -o $@ $^

newton1: hw7_newton1.o
	$(CC)  -o $@ $^

newton2: hw7_newton2.o
	$(CC)  -o $@ $^

newton3: hw7_newton3.o
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) 

# Useful phony targets
.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat:
	$(RM) *.o *.exe
echo:
	@echo $(OBJ)
