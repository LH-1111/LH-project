#include <SFML/Audio.hpp>

int main() {
    // 创建音频对象
    sf::Music music;

    // 加载音频文件
    if (!music.openFromFile("2023-11-03_09-05-08_dump_dirana_io-s32-8ch-48000Hz.wav")) {
        return -1; // 错误处理，文件加载失败
    }

    // 播放音频
    music.play();

    // 持续运行，等待音频播放完成
    while (music.getStatus() == sf::Music::Playing) {
        // 可以在这里添加其他操作
    }

    return 0;
}
