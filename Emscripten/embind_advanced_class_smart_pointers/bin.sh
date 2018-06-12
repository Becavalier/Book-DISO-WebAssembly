#!/bin/bash

emcc --bind -o embind_advanced_class_smart_pointers.html embind_advanced_class_smart_pointers.cc -s EXTRA_EXPORTED_RUNTIME_METHODS="['getValue']" -s WASM=1 --post-js post-script.js

