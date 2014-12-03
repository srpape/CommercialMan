CommercialMan
=============


## Emscripten 
From the top level folder, run the following command to generate an Emscripten build. (Tested with emcc 1.27.0)

`emcc -O3 -std=c++11 --preload-file ./images -s USE_SDL=2 -s USE_SDL_IMAGE=2 src/*.cc -o CommercialMan.html`
