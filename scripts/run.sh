#!/usr/bin/env bash

set -e

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
EXECUTABLE="$ROOT_DIR/build/IdleMMORPGEngine"

if [ ! -f "$EXECUTABLE" ]; then
	echo "Executable missing. Building first..."
	"$ROOT_DIR/scripts/build.sh"
fi

echo "== Starting IdleMMORPGEngine =="

cd "$ROOT_DIR"

"$EXECUTABLE"