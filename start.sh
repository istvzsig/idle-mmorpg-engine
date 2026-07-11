#!/usr/bin/env bash

set -e

PROJECT_ROOT="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
BINARY="$BUILD_DIR/IdleMMORPGEngine"

echo "================================"
echo "   Idle MMORPG Engine"
echo "================================"

cd "$PROJECT_ROOT"

if [ ! -f "$BUILD_DIR/CMakeCache.txt" ]; then
    echo "[INFO] Configuring CMake..."
    cmake -S . -B build
fi

echo "[INFO] Building..."
cmake --build build

if [ ! -f "$BINARY" ]; then
    echo "[ERROR] Binary not found: $BINARY"
    exit 1
fi

echo "[INFO] Starting game..."
echo ""

"$BINARY"