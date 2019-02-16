package electroshockist.lab6datastorage;

import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    EditText name, age;

    SharedPreferences preferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Initialize();
    }

    private void Initialize(){
        name = findViewById(R.id.nameField);
        age = findViewById(R.id.ageField);

        preferences = getPreferences(MODE_PRIVATE);

        readPreferences();
    }

    public void onSave(View view) {
        String nameText = name.getText().toString();
        int ageNum = Integer.parseInt(age.getText().toString());

        SharedPreferences.Editor editor = preferences.edit();
        editor.putString("name", nameText);
        editor.putInt("age", ageNum);
        editor.commit();
    }

    public void onReset(View view) {
        SharedPreferences.Editor editor = preferences.edit();
        editor.clear();
        editor.commit();
        readPreferences();
    }

    public void readPreferences(){
        String tempName = preferences.getString("name", "");
        int tempAge = preferences.getInt("age", 0);
        name.setText(tempName);
        age.setText(Integer.toString(tempAge));

    }
}
