package electroshockist.helloworld;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    int totalClicks = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick(View view) {
        TextView text = (TextView) findViewById(R.id.textView);
        text.setText("Button clicked " + ++totalClicks + " times.");
        //View layout = findViewById(R.id.)
//        ConstraintLayout layout = findViewById(R.id.layout1);
//        layout.setBackgroundColor(Color.CYAN); // feel free to use any color of your choice
    }
}
