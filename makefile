CC=x86_64-w64-mingw32-g++-posix



CC_EM=em++

SOURCES := $(shell find src/ -name '*.cpp') $(shell find src/ -name '*.c') $(shell find vendor/TGJGE/src/ -name '*.c') 

CFLAGS=-fpermissive -mwindows -o windows/sbr.exe -std=c++17 -Isrc/ -Ivendor/TGJGE/src/ -Ivendor/TGJGE/vendor/stb/ -Lwindows/lib -Lwindows/ -lopengl32 -lglew32 -lSDL2 -lSDL2main -lSDL2_ttf -Iwindows/include -static-libstdc++ -static-libgcc -Wl,-Bstatic -Wl,--whole-archive -lwinpthread -Wl,--no-whole-archive -pedantic -Wall -lmingw32
windows: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS)
	@mkdir -p windows/assets
	@cp -r assets windows/
	@mkdir -p windows/shaders
	@cp -r vendor/TGJGE/shaders windows/

emscripten: $(SRC)
	$(CC_EM) $(SRC) $(CFLAGS_EM)
