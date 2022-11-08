clang++ $1.cpp -o $1 `pkg-config --cflags --libs opencv4` -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lnppif -lcudart -lnpps -lrt -ldl -lnppig -lnppidei -lpthread -lnppicc
./$1
