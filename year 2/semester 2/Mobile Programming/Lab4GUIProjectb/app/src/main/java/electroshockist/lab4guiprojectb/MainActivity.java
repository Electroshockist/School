package electroshockist.lab4guiprojectb;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    RadioGroup rg;
    TextView txt;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        rg = findViewById(R.id.RadioGroup1);
        txt =findViewById(R.id.Text);

        rg.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton rb = findViewById(checkedId);
                switch (checkedId){
                    case R.id.radioButton1:
                        txt.setTextColor(Color.RED);
                        break;
                    case R.id.radioButton2:
                        txt.setTextColor(Color.GREEN);
                        break;
                    case  R.id.radioButton3:
                        txt.setTextColor(Color.BLUE);
                        break;
                }
            }
        });
    }
}
