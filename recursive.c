# include <stdio.h>

int a[500] = { 0, 1, 1 };

int find(int n) {
	for(int i = 3 ; i <= n ; i++) {
		a[i] = a[a[i-1]] + a[i-a[i-1]];
	}
	return a[n];
}

int main() {
	
	printf("%d", find(450));
	
	return 0;
}
