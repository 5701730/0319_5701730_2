#include <stdio.h>
#include <time.h>

double power_liter(double x, int n) {//반복 함수를 이용 정수 반환 하니깐 값이 출력이 안됨 double로 변경
    int i;
    double result = 1;
    for (i = 0; i < n; i++)
        result = result * x;
    return result;
}

double power_rec(double x, int n) {//재귀 함수를 이용
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_rec(x * x, n / 2);
    else
        return x * power_rec(x * x, (n - 1) / 2);
}

int main(int argc, char* argv[]) {
    clock_t start, end;
    start = clock();
    double result_liter = power_liter(13, 21);
    end = clock();
    printf("Power Iterative Result: %lf\n", result_liter);
    printf("Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock(); // 시간 측정을 위해 start 변수 재사용
    double result_rec = power_rec(13, 21);
    end = clock();
    printf("Power Recursive Result: %lf\n", result_rec);
    printf("Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}