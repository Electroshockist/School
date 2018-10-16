package currency.converter;

public class CurrencyConverter {
    public final String USD = "USD";
    public final String CAD = "CAD";
    public final String Euro = "Euro";    
    
    double Euroval = 0.66;
    double USDval = 0.77;
    
     public double Convert(double value, String choice){
         
         switch (choice){
             case USD:
                 value *= USDval;
                 break;
             case Euro:
                 value *= Euroval;
                 break;
             default:
                 System.out.println(choice + " is not a valid value. Please use either " + USD + " or " + Euro);
                 break;
          }
         return value;
      }
  }
