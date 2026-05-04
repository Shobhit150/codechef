string checkPassword(int arr[], int n) {
    // write your code here 
    int sumi = 0;
    for(int i=0;i<n;i++) {
        sumi += arr[i];
    }

    if(sumi - n == 0) return "SECURE";
    return "NOT SECURE";
    
}