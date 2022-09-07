class Solution 
{
public:
    string licenseKeyFormatting(string s, int k) 
    {
        int numberOfDashes = 0;
        for (int i = 0; i < s.size(); i++) 
            if (s[i] == '-') 
                numberOfDashes++;
        
        int numberOfLetters = s.size() - numberOfDashes;
        string formattedStr = "";
        
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] != '-') 
            {
                formattedStr += toupper(s[i]);
                numberOfLetters--;
                if (numberOfLetters % k == 0 && numberOfLetters > 0) 
                    formattedStr += '-';
            }
        }
        return formattedStr;
    }
};