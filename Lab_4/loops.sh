echo "Name: Hetav Shah"
echo "Roll no: 198"

for T in {2..20..2}
do 
    echo "Table for 2: $T"
done

for ((i=0; i<10; i++))
do 
    echo "$i"
done

a=0
while [ $a -lt 10 ]
do 
    echo "$a"
    if [ $a -eq 5 ]
    then 
        break
    fi
    a=` expr $a + 1 `
done

a=0
until [ $a -lt 10 ]
do
    echo "$a"
    a=` expr $a + 1 `
done