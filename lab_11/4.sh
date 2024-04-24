gr8() {
    echo "Num1: $1"
    echo "Num2: $2"

    if [[ $1 -ge $2 ]]
    then 
        echo "$1 is gr8r"
    else 
        echo "$2 is gr8r"
    fi

}

echo "Enter two no:"
read a b
gr8 $a $b

echo ""
echo ""

gr8 9 7
