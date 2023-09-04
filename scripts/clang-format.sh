#!/bin/sh
find "${MESON_SOURCE_ROOT}/src/" -iname *.h -o -iname *.c -not -path "${MESON_SOURCE_ROOT}/src/libs/*" | xargs clang-format -i
