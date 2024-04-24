echo "Name: Hetav"
echo "Roll no: 198"

while (true)
do
printf "\n\n"
echo "MENU: "

echo "1. Month's Calender"
echo "2. Today's Date && Time"
echo "3. User's logged in"
echo "4. Name at (x, y) position"
echo "5. Active Terminal Number"
echo "6. EXIT"

printf "\n"
read -p "Select one option = " num
printf "\n\n"

case $num in
1) echo "Calender: "
cal;; 

2) echo "Today's Date: "
date +%D
echo "Today's Time: "
date +%T
;;

3) echo "User's Logged in: "
who
echo "Current user details: "
whoami;; 

4) printf "%10s %20s \nHetav Shah\n";;

5) x=$(tty)
echo "Terminal Number: ${x:9}";;

6) echo "EXITING...."
break;;

*) echo "Invalid Choice";;

esac
done  