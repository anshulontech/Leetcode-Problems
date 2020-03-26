// https://leetcode.com/problems/integer-to-english-words/

string change3(int );

class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string s;
        
        if(num/1000000000!=0)
        {
            s=s+change3(num/1000000000)+"Billion ";
            num=num%1000000000;
        }
        if(num/1000000!=0)
        {
            s=s+change3(num/1000000)+"Million ";
            num=num%1000000;
        }
        if(num/1000!=0)
        {
            s=s+change3(num/1000)+"Thousand ";
            num=num%1000;
        }
        s=s+change3(num);
        return s.substr(0,s.size()-1);
    }
};

string change3(int num)
{
    string s;
    vector<string> one={"","One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    
    vector<string> ten={"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    
    if(num==0)
        return "";
    else
    {
        if(num/100!=0)
        {
            s=one[num/100]+"Hundred ";
            num=num%100;
        }
        if(num/10!=0)
        {
            if(num/10==1)
            {
                s=s+one[num];
                return s;
            }
            else
                s=s+ten[num/10];
            
            num=num%10;
        }
        if(num!=0)
            s=s+one[num];
    }
    
    return s;
        
    
}