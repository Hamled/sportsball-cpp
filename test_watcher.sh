#!/usr/bin/env bash

# Create build script
9k build/

# Setup the test watcher
cd build/
fswatch -orl 1 --event 414 -Ee '\.#' ../test/ ../src/ | xargs -n1 -I{} ninja test
