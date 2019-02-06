package electroshockist.lab5gui;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText num[] = new EditText[2];
    TextView result;
    Button addButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        num[0] = findViewById(R.id.Num1);
        num[1] = findViewById(R.id.Num2);
        result = findViewById(R.id.Result);
        addButton = findViewById(R.id.Add);
    }

    public void add(View view){
        int tnum[] = new int[2];
        tnum[0] = Integer.parseInt(num[0].getText().toString());
        tnum[1] = Integer.parseInt(num[1].getText().toString());

        int sum = tnum[0] + tnum[1];

        result.setText(Integer.toString(sum));
    }
}
