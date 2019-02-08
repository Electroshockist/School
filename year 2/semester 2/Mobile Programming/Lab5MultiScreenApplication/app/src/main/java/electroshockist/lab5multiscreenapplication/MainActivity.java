package electroshockist.lab5multiscreenapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Pizza pizza;

    TextView total;

    RadioGroup radioGroup;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Initialize();
    }

    void Initialize(){
        pizza = new Pizza();
        radioGroup = findViewById(R.id.Size);

        total = findViewById(R.id.Total);
    }

    //activated exclusively by radioboxes
    public void radioClicked(View view) {
        boolean checked = ((RadioButton)view).isChecked();
        switch (view.getId()){
            case R.id.size1:
                if(checked) pizza.setSizePrice(5);
                break;
            case R.id.size2:
                if(checked) pizza.setSizePrice(7);
                break;
            case R.id.size3:
                if(checked) pizza.setSizePrice(9);
                break;
        }
        setTotal();
    }

    //activated exclusively by checkboxes
    public void onCheckBoxClicked(View view) {
        boolean checked = ((CheckBox)view).isChecked();

        switch (view.getId()){
            case R.id.Cheese:
                if(checked) pizza.setCheesePrice(1);
                else pizza.setCheesePrice(0);
                break;
            case R.id.Crust:
                if(checked) pizza.setCrustPrice(0.5);
                else pizza.setCrustPrice(0);
                break;
            case R.id.Pineapple:
                if(checked) pizza.setPineapplePrice(0.25);
                else pizza.setPineapplePrice(0);
                break;
        }
        setTotal();
    }

    //sets total text
    void setTotal(){
        total.setText("Total: " + Double.toString(pizza.getSizePrice() + pizza.getCheesePrice() + pizza.getCrustPrice() + pizza.getPineapplePrice()));
    }

    //set toast on button press
    public void placeOrder(View view) {
        Toast.makeText(this, "Order Placed!", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        outState.putDouble("sizePrice",pizza.getSizePrice());
        outState.putDouble("cheesePrice", pizza.getCheesePrice());
        outState.putDouble("crustPrice", pizza.getCrustPrice());
        outState.putDouble("pineapplePrice", pizza.getPineapplePrice());
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        pizza.setSizePrice(savedInstanceState.getDouble("sizePrice"));
        pizza.setCheesePrice(savedInstanceState.getDouble("cheesePrice"));
        pizza.setCrustPrice(savedInstanceState.getDouble("crustPrice"));
        pizza.setPineapplePrice(savedInstanceState.getDouble("pineapplePrice"));
        //resets text to correct price
        setTotal();
    }
}