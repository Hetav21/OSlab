echo "Name: Hetav Shah"
echo "Roll no: 198"
echo ""
isPali() {
    str=$1
    rav=$(echo $str | rev)

    if [[ "$str" == "$rav" ]]
    then 
        echo "$1 is Palindrome"
    else 
        echo "$1 is not an Palindrome"
    fi
}
isPaliNew() {
    str=$1

    n=${#str}

    for ((i=0; i<n/2; i++))
    do 
        str1=${str:i:1}
        str2=${str:n-i-1:1}
       
        if [[ "$str1" != "$str2" ]]
        then 
            echo "$1 is not a Palindrome"
            return
            break
        fi
    done

    echo "$1 is a Palindrome"
}
while true
do
    echo "Menu Program to check if string is palindrome"

    printf "\n"
    read -p "Enter Argument = " str
    printf "\n"

    isPaliNew $str

    echo ""
    read -p "Do you want to continue? [y/n]: " t
    if [ "$t" != "y" ]; then
        echo "Exiting..."
        break
    fi
done
