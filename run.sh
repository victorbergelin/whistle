cp detector.cpp detector.cpp.bkup
rm dft.csv
touch dft.csv
g++ -o d detector.cpp `pkg-config opencv --cflags --libs`

# g++ -o detector.cpp `pkg-config opencv --cflags --libs`
