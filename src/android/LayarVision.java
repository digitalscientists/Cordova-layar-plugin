package com.ds.cordova.layar;

import java.text.MessageFormat;
import java.util.Timer;
import java.util.TimerTask;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

import android.app.Activity;
import android.app.ProgressDialog;
import android.util.Log;
import android.widget.Toast;


import com.layar.sdk.*;

public class LayarVision extends CordovaPlugin {

	private static final String	TAG	= LayarVision.class.getSimpleName();
	
	private ProgressDialog mProgressDlg;
	private Activity mActivity;

	@Override
	public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
		launch();
		return true;
	}

	public void launch() {
		Log.d(TAG, "#lauch");
		
		mActivity = cordova.getActivity();

		mProgressDlg = ProgressDialog.show(mActivity, "Launching scanner",
				"...");

		Toast.makeText(mActivity, "Launching scanner", Toast.LENGTH_SHORT)
				.show();

		new Timer().schedule(new TimerTask() {

			@Override
			public void run() {
				mProgressDlg.dismiss();
			}
		}, 3000);

		
		com.layar.player.R.init(mActivity);
	
		String oauthKey = mActivity.getString(com.layar.player.R.string.layar_vision_key); //"IFfARbQzwDoNMVHB";
		String oauthSecret = mActivity.getString(com.layar.player.R.string.layar_vision_secret); //"JVMjrbiogcIYKpGNqBReWLnAfHZdzQsl";

		LayarSDK.initialize(mActivity, oauthKey, oauthSecret);
		LayarSDK.startLayarActivity(mActivity);
	}

}