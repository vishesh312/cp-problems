# tc mn_n mx_n mn_q mx_q t_w q_w q_w_2
mkdir tests
cp gen-line tests/
cp v2 tests/
cd tests
echo 1
./gen-line 1 300000 300000 10000 01 > 01.in
echo 2
./gen-line 1 300000 300000 10000 02 > 02.in
echo 3
./gen-line 100 3000 3000 1000 03 > 03.in
echo 4
./gen-line 1000 300 300 100 04 > 04.in
echo 5
./gen-line 100 3000 3000 1000 05 > 05.in

echo validating

for i in {1..5}
do
    echo $i
    ./v2 < 0$i.in
done

cd ..

mkdir final_tests

for i in {1..5}
do
    echo $i
    ./xor-test < tests/0$i.in > final_tests/0$i.in
    ./validator < final_tests/0$i.in
    ./ritul-sol < final_tests/0$i.in > final_tests/0$i.out
    ./ice < final_tests/0$.in > a.out
    diff -w a.out final_tests/0$i.out
done

