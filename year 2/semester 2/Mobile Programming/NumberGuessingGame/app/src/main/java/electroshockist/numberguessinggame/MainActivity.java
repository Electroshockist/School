package electroshockist.numberguessinggame;

import android.graphics.Color;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    int points = 0;
    final int winPoints = 5;
    Button buttonL, buttonR;
    DataModel dataModel;

    String endText = "";
    TextView result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dataModel = new DataModel();

        result = findViewById(R.id.points);

        SetButtons();

    }

    public void OnClick(View view) {
        String toastTest;
        if(!endConditions(winPoints)) {
            Button temp = (Button) view;
            String txt = (String) temp.getText();
            String ans = Integer.toString(dataModel.getHighest());

            if (txt.equals(ans)) {
                toastTest = "Correct!";
                points++;
            } else {
                toastTest = "False!";
                points--;
            }

            result.setText("Points: " + points);

            SetButtons();
        }
        else toastTest = "You " + endText + "!";

        Toast.makeText(this, toastTest, Toast.LENGTH_SHORT).show();
        endConditions(winPoints);
    }

    private void SetButtons(){
        dataModel.rollNumbers();

        buttonL = findViewById(R.id.button1);
        buttonL.setText(Integer.toString(dataModel.getNum1()));


        buttonR = findViewById(R.id.button2);
        buttonR.setText(Integer.toString(dataModel.getNum2()));
    }

    private boolean endConditions(int winPoints){
        ConstraintLayout layout = findViewById(R.id.layout1);
        boolean win = points >= winPoints;
        boolean lose = points < 0;

        endText = win ? "won" : endText;
        endText = lose ? "lost" : endText;

        Log.d("test", "You " + endText + "!");

        if (win||lose) Toast.makeText(this, "You " + endText + "!", Toast.LENGTH_SHORT).show();


        if(win) layout.setBackgroundColor(Color.GREEN);

        if(lose) layout.setBackgroundColor(Color.RED);

        return win || lose;
    }
}
