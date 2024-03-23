#include <iostream>
using namespace std;

float mean(float arr[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + arr[i];
	return sum / n;
}

float covariance(float arr1[], float arr2[], int n)
{
	float sum = 0;
	float mean_arr1 = mean(arr1, n);
	float mean_arr2 = mean(arr2, n);
	for (int i = 0; i < n; i++)
		sum = sum + (arr1[i] - mean_arr1) * (arr2[i] - mean_arr2);
	return sum / (n - 1);
}

int main()
{
	float arr1[] = { 65.21, 64.75, 65.26, 65.76, 65.96 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	float arr2[] = { 67.25, 66.39, 66.12, 65.70, 66.64 };
	int m = sizeof(arr2) / sizeof(arr2[0]);
	float CovMat[2][2];
	CovMat[0][0] = covariance(arr1, arr1, m);
	CovMat[0][1] = covariance(arr1, arr2, m);
	CovMat[1][0] = CovMat[1][2];
	CovMat[1][1] = covariance(arr2, arr2, m);

	cout<<"Covariance Matrix : "<<endl;
	cout<<CovMat[0][0]<<"  "<<CovMat[0][1]<<endl<<CovMat[1][0]<<"  "<<CovMat[1][1]<<endl;
	return 0;
}