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

### 10131 -- Exact Sum
-	用set自動排序
-	用set的upper bound抓最靠近的中間值然後慢慢算
-	*小心不要再+同一個*

### 10207 -- Uncompress
-	字串處理
-	方法:
	-	利用getchar抓每個字元,同時判斷是否是字母,把字母存如string
	-	不是字母，if(!string.empty())把string存入vector,清空string
	-	如果是數字，用cin.putback() 把char丟回去cin，抓int，用iterator算是vector第幾個，cout，push_back(\*it) 然後刪掉erase(it)
-	測資好像有錯的

### 10215 -- Mine Sweeper
-	存地圖，output x的地方
-	vector的assign function 可快速把地圖換成數字的
-	並沒有碰到炸彈的case

### 10225 -- Joseph's Cousin
-	75分
-	暴力解，取餘數，不重復數

### 10235 -- Fibonacci Numbers
-	大數運算
-	不可用recursion，會TLE
-	用vector<int> 來當大數，小心第一個'0'不會顯示
-	\<iomanip\> 裏有setfill 和 setw，可控制output多少個字及填上什麼字
	-	`cout << setfill('0') << setw(10) << 10 << endl;`

### 10245 -- Minimum Path Sum
-	不需要recursion
-	在收圖的同時判斷now的上面一格和前面一個哪一個比較小，當前的值加上小的哪一格的值
-	然後直接output最後一格就好了
