class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size(),n=n1+n2;
        int i=0,j=0,count=0;
        int element1=-1,element2=-1;
        int index2=n/2,index1=index2-1;

        while(i<n1 && j<n2){

            if(nums1[i]<nums2[j]){
                if(count==index1)element1=nums1[i];
                if(count==index2)element2=nums1[i];
                count++;
                i++;
            }
            else{
                 if(count==index1)element1=nums2[j];
                if(count==index2)element2=nums2[j];
                count++;
                j++;
            }
            
        }    
         
        while(i<n1){
            if(count==index1)element1=nums1[i];
                if(count==index2)element2=nums1[i];
                count++;
                i++;
        }

        while(j<n2){
             if(count==index1)element1=nums2[j];
                if(count==index2)element2=nums2[j];
                count++;
                j++;
        }

        if(n%2==1)return element2;
        else return (double)((double)(element1+element2))/2.0;

    }
};