#!/bin/sh
find "${MESON_SOURCE_ROOT}/src/" -iname *.h -o -iname *.c -not -path "${MESON_SOURCE_ROOT}/src/libs/*" | xargs clang-tidy --checks=readability-* -p "${MESON_BUILD_ROOT}"/compile_commands.json
