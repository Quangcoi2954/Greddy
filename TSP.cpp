#include <iostream>
#include <vector>
#include <climits> 
#define COL 100
#define ROW 100
using namespace std;

void insertMatrix(int n, int arr[ROW][COL]) 
{
    cout << "Nhap ma tran chi phi: " << endl;
    for(int i = 0; i < n; i++) 
	{
        for(int j = 0; j < n; j++) 
		{
            cout << "a[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}

void TSP(int n, int arr[ROW][COL]) {
    bool flg[n] = {false}; 
    int min = INT_MAX;
    int count = 0;
    
    cout << "Lo trinh: ";
    int i = 0;
    cout << i << " "; 
    flg[i] = true; 
    while(true) 
	{
        min = INT_MAX; 
        int next = -1;
        for(int j = 0; j < n; j++) 
		{
            if(arr[i][j] < min && !flg[j]) 
			{
                min = arr[i][j];
                next = j;
            }
        }
        
        if(next == -1) break; 
        cout << next << " ";
        count += min;
        i = next;
        flg[i] = true; 
    }
//    cout << "0";
//    cout << endl;
//    cout << "Tong chi phi thap nhat: " << count + arr[0][n-1] << endl;
}

int main() 
{
    int n;
    cout << "Nhap so thanh pho: ";
    cin >> n;

    int arr[ROW][COL];

    insertMatrix(n, arr);
    TSP(n, arr);

    return 0;
}
