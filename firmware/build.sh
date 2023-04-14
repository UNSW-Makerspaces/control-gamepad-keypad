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

function build_project() {
    if [ ! -d "$BUILD_DIR" ]; then
        mkdir "$BUILD_DIR"
    fi

    cd "$BUILD_DIR"
    cmake -DCMAKE_BUILD_TYPE="$1" ..
    make

    if [ "$1" == "Debug" ]; then
        DEBUG_FLAG="_debug"
        #cmake -DPICOMACHINE_DEBUG_MODE=ON ..
    fi

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
        mv "$PROJECT_NAME.bin" "$PROJECT_NAME.uf2" "$PROJECT_NAME.hex" "$PROJECT_NAME.elf" "../$BIN_DIR"
        cd ..;
        ;;
    *)
        echo "Invalid option: $1"
        echo "Use '$0 help' for more information."
        exit 1
        ;;
esac

cd $OLD_PWD
