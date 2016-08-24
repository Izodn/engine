#! /bin/sh
set -e

APP_NAME="libengine.a"
FILES=(
	"Game.cpp"
	"Window.cpp"
	"InputHandler.cpp"
	"Component.cpp"
	"GameLevel.cpp"
	"GameObject.cpp"
)

COMPILER="g++"
BIN_DIR="./bin"
SRC_DIR="./src"

INCFLAGS=""

LINKFLAGS=""

CFLAGS_DEFAULT="-std=c++14 $INCFLAGS"

# Debug
CFLAGS="$CFLAGS_DEFAULT -g -O0"

# Release
#CFLAGS="$CFLAGS_DEFAULT -O3"

do_compile()
{
	echo "Compiling..."
	for cur in ${FILES[@]}; do
		$COMPILER $CFLAGS -o "$BIN_DIR/$(echo ${cur} | sed -e "s/\//\./g").o" -c "$SRC_DIR/${cur}"
	done
}

do_link()
{
	echo "Linking..."
	ar rvs "./bin/$APP_NAME" $(echo
		for cur in ${FILES[@]}; do
			echo "$BIN_DIR/$(echo ${cur} | sed -e "s/\//\./g").o"
		done
	)
}

main()
{
	mkdir -p $BIN_DIR
	do_compile
	do_link
	echo "Completed"
}

main
