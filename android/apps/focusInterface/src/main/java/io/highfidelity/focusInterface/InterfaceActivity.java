package io.highfidelity.focusInterface;


import android.content.res.AssetManager;
import android.os.Bundle;

import org.qtproject.qt5.android.bindings.QtActivity;

import io.highfidelity.utils.HifiUtils;

public class InterfaceActivity extends QtActivity{
    private static final String TAG = InterfaceActivity.class.getSimpleName();
   // static { System.loadLibrary("focusInterface"); }

 //   private native void NativeOnCreate(AssetManager obj);
 //   private native void NativeOnPause();
 //   private native void NativeOnResume();
 //   private native void OnAppAfterLoad();
//
 //   private native void NativeAwayMode();
 //   private native void NotifyHeadsetOn(boolean pluggedIn);


    @Override
    public void onCreate(Bundle savedInstanceState) {
        HifiUtils.upackAssets(getAssets(), getCacheDir().getAbsolutePath());
       
        if(getIntent().hasExtra("applicationArguments")){
            super.APPLICATION_PARAMETERS=getIntent().getStringExtra("applicationArguments");
        }

        super.onCreate(savedInstanceState);

      //  NativeOnCreate(getAssets());
    }




}
