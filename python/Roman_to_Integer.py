class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {
            "CM": 900,"M" : 1000,
            "CD": 400,"D" : 500,
            "XC": 90, "C" : 100,
            "XL": 40, "L" : 50,
            "IX": 9,  "X" :10,
            "IV": 4,  "V" :5,
            "III": 3, "II":2, "I" : 1,      
        }
        answer = 0
        for i in range(len(s), 0, -1):
            for roman, arabic in romans.items():
                if roman in s[:i]:
                    answer += arabic
                    s = s.replace(roman, '', 1)
                    break  
        return answer
