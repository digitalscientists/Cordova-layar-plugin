package com.ds.cordova.layar;

import java.text.MessageFormat;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

import android.app.Activity;
import android.util.Log;

import com.layar.sdk.LayarSDKListener;
import com.layar.sdk.LayarVisionSDK;

public class LayarVision extends CordovaPlugin implements LayarSDKListener {

	private static final String	TAG	= LayarVision.class.getSimpleName();

	@Override
	public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
		launch();
		return true;
	}

	public void launch() {
		Log.d(TAG, "#lauch");
	
		String oauthKey = "IFfARbQzwDoNMVHB";
		String oauthSecret = "JVMjrbiogcIYKpGNqBReWLnAfHZdzQsl";

		final Activity activity = cordova.getActivity();
		LayarVisionSDK.initialize(activity, oauthKey, oauthSecret);
		LayarVisionSDK.startLayarVisionActivity(activity, this);
	}

	@Override
	public void onLayerLaunched(String arg0, String arg1) {
		Log.d(TAG, MessageFormat.format("#onLayerLaunched\narg0 = {0}; arg1 = {1};", arg0, arg1));
		
	}

	@Override
	public void onReferenceImageTracked(String arg0, String arg1, String arg2) {
		Log.d(TAG, MessageFormat.format("#onReferenceImageTracked\narg0 = {0}; arg1 = {1}; arg2 = {2}", arg0, arg1, arg2));
	}

}