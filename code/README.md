# Solution

### 10121 -- All You Need Is Love
-	可用\<bitset\>來做binary與dec的轉換
-	GCD算法

### 10122 -- Chest of Drawers
-   用遞回的方式去計算
-   要知道計算的方式

### 10123 -- Cola
-   可直接丟借0～2去算

### 10125 -- Die Game
-   直接模擬色子
-   兩個double queue 可以很方便的模擬

### 10126 -- Zipf's Law
-   字串處理不解釋
-   利用multiset 的count，簡單的找出次數

### 10207 -- Uncompress
-	字串處理
-	方法:
	-	利用getchar抓每個字元,同時判斷是否是字母,把字母存如string
	-	不是字母，if(!string.empty())把string存入vector,清空string
	-	如果是數字，用cin.putback() 把char丟回去cin，抓int，用iterator算是vector第幾個，cout，push_back(\*it) 然後刪掉erase(it)

### 10215 -- Mine Sweeper
-	存地圖，output x的地方
-	vector的assign function 可快速把地圖換成數字的
-	並沒有碰到炸彈的test case
