// Approach 1:-

class Solution {
    public int compareVersion(String version1, String version2) {
        int i=0,j=0;
        
        while(i<version1.length() && j<version2.length()) {
            int start1=i;
            while(i<version1.length() && version1.charAt(i)!='.') i++;
            
            int firstNum=Integer.valueOf(version1.substring(start1,i));
            
            int start2=j;
            
            while(j<version2.length() && version2.charAt(j)!='.') j++;
            
            int secondNum=Integer.valueOf(version2.substring(start2,j));
            
            if(firstNum>secondNum) return 1;
            if(firstNum<secondNum) return -1;
            
            i++;
            j++;
        }
        
        while(i<version1.length()) {
            int start=i;
            while(i<version1.length() && version1.charAt(i)!='.') i++;
            
            int num=Integer.valueOf(version1.substring(start,i));
            
            if(num!=0) return 1;
            
            i++;
        }
        
        while(j<version2.length()) {
            int start=j;
            while(j<version2.length() && version2.charAt(j)!='.') j++;
            
            int num=Integer.valueOf(version2.substring(start,j));
            
            if(num!=0) return -1;
            
            j++;
        }
        
        return 0;
    }
}