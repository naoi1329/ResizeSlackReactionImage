# ResizeSlackReactionImage
slackのリアクション追加したいときに一気にリサイズしてくれるやつ　　

# 使い方　　
リサイズしたい画像をフォルダに入れます。　　

オプションにフォルダのパスをオプションに設定してあげてターミナルで実行してあげればresizeImagesというフォルダができてるので、その中にリサイズされた画像が入ってます。　　

コンパイル済みのものを入れておきました。　　
> /resizeToSlackReaction/resizeToSlackReaction/main.out　　
です。

openCV使ってるのでコンパイルするときはこれでいけます。　　
> g++ main.cpp -o main.out `pkg-config --cflags opencv` `pkg-config --libs opencv`
