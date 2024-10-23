#include <stdio.h>
#include <string.h>

int main() {
    char sup[] = "abcdcdefghijklmn";
    char sub[] = "ccfj";
    int f = 0, ind,c=0;
    int m = strlen(sup), n = strlen(sub);

    for (int i = 0; i <= m - n; i++) {
        if (sup[i] == sub[0]) {
            int k = i;
            int f1 = 0;
            for (int j = 0; j < n; j++) {
                if (sub[j] != sup[k]) {
                    f1 = 1;
                    break;
                }
                k += (j + 2);  // Increment k according to the skip pattern
            }
            if (f1 == 0) {
                f = 1;
                ind = i;
                c++;
                break;
            }
        }
    }
    
    if (f == 1) {
        printf("Sub string matched when multiple chars are skipped at index %d\n", ind);
    } else {
        printf("Sub string doesn't match when multiple char are skipped.\n");
    }

    return 0;
}

