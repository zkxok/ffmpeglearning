package com.zkx.myplayer;

public class Demo {
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();

}
