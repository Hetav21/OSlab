echo "Name: Hetav Shah"
echo "Roll no: 198"

while true
do
    echo -e "Menu:"
    echo "Enter 1 for grep command"
    echo "Enter 2 for egrep command"
    echo "Enter 3 for fgrep command"
    echo "Enter 4 to exit"

    read -rp "Select an option: " opt

    case $opt in
        1)  read -rp "For single pattern, enter any character: " x
            grep -e "$x" comic.txt
            ;;
        2)  read -rp "For double pattern, enter any character: " y
            grep -E "$y" comic.txt
            ;;
        3)  read -rp "For pattern from file, enter any word: " z
            grep -F "$z" comic.txt
            ;;
        4)  echo "Exiting..."
            break
            ;;
        *)  echo "Invalid choice"
            ;;
    esac

    read -p "Do you want to continue? [y/n]: " t
    if [[ "$t" != "y" ]]; then
        echo "Exiting..."
        break
    fi
done