read -p "Enter a: " a

    result=1

    for((i=1; i<=$a; i++))
    do 
        result=` expr $result * $i `    
    done

echo "Factorial of $a is $result"

# 1 2 6