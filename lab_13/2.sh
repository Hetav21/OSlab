echo "Hetav Shah"
echo "198"

read -p "Enter an angle(in radians): " num

echo "Cosine of $num:"
echo "$num" | awk '{print cos($1)}'

echo "Sine of $num:"
echo "$num" | awk '{print sin($1)}'