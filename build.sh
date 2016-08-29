#! /bin/sh
set -e

APP_NAME="engine"
FILES=(
	"Timer.cpp"
	"Game.cpp"
	"OpenGLRenderer.cpp"
	"Window.cpp"
	"InputHandler.cpp"
	"Component.cpp"
	"GameLevel.cpp"
	"GameObject.cpp"
)

COMPILER="g++"
BIN_DIR="./bin"
SRC_DIR="./src"

# Linux
INCFLAGS=""
LINKFLAGS="-Wl,-Bstatic -lGLEW -lglfw3 -Wl,-Bdynamic -lGL -ldl -lXinerama -lXrandr -lXcursor -lX11 -lXxf86vm -lpthread -Wl,--as-needed"

# Windows
#INCFLAGS=""
#LINKFLAGS=""

CFLAGS_DEFAULT="-std=c++14 $INCFLAGS"

# Debug
CFLAGS="$CFLAGS_DEFAULT -g -O0"

# Release
#CFLAGS="$CFLAGS_DEFAULT -O3"

do_compile()
{
	echo "Compiling..."
	for cur in ${FILES[@]}; do
		$COMPILER $CFLAGS -c -fPIC "$SRC_DIR/${cur}" -o "$BIN_DIR/$(echo ${cur} | sed -e "s/\//\./g").o"
	done
}

do_link()
{
	echo "Linking..."
	$COMPILER $(echo
		for cur in ${FILES[@]}; do
			echo "$BIN_DIR/$(echo ${cur} | sed -e "s/\//\./g").o"
		done
	) -shared $LINKFLAGS -o "./bin/lib$APP_NAME.so"
}

main()
{
	mkdir -p $BIN_DIR
	do_compile
	do_link
	echo "Completed"
}

main
