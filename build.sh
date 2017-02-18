#! /bin/sh
set -e

APP_NAME="engine"

# Linux
OUTPUT_NAME="lib$APP_NAME.so"

# Windows
#OUTPUT_NAME="$APP_NAME.dll"

FILES=(
	# Maths
	"maths/Vector3.cpp"
	"maths/Quaternion.cpp"

	# Generic
	"component/Component.cpp"
	"Game.cpp"
	"GameLevel.cpp"
	"GameObject.cpp"
	"core/Input.cpp"
	"core/Timer.cpp"
	"graphics/Renderer.cpp"

	# OpenGL
	"opengl/OpenGLApplication.cpp"
	"opengl/OpenGLEventHandler.cpp"
	"graphics/opengl/OpenGLRenderer.cpp"
	"graphics/opengl/OpenGLWindow.cpp"
	"graphics/shader/opengl/OpenGLShader.cpp"
	"graphics/shader/opengl/BasicOpenGLShader.cpp"
	"graphics/shader/opengl/TextureOpenGLShader.cpp"

	# Components
	"component/Transform.cpp"

	# Render components
	"component/RenderComponent.cpp"
	"component/FillSquare.cpp"
	"component/TestGL.cpp"
)

COMPILER="g++"
BIN_DIR="./bin"
SRC_DIR="./src"

# Linux
INCFLAGS=""
LINKFLAGS="-Wl,-Bstatic -lSOIL -lGLEW -lglfw3 -Wl,-Bdynamic -lGL -ldl -lXinerama -lXrandr -lXcursor -lX11 -lXxf86vm -lpthread -Wl,--as-needed"

# Windows
#INCFLAGS="-I../libraries"
#LINKFLAGS="-L../libraries/GL -L../libraries/GLFW -L../libraries/SOIL -Wl,-Bstatic -lglew32 -lglfw3 -lSOIL -Wl,-Bdynamic -lopengl32 -lgdi32 -lpthread -Wl,--as-needed"

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
	) -shared $LINKFLAGS -o "./bin/$OUTPUT_NAME"
}

main()
{
	mkdir -p $BIN_DIR
	do_compile
	do_link
	echo "Completed"
}

main
