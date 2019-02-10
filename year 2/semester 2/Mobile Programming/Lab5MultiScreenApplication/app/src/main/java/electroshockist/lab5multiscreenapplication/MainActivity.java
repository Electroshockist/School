package electroshockist.lab5multiscreenapplication;

import android.content.Intent;
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

        //sets title when created(for when you return from receipt screen)
        this.setTitle(R.string.title);

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

    //sets total and total text
    void setTotal(){
        pizza.setTotal(pizza.getSizePrice() + pizza.getCheesePrice() + pizza.getCrustPrice() + pizza.getPineapplePrice());
        total.setText("Total: $" + Double.toString(pizza.getTotal()));
    }

    //place order and show receipt
    public void placeOrder(View view) {
        if(pizza.getSizePrice() <= 0) Toast.makeText(this, "Please specify a size.", Toast.LENGTH_SHORT).show();
        else {

            Intent intent = new Intent(this, MainActivity2.class);
            //add values to second screen
            intent.putExtra("total", pizza.getTotal());
            intent.putExtra("size", pizza.getSizePrice());
            intent.putExtra("cheese", pizza.getCheesePrice());
            intent.putExtra("crust", pizza.getCrustPrice());
            intent.putExtra("pineapple", pizza.getPineapplePrice());

            startActivity(intent);

            Toast.makeText(this, "Order Placed!", Toast.LENGTH_SHORT).show();
        }
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