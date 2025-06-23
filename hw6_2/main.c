#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

int main(void) {
    char name[256];
    printf("Enter your name: ");
    fflush(stdout);

    if (fgets(name, sizeof(name), stdin) == NULL) {
        name[0] = '\0';
    } else {
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
    }
    if (name[0] == '\0') {
        char *login = getenv("USER");
        if (!login) {
            struct passwd *pw = getpwuid(getuid());
            login = pw ? pw->pw_name : "unknown";
        }
        printf("Hello, %s?\n", login);
    } else {
        printf("Hello, %s!\n", name);
    }
    return 0;
}
