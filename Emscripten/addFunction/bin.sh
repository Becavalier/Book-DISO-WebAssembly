#!/bin/bash

emcc addFunction.cc --std=c++11 -s WASM=1 -s RESERVED_FUNCTION_POINTERS=20 -s EXTRA_EXPORTED_RUNTIME_METHODS='["addFunction", "removeFunction"]' -o addFunction.html --post-js post-script.js

