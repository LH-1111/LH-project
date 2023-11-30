package com.example.demo;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.media.AudioManager;

import androidx.appcompat.app.AppCompatActivity;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class audioTrack extends AppCompatActivity {
    private static final int SAMPLE_RATE = 48000; // 采样率，通常为44100Hz
    private static final int CHANNEL_CONFIG = AudioFormat.CHANNEL_OUT_MONO; // 单声道
    private static final int AUDIO_FORMAT = AudioFormat.ENCODING_PCM_16BIT; // 16位PCM

    private static final int bufferSize = AudioTrack.getMinBufferSize(SAMPLE_RATE, CHANNEL_CONFIG, AUDIO_FORMAT);
    ; //audiotrack buffer size
    private AudioTrack audioTrack;

    private static String TAG = "LHLOG";


    AudioManager.OnAudioFocusChangeListener audioFocusChangeListener = new AudioManager.OnAudioFocusChangeListener() {
        @Override
        public void onAudioFocusChange(int focusChange) {
            switch (focusChange) {
                case AudioManager.AUDIOFOCUS_GAIN:
                    // 获得焦点，可以继续播放音频
                    break;
                case AudioManager.AUDIOFOCUS_LOSS:
                case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT:
                    // 失去焦点，暂停或停止播放音频
                    break;
                case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK:
                    // 失去焦点，可以降低音量或暂停播放音频
                    break;
            }
        }
    };

    //create Music audiotrack
    public AudioTrack createaudiotrack() {
        Log.d(TAG, "createaudiotrack:  " + AudioManager.STREAM_MUSIC);
        audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, SAMPLE_RATE, CHANNEL_CONFIG, AUDIO_FORMAT, bufferSize, AudioTrack.MODE_STREAM);
        return audioTrack;
    }

    private void playAudio() {
        Log.d(TAG, "playAudio: 000000000");

        audioTrack.play();
        // 开始播放
        // 模拟PCM音频数据，实际中您需要替换为实际的音频数据
        short[] audioData = generateAudioData();
        audioTrack.write(audioData, 0, audioData.length); // 将音频数据写入AudioTrack
        //java dump audiodata
        String filePath = "/data/user/11/com.example.demo/files/audiodump" ;
        try {
            // 创建一个 FileOutputStream 对象，并指定文件路径
            FileOutputStream fileOutputStream = new FileOutputStream(filePath);

            // 使用 DataOutputStream 将数据写入文件
            DataOutputStream dataOutputStream = new DataOutputStream(fileOutputStream);

            // 写入不同类型的数据
            for (short value : audioData) {
                dataOutputStream.writeShort(value);
            }

            // 关闭资源
            dataOutputStream.close();
            fileOutputStream.close();

            Log.d(TAG,"Data stream writing is successful!");
        } catch (IOException e) {
            Log.d(TAG,"An error occurred while writing the data stream: " + e.getMessage());
            e.printStackTrace();
        }
        Log.d(TAG, "playAudio: 11111111");

    }

    private short[] generateAudioData() {
        // 在这里生成您的PCM音频数据，以short数组的形式返回
        // 请注意，这只是一个示例，您需要使用实际的音频数据生成方法
        // 通常，音频数据以16位PCM样本的形式存储在short数组中
        // 例如：short[] audioData = {sample1, sample2, sample3, ...};
        // 示例：生成一个简单的正弦波声音
        int numSamples = SAMPLE_RATE * 2; // 2秒的音频数据
        double sampleRate = (double) SAMPLE_RATE;
        double frequency = 440.0; // 440Hz的A音
        short[] audioData = new short[numSamples];

        for (int i = 0; i < numSamples; i++) {
            double t = (double) i / sampleRate;
            double sineWave = Math.sin(2.0 * Math.PI * frequency * t);
            audioData[i] = (short) (sineWave * Short.MAX_VALUE);
        }
        return audioData;
    }

    //Stop audiotrack
    private void stopAudio() {
        Log.d(TAG, "stopAudio strat");
        audioTrack.stop(); // 停止播放
        Log.d(TAG, "stopAudio end");
        audioTrack.release(); // 释放资源
        Log.d(TAG, "releaseaudiotrack");
    }

    protected void onCreate(Bundle savedInstanceState) {
        AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test_audiotrack);
        //Create audiotrack
        Button button_Create = findViewById(R.id.Create_audiotrack);
        button_Create.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                audioTrack = createaudiotrack();
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
                    Log.e(TAG, "Createaudiotrack streamtype : " + audioTrack.getAudioAttributes());
                }

            }
        });
        //Play audiotrack
        Button button_Play = findViewById(R.id.Play_audiotrack);
        button_Play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int result = audioManager.requestAudioFocus(
                        audioFocusChangeListener,
                        AudioManager.STREAM_MUSIC,
                        AudioManager.AUDIOFOCUS_GAIN);
                if (result == AudioManager.AUDIOFOCUS_GAIN && audioTrack != null) {
                    playAudio();
                } else {
                    Log.e(TAG, "button_Play error because audiofocus error or audiotrack is null");
                }
            }
        });
        //stop audiotrack
        Button button_stop = findViewById(R.id.Stop_audiotrack);
        button_stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int ruselt = audioManager.abandonAudioFocus(audioFocusChangeListener);
                if (ruselt == audioManager.AUDIOFOCUS_LOSS) {
                    stopAudio();
                }
            }
        });
    }
}
