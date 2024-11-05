#include <stdio.h>
#include <math.h>

double shi(double x) {
	double y;
	y = 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
	return y;
}

int main() {
	int T, i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		double y;
		scanf("%lf", &y);
		if (y > shi(100) || y < shi(0))
			printf("No solution!\n");
		else {
			double left = 0, right = 100, mid;
			while (right - left > 1e-8) {
				mid = (right + left) / 2;
				if (shi(mid ) > y) {
					right = mid;
				} else if (shi(mid ) < y)
					left = mid;
				else if (shi(mid ) == y) {
					break;
				}
			}
			printf("%.4f\n", mid);
		}
	}

	return 0;
}
