echo "Name: Hetav Shah"
echo "Roll No: 198"

read -p "Enter num: " n

echo "1 is not prime nor composite"
i=2
while [ $n -gt 0 ]
do 
    f=0
    for ((j=2; j<=i/2; j++))
    do
        a=$((i%j))
        if [ $a -eq 0 ]
        then 
            f=1
            # if [ $i -eq $n ]; then
                echo "$i is composite"
            # fi
            break
        fi
    done
    if [ $f -eq 0 ]
    then
        # if [ $i -eq $n ]; then
            echo "$i is prime"
            n=` expr $n - 1 `
        # fi
    fi
    i=` expr $i + 1 `
done 