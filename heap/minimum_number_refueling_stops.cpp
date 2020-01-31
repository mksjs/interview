/*Minimum Number of Refueling Stops

A car with infinite gas tank capacity initially at position 0 with B liters of gas. It uses 1 liter of gas per 1 mile that it drives. It starts moving to target position A which lies to the right of starting position.

Along the way, there are gas stations. ith gas station is C[i] miles right of the starting position, and has D[i] liters of gas.

What is the least number of refueling stops the car must make in order to reach its destination? If it cannot reach the destination, return -1.

NOTE:

    If the car reaches a gas station with 0 fuel left, the car can still refuel there.
    If the car reaches the destination with 0 fuel left, it is still considered to have arrived.


Input Format

First input argument is an integer A.
Second input argument is an integer B.
Third input argument is an array of integers C.
Fourth input argument is an array of integers D. 

Output Format

Return the least number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Constraints

1 <= A, B, D[i] <= 10^9
1 <= lenght of C = lenght of D < = 50000
C[0] < C[1] < C[2] < ... < C[C.length-1] < A  

For Example

Input 1:
    A = 100
    B = 10
    C = [10, 20, 30, 60]
    D = [60, 30, 30, 40]
Output 1:
    2

Input 2:
    A = 100
    B = 2
    C = [10]
    D = [100]

Output 2:
 -1
 Explanation: With initial fuel, we can't even reach the first station.
 */
/**********************************************************************************************************************************************/

int Solution::solve(int A, int B, vector<int> &C, vector<int> &D) {
    priority_queue<int> hp;
    int len =C.size();
    vector<vector <int > > stations(len, vector<int>(2));
    
    for(int i=0;i<len ;i++){
        stations[i][0] =C[i];
        stations[i][1] =D[i]; 
    }
    
    int curr =B;
    int count1=0;
    int count2 =0;
    while(1){
        while(count2<(int)stations.size() && stations[count2][0] <=curr){
            hp.push(stations[count2][1]);
            count2++;
        }
        if(curr >=A )
            return count1;
        if(hp.empty()){
            return -1;
        }
        curr +=hp.top();
        hp.pop();
        count1++;
    }
    
}

