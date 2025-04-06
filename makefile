# Default rule to build the target
all: wordle

# Link object files to create the executable (-c to generate object file)
wordle: Wordle_final.c 
	gcc -c Wordle_final.c  -o wordle_object 
	gcc  Wordle_final.c  -o wordle_exe


# clean up build files
clean: 
	rm -f wordle