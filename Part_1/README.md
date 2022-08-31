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
- [x] 253. Hãy cho biết tất cả các phần tử trong mảng a có nằm trong mảng b hay không?
- [x] 261. Hãy sắp xếp các số dương trong mảng các số thực tăng dần các số âm giữ nguyên vị trí của chúng trong mảng (sapxepduong).
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


## Bit, byte, two's complement





## String



## File stream



## OOP


## Notes:
Các kĩ thuật khi sử dụng mảng:  
- Mảng một chiều
- Kỹ thuật nhập xuất mảng
- Kỹ thuật đặt lính canh 
- Các bài tập tìm kiếm và liệt kê
- Kỹ thuật tính tổng
- Kỹ thuật đếm
- Kỹ thuật đặt cờ hiệu
- Kỹ thuật sắp xếp
- Kỹ thuật thêm
- Kỹ thuật xóa
- Kỹ thuật xử lí mảng
- Kỹ thuật xử lí mảng con
- Xây dựng mảng

BT mảng:
- [ ] 174.(*) Cho mảng số thực có nhiều hơn hai giá trị và các giá trị trong mảng khác nhau từng đôi một. Hãy viết hàm liệt kê tất cả các cặp giá trị (a,b) trong mảng thỏa điều kiện a <= b.
- [ ] 175.(*) Cho mảng số thực có nhiều hơn hai giá trị và các giá trị trong mảng khác nhau từng đôi một. Hãy viết hàm tìm hai giá trị gần nhau nhất trong mảng (gannhaunhat). Lưu ý: Mảng có các giá trị khác nhau từng đôi một còn có tên là mảng phân biệt.
- [ ] 195. Cho mảng số thực có nhiều hơn ba giá trị và các giá trị trong mảng khác nhau từng đôi một. Hãy liệt kê tất cả các bộ ba giá trị (a,b,c) thỏa điều kiện a = b + c với a, b, c là ba giá trị khác nhau trong mảng. Ví dụ: (6, 2, 4).
- [ ] 254. Hãy đếm số lượng giá trị trong mảng thỏa tính chất: “lớn hơn tất cả các giá trị đứng đằng trước nó”.
- [ ] 260. Cho hai mảng a, b. Hãy cho biết mảng b có phải là hoán vị của mảng a hay không? (kthoanvi).
- [ ] 261. Hãy sắp xếp các số dương trong mảng các số thực tăng dần các số âm giữ nguyên vị trí của chúng trong mảng (sapxepduong).
- [ ] 278. Hãy xóa tất cả các phần tử trùng nhau trong mảng và chỉ giữ lại duy nhất một phần tử (xoatrung).
- [ ] 292. Hãy biến đổi mảng bằng cách thay tất cả các phần tử trong mảng bằng số nguyên gần nó nhất (nguyenhoa).
- [ ] 298. Đếm số lượng mảng con tăng có độ dài lớn hơn 1 trong mảng một chiều các số thực (demcontang).
- [ ] 302. Cho hai mảng a và b. Hãy đếm số lần xuất hiện của mảng a trong mảng b. (demmangcon).
- [ ] 305.(*) Tìm dãy con toàn dương có tổng lớn nhất trong mảng một chiều các số thực (duonglonnhat).

BT đệ quy:
- [ ] 714. Có 3 chồng đĩa đánh số 1, 2 và 3. Đầu tiên chồng 1 có n đĩa được xếp sao cho đĩa lớn hơn nằm bên dưới và hai chồng đĩa còn lại không có đĩa nào. Yêu cầu: chuyển tất cả các đĩa từ chồng 1 sang chồng 3, mỗi lần chỉ chuyển một đĩa và được phép sử dụng chồng hai làm trung gian.  Hơn nữa trong quá trình chuyển đĩa phải bảo đảm qui tắt đĩa lớn hơn nằm bên dưới.
- [ ] 715. Cho tập hợp A có n phần tử được đánh số từ 1, 2, … , n. Một hoán vị của A là một dãy a1, a2, … , an. Trong đó ai € A và chúng đối một khác nhau. Hãy viết hàm phát sinh tất cả các hoán vị của tập hợp A.
- [ ] 716. Cho bàn cờ vua kích thước (8x8). Hãy sắp 8 quân hậu vào bàn cờ sao cho không có bất kỳ 2 quân hậu nào có thể ăn nhau.
- [ ] 717. Cho bàn cờ vua kích thước (8x8). Hãy di chuyển quân mã trên khắp bàn cờ sao cho mỗi ô đi qua đúng một lần.
- [ ] 729.Cho mảng một chiều các số nguyên. Hãy viết hàm đệ quy sắp xếp các giá trị chẵn trong mảng tăng dần, các giá trị lẻ vẫn giữ nguyên giá trị và vị trí trong mảng.