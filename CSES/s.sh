for((i = 1; i <= 100; ++i)); do
	echo $i
	./gen $i > in3
	./brute < in3 > out3
	./meet < in3 > out4
	diff out3 out4 || break
done