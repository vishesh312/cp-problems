# tc mn_n mx_n mn_q mx_q t_w q_w q_w_2
mkdir tests
cp gen tests/
cd tests
echo 1
./gen 1000 1 300 300 300 0 0 0 1 > 01.in
./gen 1000 1 50 300 300 0 0 0 2 > 02.in
./gen 1000 1 10 300 300 0 0 0 3 > 03.in
echo 4
./gen 100 1000 3000 3000 3000 0 1000 1000 4 > 04.in
./gen 100 1000 3000 3000 3000 1000 1000 1000 5 > 05.in
./gen 100 1000 3000 3000 3000 -1000 0 0 6 > 06.in
echo 7
./gen 100 1000 3000 3000 3000 0 0 0 7 > 07.in
./gen 10 10000 30000 25000 30000 0 0 0 8 > 08.in
./gen 10 30000 30000 30000 30000 0 0 0 9 > 09.in
echo 10
./gen 10 25000 30000 30000 30000 1000 20000 20000 10 > 10.in
./gen 10 25000 30000 30000 30000 10000 10000 10000 11 > 11.in
./gen 10 10000 30000 30000 30000 -10000 0 0 12 > 12.in
echo 13
./gen 1 300000 300000 300000 300000 0 0 0 13 > 13.in
./gen 1 300000 300000 300000 300000 0 0 0 14 > 14.in
./gen 1 300000 300000 300000 300000 0 0 0 15 > 15.in
echo 16
./gen 1 300000 300000 300000 300000 10000 10000 10000 16 > 16.in
./gen 1 300000 300000 300000 300000 10000 10000 10000 17 > 17.in
./gen 1 300000 300000 300000 300000 10000 10000 10000 18 > 18.in
echo 19
./gen 1 300000 300000 300000 300000 0 100000 100000 19 > 19.in
./gen 1 300000 300000 300000 300000 0 100000 100000 20 > 20.in
./gen 1 300000 300000 300000 300000 0 100000 100000 21 > 21.in
echo 22
./gen 1 300000 300000 300000 300000 -10000 10000 10000 22 > 22.in
./gen 1 300000 300000 300000 300000 -10000 10000 10000 23 > 23.in
./gen 1 300000 300000 300000 300000 -10000 10000 10000 24 > 24.in
cd ..

mkdir final_tests

for i in {1..9}
do
    ./xor-test < tests/0$i.in > final_tests/0$i.in
    ./validator < final_tests/0$i.in
done
for i in {10..22}
do
    ./xor-test < tests/$i.in > final_tests/$i.in
    ./validator < final_tests/$i.in
done


