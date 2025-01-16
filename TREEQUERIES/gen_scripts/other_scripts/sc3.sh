for i in {1..9}
do
    echo $i
    ./v2 < tests/0$i.in
done
for i in {10..24}
do
    echo $i
    ./v2 < tests/$i.in
done


