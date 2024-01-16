class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
        int arr[N];
        int ans=INT_MIN,j=-1;
        for(int i=0;i<N;i++){
            arr[i]= 0;
        }
        for(int i=0; i<N; i++){
            if(Edge[i]!= -1){
                arr[Edge[i]] += i;
            }
        }
        for(int i=0;i<N;i++){
            if(ans<=arr[i]){
                ans = arr[i];
                j = i;
            }
        }
        if(ans!=INT_MIN)
            return j;
        return -1;
  }
};
