echo "Enter num1: "
read num1
echo "Enter num2: "
read num2
echo "Enter num3: "
read num3

if [ $num1 -ge $num2 ]; then 
    if [ $num1 -ge $num3 ]; then
        gr8r=$num1
    else
        gr8r=$num3
    fi
elif [ $num1 -le $num2 ]; then
    if [ $num2 -ge $num3 ]; then
        gr8r=$num2
    else
        gr8r=$num3
    fi
fi

echo "gr8r number is $gr8r" 