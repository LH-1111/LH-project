package com.example.demo;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MediaPlayerDemo extends AppCompatActivity {

    private MediaPlayer mediaPlayer;
    private boolean isPlaying = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test_mediaplayer);

        // 初始化 MediaPlayer
        mediaPlayer = MediaPlayer.create(this, R.raw.likeyou);

        // 设置播放完成监听器
        mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mediaPlayer) {
                // 播放完成后的操作
                isPlaying = false;
            }
        });

        // 获取播放按钮
        Button playButton = findViewById(R.id.playButton);

        // 设置播放按钮点击事件
        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!isPlaying) {
                    // 开始播放
                    mediaPlayer.start();
                    isPlaying = true;
                } else {
                    // 暂停播放
                    mediaPlayer.pause();
                    isPlaying = false;
                }
            }
        });
    }

    @Override
    protected void onDestroy() {
        // 释放 MediaPlayer 资源
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }

        super.onDestroy();
    }
}
