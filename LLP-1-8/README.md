

# Algorithm 1.8 `(grader)`

- กำหนดให้อำร์เรย์จำนวนเต็ม A ขนาด n จำนวน จงพัฒนาอัลกอริทึม `Cubic (n3)` เพื่อหาผลรวมของลำดับต่อเนื่อง
ที่มำกที่สุด ตัวอย่างเช่น `A[] = {5, 15, -30, 10, -5, 40, 10}` ผลรวมของลำดับต่อเนื่องที่มากที่สุด คือ `{10, -5, 40,
10}` ซึ่งก็คือ `10-5+40+10 = 55`

- ข้อมูลนำเข้า
  - บรรทัดที่ 1: `n` จำนวนเต็มแทนจำนวนสมาชิกในอาร์เรย์ A โดยที่ `1<= n <= 1000`
  - บรรทัดที่ 2: รายการจำนวนเต็ม `n` จำนวน แทนสมาชิกของอาร์เรย์ โดยที่ `-1,000 < A[i] < 1,000` และ
`0 <= i < n` คั่นด้วยช่องว่ำง

- ข้อมูลส่งออก
    - ผลรวมของลำดับต่อเนื่องที่มากที่สุด

- ตัวอย่าง

| input | output |
| ------ | ------ |
| 7  
5 15 -30 10 -5 40 10 | 55 |
| 5
-1 -2 5 -1 3 | 7 |