#include<stdio.h>

id merge_sort (int A[], int l, int r, int O[]) {
	if (l < r) {
		int m = (l + r)/2;
		merge_sort (A, l, m, O);
		merge_sort (A, m+1, r, O); 
		merge (A, l, m, r, O);
	}
}


}

}
