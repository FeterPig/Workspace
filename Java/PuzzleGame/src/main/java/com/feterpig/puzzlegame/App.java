package com.feterpig.puzzlegame;

import com.feterpig.puzzlegame.ui.GameJFrame;
import com.feterpig.puzzlegame.ui.LoginJFrame;
import com.feterpig.puzzlegame.ui.RegisterJFrame;

public class App {
    public static void main(String[] args) {

        new LoginJFrame();

        new RegisterJFrame();

        new GameJFrame();
    }
}
