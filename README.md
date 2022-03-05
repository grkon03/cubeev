# cubeev

立体四目並べAIのプログラムです

## ビルド・実行方法
ビルドするためには、```cubeev/build``` ディレクトリを作成して、そのディレクトリ内で以下のコマンドを実行して下さい。
```
$ cmake ..
$ make
```
実行するためには、こちらもそのディレクトリ内で以下のコマンドを実行してください。
```
$ ./cubeev
```

## 学習計算式の検証結果
いろいろな計算式による学習を試して、その所感をここに書いていきます。
### 1つ目
以下あるライン上についての話

<img src="http://latex.codecogs.com/svg.latex?w,&space;l,&space;p,&space;T" title="http://latex.codecogs.com/svg.latex?w, l, p, T" /> を順に、勝者プレイヤーのボールの個数、敗者プレイヤーのボールの個数、そのラインのパラメータ、終了時の経過ターン数、とする。また

<img src="http://latex.codecogs.com/svg.latex?d&space;=&space;w&space;-&space;l" title="http://latex.codecogs.com/svg.latex?d = w - l" />

とする。このとき、

<img src="http://latex.codecogs.com/svg.latex?W&space;=&space;\left\{&space;\begin{aligned}e^{3-p}&space;\quad&space;(d&space;\geq&space;0)&space;\\e^{p-3}&space;\quad&space;(d&space;<&space;0)\end{aligned}&space;\right.&space;" title="http://latex.codecogs.com/svg.latex?W = \left\{ \begin{aligned}e^{3-p} \quad (d \geq 0) \\e^{p-3} \quad (d < 0)\end{aligned} \right. " />

として、パラメータの変化を

<img src="http://latex.codecogs.com/svg.latex?\Delta&space;p&space;=&space;\frac{dW}{T}" title="http://latex.codecogs.com/svg.latex?\Delta p = \frac{dW}{T}" />

で計算する。新たなパラメータは <img src="http://latex.codecogs.com/svg.latex?p&space;&plus;&space;\Delta&space;p" title="http://latex.codecogs.com/svg.latex?p + \Delta p" /> とする。
#### 意図
主となっている考え方は、「パラメータは中心となってほしい値から離れていくほど、より離れていく方向には変化しづらいようにする」ということです。それを実現するために導入したのが、今回の W となっています。
他の d, T の組み込み方に関しては、まだ1つ目なので深く考えていません。