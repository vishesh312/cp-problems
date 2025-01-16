# tc mn_n mx_n mn_q mx_q t_w q_w q_w_2
mkdir tests
cp gen tests/
cp gen-star tests/
cp v2 tests/
cd tests
echo 1
./gen-star 1 300000 1 01 > 01.in
echo 2
./gen-star 1 3000 100 02 > 02.in
echo 3
./gen-star 10 300 100 03 > 03.in
echo 16
./gen 1 300000 300000 300000 300000 100 100 100 04 > 04.in
./gen 1 300000 300000 300000 300000 1000 100 100 05 > 05.in
./gen 1 300000 300000 300000 300000 100 100 100 06 > 06.in

echo validating

for i in {1..6}
do
    echo $i
    ./v2 < 0$i.in
done

cd ..

mkdir final_tests

for i in {1..6}
do
    echo $i
    ./xor-test < tests/0$i.in > final_tests/0$i.in
    ./validator < final_tests/0$i.in
    ./ritul-sol < final_tests/0$i.in > final_tests/0$i.out
done

