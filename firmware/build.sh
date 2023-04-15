#!/bin/bash

set -e

BUILD_DIR="build"
BIN_DIR="bin"
DEBUG_FLAG=""
PROJECT_NAME="usb_keypad"

OLD_PWD="$PWD"
cd $PROJECT_ROOT_DIR

function help() {
    echo "Usage: $0 [OPTION]"
    echo "Options:"
    echo "  test    Build and run the tests."
    echo "  clean   Clean the build directory and other generated files."
    echo "  debug   Build the project with debugging symbols."
    echo "  help    Display this help message."
    echo ""
}


DEBUG_FLAG="-DPICOMACHINE_DEBUG_MODE=ON"
CAREFUL_FLAG="-DPICOMACHINE_CAREFUL=ON"
declare -a CMAKE_FLAG_STRS
CMAKE_FLAG_STRS=();

function build_project() {

        CMAKE_FLAG_STRS+="-DCMAKE_BUILD_TYPE=${1}"

    # FIXME: Parse input strings for flags  

    if [ ! -d "$BUILD_DIR" ]; then
        mkdir -p "$BUILD_DIR"
    fi

    # Array of flags to be appended to cmake call 
    cd "$BUILD_DIR"
    cmake  ..
    make

    if [ ! -d "../$BIN_DIR" ]; then
        mkdir -p "../$BIN_DIR"
    fi
    cd ..
}

function clean() {
    rm -rf "$BUILD_DIR" "$BIN_DIR"
}

case "$1" in
    clean)
        clean
        ;;
    debug)
        build_project "Debug"
        ;;
    help)
        help
        ;;
    "")
        build_project "Release"
        cd "$BUILD_DIR"
        mv "$PROJECT_NAME.bin" "$PROJECT_NAME.uf2" \
            "$PROJECT_NAME.hex" "$PROJECT_NAME.elf" "../$BIN_DIR"
        cd ..;
        ;;
    *)
        echo "Invalid option: $1"
        echo "Use '$0 help' for more information."
        exit 1
        ;;
esac

cd $OLD_PWD
