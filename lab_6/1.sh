echo "Name : Hetav Shah"
echo "Roll No : 198"
i=1
for A in "$@"
do
echo "Array $i : $A"
i=$((i+1))
done