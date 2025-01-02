#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b;
        std::cin >> a >> b;

        int result = 1;
        for (int j = 0; j < b; j++) {
            result = (result * a) % 10; // 나머지 계속 계산
        }

        if (result == 0) {
            std::cout << 10 << std::endl; // 마지막 자릿수가 0이면 10 출력
        } else {
            std::cout << result << std::endl;
        }
    }

    return 0;
}