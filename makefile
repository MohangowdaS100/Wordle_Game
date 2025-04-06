# Default rule to build the target
all: wordle

# Link object files to create the executable (-c to generate object file)
wordle: Wordle_final.c 
	gcc -c -Wall Wordle_final.c  -o wordle_object.o
	gcc -Wall Wordle_final.c  -o wordle_exe


# clean up build files
clean: 
	rm -f wordle_object.o wordle_exe