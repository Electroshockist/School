package com.example.fuck;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    ImageView die1, die2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        die1 = findViewById(R.id.Die1);
        die2 = findViewById(R.id.Die2);
    }

    public void onClick(View view) {
        Random r = new Random();
        int rand1 = r.nextInt(6);
        int rand2 = r.nextInt(6);

        die1.setImageResource(determineImage(rand1));
        die2.setImageResource(determineImage(rand2));
    }

    private int determineImage(int x) {
        switch (x) {
            case 0:
                return R.drawable.die1;
            case 1:
                return R.drawable.die2;
            case 2:
                return R.drawable.die3;
            case 3:
                return R.drawable.die4;
            case 4:
                return R.drawable.die5;
            case 5:
                return R.drawable.die6;
        }
        return R.id.invisible;
    }
}
