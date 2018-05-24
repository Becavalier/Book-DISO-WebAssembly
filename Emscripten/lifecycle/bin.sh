#!/bin/bash
emcc lifecycle.cc -s WASM=1 -o lifecycle.html --post-js post-script.js -s NO_EXIT_RUNTIME=0
