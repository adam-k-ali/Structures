cd build || exit 1
#Clean build directory and recompile
make clean
make all
#Run tests
./tests/DSLib_test