vector<long long> findSuperstarDishes(vector<long long> &a, long long n) {
    // write your code here 
    

    long long cnt1 = 0;
    long long cnt2 = 0;
    long long ele1 = 0;
    long long ele2 = 0;
    for(int i=0;i<n;i++) {
        if(cnt1 > 0 && a[i] == ele1) {
            cnt1++;
        } else if(cnt2 > 0 && a[i] == ele2) {
            cnt2++;
        } else if(cnt1 == 0) {
            ele1 = a[i];
            cnt1 = 1;
        } else if(cnt2 == 0) {
            ele2 = a[i];
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == ele1) {
            cnt1++;
        }else if(a[i] == ele2) {
            cnt2++;
        }
    }
    vector<long long> ans;
    if(cnt1 > n/3) ans.push_back(ele1);
    if(cnt2 > n/3) ans.push_back(ele2);
    sort(ans.begin(), ans.end());
    return ans;

}

