class Solution 
{
public:
    string intToRoman(int num) 
    {
        string roman = "";
        if (num >= 1000) 
        {
            int thousand = num / 1000;
            while (thousand > 0) 
            {
                roman += 'M';
                thousand--;
                
            }
        }
        
        num = num % 1000;
        if (num >= 100)
        {
            if (num >= 900)
            {
                roman += 'C';
                roman += 'M';
            }
            else if (num >= 500) 
            {
                roman += 'D';
                int hundred = num / 100;
                while (hundred > 5) 
                {
                    roman += 'C';
                    hundred--;
                }
            }
            else if (num >= 400) 
            {
                roman += 'C';
                roman += 'D';
            }
            else 
            {
                int hundred = num / 100;
                while (hundred > 0) 
                {
                    roman += 'C';
                    hundred--;
                }
            }
            
        }
        
        num = num % 100;
        if (num >= 10)
        {
            if (num >= 90)
            {
                roman += 'X';
                roman += 'C';
            }
            else if (num >= 50) 
            {
                roman += 'L';
                int ten = num / 10;
                while (ten > 5) 
                {
                    roman += 'X';
                    ten--;
                }
            }
            else if (num >= 40) 
            {
                roman += 'X';
                roman += 'L';
            }
            else 
            {
                int ten = num / 10;
                while (ten > 0) 
                {
                    roman += 'X';
                    ten--;
                }
            }
        }
        
        num = num % 10;
        if (num >= 1)
        {
            if (num == 9)
            {
                roman += 'I';
                roman += 'X';
            }
            else if (num >= 5) 
            {
                roman += 'V';
                while (num > 5) 
                {
                    roman += 'I';
                    num--;
                }
            }
            else if (num >= 4) 
            {
                roman += 'I';
                roman += 'V';
            }
            else 
            {
                while (num > 0) 
                {
                    roman += 'I';
                    num--;
                }
            }
            num = num % 10;
        }
        return roman;
    }
};