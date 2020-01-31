/*N max pair combinations

Given two arrays A & B of size N each. Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6 and maximum 2 elements are 6, 5

Example:

N = 4 a[]={1,4,2,3} b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)*/



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int,int> > > hp;
    set<pair<int, int> >s;
    sort(A.begin(),A.end());
    sort(B.begin() ,B.end());
    int len =A.size();
    hp.push(make_pair(A[len-1]+B[len-1], make_pair(len-1, len-1)));
    s.insert(make_pair(len-1,len-1));
    
    int loop =len;
    vector<int> ans;
    while(loop--){
        pair< int ,pair<int,int> >p =hp.top();
        hp.pop();
        ans.push_back(p.first);
        int L =p.second.first;
        int R =p.second.second;
        if(L >0 && R>=0 && (s.find(make_pair(L,R-1)) == s.end())){
            hp.push(make_pair(A[L] + B[R-1] ,make_pair(L,R-1)) );
            s.insert(make_pair(L,R-1));
        }
         if(L >=0 && R>0 && (s.find(make_pair(L-1,R)) == s.end())){
            hp.push(make_pair(A[L-1] + B[R] ,make_pair(L-1,R)) );
            s.insert(make_pair(L-1,R));
        }
        
    }
    return ans;
}
