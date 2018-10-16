
package exchange.station;

import currency.converter.CurrencyConverter;
import java.util.Scanner;

public class ExchangeStation {
    Scanner scanner;
    Boolean running;
    double CADrate;
    double Xenorate;
    
    CurrencyConverter converter;
    
    public void interaction(){  
        //initialize scanner
        scanner = new Scanner(System.in);
        
        //Get exchange rates
        System.out.println("Type the exchange rates.");
        CADrate = scanner.nextDouble();
        Xenorate = scanner.nextDouble();
        
        //initialize CurrencyConverter
        converter = new CurrencyConverter(CADrate, Xenorate);
        
        System.out.println("Type your action");
        
        //get values for stuff
        double amount = scanner.nextDouble();
        String action = scanner.next();
        String currency = scanner.next();
        
        //Check what action the user has chosen, respond accordingly
        if (action.equals("sell")) {
            System.out.print("Selling " + amount + " " + currency + " = " + converter.Convert(amount, action) + " CAD");
        }
        if (action.equals("buy")) {
            System.out.println("Buying" + amount + " CAD = " + converter.Convert(amount, action) + " " + currency);
        }
    }    
    
    public static void main(String[] args) {
        ExchangeStation exchange = new ExchangeStation();
        
        exchange.interaction();
    }
    
}
