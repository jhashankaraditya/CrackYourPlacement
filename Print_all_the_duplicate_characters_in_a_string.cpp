class Solution {
  public:
    int sameChar(string A, string B)
    {
        // code here 
        int same_letters=0, n=A.size();
        for (int i=0; i<n; i++) {
            char first=tolower(A[i]);
            char second=tolower(B[i]);
            if (first==second) {
                same_letters++;
            }
        }
        return same_letters;
    }
}
