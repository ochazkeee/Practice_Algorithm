#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    char S[11];

    int index;
    char Answer[11];
    int cnt = 0;
    scanf("%d %s",&N,S);
    getchar();

    char **Nickname = (char**)malloc(N*sizeof(char*));
    for (int i = 0; i < N; i++) {
        Nickname[i] = (char*)malloc(11*sizeof(char));
    }

    char **Chat = (char**)malloc(N*sizeof(char*));
    for (int i = 0; i < N; i++) {
        Chat[i] = (char*)malloc(11*sizeof(char));
    }

    for (int i = 0; i < N; i++) {
        scanf("%s %s",Nickname[i],Chat[i]);

        if (strcmp(S, Nickname[i]) == 0) {
            index = i;
            strcpy(Answer,Chat[i]);
            break;
        }
    }


    for (int i = 0; i< index; i++ ) {
        if (strcmp(Answer,Chat[i]) == 0) {
            cnt++;
        }
    }

    printf("%d",cnt);

    for (int i = 0; i < N; i++) {
        free(Nickname[i]);
        free(Chat[i]);
    }
    free(Nickname);
    free(Chat);
    return 0;
}