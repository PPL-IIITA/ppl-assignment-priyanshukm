file="logfile.txt"
if [ -f $file ] ; then
	rm $file
fi
g++ Question6.cpp TestGenerator.cpp ReadFile.cpp GirlAttr.cpp BoyAttr.cpp GiftAttr.cpp Log.cpp -std=c++11
./a.out
