# Module 01 – Điện tử cơ bản và mô phỏng

> Hoàn thành: `11/10/2026` · Công cụ: Tinkercad Circuits, Wokwi (ESP32) · Ngôn ngữ: C/C++ (Arduino framework)

## Mục tiêu
- [ ] Tính điện trở hạn dòng cho LED
- [ ] Tính điện áp ra của mạch chia áp và kiểm chứng bằng Multimeter
- [ ] Đấu và chạy mạch ESP32 gồm nút nhấn và LED trên trình giả lập

## Công thức dùng trong module
| Nội dung | Công thức |
|---|---|
| Định luật Ohm | `V = I × R` |
| Điện trở hạn dòng LED | `R = (Vnguồn − Vf) / I` |
| Mạch chia áp | `Vout = Vin × R2 / (R1 + R2)` |

---

## Bài 1 – LED và điện trở (Tinkercad)

| Đại lượng | Cách tính | Kết quả tính | Đo bằng Multimeter |
|---|---|---|---|
| Điện trở R | (9 − 2) / 0.01 = 700 Ω → chọn giá trị chuẩn | 680 Ω | — |
| Dòng qua LED | 7 / 680 | ≈ 10.3 mA | 10.3 mA |
| Điện áp trên điện trở | | ≈ 7 V | 7 V |
| Điện áp trên LED | | ≈ 2 V | 2 V |

## Bài 2 – Mạch chia áp (Tinkercad)

| Thông số | Giá trị |
|---|---|
| R1 / R2 | 10 kΩ / 5 kΩ |
| Vout tính tay | 9 × 5 / (10 + 5) = **3 V** |
| Vout đo được | 3 V |
| Điện áp trên R1 (đo) | 6 V |

---

## Bài 3 và dự án chốt – Đèn báo trạng thái (ESP32, Wokwi)
**Link dự án:** `<https://wokwi.com/projects/480236941171075073>`

### Chức năng
| Trạng thái nút | GPIO27 | LED đỏ | LED xanh |
|---|---|---|---|
| Thả | HIGH | Tắt | Sáng |
| Nhấn | LOW | Sáng | Tắt |

### Sơ đồ đấu dây
| Chân ESP32 | Nối tới | Ghi chú |
|---|---|---|
| GPIO26 | Điện trở 220 Ω → anode LED đỏ | Cathode nối GND |
| GPIO25 | Điện trở 220 Ω → anode LED xanh | Cathode nối GND |
| GPIO27 | Một đầu tiếp điểm của nút nhấn | Đầu còn lại nối GND, dùng `INPUT_PULLUP` |

### Code
```cpp
const int RED_PIN = 26;
const int BLUE_PIN = 25;
const int BTN_PIN = 27;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) { 
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }
}
```

---

## Lỗi đã gặp và cách xử lý

| Hiện tượng | Nguyên nhân | Cách phát hiện và sửa |
|---|---|---|
| LED không sáng, nhấn nút không có tác dụng | Hai chân nút (đầu 1 và đầu 2) cùng nối GPIO27, không có đường xuống GND | Nhận ra 1.l/1.r là một đầu, 2.l/2.r là đầu kia. Chuyển một đầu sang GND |
| LED không sáng | Nối ngược Anode Cathode | Kiểm tra lại tên 2 chân, nối lại dây |

## Điều rút ra
- Vì sao LED cần điện trở?
- Cách sử dụng Multimeter
- `INPUT_PULLUP` dùng để làm gì, vì sao nhấn nút lại đọc ra LOW?
