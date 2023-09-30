import java.util.Scanner;

public class Card {
    public static void main(String[] args) {
        System.out.println("Enter Credit card Number");
        Scanner scanner = new Scanner(System.in);
        String card_number = scanner.nextLine();

        int lenght = get_lenght(card_number);
        int[] cardDigit = new int[lenght];
        
        for (int i = 0; i < card_number.length(); i++){
            cardDigit[i] = Character.getNumericValue(card_number.charAt(i));
        }
        if (isValid(cardDigit, lenght)) {
            System.out.println(getType(lenght, card_number));
        }
    }

    public static int get_lenght(String card_number) {
        int lenght = 0;
        for (int i = 0; i < card_number.length(); i++) {
            lenght++;
        }
        return lenght;
    }

    public static boolean isValid(int[] cardDigit, int lenght) {
        int sum = 0;
        for (int i = 0; i < lenght; i++) {
            int digit = cardDigit[i];
            if (lenght % 2 == 0) {
                if (i % 2 == 0) {
                    digit *= 2;

                    if (digit > 9) {
                        digit -= 9;
                    }
                    sum += digit;
                } else {
                    sum += digit;
                }
            } else {
                if (i % 2 != 0) {
                    digit *= 2;

                    if (digit > 9) {
                        digit =- 9;
                    }
                    sum += digit;
                } else {
                    sum += digit;
                }
            }
        }
        return sum % 10 == 0;
    }

    public static String getType(int lenght, String cardNumber) {
        if ((lenght == 16 || lenght == 13) && (40 <= Integer.parseInt(cardNumber.substring(0, 2)) && Integer.parseInt(cardNumber.substring(0, 2)) <= 49)) {
            return "VISA";
        } else if (lenght == 16 && (51 <= Integer.parseInt(cardNumber.substring(0, 2)) && Integer.parseInt(cardNumber.substring(0, 2)) <= 55)) {
            return "MASTERCARD";
        } else if (lenght == 15 && (Integer.parseInt(cardNumber.substring(0, 2)) == 34 || Integer.parseInt(cardNumber.substring(0, 2)) == 37)) {
            return "AMEX";
        } else {
            return "INVALID";
        }
    }
}