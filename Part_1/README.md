# Part 1: Programming with C++

## Basic Programming -> updated

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
- [x] 253. Hãy cho biết tất cả các phần tử trong mảng a có nằm trong mảng b hay không?

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
- [x] 728. Cho mảng một chiều các số thực. Hãy viết hàm đệ quy sắp xếp các giá trị trong mảng tăng dần.
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
- [ ] 308.Cho mảng một chiều các số thực a. Hãy tạo mảng b từ mảng a, sao cho mảng b chỉ chứa các giá trị âm.
- [x] 468.(*) Xây dựng ma phương bậc A (n x n). Một ma trận được gọi là ma phương khi tổng các phần tử trên các dòng, các cột và 2 đường chéo 
chính phụ đều bằng nhau.



## Bit, byte, two's complement



## String
- [x] 205. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
    - Given two strings s and t, determine if they are isomorphic.
    - Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    - All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
- [ ] 482. [License Key Formatting](https://leetcode.com/problems/license-key-formatting/)
    - You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
    - We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
    - Return the reformatted license key.



## File stream



## OOP

## Reference
- [1] Bài tập Kỹ thuật lập trình, Nguyễn Tấn Trần Minh Khang, Nhà sách ĐH KHTN TP. HCM
- [2] LeetCode