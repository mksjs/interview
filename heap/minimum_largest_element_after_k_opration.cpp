/*Minimum largest element after K operations

Given an array A of N numbers, you have to perform B operations. In each operation, you have to pick any one of the N elements and add original value(value stored at index before we did any operations) to it's current value. You can choose any of the N elements in each operation.

Perform B operations in such a way that the largest element of the modified array(after B operations) is minimised. Return an integer corresponding to the minimum possible largest element after K operations.

Example:

Input : 
  A = [1, 2, 3, 4] 
  B = 3

Output : 4

Explanation : 
After the 1st operation the array would change to [2, 2, 3, 4]
After the 2nd operation the array would change to [3, 2, 3, 4]
After the 3rd operation the array would change to [4, 2, 3, 4]*/


/**********************************************************************************************************************************************/


int Solution::solve(vector<int> &A, int B) {
    
    //MIN HEAP
    
    priority_queue< pair<int,int> ,vector<pair<int ,int> > ,greater< pair<int,int> > > hp;
    
    vector<int> curr = A;
    
    for(int i=0;i<A.size();i++){
        
        hp.push(make_pair(2*curr[i] ,i));
    }
    
    while(B--){
        pair< int, int > p =hp.top();
        hp.pop();
        int i =p.second;
        curr[i] +=A[i];
        hp.push(make_pair(curr[i] +A[i] , i));
        
    }
    
    int ans = INT_MIN;
    for(int i=0;i<curr.size();i++){
        ans =max(ans, curr[i]);
    }
    return ans;
}

