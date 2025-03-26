#A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
#For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
#Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def backtrack(start: int, path: List[str]):
           
            if len(path) == 4:
                if start == len(s):
                    result.append(".".join(path))
                return

           
            for length in range(1, 4):
                if start + length > len(s): 
                    break
                
                segment = s[start:start + length]

                
                if (len(segment) > 1 and segment[0] == "0") or int(segment) > 255:
                    continue

                
                backtrack(start + length, path + [segment])

        result = []
        if 4 <= len(s) <= 12:  
            backtrack(0, [])
        return result
