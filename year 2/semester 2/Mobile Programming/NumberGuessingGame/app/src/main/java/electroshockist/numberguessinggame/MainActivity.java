package electroshockist.numberguessinggame;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    Button buttonL, buttonR;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        DataModel dataModel = new DataModel();

        buttonL = findViewById(R.id.button1);
        buttonL.setText(Integer.toString(dataModel.getNum1()));


        buttonR = findViewById(R.id.button2);
        buttonR.setText(Integer.toString(dataModel.getNum2()));

    }
}
