package currency.converter;

public class CurrencyConverter {
    double CADrate;
    double Xenorate;

    public CurrencyConverter(double CADrate, double Xenorate) {
        this.CADrate = CADrate;
        this.Xenorate = Xenorate;
    }
    
     public double Convert(double amount, String action){
         amount *= CADrate;
         switch (action){
             case "buy":
                 amount *= Xenorate;
                 break;
             case "sell":
                 amount /= Xenorate;
                 break;
             default:
                 System.out.println(action + " is not a valid value. Please use either buy or sell");                 
         }
         System.out.println(amount);
         return amount;
      }
  }
