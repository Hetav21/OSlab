echo "Name: Hetav"
echo "Roll No: 198"

fibo() {
    local num=$1
    if [ $num -le 0 ]; then
        echo 0
    elif [ $num -eq 1 ]; then
        echo 1
    else
        local a=$(( $(fibo $((num - 1))) + $(fibo $((num - 2))) ))
        echo $a
    fi
}

read -p "Enter n: " n

result=$(fibo $n)

for ((i=0; i<=$n; i++))
do
    echo "$(fibo $i) "
done

echo "Fibonacci of $n is: $result"

# 1 1 2 3 5 8