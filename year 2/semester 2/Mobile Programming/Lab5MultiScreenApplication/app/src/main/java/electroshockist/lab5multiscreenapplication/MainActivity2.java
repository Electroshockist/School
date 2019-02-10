package electroshockist.lab5multiscreenapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    TextView text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        text = findViewById(R.id.receiptText);

        Intent data = getIntent();

        double total = data.getDoubleExtra("total", -1);
        double size = data.getDoubleExtra("size", -1);
        double cheese = data.getDoubleExtra("cheese", -1);
        double crust = data.getDoubleExtra("crust", -1);
        double pineapple = data.getDoubleExtra("pineapple", -1);

        String fullText = "Size: $" + Double.toString(size);
        if(cheese > 0) fullText += "\nCheese: $" + Double.toString(cheese);
        if(crust > 0) fullText += "\nCrust: $" + Double.toString(crust);
        if(pineapple > 0) fullText += "\nPineapple: $" + Double.toString(pineapple);
        fullText += "\n\nTotal: $" + Double.toString(total);

        text.setText(fullText);

        this.setTitle("Receipt");
    }

    public void returnToMenu(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}
