#include <stdio.h>
int main() {
    int t = 5;
    printf("#include <stdio.h>\nint main() { while (true) { printf(\"");
    while (t--) {
        printf("#include <stdio.h>\\nint main() { while (true) { printf(\\\"");
    }
}
