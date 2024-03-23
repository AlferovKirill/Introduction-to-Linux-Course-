#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int (*someSecretFunctionPrototype)(int);

bool initDL(const char *dlName, const char *functionName) {
    void *hdl = dlopen(dlName, RTLD_LAZY);

    if (hdl == NULL) {
        return false;
    } else {
        someSecretFunctionPrototype = (int (*)(int))dlsym(hdl, functionName);

        if (someSecretFunctionPrototype == NULL) {
            return false;
        }

        return true;
    }
}

int main(int argCount, char **argValues) {
    if (initDL(argValues[1], argValues[2])) {
        printf("%d\n", someSecretFunctionPrototype(atoi(argValues[3])));
    } else {
        printf("Error! Library was not found.\n");
    }

    return 0;
}
