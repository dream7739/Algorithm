

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 24. 이분탐색
int main() {
    int n = 0, key, i, lt=0, mid, rt ;
    //배열 크기 및 탐색할 값 입력
    scanf("%d %d", &n, &key);
  
    vector<int> a(n);

    // vector 정렬
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        //a.push_back()도 가능
    }
    sort(a.begin(), a.end());
    rt=n-1;
    
    while(lt<=rt){
        mid=(lt+rt)/2;
        if(a[mid]==key){
            printf("%d\n", mid+1);
            return 0;
        }
        else if(a[mid]>key) rt=mid-1;
        else lt=mid+1;
    }
    return 0;
}
 
