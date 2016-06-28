cp detector.c detector.c.bkup
g++ -o d detector.c `pkg-config opencv --cflags --libs`

# g++ -o detector.cpp `pkg-config opencv --cflags --libs`
