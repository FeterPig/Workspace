package com.feterpig.puzzlegame;

import javax.swing.*;
import java.net.URL;
import java.util.Random;

public class GameJFrame extends JFrame {
    int[][] data = new int[4][4];

    // 游戏主界面
    public GameJFrame() {
        // 初始化窗体
        initFrame();

        // 初始化菜单栏
        initMenu();

        // 初始化数据
        initData();

        // 初始化图片
        int x = 0;
        int y = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                initImage("/image/puzzle/1/" + data[i][j] + ".jpg", x + 105 * j, y + 105 * i);
            }
        }

        // 窗体可见
        this.setVisible(true);
    }

    private void initData() {
        int[] tempArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        Random r = new Random();

        for (int i = 0; i < tempArr.length; i++) {
            int index = r.nextInt(tempArr.length);
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }

        for (int i = 0; i < tempArr.length; i++) {
            data[i / 4][i % 4] = tempArr[i];
        }
    }

    private void initImage(String file, int x, int y) {
        URL resourceUrl = this.getClass().getResource(file);
        ImageIcon icon = null;

        // 判断是否为最后一张图
        if (resourceUrl != null) {
            icon = new ImageIcon(resourceUrl);
        }

        JLabel jLabel = new JLabel(icon);
        jLabel.setBounds(x, y, 105, 105);
        this.getContentPane().add(jLabel);
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

        // 取消默认居中放置
        this.setLayout(null);

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
