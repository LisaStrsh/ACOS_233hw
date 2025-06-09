#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rep(const char *text, const char *pt, const char *repl) {
    size_t len_text = strlen(text);
    size_t len_pattern = strlen(pt);
    size_t len_repl = strlen(repl);
    size_t bufsize = len_text + 1;
    char *result = malloc(bufsize);
    if (!result) return NULL;

    const char *pos = text;
    size_t offset = 0;

    while (*pos) {
        const char *match = strstr(pos, pt);
        if (!match) {
            size_t remain = strlen(pos);
            if (offset + remain + 1 > bufsize) {
                bufsize = offset + remain + 1;
                result = realloc(result, bufsize);
            }
            strcpy(result + offset, pos);
            break;
        }

        size_t before = match - pos;
        if (offset + before + len_repl + 1 > bufsize) {
            bufsize = offset + before + len_repl + 1;
            result = realloc(result, bufsize);
        }
        strncpy(result + offset, pos, before);
        offset += before;

        strcpy(result + offset, repl);
        offset += len_repl;

        pos = match + len_pattern;
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <pt> <text> <repl>\n", argv[0]);
        return 1;
    }

    char *result = rep(argv[2], argv[1], argv[3]);
    if (!result) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("%s\n", result);
    free(result);
    return 0;
}
