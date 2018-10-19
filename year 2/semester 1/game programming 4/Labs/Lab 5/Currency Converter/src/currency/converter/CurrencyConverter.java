package currency.converter;

public class CurrencyConverter {
    double CADrate;
    double Xenorate;

    public CurrencyConverter(double CADrate, double Xenorate) {
        this.CADrate = CADrate;
        this.Xenorate = Xenorate;
    }
    
     public double Convert(double amount, String action, String currency) throws UnknownCurrencyException, UnknownOperationException{
         amount *= CADrate;
         if (!currency.equals("USD") && !currency.equals("Euro"))throw new UnknownCurrencyException("Unknown currency");
         switch (action){
            case "buy":
                amount *= Xenorate;
                break;
            case "sell":
                amount /= Xenorate;
                break;
            default:
                throw new UnknownOperationException("Unknown operation");
         }
         return amount;
      }
  }
