mkdir final_tests

for i in {1..9}
do
    echo $i
    ./xor-test < tests-backup/0$i.in > final_tests/0$i.in
    ./ritul-sol < final_tests/0$i.in > final_tests/0$i.out
#   ./validator < final_tests/0$i.in
done
for i in {10..10}
do
    echo $i
    ./xor-test < tests-backup/$i.in > final_tests/$i.in
    ./ritul-sol < final_tests/$i.in > final_tests/$i.out
#   ./validator < final_tests/$i.in
done



