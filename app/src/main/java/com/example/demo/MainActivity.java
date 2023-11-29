package com.example.demo;

import androidx.appcompat.app.AppCompatActivity;


import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.os.Bundle;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.demo.JniClass.MyStruct;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private static final int case1 = 1;
    private static final int case2 = 2;
    private static String TAG = "LHLOG";
    private TextView textView;
    private Handler handler;
    private MyStruct myStruct;
    HandlerThread handlerThread = new HandlerThread("MyHandlerThread");


    //test jni
    public native String getStringFromJNI();

    public native MyStruct getStruct(int x);

    static {
        System.loadLibrary("native-lib");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        handlerThread.start();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        Button button = findViewById(R.id.handler);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG, "handleMessage: onClick 1111111");
                Message message = handler.obtainMessage(case1, "Hello from background thread!");

                // 发送消息到主线程
                handler.sendMessage(message);
            }
        });


        Button button2 = findViewById(R.id.handler2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG, "handleMessage: onClick 2222222");
                Message message = handler.obtainMessage(case2, "Hello from background thread!");

                // 发送消息到主线程
                handler.sendMessage(message);
            }
        });


        //JNI TETS
        Button TestJni = findViewById(R.id.TestJni);
        TestJni.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String result = getStringFromJNI();
                // 将结果显示在TextView中
                Log.d(TAG, "JNI TEST  +result：" + result);
                TextView textView = findViewById(R.id.sample_text);
                textView.setText(result);
                Log.d(TAG, "JNI TEST  +getStruct：");
                int x = 1;
                MyStruct struct = getStruct(x);
                int intValue = struct.intValue;
                float floatValue = struct.floatValue;
                Log.d(TAG, "JNI TEST  struct intValue  ：" + intValue + "floatValue :" + floatValue);
            }
        });


        new Thread(new Runnable() {
            @Override
            public void run() {
                handler = new Handler(Looper.getMainLooper()) {
                    @Override
                    public void handleMessage(Message msg) {
                        Log.d(TAG, "handleMessage: msg.what " + msg.what);
                        if (msg.what == case1) {
                            EditText editText = findViewById(R.id.etNum);
                            String inputText = editText.getText().toString();
                            Log.d(TAG, "handleMessage: inputText " + inputText);
                            TextView marqueeText = findViewById(R.id.textView);
                            marqueeText.setText(inputText);
                        }
                    }
                };
            }
        }).start();

        new Thread(new Runnable() {
            @Override
            public void run() {
                // 模拟耗时操作
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                // 创建消息对象
                Message message = Message.obtain();
                message.what = 1;
                message.obj = "Hello from background thread";

                // 发送消息给主线程
                Log.d(TAG, "LHLOG ---- Thread: msg.what " + message.obj);
                handler.sendMessage(message);
            }
        }).start();
        findViewById(R.id.Goto_audiotrack).setOnClickListener(v -> {
            Log.i("LHLOG ", "GO TO AUDIO TEST");
            startActivity(new Intent(this, audioTrack.class));
        });
    }
}


