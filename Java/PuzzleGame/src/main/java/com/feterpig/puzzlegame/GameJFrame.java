package com.feterpig.puzzlegame;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class GameJFrame extends JFrame implements KeyListener, ActionListener {
    // 菜单选项
    JMenuItem jMenuItem11 = new JMenuItem("重新游戏");
    //    JMenuItem jMenuItem12 = new JMenuItem("重新登录");
    JMenuItem jMenuItem13 = new JMenuItem("一键通关");
    JMenuItem jMenuItem14 = new JMenuItem("退出游戏");
    JMenuItem jMenuItem21 = new JMenuItem("GitHub");
    JMenuItem jMenuItem22 = new JMenuItem("个人主页");

    // 记录当前拼图状态
    int[][] data = new int[4][4];

    // 计数器
    int count = 0;

    // 空白方块位置
    int xBlock;
    int yBlock;

    // 胜利判定
    int[][] win = new int[][]{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 0}
    };

    // 游戏主界面
    public GameJFrame() {
        // 初始化窗体
        initFrame();

        // 初始化菜单栏
        initMenu();

        // 初始化数据
        initData();

        // 初始化图片
        initImage();

        // 窗体可见
        this.setVisible(true);
    }

    public boolean isWin() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (data[i][j] != win[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    private void initData() {
        int[] tempArr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        Random r = new Random();

        for (int i = 0; i < tempArr.length; i++) {
            int index = r.nextInt(tempArr.length);
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }

        for (int i = 0; i < tempArr.length; i++) {
            if (tempArr[i] == 0) {
                xBlock = i / 4;
                yBlock = i % 4;
            }
            data[i / 4][i % 4] = tempArr[i];
        }
    }

    private void initImage() {
        // 清空原本已经出现的所有图片
        this.getContentPane().removeAll();

        // 如果胜利
        if (isWin()) {
            ImageIcon win = new ImageIcon(this.getClass().getResource("/image/win.png"));
            JLabel winIcon = new JLabel(win);
            winIcon.setBounds(203, 283, 197, 73);
            this.getContentPane().add(winIcon);
        }

        JLabel countWord = new JLabel("步数:" + count);
        countWord.setBounds(50, 30, 100, 20);
        this.getContentPane().add(countWord);

        // 初始化图片
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int num = data[i][j];
                if (num == 0) {
                    continue;
                }

                ImageIcon icon = new ImageIcon(this.getClass().getResource("/image/puzzle/" + num + ".jpg"));
                JLabel jLabel = new JLabel(icon);
                jLabel.setBounds(105 * j + 83, 105 * i + 134, 105, 105);
                jLabel.setBorder(new BevelBorder(BevelBorder.LOWERED));
                this.getContentPane().add(jLabel);
            }
        }

        // 初始化背景
        ImageIcon bg = new ImageIcon(this.getClass().getResource("/image/background.png"));
        JLabel background = new JLabel(bg);
        background.setBounds(40, 40, 508, 560);
        this.getContentPane().add(background);

        // 刷新界面
        this.getContentPane().repaint();
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

        // 业务逻辑: 键盘监听
        this.addKeyListener(this);
    }

    private void initMenu() {
        // 菜单条
        JMenuBar jMenuBar = new JMenuBar();
        jMenuBar.setSize(514, 20);

        // 游戏菜单
        JMenu jMenu1 = new JMenu("游戏菜单");
        // 联系我们
        JMenu jMenu2 = new JMenu("联系我们");

        // 添加鼠标事件绑定
        jMenuItem11.addActionListener(this);
//        jMenuItem12.addActionListener(this);
        jMenuItem13.addActionListener(this);
        jMenuItem14.addActionListener(this);
        jMenuItem21.addActionListener(this);
        jMenuItem22.addActionListener(this);

        // 菜单结构
        jMenu1.add(jMenuItem11);
//        jMenu1.add(jMenuItem12);
        jMenu1.add(jMenuItem13);
        jMenu1.add(jMenuItem14);
        jMenu2.add(jMenuItem21);
        jMenu2.add(jMenuItem22);
        jMenuBar.add(jMenu1);
        jMenuBar.add(jMenu2);
        this.setJMenuBar(jMenuBar);
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();

        if (code == 'U') {
            this.getContentPane().removeAll();
            ImageIcon icon = new ImageIcon(this.getClass().getResource("/image/puzzle/all.jpg"));
            JLabel all = new JLabel(icon);
            all.setBounds(83, 134, 420, 420);
            this.getContentPane().add(all);

            // 初始化背景
            ImageIcon bg = new ImageIcon(this.getClass().getResource("/image/background.png"));
            JLabel background = new JLabel(bg);
            background.setBounds(40, 40, 508, 560);
            this.getContentPane().add(background);

            // 刷新界面
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int code = e.getKeyCode();

        if (isWin()) {
            return;
        }

        if (code == 37) {
            // 左移
            if (yBlock == 0) {
                return;
            }
            data[xBlock][yBlock] = data[xBlock][yBlock - 1];
            data[xBlock][yBlock - 1] = 0;
            yBlock--;
            count++;
            initImage();
        } else if (code == 38) {
            // 上移
            if (xBlock == 0) {
                return;
            }
            data[xBlock][yBlock] = data[xBlock - 1][yBlock];
            data[xBlock - 1][yBlock] = 0;
            xBlock--;
            count++;
            initImage();
        } else if (code == 39) {
            // 右移
            if (yBlock == 3) {
                return;
            }
            data[xBlock][yBlock] = data[xBlock][yBlock + 1];
            data[xBlock][yBlock + 1] = 0;
            yBlock++;
            count++;
            initImage();
        } else if (code == 40) {
            // 下移
            if (xBlock == 3) {
                return;
            }
            data[xBlock][yBlock] = data[xBlock + 1][yBlock];
            data[xBlock + 1][yBlock] = 0;
            xBlock++;
            count++;
            initImage();
        }

        if (code == 'U') {
            initImage();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();

        if (obj == jMenuItem11) {
            // 重新游戏
            count = 0;
            initData();
            initImage();
        } /*else if (obj == jMenuItem12) {
            // 重新登录
            this.setVisible(false);
            new LoginJFrame();
        }*/ else if (obj == jMenuItem13) {
            // 一键通关
            data = new int[][]{
                    {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 0}
            };
            initImage();
            xBlock = 3;
            yBlock = 3;
        } else if (obj == jMenuItem14) {
            // 退出游戏
            System.exit(0);
        } else if (obj == jMenuItem21) {
            // GitHub
            JDialog github = new JDialog(this, "GitHub Page", true);
            github.setSize(350, 150);
            github.setLocationRelativeTo(this);
            JLabel word1 = new JLabel("<html>GitHub: <a href=''>https://github.com/FeterPig</a></html>");
            word1.setHorizontalAlignment(SwingConstants.CENTER);
            github.add(word1);
            github.setVisible(true);
        } else if (obj == jMenuItem22) {
            // 个人主页
            JDialog page = new JDialog(this, "blog Page", true);
            page.setSize(350, 150);
            page.setLocationRelativeTo(this);
            JLabel word2 = new JLabel("<html>blog: <a href=''>https://feterpig77.top</a></html>");
            word2.setHorizontalAlignment(SwingConstants.CENTER);
            page.add(word2);
            page.setVisible(true);
        }
    }
}