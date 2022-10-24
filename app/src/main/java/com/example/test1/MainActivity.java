package com.example.test1;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    EditText editText_a;
    EditText editText_b;
    TextView textView_sum;
    Button buttonSum;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editText_a = findViewById(R.id.editText_a);
        editText_b = findViewById(R.id.editText_b);
        textView_sum = findViewById(R.id.textView_sum);
        buttonSum = findViewById(R.id.buttonSum);
    }

    public void onClick(View v) {
        double a, b, c;

        try {

            a = Double.parseDouble(editText_a.getText().toString().trim());
            b = Double.parseDouble(editText_b.getText().toString().trim());

            c = a + b;

            textView_sum.setText(String.valueOf(c));

        } catch (Exception e) {

            textView_sum.setText("Неверные входные данные для расчета!");

        }

    }

}
