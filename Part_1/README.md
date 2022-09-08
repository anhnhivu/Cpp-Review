# Part 1: Programming with C++

## Basic Programming

- [x] 23. Đếm số lượng “ước số” của số nguyên dương n.
- [x] 42. Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao  cho S(k) < n. 
Trong đó chuỗi S(k) được định nghĩa như sau : S(k) = 1 + 2 + 3 + ... + k.
- [x] 44. Hãy tính tổng các chữ số của số nguyên dương n.
- [x] 59. Hãy kiểm tra số nguyên dương n có phải số đối xứng hay không?
- [x] 75. Kiểm tra số nguyên 4 byte có dạng 2^k hay không?
- [x] 99. Viết chương trình nhập vào 3 số thực. Hãy in 3 số thực ấy ra màn hình theo thứ tự tăng dần mà chỉ dùng tối đa hai biến phụ.

## Function, code structure

- [x] 119. Liệt kê tất cả các số nguyên tố nhỏ hơn n.
- [x] 121. Hãy viết chương trình liệt kê tất cả các số Amstrong nằm trong đoạn [1, 1.000.000].

## Array

- [x] 157. Cho mảng một chiều các số thực, hãy tìm đoạn [a,b] sao cho đoạn này chứa tất cả các giá trị trong mảng (timdoan).
- [x] 169.(*) Cho mảng một chiều các số nguyên. Hãy viết hàm tìm số chẵn lớn nhất nhỏ hơn mọi giá trị lẻ có trong mảng.
- [x] 304.(*) Cho mảng một chiều các số nguyên và một số nguyên M. Hãy tìm một mảng con sao cho tổng các phần tử trong mảng bằng M.

## Struct

- [x] 599. Tìm ngày khi biết năm và số thứ tự của ngày trong năm.
- [x] 675.Viết chương trình thực hiện những yêu cầu sau:
    - [x] a. Nhập mảng một chiều các luận văn (LUANVAN). Biết rằng một luận văn gồm những thành phần như sau:
        - Mã luận văn: chuỗi tối đa 10 ký tự.
        - Tên luận văn: chuỗi tối đa 100 ký tự.
        - Họ tên sinh viên thực hiện: chuỗi tối đa 30 ký tự.
        - Họ tên giáo viên hướng dẫn: chuỗi tối đa 30 ký tự.
        - Năm thực hiện: kiểu số nguyên 2 byte.
    - [x] b. Xuất mảng.
    - [x] c. Tìm năm có nhiều luận văn nhất.
    - [x] d. Liệt kê các luận văn thực hiện gần nhất.

## Recursion
- [x] 704. Cho mảng một chiều các số nguyên. Viết hàm tính tổng các số chẵn trong mảng bằng phương pháp đệ qui.
- [x] 718.Cho mảng một chiều các số nguyên. Viết hàm đệ qui xuất mảng.
- [x] 719.Cho mảng một chiều các số nguyên. Viết hàm đệ qui xuất mảng theo thứ tự từ trái sang phải (xuất ngược).
- [x] 747. Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ lớn nhất của 100 là 25.
- [x] 763. Hãy kiểm tra số nguyên dương n có toàn chữ số chẵn hay không?

## Pointer

- [x] 769. Hãy viết đoạn chương trình để khai báo biến số nguyên a và xuất ra địa chỉ ô nhớ được cấp phát cho biến này khi chương trình chạy.
- [x] 770. Hãy khai báo biến con trỏ cấu trúc phân số có tên là p.
- [x] 772. Hãy cho biết trong đoạn chương trình dưới đây câu lệnh nào là đúng, câu lệnh nào là sai.
```
int a;
int *p;
a = 5;
p = a;
```
Câu lệnh `p = a` sai, do p là một con trỏ, a là một số nguyên. Không thể gán giá trị cho p. Có thể gán bằng cách `*p = a`.

- [x] 776. Hãy khai báo biến con trỏ p các số nguyên và viết lệnh cấp phát không gian bộ nhớ để biến con trỏ p có thể chứa 100 số nguyên. Sau đó viết lệnh thu hồi lại không gian bộ nhớ đã cấp phát cho con trỏ.
- [x] 777. Viết hàm hoán vị 2 số nguyên bằng cách sử dụng kỹ thuật con trỏ.

### New exercises
- [x] 308. Cho mảng một chiều các số thực a. Hãy tạo mảng b từ mảng a, sao cho mảng b chỉ chứa các giá trị âm.
- [x] 468.(*) Xây dựng ma phương bậc A (n x n). Một ma trận được gọi là ma phương khi tổng các phần tử trên các dòng, các cột và 2 đường chéo 
chính phụ đều bằng nhau.



## Bit, byte, two's complement

- [x] 001. Two’s complement: this solution works on a string. A new version works with binary is on branch `twos-complement`. 

Given an array of 8-bit unsigned numbers {0, 1, 2, 126, 127, 128, 129, 130, 254, 255}, write a program
- Calculate two’s complement value of the binary based on its bits
- Keep in mind time and space complexity

- [x] 010. [Find the Missing Number](https://www.geeksforgeeks.org/find-the-missing-number/)

Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.

Note: There are no duplicates in the list.

```
Input: arr[] = {1, 2, 4, 6, 3, 7, 8}, N = 8
Output: 5
Explanation: The missing number between 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}, N = 5
Output: 4
Explanation: The missing number between 1 to 5 is 4
```

Solution:

XOR has certain properties
```
Assume a_1 ⊕ a_2 ⊕ a_3 ⊕ . . . ⊕ a_n = a and a_1 ⊕ a_2 ⊕ a_3 ⊕ . . . ⊕ a_n-1 = b
Then a ⊕ b = a_n
```


## String
- [x] 205. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
    - Given two strings s and t, determine if they are isomorphic.
    - Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    - All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
- [x] 482. [License Key Formatting](https://leetcode.com/problems/license-key-formatting/)
    - You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
    - We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
    - Return the reformatted license key.

- [x] 12. [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X` + `II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:


- `I` can be placed before `V (5)` and `X (10)` to make `4` and `9`. 
- `X` can be placed before `L (50)` and `C (100)` to make `40` and `90`. 
- `C` can be placed before `D (500)` and `M (1000)` to make `400` and `900`.

Given an integer, convert it to a roman numeral.

## File stream

- [x] 011. Perform basic read and write on .txt file operations. 

## OOP

Four main principles of OOP:
- **Abstraction** 
- **Encapsulation**
- **Inheritance** 
- **Polymorphism** 



## Reference
- [1] Bài tập Kỹ thuật lập trình, Nguyễn Tấn Trần Minh Khang, Nhà sách ĐH KHTN TP. HCM
- [2] LeetCode
- [3] Geeksforgeeks
- [4] [What is OOP?](https://www.educba.com/what-is-oop/)