emcc sdl.cc -s WASM=1 -s FORCE_FILESYSTEM=1 -s USE_SDL=2 --use-preload-plugins --post-js post-script.js -o sdl.html

