echo "Name: Hetav"
echo "Roll no: 198"

echo "Calculator"

read -p "Select one symbol = " ch

echo "+ Add"
echo "- Sub"
echo "/* Mul"
echo "/ Div"

read -p "Enter no1 = " n1
read -p "Enter no2 = " n2

case $ch in
+) sum=` expr $n1 + $n2 `
echo "$n1 + $n2 = $sum";;

-) Sub=` expr $n1 - $n2 `
echo "$n1 - $n2 = $Sub";;

\*) Mul=` expr $n1 \* $n2 `
echo "$n1 * $n2 = $Mul";;

/) Div=` expr $n1 / $n2 `
echo "$n1 / $n2 = $Div";;

*) echo "Invalid Choice"

esac