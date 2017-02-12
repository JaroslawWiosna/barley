# Barley

## How to clone repository

```
$ git clone https://github.com/JaroslawWiosna/barley.git 
$ git submodule init
$ git submodule update
```

Stl files are quite large, so they are kept in another repository `barleyKernels`. In order to clone mentioned files the `git submodule $$$` commands are essential.

## How to compile and run

```
$ mkdir -p build
$ cd build
$ cmake ..
$ cmake --build . 
$ ./Barley ../barleyKernels/001.stl
```

Instead of `cmake --build .`, one can simply type `make`

