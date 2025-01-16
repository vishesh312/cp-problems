# tc mn_n mx_n mn_q mx_q t_w q_w q_w_2
mkdir tests
cp gen tests/
cp v2 tests/
cd tests
echo 1
./gen 1000 1 300 300 300 0 0 0 11 > 01.in
./gen 1000 1 50 300 300 0 0 0 22 > 02.in
./gen 1000 1 10 300 300 0 0 0 33 > 03.in
echo 4
./gen 100 1000 3000 3000 3000 0 100 100 44 > 04.in
./gen 100 1000 3000 3000 3000 100 100 100 55 > 05.in
./gen 100 1000 3000 3000 3000 -100 0 0 66 > 06.in
echo 7
./gen 100 1000 3000 3000 3000 0 0 0 77 > 07.in
./gen 10 10000 30000 25000 30000 0 0 0 88 > 08.in
./gen 10 30000 30000 30000 30000 0 0 0 99 > 09.in
echo 10
./gen 10 25000 30000 30000 30000 100 100 100 10 > 10.in
./gen 10 25000 30000 30000 30000 100 50 50 11 > 11.in
./gen 10 10000 30000 30000 30000 -100 0 0 12 > 12.in
echo 13
./gen 1 300000 300000 300000 300000 0 0 0 13 > 13.in
./gen 1 300000 300000 300000 300000 0 0 0 14 > 14.in
./gen 1 300000 300000 300000 300000 0 0 0 15 > 15.in
echo 16
./gen 1 300000 300000 300000 300000 100 100 100 16 > 16.in
./gen 1 300000 300000 300000 300000 1000 100 100 17 > 17.in
./gen 1 300000 300000 300000 300000 100 100 100 18 > 18.in
echo 19
./gen 1 300000 300000 300000 300000 0 100 100 19 > 19.in
./gen 1 300000 300000 300000 300000 0 100 100 20 > 20.in
./gen 1 300000 300000 300000 300000 0 100 100 21 > 21.in
echo 22
./gen 1 300000 300000 300000 300000 -100 100 100 22 > 22.in
./gen 1 300000 300000 300000 300000 -100 100 100 23 > 23.in
./gen 1 300000 300000 300000 300000 -100 100 100 24 > 24.in

for i in {1..9}
do
    ./v2 < 0$i.in
done
for i in {10..24}
do
    ./v2 < $i.in
done

cd ..

mkdir final_tests

for i in {1..9}
do
    echo $i
    ./xor-test < tests/0$i.in > final_tests/0$i.in
    ./validator < final_tests/0$i.in
    ./ritul-sol < final_tests/0$i.in > final_tests/0$i.out
done
for i in {10..24}
do
    echo $i
    ./xor-test < tests/$i.in > final_tests/$i.in
    ./validator < final_tests/$i.in
    ./ritul-sol < final_tests/$i.in > final_tests/$i.out
done

