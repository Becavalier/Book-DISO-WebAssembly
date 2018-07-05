emcc sdl.cc -s WASM=1 -s FORCE_FILESYSTEM=1 -s USE_SDL=2 --preload-file hello_sdl.bmp -o sdl.html
