cp detector.cpp detector.cpp.bkup
g++ -o d detector.cpp `pkg-config opencv --cflags --libs`

# g++ -o detector.cpp `pkg-config opencv --cflags --libs`
