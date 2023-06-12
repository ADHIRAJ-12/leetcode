class Solution {
public:
    
    //optimal
    
    int f(int n){
        int ans=0;
        int start = 2;
            while(n > 1)
            {
                if(n%start==0)
                {
                    ans+=start;
                    n/=start;
                }
                else start++;
            }
            return ans;
    
    }
    int smallestValue(int n) {
    
     
    while(n != f(n))
          n = f(n);
        
        return n;
    
    
    
//     //get the factors
//   vector <int> factors(int num){
//   vector<int> temp;
//   while (num != 1){
//     temp.push_back(arr[num]);
//     num = num / arr[num];
//   }
//   return temp;
// }
  

// int arr[1000000];
//     //using sieve of eratostnes for prime
    
// void seiveofearth(){
//   arr[1] = 1;
//   for (int i=2; i<1000000; i++)arr[i] = i;
//   //iterating further
//   for (int i=4; i<1000000; i+=2)arr[i] = 2;
//   for (int i=3; i*i<1000000; i++){
//       if (arr[i] == i){
//       for (int j=i*i; j<1000000; j+=i)
//         if (arr[j]==j)
//           arr[j] = i;
//     }
//   }
// }
    
//     //check for prime or not
//     bool prime(int num){
//     if (num <= 1)           //if no less than 2
//         return false;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0)   //divisible number
//             return false;
//     }
//     return true;
// }

  
//     int smallestValue(int n) {
//         ///calling sieve of eratosthens
//       seiveofearth();
//         //if value is less than = 4
//         if(n<=4)return n;
        
//         while(!prime(n)){
//             //take out the factors and store
//             vector<int>vec=factors(n);
//             int ans=0;
//             int siz=vec.size();
//             for(int i=0;i<siz;i++){
//                 ans+=vec[i];
//             }
//             n=ans;
//         }
//         return n;

        
    }
};
class Solution {
public:
    
    //optimal
    
    int f(int n){
        int ans=0;
        int start = 2;
            while(n > 1)
            {
                if(n%start==0)
                {
                    ans+=start;
                    n/=start;
                }
                else start++;
            }
            return ans;
    
    }
    int smallestValue(int n) {
    
     
    while(n != f(n))
          n = f(n);
        
        return n;
    
    
    
//     //get the factors
//   vector <int> factors(int num){
//   vector<int> temp;
//   while (num != 1){
//     temp.push_back(arr[num]);
//     num = num / arr[num];
//   }
//   return temp;
// }
  

// int arr[1000000];
//     //using sieve of eratostnes for prime
    
// void seiveofearth(){
//   arr[1] = 1;
//   for (int i=2; i<1000000; i++)arr[i] = i;
//   //iterating further
//   for (int i=4; i<1000000; i+=2)arr[i] = 2;
//   for (int i=3; i*i<1000000; i++){
//       if (arr[i] == i){
//       for (int j=i*i; j<1000000; j+=i)
//         if (arr[j]==j)
//           arr[j] = i;
//     }
//   }
// }
    
//     //check for prime or not
//     bool prime(int num){
//     if (num <= 1)           //if no less than 2
//         return false;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0)   //divisible number
//             return false;
//     }
//     return true;
// }

  
//     int smallestValue(int n) {
//         ///calling sieve of eratosthens
//       seiveofearth();
//         //if value is less than = 4
//         if(n<=4)return n;
        
//         while(!prime(n)){
//             //take out the factors and store
//             vector<int>vec=factors(n);
//             int ans=0;
//             int siz=vec.size();
//             for(int i=0;i<siz;i++){
//                 ans+=vec[i];
//             }
//             n=ans;
//         }
//         return n;

        
    }
};
