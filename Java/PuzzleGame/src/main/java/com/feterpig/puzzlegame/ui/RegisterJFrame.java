package com.feterpig.puzzlegame.ui;

import javax.swing.*;

public class RegisterJFrame extends JFrame {
    // 注册页面
    public RegisterJFrame() {
        // 初始化窗体
        initFrame();

        // 窗体可见
        this.setVisible(true);
    }

    private void initFrame() {
        // 窗体大小
        this.setSize(488, 500);

        // 窗体标题
        this.setTitle("Registering...");

        // 窗体置顶
        this.setAlwaysOnTop(true);

        // 窗体居中
        this.setLocationRelativeTo(null);

        // 禁用最大化
        this.setResizable(false);

        // 设置程序关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
}
