package electroshockist.layoutchanger;

import android.graphics.drawable.Drawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    boolean textVisible = true;
    boolean swappedImage = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ImageView iv = findViewById(R.id.swappableImage);
        iv.setImageResource(R.drawable.android1);
    }

    //toggles text visibility
    public void toggleText(View view){
        textVisible = !textVisible;

        TextView tv = findViewById(R.id.textView);

        if(!textVisible) tv.setVisibility(View.INVISIBLE);
        else tv.setVisibility(View.VISIBLE);
    }

    //swaps image
    public void swapImage(View view){
        swappedImage = !swappedImage;

        ImageView iv = findViewById(R.id.swappableImage);

        if(swappedImage) iv.setImageResource(R.drawable.android2);
        else  iv.setImageResource(R.drawable.android1);

    }
}
