package com.feterpig.puzzlegame.ui;

import javax.swing.*;

public class GameJFrame extends JFrame {
    // 游戏主界面
    public GameJFrame() {
        // 初始化窗体
        initFrame();

        // 初始化菜单栏
        initMenu();

        // 窗体可见
        this.setVisible(true);
    }

    private void initFrame() {
        // 窗体大小
        this.setSize(603, 680);

        // 窗体标题
        this.setTitle("Puzzle Game --by pxb");

        // 窗体置顶
        this.setAlwaysOnTop(true);

        // 窗体居中
        this.setLocationRelativeTo(null);

        // 禁用最大化
        this.setResizable(false);

        // 设置程序关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }

    private void initMenu() {
        // 菜单条
        JMenuBar jMenuBar = new JMenuBar();
        jMenuBar.setSize(514, 20);

        // 游戏菜单
        JMenu jMenu1 = new JMenu("游戏菜单");
        JMenuItem jMenuItem11 = new JMenuItem("重新游戏");
        JMenuItem jMenuItem12 = new JMenuItem("选择难度");
        JMenuItem jMenuItem13 = new JMenuItem("一键通关");
        JMenuItem jMenuItem14 = new JMenuItem("退出游戏");

        // 联系我们
        JMenu jMenu2 = new JMenu("联系我们");
        JMenuItem jMenuItem21 = new JMenuItem("GitHub");
        JMenuItem jMenuItem22 = new JMenuItem("个人主页");

        // 菜单结构
        jMenu1.add(jMenuItem11);
        jMenu1.add(jMenuItem12);
        jMenu1.add(jMenuItem13);
        jMenu1.add(jMenuItem14);
        jMenu2.add(jMenuItem21);
        jMenu2.add(jMenuItem22);
        jMenuBar.add(jMenu1);
        jMenuBar.add(jMenu2);
        this.setJMenuBar(jMenuBar);
    }
}
