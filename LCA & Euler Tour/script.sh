for((i = 1; i <= 100; ++i)); do
    echo $i
    ./gen $i > int
    ./correct < int > out1
    ./company2 <int > out2
    diff -w out1 out2 || break
done