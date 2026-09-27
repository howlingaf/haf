#!/usr/bin/env bash
# On save of any .c file in this tree, build it to bin/<name> and run it.
# Emacs doesn't run this script: its after-save hook reads the prod line below
# and runs `make bin/<name> && ./bin/<name>` itself.
TARGETS=(
    "prod | bin/\$RUN | ./bin/\$RUN"
)
echo "watching $(pwd) for .c saves..."
inotifywait -mrq -e close_write -e moved_to --include '\.c$' --format '%w%f' . |
while read -r f; do
    clear
    RUN=$(basename "$f" .c)
    printf '[%s] %s\n' "$(date +%T)" "$f"
    if make -s "bin/$RUN"; then
        echo "--- running ./bin/$RUN ---"
        "./bin/$RUN"
        echo "--- exit $? ---"
    else
        echo "--- build failed ---"
    fi
done
