
#!/bin/sh

BUILD_DIR=build

if [ -d "$BUILD_DIR" ]; then
  cd "$BUILD_DIR"
  make clean
  cd ..
  rm -rf "$BUILD_DIR"
fi