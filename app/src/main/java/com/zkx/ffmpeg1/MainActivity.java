package com.zkx.ffmpeg1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.zkx.myplayer.Demo;

import java.util.Collection;
import java.util.Iterator;
import java.util.Queue;

public class  MainActivity extends AppCompatActivity {

    private ThreadDemo threadDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        threadDemo = new ThreadDemo();


    }

    public void normal(View view) {
        threadDemo.normalThread();
    }

    public void mutexThread(View view) {
        threadDemo.mutexThread();
    }
}
