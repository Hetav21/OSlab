echo "Hetav Shah"
echo "198"

read -p "Enter your name: " str

echo "Name in UpperCase: "
echo "$str" | awk '{print toupper($str)}'

echo "Name in LowerCase: "
echo "$str" | awk '{print tolower($str)}'