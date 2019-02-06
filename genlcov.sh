#!/bin/sh

LCOV=lcov
GENHTML=genhtml

SRC_DIR="/home/veto/build-testing-Desktop-Debug"
HTML_RESULTS="/home/veto/build-testing-Desktop-Debug/html"

mkdir -p ${HTML_RESULTS}

# generate our initial info
"${LCOV}" -d "${SRC_DIR}" -c -o "${SRC_DIR}/coverage.info"

# remove some paths
"${LCOV}" -r "${SRC_DIR}/coverage.info" "*Qt*" "*bits*" "*.moc" "*moc_*.cpp"  -o "${SRC_DIR}/coverage-filtered.info"

# generate our HTML
"${GENHTML}" -o "${HTML_RESULTS}" "${SRC_DIR}/coverage-filtered.info"

# reset our counts
"${LCOV}" -d "${SRC_DIR}" -z
