echo "Name: Hetav Shah"
echo "Roll No: 198"

read -p "Enter a: " a
result=1

for ((i=1; i<=$a; i++))
do 
    temp=$((result*i))    
    result=$temp
done

echo "Factorial of $a is $result"

# 1 2 6