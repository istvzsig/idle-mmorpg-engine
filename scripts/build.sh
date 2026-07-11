#!/usr/bin/env bash

set -e

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"

echo "== Configuring IdleMMORPGEngine =="

cmake -S "$ROOT_DIR" -B "$BUILD_DIR"

echo "== Building =="

cmake --build "$BUILD_DIR"

echo "== Build complete =="