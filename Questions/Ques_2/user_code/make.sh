#   -std=c99 is used to specify the version of C language 
#   -O3 is used to specify the optimization level
#   -march=native is used to specify the architecture
#   -o is used to specify the output file
#   -c is used to compile the source files without linking
#   -lm is used to link math library
#   -strip is used to remove unnecessary information from executable files
#   if file is not executable, run chmod +x make.sh

mkdir -p build

rm *.png

# Compile library code files
gcc -c lib/pbPlots.c -std=c99 -O3 -march=native -o build/pbPlots.o
gcc -c lib/supportLib.c -std=c99 -O0 -march=native -o build/supportLib.o


# Compile utility code files
gcc -c util/util.c -std=c99 -O0 -march=native -o build/util.o

# Compile user code files 
gcc -c main.c -std=c99 -O0 -march=native -o build/main.o

# Link all object files : -lm is used to link math library
gcc build/main.o build/util.o build/pbPlots.o build/supportLib.o -lm -o out

# strip is a command that removes unnecessary information from executable files, making them smaller.
strip out

# # Run the executable
# ./out