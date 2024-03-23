#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static const int SIZE = 1000;

int main(int argc, char** argv) {
    int sharedMemoryID_1, sharedMemoryID_2, sharedMemoryAnswerID, key_1, key_2, answerKey = 512997;
    int *nums_1, *nums_2, *answerNums;

    if (argc < 3) {
        printf("Usage: %s <key 1> <key 2>\n", argv[0]);
        exit(1);
    } else if (!(key_1 = atoi(argv[1])) || !(key_2 = atoi(argv[2]))) {
        printf("Usage: %s <key 1> <key 2> (key is a number)\n", argv[0]);
        exit(1);
    }

    if (((sharedMemoryID_1 = shmget(key_1, SIZE, 0666)) < 0) || ((sharedMemoryID_2 = shmget(key_2, SIZE, 0666)) < 0)) {
        perror("shmget");
        exit(1);
    }

    if (((nums_1 = shmat(sharedMemoryID_1, NULL, 0)) == (int*)-1) || ((nums_2 = shmat(sharedMemoryID_2, NULL, 0)) == (int*)-1)) {
        perror("shmat");
        exit(1);
    }

    if ((sharedMemoryAnswerID = shmget(answerKey, SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((answerNums = shmat(sharedMemoryAnswerID, NULL, 0)) == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    for (int i = 0; i < 100; ++i) {
        answerNums[i] = nums_1[i] + nums_2[i];
    }

    printf("%i\n", answerKey);

    return 0;
}
