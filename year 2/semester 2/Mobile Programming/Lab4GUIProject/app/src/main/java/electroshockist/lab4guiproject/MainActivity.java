package electroshockist.lab4guiproject;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    EditText[] Num = new EditText[2];
    TextView result;
    Button AddButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Num[0] = findViewById(R.id.Num1);
        Num[1] = findViewById(R.id.Num2);
        result = findViewById(R.id.Answer);
        AddButton = findViewById(R.id.Add);
    }

    public void onAdd(View view){
        int num[] = new int[2];
        num[0] = Integer.parseInt(Num[0].getText().toString());
        num[1] = Integer.parseInt(Num[1].getText().toString());

        int sum = num[0] + num[1];

        result.setText(Integer.toString(sum));
    }
}
