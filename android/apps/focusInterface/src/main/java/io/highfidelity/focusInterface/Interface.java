package io.highfidelity.focusInterface;


import android.os.Bundle;

import org.qtproject.qt5.android.bindings.QtActivity;

import io.highfidelity.utils.HifiUtils;

public class Interface extends QtActivity{

    @Override
    public void onCreate(Bundle savedInstanceState) {
        HifiUtils.upackAssets(getAssets(), getCacheDir().getAbsolutePath());
        super.onCreate(savedInstanceState);

    }
}
