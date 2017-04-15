#include<iostream>
using namespace std;

void sort(int a, int b, int data[]) {
	int temp = data[b];
	for (int i = b; i > a; i--) {
		data[i] = data[i - 1];
	}
	data[a] = temp;
}
int main() {
	int data[15] = { 2,547,51,4,5,15,48,26,15,852,165,75,18,14,16};
	int sizeData = sizeof(data)/sizeof(int);
	cout << "sizedata = " << sizeData << endl;

	int middleNo = (sizeData+1)/2;

	int S = 0;
	int E = sizeData;

	int flag = 0;
	int i = 0;
	while(S + 1 != E) {
		bool sorted = false;
		for (int j = S + 1; j < E; j++) {
			if (data[i] >= data[j]) {
				sort(i, j, data);
				i += 1;
				flag = i + 1;
				sorted = true;
			}
		}

		if (sorted) {
			if (flag < middleNo) {
				S = flag;
				i = S;
			}
			else if (flag > middleNo) {
				E = flag - 1;
				i = S;
			}
		}
		else {
			S += 1;
			i = S;
		}

		

		for (int k = 0; k < sizeData; k++) {
			cout << data[k] << " ";
		}
		cout << endl;
		cout << "S = " << S << " E = " << E <<" data[i] = "<< data[i] << endl;
		system("pause");
	}
	cout << "The middle number is " << data[middleNo-1] << endl;
	system("pause");
	return 0;
}