#!/usr/bin/env bash

set -e

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"

echo "Removing build directory..."

rm -rf "$ROOT_DIR/build"

echo "Clean complete"