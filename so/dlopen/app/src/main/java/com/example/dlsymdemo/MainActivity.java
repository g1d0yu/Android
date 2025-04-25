package com.example.dlsymdemo;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("test");
    }
    String result;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = findViewById(R.id.textView);
        TextView button = findViewById(R.id.button);
        button.setOnClickListener((view -> {
            result = callOtherSo();
            textView.setText(result);
        }));
    }

    public native String callOtherSo();
}

