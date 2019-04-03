package towe.def;

/**
 * Main.java 
 * MIDTERM PROJECT "Tower Defence" 
 * * If you update this code, Your comments should start with your INITIALS!***
 */

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

public class Main extends Activity {
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // special screen orientation is required      
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

        // full-screen app
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
       requestWindowFeature(Window.FEATURE_NO_TITLE);
        
        setContentView(new GameView(this));
    }
}