# CugoArduinoKit 快速入門指南
## 1. 開始
這個 Repo 是用於使用 CugoArduinoKit 的示範程式碼。
您可以使用 CugoArduinoKit 實現遙控車行駛或自動行駛。</br>
![arduino_kit](https://user-images.githubusercontent.com/22425319/208833953-755492cb-052f-4d29-8a24-4b87168e3f8e.jpg)

## 2. 準備
解釋使用 CugoArduinoKit 的起始步驟
### 2-1. 事前準備
在進行快速入門之前，請確認以下步驟已完成：<br>
- [ ] 組裝 CugoArduinoKit
  - 組裝手冊請參閱此處<br>https://github.com/CuboRex-Development/cugo-arduino-beginner-programming/tree/main/manuals
- [ ] USB 傳輸線：用於連接 Arduino 與個人電腦
- [ ] 電腦（Windows 或 Mac）
### 2-2. 安裝 Arduino IDE
1. 前往官方網站（https://www.arduino.cc/en/software）
2. 從「DOWNLOAD OPTIONS」中選擇適合的版本
3. 選擇「JUST DOWNLOAD」或「CONTRIBUTE & DOWNLOAD」
4. 下載完成後，執行下載的檔案，按照指示進行安裝
### 2-2. 下載學習用的原始碼
1. 點擊這裡下載
![download_zip](https://user-images.githubusercontent.com/22425319/208834960-235e190f-5382-4ece-a3cc-58f4546fe24c.png)

2. 解壓縮下載的檔案
3. 雙擊 "CuGoArduinoBeginnerProgramming.ino" 檔案，啟動 Arduino IDE
### 2-3. 將程式碼燒錄到 Arduino UNO 上

1. 確認 "CuGoArduinoBeginnerProgramming.ino" 已在 Arduino IDE 中開啟
2. 使用 USB 傳輸線將個人電腦與 Arduino 連接
3. 從「工具」>「板子」選擇 "Arduino Uno"
4. 從「工具」>「連接埠」中選擇 Arduino 的連接埠
5. 選擇箭頭按鈕 "→"，並執行程式燒錄至微控制器板
6. 如果顯示寫入至板子完成的訊息，表示燒錄完成
## 3. 使用方法
CugoArduinoKit 可以使用兩種模式
### 3-1. 使用遙控模式
在燒錄完"CuGoArduinoBeginnerProgramming.ino"之後，將附帶的遙控器的左搖桿向左傾斜，即可啟動遙控模式 <br>
![controller](https://user-images.githubusercontent.com/22425319/208835611-c366764d-4b30-477a-aac8-c848712c4710.png)

在遙控模式下的操作方法如下：<br>
- 使用左搖桿的上下操作可以控制左履帶輪前進和後退
- 使用右搖桿的上下操作可以控制右履帶輪前進和後退　<br>

如下所示：<br>
![radiocontrol](https://user-images.githubusercontent.com/22425319/208835778-1dd170dc-3de1-4dce-b7ee-83f2c1e0838d.png)
### 3-2. 使用自動行駛模式
透過編程 CuGoArduinoBeginnerProgramming 中最底部的 CMD_EXECUTE 函式，可以實現自動行駛功能
### 指令列表
在 CMD_EXECUTE 函式內，可以執行以下指令：<br>

- 基本指令列表<br>

|  指令名稱  |  動作  |　備註 |
| ---- | ---- | ---- |
|  button()  |  等待按鈕按下  | 在按鈕按下之前，都會是等待狀態 |
|  matsu(1000)  |  等待1000毫秒  | 等待括號內輸入的數字毫秒。1000毫秒等於1秒。 |
|  susumu(1.0)  |  向前移動1公尺  | 透過更改括號內的數字，可以修改前進的距離 |
|  modoru(1.0)  |  向後移動1公尺  | 透過更改括號內的數字，可以調整後退的距離 |
|  migimawari45()  |  以右轉45度旋轉  |      |
|  hidarimawari45()  |  以左轉45度旋轉  |      |
|  migimawari90()  |  以右轉90度旋轉 |      |
|  hidarimawari90()  |  以左轉90度旋轉  |      |
|  migimawari180()  |  以右轉180度旋轉  |      |
|  hidarimawari180()  |  以左轉180度旋轉  |      |
 
  
- 應用指令列表<br> 

|  指令名稱  |  動作  |　備註 |
| ---- | ---- | ---- |
|  susumu(1.0,90) | 以最高速度 90rpm 前進 1.0m  | 在括號內設定移動距離和上限速度。上限速度最高可設定為180rpm，如果距離較短，可能無法達到上限速度　|
| sagaru(1.0,90) | 以最高速度 90rpm 後退 1.0m | 括號內的設定與 susumu(1.0, 90) 相同 |
| migimawari45(90) | 以最高速度90rpm向右旋轉45度 | 在括號內設定上限速度。上限速度最高可設定為180rpm，如果距離較短，可能無法達到上限速度　|
|migimawari90(90) | 以最高速度90rpm向右旋轉90度 | 括號內的設定與 migimawari45(90) 相同 |
| migimawari180(90) | 以最高速度90rpm向右旋轉180度  | 括號內的設定與 migimawari45(90) 相同 |
| hidarimawari45(90) | 以最高速度90rpm向左旋轉45度 | 括號內的設定與 migimawari45(90) 相同 |
| hidarimawari90(90) | 以最高速度90rpm向左旋轉90度 | 括號內的設定與 migimawari45(90) 相同 |
| hidarimawari180(90) | 以最高速度90rpm向左旋轉180度 | 括號內的設定與 migimawari45(90) 相同 |
| turn_clockwise(60,90) | 以最高速度90rpm向右旋轉60度 | 在括號內設定旋轉角度和上限速度。上限速度最高可設定為180rpm，如果距離較短，可能無法達到上限速度 |
| turn_counter_clockwise(60,90) | 以最高速度90rpm向左旋轉60度 | 括號內的設定與 turn_clockwise(60, 90) 相同 |
## 4. 示範程式碼解說
### 4-1. 執行示範程式碼
1. 請檢查程式碼檔案最底部的以下程式碼
- <details>
  <summary>如果您要檢查程式碼，請點擊這裡</summary>
  
  ```c
  void CMD_EXECUTE()
  {
  cmd_manager();  // おまじない Good Luck Charm
  // 從這裡↓開始進行修改！
  button();//等待按鈕按下

  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000);
  
  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000);  
  // 從這裡↑開始進行修改！
  cmd_end(motor_controllers);      // おまじない Good Luck Charm
  }
  ```
</details>

2. 指令說明 <br>
執行這個指令將使 CugoArduinoKit 依照一個正方形移動


### 4-2. 修改示範程式碼
#### 4-2-1. 繪製一個長方形
- 問題：讓我們來思考 CugoArduinoKit 如何繪製一個長方形
  - 提示：susumu()指令中的括號內表示前進的距離
  - 讓我們嘗試不同的方法並確認，正確答案將在詳細範例中提供

- <details>
  <summary>點擊這裡以查看答案</summary>
  答案範例請點擊這裡<br>

   ```c
  void CMD_EXECUTE()
  {
  cmd_manager();  // おまじない Good Luck Charm
  // 從這裡↓開始進行修改！
  button();//等待按鈕按下

  susumu(0.5); // ★ 從示範程式碼進行修改的部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(0.5); // ★ 從示範程式碼進行的修改部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000);
  
  susumu(1.0);
  matsu(1000); 
  
  migimawari90();
  matsu(1000);  

  // 從這裡↑開始進行修改！
  cmd_end(motor_controllers);      // おまじない Good Luck Charm
  }
  ```
</details>

#### 4-2-2. 改變速度
- 問題：讓我們來思考 CugoArduinoKit 如何改變速度並前進
  - 提示：在 susumu() 應用指令的括號內，代表著前進的距離和上限速度
  - 讓我們嘗試不同的方法並確認，正確答案將在詳細範例中提供

- <details>
  <summary>請點擊這裡查看答案</summary>
  讓我們修改 susumu 指令中的內容，使得兩邊履帶行進相同的距離<br>

   ```c
  void CMD_EXECUTE()
  {
  cmd_manager();  // おまじない Good Luck Charm
  // 從這裡↓開始進行修改！
  button();//等待按鈕按下

  susumu(1.5,60); // ★ 從示範程式碼進行的修改部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(1.0,120);// ★ 從示範程式碼進行的修改部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000); 
  
  susumu(1.5,40); // ★ 從示範程式碼進行的修改部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000);
  
  susumu(1.0,120);// ★ 從示範程式碼進行的修改部分
  matsu(1000); 
  
  migimawari90();
  matsu(1000);  
  
  // 從這裡↑開始進行修改！
  cmd_end(motor_controllers);      // おまじない Good Luck Charm
  }
  ```
</details>

## 5. 聯絡方式
- 如果您有疑問或不明之處，請提出問題或發起議題（issue）
  - https://github.com/CuboRex-Development/cugo-arduino-beginner-programming/issues
