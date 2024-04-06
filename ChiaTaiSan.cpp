#include <iostream>
#include <vector>
#include <string>
using namespace std;

void SapXep(vector<int> &taiSan)
{
    for(int i = 0; i < taiSan.size() - 1; i++)
    {
        if(taiSan[i] > taiSan[i+1])
        {
            int temp = taiSan[i];
            taiSan[i] = taiSan[i+1];
            taiSan[i+1] = temp;
        }
    }
}

void In(vector<int> &taiSan)
{
    for(int i:taiSan)
    {
        cout << i << " ";
    }
}

void ChiaTaiSan(int n, vector<int> &taiSan)
{
    int x;
    cout << "Nhap gia cua tung do choi: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x;
        taiSan.push_back(x);
    }
    
    SapXep(taiSan);
    
    int sumTom = 0;
    int sumAlice = 0;
    vector<int> trai;
    vector<int> phai;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(sumTom <= sumAlice)
        {
            trai.push_back(taiSan[i]); 
            sumTom += taiSan[i];
        }
        else
        {
            phai.push_back(taiSan[i]); 
            sumAlice += taiSan[i];
        }
    }
    
    cout << "Tom nhan duoc do choi co gia tri: ";
    In(trai);
    cout << endl;
    cout << "Alice nhan duoc do choi co gia tri: ";
    In(phai);
}

int main()
{
    int n;
    cout << "Nhap so do choi : ";
    cin >> n;
    
    vector<int> taiSan;
    ChiaTaiSan(n, taiSan);
    
    return 0;
}
