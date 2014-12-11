CommercialMan
=============


## Emscripten 
From the top level folder, run the following command to generate an Emscripten build. (Tested with emcc 1.27.0)

`emcc --preload-file ./sounds/ --preload-file ./images/ -std=c++11 -O2 -I ~/emscripten/include/SDL2/ src/*.cc ~/emscripten/lib/libSDL2.a ~/emscripten/lib/libSDL2_image.a ~/emscripten/lib/libSDL2_gfx.a -o CommercialMan.html`
