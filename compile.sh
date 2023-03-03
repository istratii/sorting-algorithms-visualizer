
#!/bin/sh

BUILD_DIR=build

if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi

cmake -S . -B "$BUILD_DIR"
cd "$BUILD_DIR"
make
cd ..