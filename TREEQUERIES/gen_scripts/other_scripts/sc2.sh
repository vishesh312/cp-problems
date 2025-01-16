for i in {1..9}
do
    echo $i
    ./validator < final_tests/0$i.in
    ./ritul-sol < final_tests/0$i.in > final_tests/0$i.out
done
for i in {10..24}
do
    echo $i
    ./validator < final_tests/$i.in
    ./ritul-sol < final_tests/$i.in > final_tests/$i.out
done


